#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

// 将四元数转换为旋转矩阵
Mat quaternionToRotationMatrix(float qx, float qy, float qz, float qw) {
    Mat R = Mat::zeros(3, 3, CV_32F);

    R.at<float>(0, 0) = 1 - 2 * (qy * qy + qz * qz);
    R.at<float>(0, 1) = 2 * (qx * qy - qz * qw);
    R.at<float>(0, 2) = 2 * (qx * qz + qy * qw);

    R.at<float>(1, 0) = 2 * (qx * qy + qz * qw);
    R.at<float>(1, 1) = 1 - 2 * (qx * qx + qz * qz);
    R.at<float>(1, 2) = 2 * (qy * qz - qx * qw);

    R.at<float>(2, 0) = 2 * (qx * qz - qy * qw);
    R.at<float>(2, 1) = 2 * (qy * qz + qx * qw);
    R.at<float>(2, 2) = 1 - 2 * (qx * qx + qy * qy);

    return R;
}

int main() {
    // 读取 points.txt 文件中的点
    ifstream file("../points.txt");
    if (!file.is_open()) {
        cout << "无法打开文件" << endl;
        return -1;
    }

    int numPoints;
    file >> numPoints;

    vector<Point3f> worldPoints(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        file >> worldPoints[i].x >> worldPoints[i].y >> worldPoints[i].z;
    }
    file.close();

    // 设置相机的内参矩阵
    Mat K = (Mat_<float>(3, 3) << 400, 0, 190,
                                   0, 400, 160,
                                   0, 0, 1);

    // 相机位置和姿态（四元数）
    Point3f cameraPosition(2, 2, 2);  // 相机的世界坐标
    float qx = 0.5, qy = 0.5, qz = -0.5, qw = -0.5;  // 四元数

    // 将四元数转换为旋转矩阵
    Mat R = quaternionToRotationMatrix(qx, qy, qz, qw);
    Mat inv = R.inv();

    // 初始化图像
    Mat image(1024, 1657, CV_8UC3, Scalar(0, 0, 0));  // 创建一个空图像

    // 投影三维点到二维图像上
    for (const auto& worldPoint : worldPoints) {
        //  计算相机坐标系下的点
        Mat worldPointMat = (Mat_<float>(3, 1) << worldPoint.x - cameraPosition.x,
                                                   worldPoint.y - cameraPosition.y,
                                                   worldPoint.z - cameraPosition.z);
        Mat cameraPointMat = inv * worldPointMat;

        // 透视投影
        Mat imagePointMat = K * cameraPointMat;

        // 归一化
        float u = imagePointMat.at<float>(0) / imagePointMat.at<float>(2);
        float v = imagePointMat.at<float>(1) / imagePointMat.at<float>(2);

        //  在图像中绘制点
        if (u >= 0 && u < image.cols && v >= 0 && v < image.rows) {
            circle(image, Point2f(u, v), 3, Scalar(0, 255, 0), -1);  // 在图像中画出点
        }
    }

    // 显示图像
    imshow("Projected Points", image);
    waitKey(0);

    // 保存图像
    imwrite("projected_image.png", image);

    return 0;
}
