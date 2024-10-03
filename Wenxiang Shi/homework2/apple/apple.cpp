#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 读取图像
    cv::Mat image = cv::imread("../apple.png");
    if (image.empty()) {
        std::cout << "Could not read the image" << std::endl;
        return 1;
    }

    // 将图像从BGR转换到HSV颜色空间
    cv::Mat hsv;
    cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);

        cv::Mat channels[3];
    split(image, channels); 
    cv::Mat red_sub_blue = 2 * channels[2] - channels[0] - channels[1]; 
    cv::Mat normalized_red_sub_blue;
    cv::normalize(red_sub_blue, normalized_red_sub_blue, 0, 255, cv::NORM_MINMAX); 
    
    cv::Mat binary;
    threshold(normalized_red_sub_blue, binary, 100, 255, cv::THRESH_BINARY);

    //erode then dilate
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(13, 13));
    cv::erode(binary, binary, element);
    cv::Mat element2 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, 1));
    cv::dilate(binary, binary, element);

    //find contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    //find the biggest contour
    int max_area = 0;
    int max_index = 0;
    for (int i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area > max_area) {
            max_area = area;
            max_index = i;
        }
    }
    //draw the biggest contour
    cv::Mat result = cv::Mat::zeros(image.size(), CV_8UC3);
    cv::drawContours(image, contours, max_index, cv::Scalar(0, 255, 0), 2);

    //draw the bounding box
    cv::Rect rect = cv::boundingRect(contours[max_index]);
    cv::rectangle(image, rect, cv::Scalar(255, 0, 0), 2);


    // 显示图像
    cv::imshow("Apple Detection", image);
    //output the result
    cv::imwrite("my_apple_detection.png", image);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}