#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    Mat src = imread("../apple.png");
    if (src.channels() !=3){
        std::cerr << "image not opened!" << std::endl;
    }
    Mat hsv;
    cvtColor(src, hsv, COLOR_BGR2HSV);
    Scalar red_lower(156, 43, 46);
    Scalar red_upper(180, 255, 255);
    Mat mask;
    inRange(hsv, red_lower, red_upper, mask);
    Mat open_mask;
    Mat kernel = getStructuringElement(MORPH_ELLIPSE,Size(10,10));
    morphologyEx(mask, open_mask, MORPH_DILATE,kernel);
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    std::vector<Point> hull;
    findContours(open_mask, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    convexHull(contours[0], hull);
    Rect drawer = boundingRect(hull); 
    rectangle(src, drawer, Scalar(20,220,20), 4);

    // imshow("mask", mask);
    imshow("dilated", open_mask);
    imshow("detected apple", src);
    imwrite("../ans/ans.png",src);
    waitKey(0);
    return 0;
}