#include <assert.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>



int main(){
    cv::Mat src = cv::imread("../apple.png");
    cv::Mat hsv;

    cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV); // 将颜色空间从BGR转为HSV
    cv::Mat hsv_part1, hsv_part2;
    cv::inRange(hsv, cv::Scalar(0, 43, 46), cv::Scalar(10, 255, 255), hsv_part1);
    cv::inRange(hsv, cv::Scalar(156, 43, 46), cv::Scalar(180, 255, 255),hsv_part2); // 提取红色和橙色
    cv::Mat ones_mat = cv::Mat::ones(cv::Size(src.cols, src.rows), CV_8UC1);
    cv::Mat hsv_result1 = 255 * (ones_mat - (ones_mat - hsv_part1 /255).mul(ones_mat - hsv_part2 / 255));
// 对hsv_part1的结果和hsv_part2的结果取并集
    // cv::imshow("hsv1", hsv_result1);

    cv::Mat hsv_part3;
    cv::inRange(hsv, cv::Scalar(11,200,80),cv::Scalar(26,255,255),hsv_part3);
    cv:: Mat hsv_result2 = 255 * (ones_mat - (ones_mat - hsv_part3 /255));
    // cv::imshow("hsv2",hsv_result2);

     cv::Mat red;
    cv::morphologyEx(hsv_result1, red, cv::MORPH_OPEN, getStructuringElement(cv::MORPH_RECT, cv::Size(7,7)));
    cv::morphologyEx(red, red, cv::MORPH_CLOSE, getStructuringElement(cv::MORPH_CROSS, cv::Size(7,7)));
    // cv::imshow("y",red);
    cv::Mat y;
    cv::morphologyEx(hsv_result2, y, cv::MORPH_OPEN, getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));
    cv::morphologyEx(y, y, cv::MORPH_CLOSE, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
    cv::Mat res = 255 * (ones_mat - (ones_mat - red /255).mul(ones_mat - y / 255));
    // cv::imshow("r",y);
    // cv::imshow("res",res);
    cv::morphologyEx(res, res, cv::MORPH_OPEN, getStructuringElement(cv::MORPH_RECT, cv::Size(7,7)));
    cv::morphologyEx(res, res, cv::MORPH_CLOSE, getStructuringElement(cv::MORPH_CROSS, cv::Size(7,7)));
     cv::imshow("fres",res);
    
     // 检测轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(res, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 在原图上画出轮廓、矩形
    cv::Mat original_image = cv::imread("../apple.png");  // 读取原始彩色图片
    if (original_image.empty()) {
        std::cout << "Could not open or find the original image!" << std::endl;
        return -1;
    }

    // 拟合矩形并绘制轮廓
    cv::Rect bounding_rect;

    if (!contours.empty()) {
        // 找到最大轮廓
        int largest_contour_index = 0;
        for (int i = 1; i < contours.size(); i++) {
            if (cv::contourArea(contours[i]) > cv::contourArea(contours[largest_contour_index])) {
                largest_contour_index = i;
            }
        }
     std::vector<cv::Point> contour = contours[largest_contour_index];


        // 使用凸包
        std::vector<cv::Point> hull;
        cv::convexHull(contour, hull);

        // 拟合矩形
        bounding_rect = cv::boundingRect(hull);
        cv::rectangle(original_image, bounding_rect, cv::Scalar(255, 255, 255), 2);  // 白色矩形

        // 绘制轮廓
        cv::drawContours(original_image, std::vector<std::vector<cv::Point>>{hull}, -1, cv::Scalar(255, 255, 255), 2);  // 白色轮廓线
    
    }

    // 显示结果
    // cv::imshow("Final Result", original_image);  // 显示标注轮廓后的原彩色图像
    cv::imwrite("../myresult.png",original_image);
    // cv::waitKey(0);
return 0;
}