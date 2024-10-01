//
// Created by cwlm on 2024/10/1.
//
#include <fstream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


// 将世界坐标系的点投影到相机坐标系
Matrix<double, 4, 1> projectPointToCam(const Matrix<double, 4, 1> &point, const Matrix3d &R, const Vector3d &T) {
    Matrix<double, 4, 4> RT;

    RT << R(0, 0), R(0, 1), R(0, 2), T(0),
            R(1, 0), R(1, 1), R(1, 2), T(1),
            R(2, 0), R(2, 1), R(2, 2), T(2),
            0, 0, 0, 1;

    Matrix<double, 4, 1> camPoint = RT * point;

    // 投影到图像平面
    return camPoint;
}

// 将世界坐标系的点投影到图像平面
vector<cv::Point2d> projectPointsToCV(const vector<Matrix<double, 4, 1>> &points, const Matrix3d &R, const Vector3d &T,
                                      const Matrix<double, 3, 4> &K) {
    vector<cv::Point2d> projectedPoints;

    for (const auto &point: points) {
        Matrix<double, 4, 1> camPoint = projectPointToCam(point, R, T);

        // 投影到图像平面
        if (camPoint(2) > 0) { // 确保点在相机前面
            Vector3d projected = K * camPoint;
            projectedPoints.emplace_back(projected(0) / projected(2),
                                         projected(1) / projected(2));
        }
    }

    return projectedPoints;
}

cv::Mat drawPoints(const vector<cv::Point2d> &points) {
    cv::Mat image = cv::Mat::zeros(1080, 1920, CV_8UC3);
    for (const auto &p: points) {
        cv::circle(image, cv::Point(static_cast<int>(p.x), static_cast<int>(p.y)),
                   1, cv::Scalar(0, 255, 0), -1);
    }
    return image;
}

cv::Mat takePhoto(const vector<Matrix<double, 4, 1>> &points,const Quaternion<double> &quaternionInv, const Vector3d &T_inv,
                  const Matrix<double, 3, 4> &K) {
    // 计算相机坐标系的平移向量
    Quaternion<double> quaternion = quaternionInv.inverse();
    Vector3d T = -(quaternion * T_inv);

    // 计算相机坐标系的旋转矩阵
    Matrix3d R = quaternion.toRotationMatrix();

    // 将世界坐标系的点投影到图像平面
    vector<cv::Point2d> projectedPoints = projectPointsToCV(points, R, T, K);

    // 绘制投影点
    return drawPoints(projectedPoints);
}

int main() {
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

    // 相机内参矩阵
    Matrix<double, 3, 4> K;
    K << 400.0, 0.0, 190.0, 0.0,
            0.0, 400.0, 160.0, 0.0,
            0.0, 0.0, 1.0, 0.0;

    // 相机坐标和姿态四元数
    Quaternion<double> quaternionInv(-0.5, 0.5, 0.5, -0.5);
    Vector3d T_inv(2.0, 2.0, 2.0);

    auto image = takePhoto(worldPoints, quaternionInv, T_inv, K);

    // 显示图像
    cv::imshow("Projected Points", image);
    cv::waitKey(0);
    return 0;
}
