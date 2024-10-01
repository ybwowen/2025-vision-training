// 不知道为什么执行不了，再说吧
#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Geometry/Quaternion.h>
#include <eigen3/Eigen/src/Core/Matrix.h>

// 声明已知的相机参数
cv::Mat cameraMatrix, rotationMatrix; // 相机内参矩阵和旋转矩阵
cv::Vec3d translationVector; // 平移向量

// 读取坐标
void readDataFromFile(const std::string& filename, std::vector<cv::Point3f>& points) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    int n;
    file >> n;
    points.reserve(n);

    for (int i = 0; i < n; ++i) {
        float x, y, z;
        file >> x >> y >> z;
        points.emplace_back(x, y, z);
    }
    file.close();
}

void projectAndDrawPoints(const std::vector<cv::Point3f>& worldPoints, cv::Mat& image) {
    cv::Mat distCoeffs = cv::Mat::zeros(4, 1, CV_64F); // 假设没有径向畸变和切向畸变

    for (const auto& point3D : worldPoints) 
    {
        // 将3D点转换为相机坐标系下的点
        cv::Mat point3D_cv = (cv::Mat_<double>(3, 1) << point3D.x, point3D.y, point3D.z);
        cv::Mat temp =rotationMatrix * point3D_cv;
        //cv::transpose(temp, temp);
        cv::Mat pointCam = temp+translationVector;

        // 投影到图像平面
        cv::Mat point2D;
        cv::projectPoints(pointCam.reshape(1, 1), cv::Mat(), cv::Mat(), cameraMatrix, distCoeffs, point2D);

        // 绘制点
        cv::circle(image, cv::Point(cvRound(point2D.at<double>(0, 0)), cvRound(point2D.at<double>(1, 0))), 3, cv::Scalar(0, 0, 255), -1);
    }
}

int main() {
    std::string filename = "points.txt";
    std::vector<cv::Point3f> worldPoints;
    
    // 初始化相机参数
    cameraMatrix = (cv::Mat_<double>(3,3) << 400., 0., 190., 0.,// 相机内参矩阵
                                                        0., 400., 160., 0.,
                                                        0., 0., 1., 0.); 

    Eigen::Quaterniond quaterniond(0.5,0.5,-0.5,-0.5);// 通过四元数转换得到的旋转矩阵
    Eigen::Matrix3f rot_Matrix = quaterniond.toRotationMatrix(); 
    rotationMatrix=(rot_Matrix.rows(),rot_Matrix.cols(),CV_32F);
    for (int i=0;i<rot_Matrix.rows();i++)
    {
        for (int j=0;j<rot_Matrix.cols();j++)
        {
            rotationMatrix.at<float>(i,j)=rot_Matrix(i,j);
        }
    }

    translationVector = cv::Vec3d(2, 2, 2); // 平移向量


    // 读取数据
    readDataFromFile(filename, worldPoints);

    // 创建图像并设置大小（根据需要调整）
    cv::Mat image(720, 1280, CV_8UC3, cv::Scalar(255, 255, 255));

    // 投影并绘制点
    projectAndDrawPoints(worldPoints, image);

    // 显示图像
    cv::imshow("Projected Points", image);
    cv::waitKey(0);

}