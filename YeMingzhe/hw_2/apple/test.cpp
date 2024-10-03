#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <assert.h>

cv::Mat image, hsv, result, grey_image, result2, combined_result;
int h_min_part1 = 0;      // h最小值，控制橙色
int h_max_part1 = 25;     // h最大值，控制橙色
int h_min_part2 = 156;    // h最小值，控制红色
int h_max_part2 = 180;    // h最大值，控制红色
int canny_low_threshold = 20;  // Canny低阈值
int canny_high_threshold = 200; // Canny高阈值

void hsv_extract(int, void*) {
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
    cv::imshow("result2_1", result2);

    int dilation_size = 2; 
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1));
    cv::dilate(result2, result2, kernel);  // 对边缘进行膨胀操作
    cv::imshow("result2", result2);

    // 将颜色分割结果和边缘检测结果结合
    cv::bitwise_not(result2, result2);  
    cv::bitwise_and(result, result2, combined_result); 

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


    cv::Mat contour_mask = cv::Mat::zeros(image.size(), CV_8UC1);


    if (maxAreaIdx != -1) {
        cv::drawContours(contour_mask, contours, maxAreaIdx, cv::Scalar(255), 1);  // 用 1 像素宽度绘制最大轮廓
    }

    dilation_size = 5; 
    cv::Mat kernel3 = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1));
    cv::dilate(contour_mask, contour_mask, kernel3);  

    std::vector<std::vector<cv::Point>> expanded_contours;
    cv::findContours(contour_mask, expanded_contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::Mat contour_output = image.clone(); 
    if (!expanded_contours.empty()) {
        cv::drawContours(contour_output, expanded_contours, 0, cv::Scalar(0, 255, 0), 2);  // 用绿色绘制扩展后的轮廓
    }

    cv::imshow("hsv", result);
    cv::imshow("combined_result", combined_result);
    cv::imshow("Apple Contour (Expanded)", contour_output);
}

int main(int argc, char **argv) {
    // 读取图像
    image = cv::imread("/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_2/apple/apple.png");
    assert(image.channels() == 3);

    // 预处理
    cv::GaussianBlur(image, image, cv::Size(5, 5), 0);
    cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV); // 转换为HSV颜色空间
    cv::cvtColor(image, grey_image, cv::COLOR_BGR2GRAY); // 转换为灰度图

    // 创建窗口
    cv::namedWindow("hsv", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("combined_result", cv::WINDOW_AUTOSIZE);

    // 创建Trackbar用于调节HSV颜色范围和Canny参数
    cv::createTrackbar("h_min_part1", "hsv", &h_min_part1, 50, hsv_extract);
    cv::createTrackbar("h_max_part1", "hsv", &h_max_part1, 50, hsv_extract);
    cv::createTrackbar("h_min_part2", "hsv", &h_min_part2, 180, hsv_extract);
    cv::createTrackbar("h_max_part2", "hsv", &h_max_part2, 180, hsv_extract);
    cv::createTrackbar("Canny Low", "combined_result", &canny_low_threshold, 100, hsv_extract);
    cv::createTrackbar("Canny High", "combined_result", &canny_high_threshold, 300, hsv_extract);

    // 调用一次回调函数以显示初始结果
    hsv_extract(0, nullptr);

    // 等待按键退出
    cv::waitKey(0);
    return 0;
}
