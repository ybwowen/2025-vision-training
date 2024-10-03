#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <assert.h>
#include <string>

int main(int argc, char **argv) {
    // 读取图像
    cv::Mat image = cv::imread("/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_2/apple/apple.png");
    assert(image.channels() == 3);

    // 参数设置
    int h_min_part1 = 0;   
    int h_max_part1 = 25;   
    int h_min_part2 = 161;  
    int h_max_part2 = 180;    
    int canny_low_threshold = 16; 
    int canny_high_threshold = 156;
    cv::Mat hsv, result, grey_image, result2, combined_result;

    // 预处理
    cv::GaussianBlur(image, image, cv::Size(5, 5), 0);
    cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV); // 转换为HSV颜色空间
    cv::cvtColor(image, grey_image, cv::COLOR_BGR2GRAY); // 转换为灰度图

    // 提取颜色
    cv::Mat hsv_part1, hsv_part2;
    cv::inRange(hsv, cv::Scalar(h_min_part1, 43, 46), cv::Scalar(h_max_part1, 255, 255), hsv_part1);
    cv::inRange(hsv, cv::Scalar(h_min_part2, 43, 46), cv::Scalar(h_max_part2, 255, 255), hsv_part2); 

    // 取并集
    cv::Mat ones_mat = cv::Mat::ones(cv::Size(image.cols, image.rows), CV_8UC1);
    result = 255 * (ones_mat - (ones_mat - hsv_part1 / 255).mul(ones_mat - hsv_part2 / 255));

    // 形态学操作
    cv::Mat kernel1 = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(10, 10));
    cv::Mat kernel2 = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(10, 10));
    cv::morphologyEx(result, result, cv::MORPH_OPEN, kernel1);
    cv::morphologyEx(result, result, cv::MORPH_CLOSE, kernel2);

    // Canny边缘检测
    cv::Canny(grey_image, result2, canny_low_threshold, canny_high_threshold);

    int dilation_size = 2;  
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1));
    cv::dilate(result2, result2, kernel);  

    // 将颜色分割结果和边缘检测结果结合
    cv::bitwise_not(result2, result2);  // 先对 result2 取反，得到它的非边缘区域
    cv::bitwise_and(result, result2, combined_result);  // 只保留 result 中不在 result2 中的部分

    // 寻找轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(combined_result, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 找到面积最大的轮廓
    double maxArea = 0;
    int maxAreaIdx = -1;
    for (int i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area > maxArea) {
            maxArea = area;
            maxAreaIdx = i;
        }
    }

    // 创建一个用于存储轮廓的掩码图像
    cv::Mat contour_mask = cv::Mat::zeros(image.size(), CV_8UC1);

    // 将最大轮廓绘制到掩码图像上
    if (maxAreaIdx != -1) {
        cv::drawContours(contour_mask, contours, maxAreaIdx, cv::Scalar(255), 1);  // 用 1 像素宽度绘制最大轮廓
    }

    // 扩展轮廓：膨胀操作
    dilation_size = 5; 
    cv::Mat kernel3 = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1));
    cv::dilate(contour_mask, contour_mask, kernel3); 

    // 重新查找扩展后的轮廓
    std::vector<std::vector<cv::Point>> expanded_contours;
    cv::findContours(contour_mask, expanded_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 绘制扩展后的轮廓
    cv::Mat contour_output = image.clone();  
    if (!expanded_contours.empty()) {
        cv::drawContours(contour_output, expanded_contours, 0, cv::Scalar(0, 255, 0), 2);

        // 获取包含扩展轮廓的最小外接矩形
        cv::Rect bounding_box = cv::boundingRect(expanded_contours[0]);

        // 绘制最小白色矩形
        cv::rectangle(contour_output, bounding_box, cv::Scalar(255, 255, 255), 2); 
    }

    std::string output_image_path = "/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_2/apple/detect_result.jpg";
    cv::imwrite(output_image_path, contour_output);
    // 显示结果
    cv::imshow("result", contour_output);
    cv::waitKey(0);

    return 0;
}
