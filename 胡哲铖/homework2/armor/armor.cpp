#include <fstream>
#include <opencv2/calib3d.hpp>
#include <opencv2/core/persistence.hpp>
#include <opencv2/core/types.hpp>
#include "assets/big_armor_scale.hpp"
#include <string>
#include <vector>
#include <regex>
#include <Eigen/Dense>
#include <opencv2/core/eigen.hpp>
#include <opencv2/opencv.hpp>

Eigen::Quaterniond str2Quat(std::string str){
    std::regex pattern(R"([-]?[0-9]+\.?[0-9]+)");//匹配小数
    std::smatch res;
    std::string::const_iterator start=str.begin();
    std::string::const_iterator end=str.end();
    std::vector<double> nums;
    while(regex_search(start,end,res,pattern)){
		nums.push_back(std::stod(res[0]));
		//重设匹配开始位置为上一个匹配结果之后
		start=res[0].second;
	}
    Eigen::Quaterniond quat(nums[3],nums[0],nums[1],nums[2]);
    return quat;
}

cv::Point2d str2Point(std::string str){
    std::regex pattern(R"([-]?[0-9]+\.?[0-9]+)");//匹配小数
    std::smatch res;
    std::string::const_iterator start=str.begin();
    std::string::const_iterator end=str.end();
    std::vector<double> nums;
    while(regex_search(start,end,res,pattern)){
		nums.push_back(std::stod(res[0]));
		//重设匹配开始位置为上一个匹配结果之后
		start=res[0].second;
	}
    cv::Point2d point(nums[0],nums[1]);
    return point;
}

int main() {
    //读取文件
    std::ifstream imuAndArmFile("../assets/imu_and_armor.txt");
    std::string line;

    std::getline(imuAndArmFile, line); //skip
    
    // 读取四元数
    std::getline(imuAndArmFile, line); 
    Eigen::Quaterniond imu;
    imu = str2Quat(line);
    imu.normalize();
    
    std::getline(imuAndArmFile, line); //skip x2
    
    //读取点位
    std::vector<cv::Point2d> armPoints;
    for (int i = 0; i < 4; i++) {
        std::getline(imuAndArmFile, line);
        cv::Point2d armPoint = str2Point(line);
        armPoints.push_back(armPoint);
    }
    
    //读取内参及畸变
    cv::FileStorage fs1("../assets/f_mat_and_c_mat.yml", cv::FileStorage::READ);
    cv::Mat cameraMatrix, distCoeffs;
    fs1["F"] >> cameraMatrix;
    fs1["C"] >> distCoeffs;

    //读取装甲板数据
    std::vector<cv::Point3d> objectPoints = PW_BIG;

    //解出旋转平移向量
    cv::Mat rvec, tvec;
    cv::solvePnP(objectPoints, armPoints, cameraMatrix, distCoeffs, rvec, tvec);
    
    //从cv转换为eigen
    Eigen::Vector3d tVector;
    cv::cv2eigen(tvec,tVector);

    //变换至陀螺仪坐标系 (solvePNP给出的变换中旋转对处于原点的装甲板中心无影响，不知道我的理解是否正确)
    Eigen::Vector3d armPosInGryo = imu* tVector;
    
    //存储
    cv::FileStorage fs2("../armor.yml", cv::FileStorage::WRITE);
    cv::Mat armPosInGryoCv;
    cv::eigen2cv(armPosInGryo,armPosInGryoCv);
    fs2 << "Position" << armPosInGryoCv;

    return 0;
}