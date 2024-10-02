//
// Created by cwlm on 2024/10/2.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

const std::vector<cv::Point3d> PW_BIG{
    // 灯条坐标，单位：m
    {-0.115, 0.0265, 0.},
    {-0.115, -0.0265, 0.},
    {0.115, -0.0265, 0.},
    {0.115, 0.0265, 0.}
};

Eigen::Quaterniond parseQuaternion(const std::string& str) {
    std::vector<double> numbers;
    std::string temp = str;
    size_t pos = 0;

    while ((pos = temp.find_first_of('+')) != std::string::npos) {
        std::string token = temp.substr(0, pos);
        temp.erase(0, pos + 1);
        numbers.push_back(std::stod(token));
    }
    numbers.push_back(std::stod(temp));

    return {numbers[1], numbers[2], numbers[3], numbers[0]};
}


void readIMUAndArmor(const std::string& filename, Eigen::Quaterniond& imuQuat, std::vector<cv::Point2f>& armorPoints) {
    std::ifstream infile(filename);
    std::string line;

    std::getline(infile, line);
    std::getline(infile, line); // 读取四元数
    imuQuat = parseQuaternion(line);
    std::getline(infile, line);
    for (int i = 0; i < 4; ++i) {
        std::getline(infile, line);
        std::stringstream ss(line);
        cv::Point2f point;
        ss >> point.x >> point.y;
        armorPoints.push_back(point);
    }

    infile.close();
}

void readCameraMatrixAndDistCoeffs(const std::string& filename, cv::Mat& cameraMatrix, cv::Mat& distCoeffs) {
    cv::FileStorage fs(filename, cv::FileStorage::READ);
    fs["F"] >> cameraMatrix;
    fs["C"] >> distCoeffs;
    fs.release();
}

int main() {
    // 读取内参和畸变参数
    cv::Mat cameraMatrix, distCoeffs;
    readCameraMatrixAndDistCoeffs("assets/f_mat_and_c_mat.yml", cameraMatrix, distCoeffs);

    // 读取 IMU 和装甲板坐标
    Eigen::Quaterniond imuQuat;
    std::vector<cv::Point2f> armorPoints;
    readIMUAndArmor("assets/imu_and_armor.txt", imuQuat, armorPoints);

    // 去畸变
    std::vector<cv::Point2f> undistortedPoints;
    undistortPoints(armorPoints, undistortedPoints, cameraMatrix, distCoeffs);

    // 假设相机的焦距为 fx 和 fy，主点为 cx 和 cy
    double fx = cameraMatrix.at<double>(0, 0);
    double fy = cameraMatrix.at<double>(1, 1);
    double cx = cameraMatrix.at<double>(0, 2);
    double cy = cameraMatrix.at<double>(1, 2);



    return 0;
}
