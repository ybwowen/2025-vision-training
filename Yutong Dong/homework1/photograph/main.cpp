#include <opencv2/calib3d.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<iostream>
#include<fstream>
#include <ostream>
#include<vector>
#include<Eigen/Dense>

using namespace std;
using namespace cv;
using namespace Eigen;

int main(){

    Mat camera=(Mat_<float>(3,3)<<
    400., 0., 190., 
    0., 400., 160., 
    0., 0., 1.);

    Mat distCoeffs=Mat::zeros(1,5,CV_64F);

    Mat tvec=(Mat_<float>(3,1)<<
    2.,2.,2.);

    vector<Point3f> objectPoints;
    ifstream file("../points.txt");
    
    if(!file.is_open()){
        cerr<<"failed to open file"<<endl;
        return -1;
    }

    int num;
    file>>num;

    for(int i=0;i<num;i++){
        float x,y,z;
        file>>x>>y>>z;
        objectPoints.push_back(Point3f(x,y,z));
    }

    file.close();

    Quaterniond q;
    q.x()=0.5;
    q.y()=0.5;
    q.z()=-0.5;
    q.w()=-0.5;

    Matrix3d rotation=q.toRotationMatrix();
    cout << rotation<<endl;
    Mat rotation_mat(3,3,CV_64F,rotation.data());//在转换的时候填的顺序相当于转置
    cout << rotation_mat <<endl;

    Mat rvec_transposedMatrix = rotation_mat;

    Mat tvec_converted;
    tvec.convertTo(tvec_converted, rvec_transposedMatrix.type());

    cout<<tvec_converted.cols<<" "<<tvec_converted.rows<<endl;
    cout<<rvec_transposedMatrix.cols<<" "<<rvec_transposedMatrix.rows<<endl;
    //return 0;

    tvec_converted=-rvec_transposedMatrix*tvec_converted;
    
    cout << rvec_transposedMatrix <<endl;
    cout << tvec_converted <<endl;

    Mat img=Mat::zeros(1080,1920,CV_8UC3);

    vector<Point2f> imgPoints;
    projectPoints(Mat(objectPoints), rvec_transposedMatrix, tvec_converted, camera, distCoeffs, imgPoints);
    
    for(size_t i=0;i<imgPoints.size();i++){
        circle(img, imgPoints[i], 3, Scalar(0,0,255));
    }

    namedWindow("projected points");
    imshow("projected points",img);
    waitKey(0);
}