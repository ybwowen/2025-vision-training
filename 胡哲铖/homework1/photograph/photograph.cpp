#include <eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include <fstream>
#include <iostream>


using namespace cv;
using namespace std;
using namespace Eigen;

int main(){
    // 读取所有点的世界坐标
    ifstream pointsFile;
    pointsFile.open("../points.txt");
    int numPoints;
    pointsFile >> numPoints;
    vector<Point3f> points;
    for (int i = 0; i < numPoints; i++) {
        float x, y, z;
        pointsFile >> x >> y >> z;
        points.push_back(Point3f(x, y, z));
    }
    pointsFile.close();
    // 相机内参矩阵
    Mat cameraMatrix = (Mat_<float>(3, 3) <<   400., 0., 190.,
                                                0., 400., 160.,
                                                0., 0., 1.);
    // 相机位置
    Vector3f cameraPos(2, 2, 2);

    //四元数
    Quaternionf cameraQuat(-0.5, 0.5, 0.5, -0.5);
    
    //整个大的图方便画
    Mat image = Mat::zeros(1080, 1920, CV_8UC3);

    //将每个点变换后画上去
    for (const auto& point : points){
        Vector3f pointPosInWorld(point.x,point.y,point.z); 
        Vector3f pointPosInCamera = cameraQuat * (pointPosInWorld - cameraPos);
        float x = cameraMatrix.at<float>(0, 0) * pointPosInCamera[0] + cameraMatrix.at<float>(0, 2) * pointPosInCamera[2];
        float y = cameraMatrix.at<float>(1, 1) * pointPosInCamera[1] + cameraMatrix.at<float>(1, 2) * pointPosInCamera[2];
        float z = pointPosInCamera[2];
        Point2f pointPosInImg(x / z, y / z);
        circle(image, pointPosInImg, 5, Scalar(255, 255, 255), -1);
    }
    imwrite("../photograph.png", image);
}