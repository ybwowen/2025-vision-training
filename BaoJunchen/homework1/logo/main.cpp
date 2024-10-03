#include <cmath>
#include <iostream>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <Eigen/Geometry>
#include <vector>
#include <fstream>
using namespace cv;
using namespace std;

int main() {
    
    int frame_width=1280;
    int frame_height=720;
    int fps=60;
    cv::VideoWriter writer
        ("../output.avi", 
        cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 
        fps, 
        cv::Size(frame_width, frame_height), 
        true);  

    if (!writer.isOpened()) {
        std::cerr << "无法创建输出视频文件" << std::endl;
        return -1;
    }
    //initialize video output
    
    ifstream input("../points.txt");
    int num=1;
    input>>num;
    vector<Mat> points_world;
    for(int i=0;i<num;i++){
        Mat point=Mat_<double> (3,1);
        input >> point.at<double>(0, 0)>> point.at<double>(1, 0)>> point.at<double>(2, 0);
        points_world.push_back(point);
    }

    Mat innerMat = (Mat_<double>(3, 3) << 400.,0.,190.,0.,400.,160.,0.,0.,1.); 
    Mat innerMatrix=Mat::zeros(3, 4,CV_64F); 
    innerMat.copyTo(innerMatrix.colRange(0, 3)); 

    Eigen::Quaterniond quaternion(-0.5, 0.5, 0.5, -0.5); 
    Eigen::Matrix3d Emat = quaternion.toRotationMatrix();  
    Mat R(3, 3, CV_64F);
    R=Mat(Emat.rows(),Emat.cols(),CV_64F,Emat.data());
    Mat T=(Mat_<double>(3, 1) << 2,2,2); 
    double frame_num=0.7;

    while(1)
    {
        Mat frame(frame_height, frame_width, CV_8UC3, Scalar(0, 0, 0));
        double extra_x=1/sqrt(frame_num);
        double extra_y=1/sqrt(frame_num);
        double extra_z=-1/sqrt(frame_num);
        

        frame_num*=1.05;
        if(frame_num>5000)
            break;

        Mat extra_T=(Mat_<double>(3, 1) << extra_x,extra_y,extra_z); 
        Mat extra_R=Mat::eye(3,3,CV_64F);
        for(int i=0;i<num;i++)
        {
            Mat pixels=innerMat*(extra_R*R)*(points_world[i]-(T+extra_T));
            double u=pixels.at<double>(0,0)/pixels.at<double>(2,0);
            double v=pixels.at<double>(1,0)/pixels.at<double>(2,0);
            circle(frame, Point(u,v), 1, Scalar(255, 255, 255), 1);
        }
        writer<<frame;
        //cout<<"process left: "<<frame_num<<endl;

    }
    // imshow("img",img);
    // waitKey();
    cout<<"done."<<endl;
    writer.release();
    return 0;

}