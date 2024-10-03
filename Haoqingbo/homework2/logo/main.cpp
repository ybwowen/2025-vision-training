#include <Eigen/Dense>
#include <Eigen/Core>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace cv;
using namespace Eigen;

int main(){
    Mat src = imread("../img.png");
    Mat drawer = Mat::zeros(src.size(), CV_8UC3);
    std::vector<Point3d> stars;
    cvtColor(src, src,COLOR_BGR2GRAY);
    Mat thresh;
    threshold(src, thresh, 100,255, THRESH_BINARY);
    cvtColor(thresh, thresh, COLOR_BGR2GRAY);
    std::vector<std::vector<Point2d>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    for (Point2d pt : contours[0]){
        circle(drawer, pt, 4, Scalar(20,220,20),3);

    }
    imshow("draw", drawer);
    waitKey(0);

    return 0;
}