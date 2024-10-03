#include <opencv2/opencv.hpp>
#include <Eigen/Dense> 
#include <Eigen/Geometry> 
#include <fstream>
#include <vector>
#include <iostream>

int main() {
    // 读取points.txt文件
    std::ifstream file("/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_1/photograph/points.txt");
    int num_points;
    file >> num_points;

    cv::Mat world_point=cv::Mat_<double> (3,1);

    // 相机位置
    cv::Mat cam_position=(cv::Mat_<double>(3, 1) << 2,2,2);

    Eigen::Quaterniond quaternion(-0.5, 0.5, 0.5, -0.5); 
    Eigen::Matrix3d Emat = quaternion.toRotationMatrix();  
    cv::Mat R(3, 3, CV_64F);
    R=cv::Mat(Emat.rows(),Emat.cols(),CV_64F,Emat.data());

    // 相机内参矩阵
    cv::Mat K = (cv::Mat_<double>(3, 3) << 400.,0.,190.,0.,400.,160.,0.,0.,1.); 

    // 创建一个空白图像
    cv::Mat image = cv::Mat::zeros(800, 1200, CV_8UC3);

    for (int i=0; i<num_points; i++) {
        file >> world_point.at<double>(0, 0)>> world_point.at<double>(1, 0)>> world_point.at<double>(2, 0);
        // 世界坐标转换到相机坐标
        cv::Mat point_in_camera = R * (world_point - cam_position);

        // 投影到图像平面
        cv::Mat projected = K * point_in_camera;
        double u = projected.at<double>(0,0)/projected.at<double>(2,0);
        double v = projected.at<double>(1,0)/projected.at<double>(2,0);
        
        // 绘制投影点
        std::cout << u << " " << v << std::endl;
        cv::circle(image, cv::Point(u, v), 3, cv::Scalar(255, 255, 255), -1);
        
    }

    // 保存图像到程序路径下
    cv::imwrite("../photographResult.jpg", image);

    // 显示结果
    cv::imshow("Projected Points", image);

    cv::waitKey(0);

    return 0;
}

