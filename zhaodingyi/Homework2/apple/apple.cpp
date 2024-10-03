#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <assert.h>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/videoio.hpp>
using namespace std;
using namespace cv;
int main(int argc, char ** argv)
{
    Mat src = imread("../apple.png");
    Mat hsv;
    if(src.empty()){
        cerr<<"The photo is empty"<<endl;
        exit(-1);
    }
    imshow("hsv", src);
    if(src.channels() != 3){
        cerr<<"It's not 3-channel picture!"<<endl;
        exit(-1);
    }
    cvtColor(src, hsv, COLOR_BGR2HSV);
    // Turn BGR into HSC
    Mat hsv_part1, hsv_part2;
    inRange(hsv, Scalar(0, 43, 46), Scalar(21, 255, 255), hsv_part1);
    inRange(hsv, Scalar(156, 43, 46), Scalar(180, 255, 255), hsv_part2);
    
    Mat ones_mat = Mat::ones(Size(src.cols, src.rows), CV_8UC1);
    Mat hsv_result = 255 * (ones_mat - (ones_mat - hsv_part1 /
    255).mul(ones_mat - hsv_part2 / 255));
    Mat morph_img;

    Mat kernel=getStructuringElement(MORPH_RECT, {3,3});
    morphologyEx(hsv_result,morph_img, MORPH_ERODE, kernel,Point(-1,-1), 4);
    morphologyEx(morph_img,morph_img, MORPH_OPEN, kernel,Point(-1,-1), 8);
    // morphologyEx(morph_img,morph_img, MORPH_DILATE, kernel,Point(-1,-1), 4);
    
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(morph_img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    Mat result = src.clone();


    int largest_contour_index = -1;
    double max_area = 0;
    for (size_t i = 0; i < contours.size(); i++) {
        double area = contourArea(contours[i]);
        if (area > max_area) {
        max_area = area;
        largest_contour_index = i;
        }
    }
    drawContours(result, contours, largest_contour_index, Scalar(255, 255, 0), 1);
    Rect bounding_box = boundingRect(contours[largest_contour_index]);

    rectangle(result, bounding_box, Scalar(255, 0, 0), 1); 

    imshow("result",result);
    waitKey(0);
    return 0;
}
