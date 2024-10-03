#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

// 将四元数转换为旋转矩阵
Mat quaternionToRotationMatrix(const Vec4d& q) {
    double qx = q[0], qy = q[1], qz = q[2], qw = q[3];
    Mat R = Mat::zeros(3, 3, CV_64F);

    R.at<double>(0, 0) = 1 - 2 * (qy * qy + qz * qz);
    R.at<double>(0, 1) = 2 * (qx * qy - qz * qw);
    R.at<double>(0, 2) = 2 * (qx * qz + qy * qw);

    R.at<double>(1, 0) = 2 * (qx * qy + qz * qw);
    R.at<double>(1, 1) = 1 - 2 * (qx * qx + qz * qz);
    R.at<double>(1, 2) = 2 * (qy * qz - qx * qw);

    R.at<double>(2, 0) = 2 * (qx * qz - qy * qw);
    R.at<double>(2, 1) = 2 * (qy * qz + qx * qw);
    R.at<double>(2, 2) = 1 - 2 * (qx * qx + qy * qy);

    return R;
}

int main() {
    // 读取 points.txt 文件中的点
    ifstream file("../points.txt");
    if (!file.is_open()) {
        cerr << "无法打开文件" << endl;
        return -1;
    }

    int numPoints;
    file >> numPoints;

    vector<Point3d> worldPoints(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        file >> worldPoints[i].x >> worldPoints[i].y >> worldPoints[i].z;
    }
    file.close();

    // 设置相机的内参矩阵
    Mat K = (Mat_<double>(3, 3) << 400, 0, 190,
                                    0, 400, 160,
                                    0, 0, 1);

    // 相机位置和姿态（四元数）
    Point3d cameraPosition(2, 2, 2);  // 相机的世界坐标
    Vec4d quaternion(0.5, 0.5, -0.5, -0.5);  // 四元数 (x, y, z, w)

    // 将四元数转换为旋转矩阵
    Mat R = quaternionToRotationMatrix(quaternion);

    // 计算变换矩阵
    Mat t = -R * Mat(cameraPosition);

    // 初始化图像
    Mat image(1024, 1657, CV_8UC3, Scalar(0, 0, 0));  // 创建一个空图像

    // 投影三维点到二维图像上
    vector<Point2d> imagePoints;
    projectPoints(worldPoints, R, t, K, noArray(), imagePoints);

    for (const auto& point : imagePoints) {
        if (point.x >= 0 && point.x < image.cols && point.y >= 0 && point.y < image.rows) {
            circle(image, Point(round(point.x), round(point.y)), 3, Scalar(0, 255, 0), -1);  // 在图像中画出点
        }
    }

    // 显示图像
    imshow("Projected Points", image);
    waitKey(0);

    // 保存图像
    imwrite("projected_image.png", image);

    return 0;
}