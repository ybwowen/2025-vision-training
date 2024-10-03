#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

int lower_red1_h=170;
int lower_red1_s=100;
int lower_red1_v=100;
int upper_red1_h=180;
int upper_red1_s=255;
int upper_red1_v=255;
int lower_red2_h=0;
int lower_red2_s=198;
int lower_red2_v=85;
int upper_red2_h=30;
int upper_red2_s=255;
int upper_red2_v=255;
int applearea=100;
int kernel =5;


void on_trackbar(int, void*) {

    cv::Mat img = cv::imread("../apple.png");
    if (img.empty()) {
        std::cout << "Failed to open image. Please check the path." << std::endl;
    }
    assert(img.channels() == 3);

    cv::Mat hsv;
    cvtColor(img, hsv, cv::COLOR_BGR2HSV);
    cv::Scalar lower_red1 = cv::Scalar(lower_red1_h, lower_red1_s, lower_red1_v);
    cv::Scalar upper_red1 = cv::Scalar(upper_red1_h, upper_red1_s, upper_red1_v);
    cv::Scalar lower_red2 = cv::Scalar(lower_red2_h, lower_red2_s, lower_red2_v);
    cv::Scalar upper_red2 = cv::Scalar(upper_red2_h, upper_red2_s, upper_red2_v);

    // 创建两个掩膜
    cv::Mat mask1, mask2;
    inRange(hsv, lower_red1, upper_red1, mask1);
    inRange(hsv, lower_red2, upper_red2, mask2);

    // 合并两个掩膜
    cv::Mat mask;
    mask = mask1 + mask2;

    // 将掩膜应用到图像上
    cv::Mat dst; // 结果图像
    cv::bitwise_and(hsv, hsv, dst, mask);


    cv::GaussianBlur(mask, mask, cv::Size(3, 3), 0, 0);
    cv::Mat kernel1 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::Mat kernel2 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    cv::erode(mask, mask, kernel1);
    cv::dilate(mask, mask, kernel2);


    // 显示掩膜图像
    cv::imshow("Masked1", mask);

    // 找轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::Mat hierarchy;
    cv::findContours(mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

    std::vector<cv::Point> contour0;
    std::vector<std::vector<cv::Point>> closedcontours;
    for(const auto&contour:contours){
        if(!contour.empty()){
            double area=cv::contourArea(contour);
            std::cout<<"here"<<std::endl;
            if(area>5000){
                std::cout<<area<<""<<std::endl;
                closedcontours.push_back(contour);
                contour0=contour;
                }
        }

    }

    //制轮廓
    cv::Mat result = img.clone();
    cv::drawContours(result, closedcontours, -1, cv::Scalar(255, 255, 255), 2);
    cv::Rect juxing=cv::boundingRect(contour0);
    cv::rectangle(result,juxing,cv::Scalar(255,255,255));

    // 显示带有轮廓的结果图像
    cv::imshow("Masked", result);
    cv::imwrite("../result.png", result);
}

int main() {
    cv::Mat img = cv::imread("../apple.png");
    if (img.empty()) {
        std::cout << "Failed to open image. Please check the path." << std::endl;
        return -1;
    }
    assert(img.channels() == 3);

    cv::Mat hsv;
    cvtColor(img, hsv, cv::COLOR_BGR2HSV);

    // 创建滑动条
    cv::namedWindow("Processed Frame");
    cv::createTrackbar("lower_red1_h", "Processed Frame", &lower_red1_h, 255, on_trackbar);
    cv::createTrackbar("lower_red1_s", "Processed Frame", &lower_red1_s, 255, on_trackbar);
    cv::createTrackbar("lower_red1_v", "Processed Frame", &lower_red1_v, 255, on_trackbar);
    cv::createTrackbar("upper_red1_h", "Processed Frame", &upper_red1_h, 255, on_trackbar);
    cv::createTrackbar("upper_red1_s", "Processed Frame", &upper_red1_s, 255, on_trackbar);
    cv::createTrackbar("upper_red1_v", "Processed Frame", &upper_red1_v, 255, on_trackbar);
    cv::createTrackbar("lower_red2_h", "Processed Frame", &lower_red2_h, 255, on_trackbar);
    cv::createTrackbar("lower_red2_s", "Processed Frame", &lower_red2_s, 255, on_trackbar);
    cv::createTrackbar("lower_red2_v", "Processed Frame", &lower_red2_v, 255, on_trackbar);
    cv::createTrackbar("upper_red2_h", "Processed Frame", &upper_red2_h, 255, on_trackbar);
    cv::createTrackbar("upper_red2_s", "Processed Frame", &upper_red2_s, 255, on_trackbar);
    cv::createTrackbar("upper_red2_v", "Processed Frame", &upper_red2_v, 255, on_trackbar);
    cv::createTrackbar("applearea", "Processed Frame", &applearea, 5000, on_trackbar);
    cv::createTrackbar("kernel", "Processed Frame", &kernel, 21, on_trackbar);

    // 初始化HSV范围
    cv::Scalar lower_red1 = cv::Scalar(lower_red1_h, lower_red1_s, lower_red1_v);
    cv::Scalar upper_red1 = cv::Scalar(upper_red1_h, upper_red1_s, upper_red1_v);
    cv::Scalar lower_red2 = cv::Scalar(lower_red2_h, lower_red2_s, lower_red2_v);
    cv::Scalar upper_red2 = cv::Scalar(upper_red2_h, upper_red2_s, upper_red2_v);

    cv::Mat mask1, mask2;
    inRange(hsv, lower_red1, upper_red1, mask1);
    inRange(hsv, lower_red2, upper_red2, mask2);
    cv::Mat mask = mask1 + mask2;

    cv::imshow("Masked1", mask);
    cv::Mat result = img.clone();
    cv::imshow("Masked", result);

    cv::waitKey(0);

    return 0;
}