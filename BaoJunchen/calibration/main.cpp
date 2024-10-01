#include <iostream>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

int main() {
    string folder_path="../chess/";

     //variables for calibrate
    vector<vector<Point3f>>objectPoints;
    vector<vector<Point2f>>imagePoints;
    Size imageSize;
    Mat cameraMatrix, distCoeffs;
    vector<Mat> rvecs, tvecs;

    for(int index=0;index<=40;index++)
    {

        string file_path = folder_path + to_string(index)+".jpg";  
        Mat image= imread(file_path);
        imageSize=image.size();
       
        Size patternSize(9, 6); 
        vector<Point3f> obj;
        for (int i=0;i<patternSize.width;i++)
        {
            for(int j=0;j<patternSize.height;j++)
            {
                obj.emplace_back(Point3f(i,j,0));
            }
        }

        vector<Point2f> corners;
        findChessboardCorners(image, patternSize, corners);

        Mat gray;
        cvtColor(image, gray, COLOR_BGR2GRAY);
        find4QuadCornerSubpix(gray,corners,Size(5,5));

        imagePoints.emplace_back(corners);
        objectPoints.emplace_back(obj);


        // drawChessboardCorners(image, patternSize, corners, 1);
        // imshow(" ",image);
        // waitKey();
        cout<<"including picture "<<index<<endl;
    }   
    cout<<"calibrating..."<<endl;
    calibrateCamera(objectPoints,imagePoints,imageSize,cameraMatrix,distCoeffs,rvecs,tvecs);
    cout<<"相机内参矩阵:"<<cameraMatrix<<endl;
    cout<<"相机畸变矩阵:"<<distCoeffs<<endl;

    return 0;

}