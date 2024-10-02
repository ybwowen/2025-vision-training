#include<iostream>
#include <vector>
#include<opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat img = imread("../apple.png");

    Mat channels[3];
    split(img, channels);
    Mat red = channels[2] - channels[1] - channels[0];
    Mat img_nm;
    normalize(red, img_nm, 0., 255., NORM_MINMAX);

    Mat img_open;
    morphologyEx(img_nm, img_open, MORPH_OPEN, Mat(), Point(-1, -1), 2);

    Mat img_fin;
    morphologyEx(img_open, img_fin, MORPH_CLOSE, Mat(), Point(-1, -1), 1);

    vector<vector<Point> > contours;
    vector<Vec4i> hierachy;
    findContours(img_fin, contours, hierachy, RETR_LIST, CHAIN_APPROX_NONE);
    
    int maxC = 0;
    double area, maxS=0.0;
    for(int i=0; i<contours.size(); i++){
        area = contourArea(contours[i]);
        if(area>maxS){
            maxS = area;
            maxC = i;
        }
    }
    vector<Point> largest = contours[maxC];
    
    Mat result = img.clone();
    drawContours(result, contours, maxC, Scalar(255,0,0));
    Rect box = boundingRect(largest);
    rectangle(result, box, Scalar(255, 0, 0), 2);
    imwrite("../apple_detect.png", result);
    imshow("apple detect", result);
    waitKey(0);
    return 0;
}