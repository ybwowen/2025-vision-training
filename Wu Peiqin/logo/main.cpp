#include <iostream>

#include <opencv2/highgui.hpp>
#include <vector>
#include <string>
#include <random>

#include <dirent.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>



int main() {
    // 加载图标图像
    std::string image_path = "../img.png";
    cv::Mat image = cv::imread(image_path, cv::IMREAD_GRAYSCALE);

    if (image.empty()) {
        std::cerr << "无法打开图像文件: " << image_path << std::endl;
        return -1;
    }

    // 二值化图像
    cv::Mat thresh;
    cv::threshold(image, thresh, 127, 255, cv::THRESH_BINARY);

    // 提取轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(thresh, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    if (contours.empty()) {
        std::cerr << "未找到任何轮廓，请检查图像内容" << std::endl;
        return -1;
    }

    // 生成光点
    int num_points = 7000; 
    std::vector<cv::Point> points;
    std::vector<cv::Point> start_points(num_points);
    std::vector<float> depths(num_points);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rand_x(0, image.cols - 1);
    std::uniform_int_distribution<> rand_y(0, image.rows - 1);
    std::uniform_real_distribution<> depth_dis(-50, 50);

    // 从所有轮廓中随机选择点
    for (int i = 0; i < num_points; ++i) {
        int contour_idx = std::uniform_int_distribution<>(0, contours.size() - 1)(gen);
        int point_idx = std::uniform_int_distribution<>(0, contours[contour_idx].size() - 1)(gen);
        points.push_back(contours[contour_idx][point_idx]);
        start_points[i] = cv::Point(rand_x(gen), rand_y(gen));
        depths[i] = depth_dis(gen);
    }

    // 初始化视频写入
    cv::VideoWriter out("../logo_animation.mp4", cv::VideoWriter::fourcc('m', 'p', '4', 'v'), 30.0, image.size());

    if (!out.isOpened()) {
        std::cerr << "无法打开视频文件进行写入" << std::endl;
        return -1;
    }

    // 创建显示窗口
    cv::namedWindow("Animation", cv::WINDOW_AUTOSIZE);

    // 模拟光点移动并生成动画
    for (int t = 0; t < 200; ++t) { // 增加动画帧数
        cv::Mat frame = cv::Mat::zeros(image.size(), CV_8UC1);
        float alpha = static_cast<float>(t) / 200; // 调整alpha计算
        for (int i = 0; i < num_points; ++i) {
            cv::Point current_point = (1 - alpha) * start_points[i] + alpha * points[i];
            int x_proj = current_point.x;
            int y_proj = current_point.y;
            if (x_proj >= 0 && x_proj < frame.cols && y_proj >= 0 && y_proj < frame.rows) {
                frame.at<uchar>(y_proj, x_proj) = 255;
            }
        }
        cv::cvtColor(frame, frame, cv::COLOR_GRAY2BGR);
        out.write(frame);

        // 显示当前帧
        cv::imshow("Animation", frame);
        if (cv::waitKey(20) >= 0) break; // 等待20毫秒，按任意键退出
    }

    cv::waitKey(0); // 等待用户按键
    out.release();
    cv::destroyAllWindows();
    return 0;
}