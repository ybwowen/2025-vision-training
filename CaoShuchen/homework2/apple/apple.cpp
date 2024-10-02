//
// Created by cwlm on 2024/10/2.
//
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cassert>

int main(int argc, char ** argv)
{
    cv::Mat src = cv::imread("apple.png");

    assert(src.channels() == 3); // 检测是否为三通道彩色图片
    cv::Mat channels[3];
    split(src, channels); // 三通道分离
    cv::Mat red_sub_blue = 2 * channels[2] - channels[0] - channels[1]; // 红绿通道相减

    cv::Mat normal_mat;
    normalize(red_sub_blue, normal_mat, 0., 255., cv::NORM_MINMAX); // 归一化到[0, 255]

    cv::Mat binary;
    threshold(normal_mat, binary, 115, 255, cv::THRESH_BINARY); // 二值化

    // 进行闭运算
    cv::Mat opened;
    cv::morphologyEx(binary, opened, cv::MORPH_OPEN, cv::Mat(), cv::Point(-1, -1), 2);

    // 找到所有轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(opened, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 找到最大轮廓
    double max_area = 0;
    int max_index = -1;
    for (size_t i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area > max_area) {
            max_area = area;
            max_index = i;
        }
    }

    // 创建一个只包含最大轮廓的二值图像
    cv::Mat largestContour = cv::Mat::zeros(opened.size(), CV_8UC1);
    if (max_index != -1) {
        cv::drawContours(largestContour, contours, max_index, cv::Scalar(255), cv::FILLED);
    }

    // 进行闭运算
    cv::Mat opened2;
    morphologyEx(largestContour, opened2, cv::MORPH_OPEN, cv::Mat(), cv::Point(-1, -1), 4);

    // 进行梯度运算
    cv::Mat gradient;
    morphologyEx(opened2, gradient, cv::MORPH_GRADIENT, cv::Mat(), cv::Point(-1, -1), 1);

    // 将轮廓叠加到原图像上
    cv::Mat result;
    cvtColor(gradient, gradient, cv::COLOR_GRAY2BGR); // 转换为三通道
    addWeighted(src, 1.0, gradient, 0.5, 0, result); // 叠加

    // 显示结果
    imshow("Result", result);
    cv::waitKey(0);
    return 0;
}