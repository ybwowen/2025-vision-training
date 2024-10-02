#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

int main(int argc, char* argv[]){
    cv::Mat src = cv::imread("../apple.png");
    assert(src.channels() == 3);
    
    cv::Mat channels[3];
    cv::split(src, channels);

    cv::Mat diff;
    diff = channels[2] - channels[0] - channels[1] ;
    cv::Mat mask;
    cv::threshold(diff, mask, 10, 255, cv::THRESH_BINARY);

    // don't use HSV
    // cv::Mat hsv;
    // cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV); // 将颜色空间从BGR转为HSV
    // cv::Mat hsv_part1, hsv_part2;
    // cv::inRange(hsv, cv::Scalar(0, 120, 46), cv::Scalar(25, 255, 255), hsv_part1);
    // cv::inRange(hsv, cv::Scalar(156, 120, 46), cv::Scalar(180, 255, 255), hsv_part2); // 提取红色和橙色
    // cv::Mat ones_mat = cv::Mat::ones(cv::Size(src.cols, src.rows), CV_8UC1);
    // cv::Mat hsv_result = 255 * (ones_mat - (ones_mat - hsv_part1 / 255).mul(ones_mat - hsv_part2 / 255));
    // cv::morphologyEx(hsv_result, hsv_result, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)), cv::Point(-1,-1), 3);
    // cv::morphologyEx(hsv_result, hsv_result, cv::MORPH_CLOSE, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)), cv::Point(-1,-1), 3);
    // cv::imwrite("test0.png", hsv_result);
    // cv::imwrite("test1.png", mask);

    cv::morphologyEx(mask, mask, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)),cv::Point(-1,-1), 3);

    // debug: show threshold picture
    //cv::imwrite("test2.png", mask);

    // 查找轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    if (contours.empty()) {
        std::cerr << "No contours found." << std::endl;
        return -1;
    }
    // 筛选轮廓
    int largest_idx = -1;
    double largest_area = 0;
    for (size_t i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area > largest_area) {
            largest_area = area;
            largest_idx = i;
        }
    }
    // std::cout << largest_idx << std::endl;

    // 绘制最大轮廓
    cv::Mat contour_output = src.clone();
    // cv::drawContours(contour_output, contours, largest_idx, cv::Scalar(0, 255, 0), 2);

    // 计算凸包
    std::vector<cv::Point> hull;
    cv::convexHull(contours[largest_idx], hull);
    std::vector<std::vector<cv::Point>> contourList;
    contourList.push_back(hull);
    cv::drawContours(contour_output, contourList, 0, cv::Scalar(255, 255, 255), 2);

    // 计算最小外接矩形
    cv::RotatedRect minRect = cv::minAreaRect(contours[largest_idx]);
    cv::Point2f vertices[4];
    minRect.points(vertices);
    for (int i = 0; i < 4; i++) {
        cv::line(contour_output, vertices[i], vertices[(i + 1) % 4], cv::Scalar(255, 255, 255), 2);
    }

    cv::imwrite("out.png", contour_output);
    return 0;
}