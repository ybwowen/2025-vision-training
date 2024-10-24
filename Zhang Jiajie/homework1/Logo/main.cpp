

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<Eigen/Dense>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace Eigen;
using namespace cv;

int main(){
    Mat img = imread("../img.png");
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    Mat img_bin;
    threshold(img_gray, img_bin, 100, 255, THRESH_BINARY);

    vector<vector<Point> > contours;
    vector<Vec4i> hierachy;
    findContours(img_bin, contours, hierachy, RETR_LIST, CHAIN_APPROX_NONE);
    
    vector<Vector4d> pos_list;
    vector<int> rad_list;
        for(int i=0; i<contours.size(); i++){
            for(int j=0; j<contours[i].size(); j++){
                double z = rand()%200-100.0;
                pos_list.push_back(Vector4d(contours[i][j].x, contours[i][j].y, z, 1.0));
                rad_list.push_back(rand()%4+1);
            }
        }

    VideoWriter video("../logo.mp4", VideoWriter::fourcc('M', 'J', 'P', 'G'), 20, Size(700, 500));

    Matrix<double,3,4> Mc;
    Mc << 400., 0., 190., 0.,
            0., 400., 160., 0.,
            0., 0., 1., 0.;

    for(int t=0; t<100; t++){
        double angle = t*M_PI/200.0;

        Vector3d T(750.0*cos(angle)+472.0, 267.0, 750.0*sin(angle));;
        Matrix3d Mr = AngleAxisd(M_PI/2-angle, Vector3d(0, 1, 0)).toRotationMatrix();
        
        Matrix<double, 4, 4> M0;
        M0 << Mr(0, 0), Mr(0, 1), Mr(0, 2), T(0),
                Mr(1, 0), Mr(1, 1), Mr(1, 2), T(1),
                Mr(2, 0), Mr(2, 1), Mr(2, 2), T(2),
                0, 0, 0, 1;

        Mat image = Mat(500, 700, CV_8UC3, Scalar(0,0,0));
        for(int i=0; i<pos_list.size(); i++){
            Vector<double, 3> posr = Mc * M0.inverse() * pos_list[i];
            Point p(-posr(0)/posr(2)+500, -posr(1)/posr(2)+400);
            circle(image, p, rad_list[i], Scalar(255,255,255), -1);
        }
        video.write(image);
        imshow("Photo", image);
        waitKey(25);
    }
    video.release();
    return 0;
}

