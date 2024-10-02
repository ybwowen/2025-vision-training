#include <iostream>
#include <assert.h>

#include <opencv2/core.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>


int main()
{
    cv::Mat image=cv::imread("../apple.png");

    
    assert(image.channels()==3);
    cv::Mat hsv_img;

    
    cv::cvtColor(image, hsv_img, cv::COLOR_BGR2HSV);

    cv::Mat hsv_part1,hsv_part2;
    cv::inRange(hsv_img, cv::Scalar(0, 90, 46), cv::Scalar(23, 255, 255), hsv_part1);
    cv::inRange(hsv_img, cv::Scalar(156, 43, 46), cv::Scalar(180, 255, 255),hsv_part2);
    
    cv::Mat ones_mat=cv::Mat::ones(cv::Size(image.cols,image.rows),CV_8UC1);
    cv::Mat hsv_result = 255 * (ones_mat - (ones_mat - hsv_part1 /255).mul(ones_mat - hsv_part2 / 255));


    cv::Mat morph_img;
    cv::Mat kernel=cv::getStructuringElement(cv::MORPH_RECT, {3,3});
        
    cv::morphologyEx(hsv_result,morph_img, cv::MORPH_ERODE, kernel,cv::Point(-1,-1), 3);


    cv::morphologyEx(morph_img,morph_img, cv::MORPH_OPEN, kernel,cv::Point(-1,-1), 5);


    cv::Mat canny_result;
    cv::Canny(morph_img,canny_result,50,100,3);



    std::vector< std::vector<cv::Point> > contours;
    std::vector< cv::Vec4i > hierachy;
    cv::findContours( canny_result, contours, hierachy, cv::RETR_TREE,cv::CHAIN_APPROX_NONE);

      // 初始化最大周长和对应的轮廓索引
    double maxPerimeter = 0;
    int maxIndex = -1;

    // 遍历轮廓，找到周长最大的轮廓
    for (size_t i = 0; i < contours.size(); i++) {
        double perimeter = cv::arcLength(cv::Mat(contours[i]), true);
        if (perimeter > maxPerimeter) {
            maxPerimeter = perimeter;
            maxIndex = i;
        }
    }

    // 如果找到了轮廓
    if (maxIndex != -1) {
        // 计算外接矩形
        cv::Rect boundingRect = cv::boundingRect(cv::Mat(contours[maxIndex]));

        // 绘制外接矩形
        cv::rectangle(image, boundingRect, cv::Scalar(0, 255, 0), 2);

        // 显示结果
        cv::imshow("Largest Contour Bounding Box", image);
        cv::waitKey(0);
    } else {
        std::cerr << "No contours found" << std::endl;
    }


}