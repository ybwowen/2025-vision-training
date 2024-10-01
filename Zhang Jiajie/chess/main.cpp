#include<iostream>
#include<string>
#include<vector>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
    freopen("../cam.txt", "w", stdout);
    for(int i=0; i<=40; i++){
        Mat img = imread("../"+to_string(i)+".jpg");
        Mat gray;
        cvtColor(img, gray, COLOR_BGR2GRAY);
        Size image_size = gray.size();

        Size patternSize(6, 9);
        vector<Point2f> corners;

        bool found = findChessboardCorners(gray, patternSize, corners);
        find4QuadCornerSubpix(gray, corners, Size(5, 5));

        vector<Point3f> obj;
        vector<vector<Point3f> > object_points;
        vector<vector<Point2f> > image_points;

        for(int i=0; i<6; i++){
            for(int j=0; j<9; j++){
                obj.push_back(Point3f(j*10.0, i*10.0, 0.0));
            }
        }
        object_points.push_back(obj);
        image_points.push_back(corners);

        Mat camMat, coeff;
        vector<Mat> rvecs, tvecs;
        calibrateCamera(object_points, image_points, image_size, camMat, coeff, rvecs, tvecs);
        cout<<i<<endl<<camMat<<endl<<coeff<<endl<<endl;
    }
    return 0;
}
