#include <opencv2/opencv.hpp>
#include <Eigen/Dense> 
#include <Eigen/Geometry> 
#include <fstream>
#include <vector>
#include <iostream>

int main() {

    cv::Mat world_point = cv::Mat_<double>(3, 1);
    
    // 相机位置初始化
    cv::Mat cam_position=(cv::Mat_<double>(3, 1) << 0,0,0);

    Eigen::Quaterniond quaternion(0,0,0,0); 

    // 相机内参矩阵
    cv::Mat K = (cv::Mat_<double>(3, 3) << 400., 0., 190., 0., 400., 160., 0., 0., 1.); 

    // 创建视频写入对象
    cv::VideoWriter video("/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_2/logo/output_video.avi", cv::VideoWriter::fourcc('M','J','P','G'), 30, cv::Size(1200, 800));

    for (int frame = 0; frame < 250; ++frame) {  // 5秒，30帧/秒
        std::cout << "Frame " << frame << std::endl;
        // 清空图像
        cv::Mat image = cv::Mat::zeros(800, 1200, CV_8UC3);

        // 计算相机位置和旋转
        double t = static_cast<double>(frame) / 30.0;  // 当前时间
        if (cam_position.at<double>(0, 0) < 2) cam_position += 0.01;
        if (quaternion.w() > -0.5) {
            quaternion.w() -= 0.0025;
            quaternion.x() += 0.0025;
            quaternion.y() += 0.0025;
            quaternion.z() -= 0.0025;
        }
        Eigen::Matrix3d Emat = quaternion.toRotationMatrix();
        cv::Mat R(3, 3, CV_64F);
        R = cv::Mat(Emat.rows(), Emat.cols(), CV_64F, Emat.data());

        std::ifstream file("/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_1/photograph/points.txt");
        int num_points;
        file >> num_points;
        for (int i = 0; i < num_points; i++) {
            file >> world_point.at<double>(0, 0) >> world_point.at<double>(1, 0) >> world_point.at<double>(2, 0);
            // 世界坐标转换到相机坐标
            cv::Mat point_in_camera = R * (world_point - cam_position);

            // 投影到图像平面
            cv::Mat projected = K * point_in_camera;
            double u = projected.at<double>(0, 0) / projected.at<double>(2, 0);
            double v = projected.at<double>(1, 0) / projected.at<double>(2, 0);
            
            // 绘制投影点
            cv::circle(image, cv::Point(u, v), 3, cv::Scalar(255, 255, 255), -1);
        }
        file.close();

        // 保存当前帧到视频
        video.write(image);
    }

    // 释放资源
    video.release();

    return 0;
}
