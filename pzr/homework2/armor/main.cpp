#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> // 必须在包含 Eigen 头文件之前包含
#include <vector>
#include <iostream>
#include "assets/big_armor_scale.hpp"
#include <fstream>


int main(int argc, char* argv[]){
    cv::FileStorage fs("../assets/f_mat_and_c_mat.yml", cv::FileStorage::READ);
    cv::Mat cameraMatrix, distCoeffs;
    fs["F"] >> cameraMatrix;
    fs["C"] >> distCoeffs;

    std::vector<cv::Point3d> objectPoints = PW_BIG; // 世界空间中的点

    // 获取像素坐标系的点
    std::vector<cv::Point2d> armorPoints;
    std::fstream file("../assets/imu_and_armor.txt");
    std::string line;

    // 跳过第一行
    std::getline(file, line);

    // 读四元数
    double x,y,z,w;
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
    // std::cout<< "q: " << quaternion << std::endl;

    std::getline(file, line);
    double tmp1, tmp2;
    while(file >> tmp1 >> tmp2){
        armorPoints.push_back(cv::Point2d(tmp1, tmp2));
    }
    // std::cout<< "armorp: " << armorPoints << std::endl;


    cv::Mat rvec, tvec;

    cv::solvePnP(objectPoints, armorPoints, cameraMatrix, distCoeffs, rvec, tvec);

    cv::Point3d tvec_in_cv(tvec.at<double>(0), tvec.at<double>(1), tvec.at<double>(2));
    cv::Mat rot_mat;
    cv::Rodrigues(rvec, rot_mat);
    Eigen::MatrixXd rot_mat_e;
    cv::cv2eigen(rot_mat, rot_mat_e);
    // std::cout << rot_mat << rot_mat_e <<std::endl;
    

    // 输出四元数
    // std::cout << "rotate (data): " << quaternion.matrix() << std::endl;
    // std::cout << "rotate (cal):" << rot_mat << std::endl;

    // 输出坐标即为 相机到陀螺仪旋转矩阵 * 世界到相机旋转矩阵 * (世界坐标系坐标 - tvec)
    cv::Point3d avg( 0, 0, 0);
    for(int i=0; i< objectPoints.size(); i++){
        avg += objectPoints[i];
    }
    avg.x /= objectPoints.size();
    avg.y /= objectPoints.size();
    avg.z /= objectPoints.size();
    // std::cout << avg << std::endl;
    std::cout << tvec_in_cv << std::endl;
    Eigen::Vector3d world_p( tvec_in_cv.x ,  tvec_in_cv.y,  tvec_in_cv.z);
    std::cout<<" 装甲板中心坐标 : " << quaternion.matrix() * world_p << std::endl;


    fs.release();
    file.close();
    return 0;
}