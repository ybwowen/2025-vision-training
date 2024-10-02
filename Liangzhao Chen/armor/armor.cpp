#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <Eigen/Dense> 
#include <fstream>

// 四元数转旋转矩阵的函数
Eigen::Matrix3d quaternionToRotationMatrix(const Eigen::Quaterniond& q) {
    return q.toRotationMatrix();
}

int main() {
    // 装甲板的实际3D坐标（单位：米)
    std::vector<cv::Point3d> armor_3D_points = {
        {-0.115, 0.0265, 0.},
        {-0.115, -0.0265, 0.},
        {0.115, -0.0265, 0.},
        {0.115, 0.0265, 0.}
    };

    // 装甲板在像素坐标系下的4个顶点
    std::vector<cv::Point2d> armor_2D_points = {
        {575.508, 282.175},
        {573.93, 331.819},
        {764.518, 337.652},
        {765.729, 286.741}
    };

    // 读取相机内参矩阵
    cv::Mat camera_matrix = (cv::Mat_<double>(3, 3) << 1.4142055480888289e+03,0,6.5792667877101735e+02, 0.,
       1.4137212634286254e+03, 4.0455967287503142e+02, 0., 0., 1. );
    cv::Mat dist_coeffs = (cv::Mat_<double>(1, 5)<<-1.5713532786218060e-01, 3.3883933349759310e-01,
       7.0103028435554145e-04, -2.9035486504482461e-04,-4.2372708010388316e-01 ); 

    // 计算装甲板中心在相机坐标系下的3D位置
    cv::Mat rvec, tvec;
    cv::solvePnP(armor_3D_points, armor_2D_points, camera_matrix, dist_coeffs, rvec, tvec);

    // 计算中心点在相机坐标系下的坐标
    cv::Point3d armor_center_camera = cv::Point3d(tvec);

    // std::cout << "装甲板中心在相机坐标系下的坐标: " << armor_center_camera << std::endl;

    // 读取旋转四元数 (camera 到 imu)
    Eigen::Quaterniond q_camera_to_imu(-0.0816168, 0.994363, -0.0676645, -0.00122528); // w, x, y, z 顺序

    // 将四元数转为旋转矩阵
    Eigen::Matrix3d rotation_matrix_camera_to_imu = quaternionToRotationMatrix(q_camera_to_imu);
    

    // 将装甲板中心坐标从相机坐标系转换为陀螺仪坐标系
    Eigen::Vector3d armor_center_camera_eigen(armor_center_camera.x, armor_center_camera.y, armor_center_camera.z);
    Eigen::Vector3d armor_center_imu = rotation_matrix_camera_to_imu * armor_center_camera_eigen;

    std::ofstream output_file("ans.txt");
    if (output_file.is_open()) {
        output_file << "装甲板中心在陀螺仪坐标系下的坐标:\n";
        output_file << armor_center_imu.transpose() << std::endl;
        output_file.close();
        std::cout << "装甲板中心在陀螺仪坐标系下的坐标: " << armor_center_imu.transpose() << std::endl;
    } else {
        std::cerr << "无法打开 ans.txt 文件进行写入。" << std::endl;
    }
    return 0;
}
