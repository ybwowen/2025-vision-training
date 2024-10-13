#include <eigen3/Eigen/Dense>
#include <opencv2/calib3d.hpp>
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

    // 相机内参矩阵
    Mat cameraMatrix = (Mat_<double>(3, 3) <<   400, 0., 0.,
                                                0., 400, 0.,
                                                0., 0., 1.);
   // Mat invmat = cameraMatrix.
    int numPoints{0};
    vector<Point3d> points;
    for (size_t i = 0; i < contours.size(); i++) {
        for (const auto& point : contours[i]) {
            double zc = generateRandomDepth(0.0, 100000.0);
            points.push_back(Point3d(point.x*zc/cameraMatrix.at<double>(0, 0) ,point.y*zc/cameraMatrix.at<double>(1, 1),zc));
            numPoints++;
        }
    }
    for (size_t j = 0; j < 100; j++){ //气氛组
        points.push_back(Point3d(generateRandomDepth(0.0, width) ,generateRandomDepth(0.0, height),generateRandomDepth(0.0, 100000.0)));
    }
    vector<Mat>images;
    //画动画帧
    for (int i{0};i < 122 ;i++){
        Matrix3d rotateMatrix;
        double theta = pow(1.012,i)-1;
        Quaterniond rotateQuat(cos(theta/2),0.424*sin(theta/2),0.707*sin(theta/2),0.566*sin(theta/2));
        rotateMatrix << cos(theta), 0, sin(theta),
                        0, 1, 0,
                        -sin(theta), 0, cos(theta);
        
        Mat black = Mat::zeros(width, height, CV_8UC3);
        for (const auto& point : points){
            Vector3d pointPosInWorld(point.x,point.y,point.z);
            Vector3d pointPosInCamera = rotateQuat* pointPosInWorld; 
            double x = cameraMatrix.at<double>(0, 0) * pointPosInCamera[0] + cameraMatrix.at<double>(0, 2) * pointPosInCamera[2];
            double y = cameraMatrix.at<double>(1, 1) * pointPosInCamera[1] + cameraMatrix.at<double>(1, 2) * pointPosInCamera[2];
            double z = pointPosInCamera[2] + i*10;
            Point2f pointPosInImg(x / z, y / z);
            circle(black, pointPosInImg, 0, Scalar(255, 255, 255), 10-z/7000);
        }
        images.push_back(black);
        
        if (i==0){
            for (int k{0};k < 119 ;k++){ //停一下
                images.push_back(black);
            }
        }
        
    }
    VideoWriter writer;
    writer.open("../logo.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 60, size, true);
    
    int t{0};
    
    reverse(images.begin(),images.end());
    for (Mat frame : images){
        writer.write(frame);
    }
    writer.release();
    return 0;

}