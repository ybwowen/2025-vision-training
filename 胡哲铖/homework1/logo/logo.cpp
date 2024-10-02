#include <eigen3/Eigen/Dense>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <random>
#include <algorithm>

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
    findContours(th, contours, cv::RETR_TREE, CHAIN_APPROX_NONE);

    // 将轮廓点转换为三维
    int numPoints{0};
    vector<Point3d> points;
    for (size_t i = 0; i < contours.size(); i++) {
        for (const auto& point : contours[i]) {
            points.push_back(Point3d(point.x,point.y,generateRandomDepth(-100.0, 100.0)));
            numPoints++;
        }
    }
    


    // 相机内参矩阵
    Mat cameraMatrix = (Mat_<double>(3, 3) <<   1., 0., width,
                                                0., 1., height,
                                                0., 0., 1.);

    vector<Mat>images;
    //画动画帧
    for (int i{0};i < 360 ;i++){
        Vector3d eularAngle(0, i/60, 90);
        Quaterniond cameraQuat;
        cameraQuat =   Eigen::AngleAxisd(eularAngle[0], Eigen::Vector3d::UnitZ()) * 
                        Eigen::AngleAxisd(eularAngle[1], Eigen::Vector3d::UnitY()) * 
                        Eigen::AngleAxisd(eularAngle[2], Eigen::Vector3d::UnitX());

      // Quaternionf cameraQuat(1, i/10, i/10, i/10);
        Mat image = Mat::zeros(width*2, height*2, CV_8UC3);
        for (const auto& point : points){
            Vector3d cameraPos(0,0,0); 
            Vector3d pointPosInWorld(point.x,point.y,point.z);
            Vector3d pointPosInCamera = cameraQuat * (pointPosInWorld - cameraPos);
            double x = cameraMatrix.at<double>(0, 0) * pointPosInCamera[0] + cameraMatrix.at<double>(0, 2) * pointPosInCamera[2];
            double y = cameraMatrix.at<double>(1, 1) * pointPosInCamera[1] + cameraMatrix.at<double>(1, 2) * pointPosInCamera[2];
            double z = pointPosInCamera[2];
            Point2f pointPosInImg(x / z, y / z);
            circle(image, pointPosInImg, 5, Scalar(255, 255, 255), -1);
        }
        images.push_back(image);
    }
    VideoWriter writer;
    writer.open("../logo.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 60, size*2, true);
    
    int t{0};
    
    reverse(images.begin(), images.end());
    for (auto& frame : images){
        writer.write(frame);
    }
    writer.release();
    return 0;
}