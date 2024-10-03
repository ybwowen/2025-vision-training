#include <iostream>
#include <fstream>
#include <opencv2/calib3d.hpp>
#include <opencv2/core/mat.hpp>
#include <vector>
#include <utility>

#include <eigen3/Eigen/Dense>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "assets/big_armor_scale.hpp" // 装甲板四点的真实尺寸 const std::vector<cv::Point3d> PW_BIG


// 结果并不对，不知道为啥


// 读取yml文件中的相机内参和畸变矩阵
std::pair<cv::Mat,cv::Mat> readCameraParameters(const std::string& filename) 
{
    cv::FileStorage fs(filename, cv::FileStorage::READ);
    if (!fs.isOpened()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    cv::Mat F, C;
    fs["F"] >> F; // 相机内参矩阵
    fs["C"] >> C; // 畸变系数
    fs.release();

    cv::Mat F2=cv::Mat::zeros(3,3,F.type());
    F.copyTo(F2(cv::Rect(0,0,3,3)));

    return std::make_pair(F2, C);
}

// 将像素坐标转换为归一化相机坐标
cv::Point2d pixelToNormalized(const cv::Point2d& pixel, const cv::Mat& F) 
{
    cv::Point2d norm;
    norm.x = (pixel.x - F.at<double>(0, 2)) / F.at<double>(0, 0);
    norm.y = (pixel.y - F.at<double>(1, 2)) / F.at<double>(1, 1);
    return norm;
}

// 四元数到旋转矩阵
cv::Mat quaternionToRotationMatrix(const Eigen::Quaterniond& q) 
{
    cv::Mat rot=(cv::Mat_<double>(3,3) << q.x() * q.x(), q.x() * q.y(), q.x() * q.z(),
           q.y() * q.x(), q.y() * q.y(), q.y() * q.z(),
           q.z() * q.x(), q.z() * q.y(), q.z() * q.z());
    return rot;
}

int main() 
{
    try {
        // 读取相机参数
        auto params = readCameraParameters("../assets/f_mat_and_c_mat.yml");
        cv::Mat camera_intrinsic = params.first;
        cv::Mat discoeffs = params.second;


        // 装甲板像素坐标
        std::vector<cv::Point2d> armorPoints = {
            {575.508, 282.175},
            {573.93, 331.819},
            {764.518, 337.652},
            {765.729, 286.741}
        };
        
        // 陀螺仪四元数
        Eigen::Quaterniond q(-0.0816168, 0.994363, -0.0676645, -0.00122528);
        cv::Mat rotMatrix = quaternionToRotationMatrix(q.conjugate());

        // PNP求解
        cv::Mat out_rotat, out_trans, rot_mat;
        cv::solvePnP(PW_BIG, armorPoints, camera_intrinsic, discoeffs, out_rotat, out_trans);

        // 将旋转向量转换为旋转矩阵
        cv::Rodrigues(out_rotat, rot_mat);

        // 将相机坐标系下的点转换到陀螺仪坐标系
        cv::Point3d Center = PW_BIG[0]  + PW_BIG[2] ;
        Center *= 0.5;
        cv::Mat CenterMat = (cv::Mat_<double>(3, 1) << Center.x, Center.y, Center.z);
        cv::Mat gyroCenter = rot_mat * CenterMat + out_trans;
        std::cout << "Armor center in camera coordinate system: " << gyroCenter.t() << std::endl;

        // 将结果转换到陀螺仪坐标系
        gyroCenter = rotMatrix * gyroCenter;
        std::cout << "Armor center in gyroscope coordinate system: " << gyroCenter.t() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
