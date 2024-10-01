#include <opencv2/opencv.hpp>
#include <Eigen/Dense> 
#include <Eigen/Geometry> 
#include <fstream>
#include <vector>
#include <iostream>

int main() {
    // 读取points.txt文件
    std::ifstream file("/home/ymz/Codes/2025-vision-training/homework1/photograph/points.txt");
    int num_points;
    file >> num_points;

    std::vector<Eigen::Vector3d> world_points;
    for (int i = 0; i < num_points; i++) {
        double x, y, z;
        file >> x >> y >> z;
        world_points.push_back(Eigen::Vector3d(x, y, z));
    }

    // 相机位置
    Eigen::Vector3d cam_position(2, 2, 2);

    // 相机姿态四元数
    Eigen::Quaterniond q(-0.5, 0.5, 0.5, -0.5);  // 四元数

    // 四元数转换为旋转矩阵
    Eigen::Matrix3d R = q.toRotationMatrix();

    // 相机内参矩阵
    Eigen::Matrix3d K;
    K << 400, 0, 190,
         0, 400, 160,
         0, 0, 1;

    // 创建一个空白图像
    cv::Mat image = cv::Mat::zeros(320, 380, CV_8UC3);

    int count = 0;
    for (auto& point : world_points) {
        // 世界坐标转换到相机坐标
        Eigen::Vector3d point_in_camera = R * (point - cam_position);

         // 如果点在相机后方，跳过该点
        if (point_in_camera(2) <= 0) {
            continue;
        }

        // 投影到图像平面
        Eigen::Vector3d projected = K * point_in_camera;
        double u = projected(0) / projected(2);  // 归一化像素坐标
        double v = projected(1) / projected(2);
        
        // 绘制投影点
        if (u >= 0 && u < image.cols && v >= 0 && v < image.rows) {
            std::cout << count << " " << u << " " << v << std::endl;
            count++;
            cv::circle(image, cv::Point(u, v), 3, cv::Scalar(0, 255, 0), -1);
        }
    }

    // 保存图像到程序路径下
    cv::imwrite("../photographResult.jpg", image);

    // 显示结果
    cv::imshow("Projected Points", image);

    cv::waitKey(0);

    return 0;
}

