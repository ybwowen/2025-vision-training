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
    srand(time(NULL));
    Mat src = imread("../img.png");
    Mat drawer = Mat::zeros(src.size(), CV_8UC3);
    VideoWriter ov("../ans.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 50, src.size(), true);
    std::vector<Point3d> stars;
    cvtColor(src, src,COLOR_BGR2GRAY);
    Mat thresh;
    threshold(src, thresh, 100,255, THRESH_BINARY);
    std::vector<std::vector<Point>> contours;
    findContours(thresh, contours, RETR_TREE, CHAIN_APPROX_NONE);
    Mat canva(src.size(), CV_8UC3);
    for (int i = 0; i < contours.size();i++){
        drawContours(canva, contours, i, Scalar(20, 220, 20), 3);
    }

    for (size_t i = 0;i < contours.size(); i++){
        for (const auto &point : contours[i]){
            double starx = point.x;
            double stary = point.y;
            double starz = rand()%1000;
            Point3d star(starx, stary, starz);
            stars.push_back(star);
        }
    }
    for (int i = 180; i >= 0; i--){
        drawer = Mat::zeros(src.size(), CV_8UC3);
        Vector3d rpy;
        rpy << i, i, 0;
        rpy = rpy * M_PI / 180.;
        Matrix3d rotation;
        rotation = Eigen::AngleAxisd(rpy[0], Eigen::Vector3d::UnitX())*
        Eigen::AngleAxisd(rpy[1],Eigen::Vector3d::UnitY());
        for (const auto &point : stars){
            Vector3d vec;
            vec << point.x, point.y, point.z;
            Vector3d temp = rotation * vec;
            vec = temp;
            Point draw(vec.x(), vec.y());
            if (draw.x < src.cols && draw.y < src.rows && draw.x >=0 && draw.y >=0){
                circle(drawer, draw, 3, Scalar(220, 20, 20));
            }
        }
        imshow("final",drawer);
        waitKey(50);
        ov.write(drawer); 
    }
    ov.release();

    return 0;
}