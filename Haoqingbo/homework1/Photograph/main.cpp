#include <Eigen/Dense>
#include <Eigen/Core>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace cv;
using namespace Eigen;

int main(){
    std::fstream file("../points.txt");
    std::string Num = "";
    file >> Num;
    if ( Num == ""){
        std::cerr << "file not open" << std::endl;
    }
    int points_num = std::stoi(Num);
    std::vector<Point3f> points_world(points_num);
    for (int i = 0; i < points_num; i++){
        file >> points_world[i].x >> points_world[i].y >> points_world[i].z; //输入世界坐标
    }
    Mat inter = (Mat_<double>(3,3) <<400., 0., 190., //定义相机内参矩阵
                                        0., 400., 160.,
                                        0., 0., 1.);
    Quaterniond rotate; //定义旋转四元数
    rotate.x()=0.5;
    rotate.y()=0.5;
    rotate.z()=-0.5;
    rotate.w()=-0.5;
    Matrix3d c2wmat = rotate.normalized().toRotationMatrix(); //将四元数转化为旋转矩阵
    Matrix3d internal;
    cv2eigen(inter, internal);                //内参矩阵转化
    // std::cout<< internal <<std::endl;
    Vector3d c2wtrans;                                      //平移向量
    c2wtrans << 2,2,2;
    // std::cout<< c2wtrans <<std::endl;
    Matrix3d w2cmat = c2wmat.transpose();                  //旋转矩阵的转置，即为逆向旋转
    // std::cout<< w2cmat <<std::endl << c2wmat <<std::endl;
    Vector3d w2ctrans = -w2cmat * c2wtrans;                //世界坐标系向相机坐标系的平移
    Vector3d image;
    Vector3d pixel[points_num];
    Mat src(1024,1657,CV_8UC3,Scalar(0,0,0));//创建相片
    Matrix3d c2pixel;                       //由相机坐标系到像素坐标系
    c2pixel << 1, 0, 0,
                0, 1, 0,
                0, 0, 1;
    for (int i=0; i < points_num; i++){
        Vector3d pw;
        pw << points_world[i].x, points_world[i].y, points_world[i].z;
        Vector3d pc = (w2cmat * pw + w2ctrans);
        pc = pc / pc[2];
        Vector3d pp;
        pp = c2pixel * internal * pc;
        Point2f pix;
        pix.x = pp[0];
        pix.y = pp[1];
        circle(src, pix, 5, Scalar(0,255,0), 5);
    }
    imshow("final", src);
    imwrite("../ans/ans.png",src);
    waitKey(0);
    return 0;
}