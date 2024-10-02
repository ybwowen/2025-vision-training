#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
#include <vector>

using namespace std;
using namespace cv;

Mat src,dst;
Mat diff;
int tsh_rate=5;
int blur_rate=2;
int size_min=400;
int kernal_size=2;


void func(int, void*) {
    Mat tsh;
    adaptiveThreshold(diff, tsh, 255, ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY, tsh_rate*2+3, 0);
    Mat blur;
    medianBlur(tsh, blur, blur_rate*2+1);

    //imshow("hsv",blur);

    vector<vector<Point>> contours;
    findContours(blur,contours,RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    cv::Mat drawing = cv::Mat::zeros(blur.size(), CV_8UC3);  
    // 绘制轮廓  
    for (size_t i = 0; i < contours.size(); i++) {  
        if (contours[i].size() < size_min) {
                continue;
            }
        cv::drawContours(drawing, contours, (int)i, Scalar(i, 255-i, 0), 2, cv::LINE_8);  
    } 

    Mat kernal=getStructuringElement(MORPH_RECT, Size(kernal_size*2+1, kernal_size*2+1));
    morphologyEx(drawing,drawing,MORPH_CLOSE, kernal);
    GaussianBlur(drawing, drawing, cv::Size(kernal_size*2+1, kernal_size*2+1), 0, 0);

    //imshow("hsv",drawing);

    cvtColor(drawing, drawing, COLOR_BGR2GRAY);
    vector<vector<Point>> contour_output;
    findContours(drawing,contour_output,RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    dst=src.clone();
    cv::drawContours(dst, contour_output, -1, Scalar(255, 255, 255), 2, cv::LINE_8);  
    imshow("hsv",dst);

}

int main(int argc, char** argv) {
    src = cv::imread("../apple.png");
    
    vector<Mat> channels;
    split(src,channels);
    diff=channels[2]-channels[1];

    namedWindow("hsv");
    cv::createTrackbar("tsh", "hsv", &tsh_rate, 50, func);
    cv::createTrackbar("blur", "hsv", &blur_rate, 12, func);
    cv::createTrackbar("size", "hsv", &size_min, 500, func);
    cv::createTrackbar("kernal", "hsv", &kernal_size, 12, func);

    func(0, nullptr);
    cv::waitKey(0);

    imwrite("../apple_detect.png",dst);

    return 0;
}
