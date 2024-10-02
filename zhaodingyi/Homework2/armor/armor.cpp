#include <Eigen/Dense>
#include <cstdlib>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <eigen3/Eigen/src/Geometry/Quaternion.h>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <opencv4/opencv2/core/eigen.hpp>
#include <opencv4/opencv2/core/types.hpp>
#include <sstream>
#include <vector>
#include <string>
#include "assets/big_armor_scale.hpp"

using namespace std;
using namespace cv;
using namespace Eigen;
// 为什么不乘上相机的pose的R^T反而对了？？？
// 我的思路：pnp求出相机姿态，相当于相机对于世界的坐标转换
// 1. 相机坐标系下点的坐标：center''=R^T+(center-tvec)
// 2. q.matrix()*center''
//
// 实际上：
// 1. center''=center-tvec
// 2. res = q.matrix*center''
//
// 为什么没有关于相机的旋转？
// 为什么没有关于相机的旋转？
// 为什么没有关于相机的旋转？
// 为什么没有关于相机的旋转？
// 为什么没有关于相机的旋转？

int main(){
    // Data input and definition.
    // ————————————————————————————————————————————————————————————————————————
    // Reading yml file and get Camera Intrinsic Matrix and Distortion Coefficients.
    Mat camera_instrinsic, dist_coefficients;
    FileStorage fs("../assets/f_mat_and_c_mat.yml", cv::FileStorage::READ);
    if(!fs.isOpened()){
        cerr<<"Cannot open f_mat_and_c_mt.yml"<<endl;
        exit(-1);
    }
    fs["F"] >> camera_instrinsic;
    fs["C"] >> dist_coefficients;

    // Including .hpp as the real world location.
    vector<Point3d> real_loca=PW_BIG;
    // cout<<"real location"<<real_loca<<endl;

    // Reading imu_and_armor.txt for c2g quaternion and pixel coordinates.
    // Reading quaternion.
    string line;
    double x,y,z,w;
    ifstream file("../assets/imu_and_armor.txt");
    if(!file.is_open()){
        cerr<<"Cannot open imu_and_armor.txt"<<endl;
        exit(-1);
    }
    getline(file,line);
    getline(file,line);
    istringstream str(line);
    string part;
    while (str >> part) {
        // cout << "Parsing part: " << part << endl; 
        if (part.back() == '+'){
            continue;
        }
        if (part.back() == 'i') {
            x = std::stod(part.substr(0, part.length() - 1));
            
        } else if (part.back() == 'j') {
            y = std::stod(part.substr(0, part.length() - 1));
        } else if (part.back() == 'k') {
            z= std::stod(part.substr(0, part.length() - 1));
        } else {
            w = std::stod(part);
        }
    }
    // cout<<"x: "<<x<<endl;
    // cout<<"y: "<<y<<endl;
    // cout<<"z: "<<z<<endl;
    // cout<<"w: "<<w<<endl;
    Quaterniond quaternion(w, x, y, z);
    // quaternion.normalize();

    getline(file,line);
    // Reading pixel coordinates.
    vector<Point2d> pixel_coor;
    double part1, part2;
    while(file>> part1>> part2){
        pixel_coor.push_back(Point2d(part1, part2));
    }
    // cout<<"what   "<<pixel_coor<<endl;

    // The absolute coordinates of the center of the armor.
    Point3d avg(0,0,0);
    for(int i=0; i< real_loca.size(); i++){
        avg += real_loca[i];
    }
    avg.x /= real_loca.size();
    avg.y /= real_loca.size();
    avg.z /= real_loca.size();
    // cout<<real_loca.size()<<endl;
    Mat center=(Mat_<double>(3,1)<<avg.x,avg.y,avg.z);
    // cout<<"center:  "<<center<<endl;


    // SlovePNP, calculating the relative translation from world to camera, i.e. the pose of camera.
    Mat rvec, tvec;
    solvePnP(real_loca, pixel_coor, camera_instrinsic, dist_coefficients, rvec, tvec);    
    Mat rot_mat;
    Rodrigues(rvec, rot_mat);

    // Calaulate the relative position of armor in camera world.
    Mat camera_center= center-tvec;
    // cout<<camera_center<<endl;
    
    // Use quaternion to calculate the relative position of armor in gyroscope world.
    Vector3d camera_center_eigen(camera_center.at<double>(0), camera_center.at<double>(1), camera_center.at<double>(2));
    Vector3d result=quaternion.matrix()*camera_center_eigen;
    cout<<result<<endl;
}

