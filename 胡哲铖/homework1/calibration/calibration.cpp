//参考了22赛季的培训代码
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <string>

using namespace std;
using namespace cv;

int main() {
    int found, successes{0};
    Mat grayImg;
    vector< Point2f > imagePoint;
    vector< vector<Point2f> > imagePoints;
    Size board_size( 9, 6 );
    int width{9},height{6};
    int number{width*height};
    Size imgSize;
    for (int i = 0;i <= 40;i++){ //读入图片并找到角点
        Mat src = imread("../chess/"+to_string(i)+".jpg");
        found = findChessboardCorners( src, board_size, imagePoint );
        if (i == 0){ //留下宽高备用
            imgSize.width=src.cols;
            imgSize.height=src.rows;
        }
        if (found && (imagePoint.size() == number)){ //对找到的角点亚像素精化
            cvtColor( src, grayImg, COLOR_BGR2GRAY );
            find4QuadCornerSubpix( grayImg, imagePoint, Size( 11, 11 ) );
            imagePoints.push_back( imagePoint );
            imagePoint.clear();
            successes++;
        } 
    }
    
    //初始化
    vector< vector< Point3f > > objectPoints;
    vector< Point3f > objectPoint;
    Mat cameraMatrix( 3, 3, CV_32FC1, Scalar::all( 0 ) );
    Mat distCoeffs( 1, 5, CV_32FC1, Scalar::all( 0 ) );
    vector< Mat > rvecs;
    vector< Mat > tvecs;

    //构建网格
    for (int i = 0; i < successes; i++ ) { 
        for (int j = 0; j < height; j++ ) {
            for (int k = 0; k < width; k++ ){
                objectPoint.push_back( Point3f(k,j,0) );
            }
        }
        objectPoints.push_back( objectPoint );
        objectPoint.clear();
    }
    calibrateCamera( objectPoints, imagePoints, imgSize, cameraMatrix, distCoeffs, rvecs, tvecs );
    cout << "CameraMatrix:\n"<<cameraMatrix << "\nDistCoeffs:\n" << distCoeffs << "\n";
    FileStorage fs("../calibration.json", FileStorage::WRITE);
    fs << "CameraMatrix" << cameraMatrix;
    fs << "DistCoeffs" << distCoeffs;
    fs.release();
}