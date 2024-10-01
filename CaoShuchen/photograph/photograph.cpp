//
// Created by cwlm on 2024/10/1.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {
    // 相机内参矩阵
    Matrix<double, 3, 4> K;
    K << 400.0, 0.0, 190.0, 0.0,
            0.0, 400.0, 160.0, 0.0,
            0.0, 0.0, 1.0, 0.0;

    // 相机坐标和姿态四元数
    Vector3d cameraPosition(2.0, 2.0, 2.0);
    Quaternion<double> quaternion(0.5, 0.5, -0.5, -0.5);

    // 读取点坐标
    ifstream inputFile("points.txt");
    int numPoints;
    inputFile >> numPoints;

    vector<Matrix<double, 4, 1>> worldPoints(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        double x, y, z;
        inputFile >> x >> y >> z;
        worldPoints[i] = Matrix<double, 4, 1>(x, y, z, 1.0);
    }
    inputFile.close();

    // 计算相机坐标系的旋转矩阵
    Matrix3d R = quaternion.toRotationMatrix();

    // 存储投影点
    vector<cv::Point2d> projectedPoints;

    for (const auto &point: worldPoints) {
        Matrix<double, 4, 4> RT;

        RT << R(0, 0), R(0, 1), R(0, 2), cameraPosition(0),
                R(1, 0), R(1, 1), R(1, 2), cameraPosition(1),
                R(2, 0), R(2, 1), R(2, 2), cameraPosition(2),
                0, 0, 0, 1;

        Matrix<double, 4, 1> camPoint = RT * point;

        // 投影到图像平面
        if (camPoint(2) > 0) { // 确保点在相机前面
            Vector3d projected = K * camPoint;
            projectedPoints.emplace_back(projected(0) / projected(2),
                                         projected(1) / projected(2));
        }
    }

    // 创建图像并绘制投影点
    cv::Mat image = cv::Mat::zeros(1080, 1920, CV_8UC3);
    for (const auto &p: projectedPoints) {
        cv::circle(image, cv::Point(static_cast<int>(p.x), static_cast<int>(p.y)),
                   1, cv::Scalar(0, 255, 0), -1);
    }

    // 显示图像
    cv::imshow("Projected Points", image);
    cv::waitKey(0);
    return 0;
}
