#include <eigen3/Eigen/Dense>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <sys/types.h>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

using namespace cv;
using namespace std;
using namespace Eigen;

// 函数用于生成随机深度值
float generateRandomDepth(float minDepth, float maxDepth) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<> dis(minDepth, maxDepth);
    return dis(gen);
}

int main() {
    // 读取图像
    Mat image = imread("../img.png");
    int width = image.rows;
    int height = image.cols;
    Size size = image.size();
    Mat gray,th;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    threshold(gray, th, 100, 255, THRESH_BINARY);

    // 找到轮廓
    vector<vector<Point>> contours;
    findContours(th, contours, cv::RETR_TREE, CHAIN_APPROX_SIMPLE);
    // 将轮廓点转换为三维
    int numPoints{0};
    vector<Point3d> points;
    for (size_t i = 0; i < contours.size(); i++) {
        for (const auto& point : contours[i]) {
            points.push_back(Point3d(point.x ,point.y,generateRandomDepth(0, 500.0)));
            numPoints++;
        }
    }
    


    // 相机内参矩阵
    Mat cameraMatrix = (Mat_<double>(3, 3) <<   width, 0., 0,
                                                0., height, 0,
                                                0., 0., 1.);

    vector<Mat>images;
    //画动画帧
    for (int i{0};i < 122 ;i++){
        Matrix3d rotateMatrixX,rotateMatrixY,rotateMatrix;
        double theta = i/31.4;
        //偷个懒
        rotateMatrixX << 1, 0, 0,
                        0, cos(8/31.0), sin(8/31.0),
                        0, -sin(8/31.0), cos(8/31.0);
        rotateMatrixY << cos(i/31.0), 0, sin(i/31.0),
                        0, 1, 0,
                        -sin(i/31.0), 0, cos(i/31.0);
        //合成旋转矩阵
        rotateMatrix = rotateMatrixX*rotateMatrixY;

        Mat black = Mat::zeros(width*2, height*2, CV_8UC3);
        for (const auto& point : points){
            Vector3d cameraPos(-2000,0,-1000); 
            Vector3d pointPosInWorld(point.x,point.y,point.z);
            Vector3d pointPosInCamera = rotateMatrix* pointPosInWorld - cameraPos; //很奇怪，相机初始并不是对着图像正前方的
            double x = cameraMatrix.at<double>(0, 0) * pointPosInCamera[0] + cameraMatrix.at<double>(0, 2) * pointPosInCamera[2];
            double y = cameraMatrix.at<double>(1, 1) * pointPosInCamera[1] + cameraMatrix.at<double>(1, 2) * pointPosInCamera[2];
            double z = pointPosInCamera[2];
            Point2f pointPosInImg(x / z, y / z);
            circle(black, pointPosInImg, 0, Scalar(255, 255, 255), 20-z/70);
        }
        flip(black,black, 1);
        images.push_back(black);
        if (i==121){
            for (int j{0};j < 119 ;j++){
                images.push_back(black);
            }
        }
    }
    VideoWriter writer;
    writer.open("../logo.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 60, size*2, true);
    
    int t{0};
    

    for (auto& frame : images){
        writer.write(frame);
    }
    writer.release();
    return 0;

}