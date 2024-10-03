#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <vector>
#include <iostream>
#include "assets/big_armor_scale.hpp"
#include <fstream>

int main(int argc, char* argv[]) {
    cv::FileStorage fs("../assets/f_mat_and_c_mat.yml", cv::FileStorage::READ);
    cv::Mat cameraMatrix, distCoeffs;
    fs["F"] >> cameraMatrix;
    fs["C"] >> distCoeffs;

    std::vector<cv::Point3d> objectPoints = PW_BIG;

    std::vector<cv::Point2d> armorPoints;
    std::ifstream file("../assets/imu_and_armor.txt");
    std::string line;

    std::getline(file, line);

    double x, y, z, w;
    std::getline(file, line);
    std::istringstream iss(line);
    std::vector<std::string> parts;
    std::string part;

    while (std::getline(iss, part, '+')) {
        parts.push_back(part);
    }

    x = std::stod(parts[0].substr(0, parts[0].length()-1));
    y = std::stod(parts[1].substr(0, parts[1].length()-1));
    z = std::stod(parts[2].substr(0, parts[2].length()-1));
    w = std::stod(parts[3]);

    Eigen::Quaterniond quaternion(w, x, y, z);
    quaternion.normalize();

    std::getline(file, line);
    double tmp1, tmp2;
    while(file >> tmp1 >> tmp2) {
        armorPoints.push_back(cv::Point2d(tmp1, tmp2));
    }

    cv::Mat rvec, tvec;
    cv::solvePnP(objectPoints, armorPoints, cameraMatrix, distCoeffs, rvec, tvec);

    cv::Mat rot_mat;
    cv::Rodrigues(rvec, rot_mat);
    Eigen::Matrix3d R_c2w;
    cv::cv2eigen(rot_mat, R_c2w);

    Eigen::Vector3d armor_center_local(0, 0, 0);
    for (const auto& point : objectPoints) {
        armor_center_local += Eigen::Vector3d(point.x, point.y, point.z);
    }
    armor_center_local /= objectPoints.size();

    Eigen::Vector3d t_c2w(tvec.at<double>(0), tvec.at<double>(1), tvec.at<double>(2));
    Eigen::Vector3d armor_center_camera = R_c2w * armor_center_local + t_c2w;

    Eigen::Vector3d armor_center_world = quaternion * armor_center_camera;

    std::cout << armor_center_world.transpose() << std::endl;

    fs.release();
    file.close();
    return 0;
}