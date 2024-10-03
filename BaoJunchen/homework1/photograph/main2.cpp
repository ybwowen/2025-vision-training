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
    
    ifstream input("../points.txt");
    int num=1;
    input>>num;
    Mat w_point=Mat_<double> (3,1);

    Mat innerMat = (Mat_<double>(3, 3) << 400.,0.,190.,0.,400.,160.,0.,0.,1.); 
    Mat innerMatrix=Mat::zeros(3, 4,CV_64F); 
    innerMat.copyTo(innerMatrix.colRange(0, 3)); 



    Eigen::Quaterniond quaternion(-0.5, 0.5, 0.5, -0.5); 
    Eigen::Matrix3d Emat = quaternion.toRotationMatrix();  
    Mat R(3, 3, CV_64F);
    R=Mat(Emat.rows(),Emat.cols(),CV_64F,Emat.data());
    //R=R.inv();


    Mat T=(Mat_<double>(3, 1) << 2,2,2); 

    Mat img(1200, 1200, CV_8UC3, Scalar(0, 0, 0));


    for(int i=0;i<num;i++)
    {
        input >> w_point.at<double>(0, 0)>> w_point.at<double>(1, 0)>> w_point.at<double>(2, 0);
        Mat pixels;
        pixels=w_point-T;
        pixels=R*pixels;

        pixels=innerMat*pixels;

        double u=pixels.at<double>(0,0)/pixels.at<double>(2,0);
        double v=pixels.at<double>(1,0)/pixels.at<double>(2,0);
        //cout<<pixels<<endl;
        circle(img, Point(u,v), 2, Scalar(255, 255, 255), 1);

    }
    imshow("img",img);
    waitKey();
    cout<<"done."<<endl;
    return 0;

}