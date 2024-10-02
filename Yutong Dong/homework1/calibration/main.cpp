#include <opencv2/calib3d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include<sstream>

using namespace cv;
using namespace std;

int main()
{
    //9*6的棋盘格大小
    Size patternSize(9, 6); 

    //每个格子是10cm*10cm
    float squareSize = 10.0f; 
    
    vector<vector<Point2f>> imagePoints;
    vector<vector<Point3f>> objectPoints;
    vector<Point3f> singleObjectPoints;
    
    vector<string> images;

    for(int i=0;i<=40;i++){
        std::ostringstream oss;
        oss<<"../"<<i<<".jpg";
        images.push_back(oss.str());
    }

    //获得图像的尺寸
    cv::Mat size=imread("../0.jpg");
    cv::Size imgsize=size.size();

    for (const auto& imagePath : images)
    {   
        Mat image = imread(imagePath, IMREAD_GRAYSCALE);

        if(image.empty())
        {
            cout << "Failed to load image: " << imagePath << endl;
            continue;
        }
        
        vector<Point2f> corners;
        
        bool found = findChessboardCorners(image, patternSize, corners);
        
        if (found)
        {
            cv::Size region_size(11,11);
            cv::find4QuadCornerSubpix(image, corners, region_size);

            imagePoints.push_back(corners);

            //设置每张图中角点的世界坐标系
            singleObjectPoints.clear();
            for (int i = 0; i < patternSize.height; ++i)
            {
                for (int j = 0; j < patternSize.width; ++j)
                {
                    singleObjectPoints.push_back(Point3f(float(j * squareSize), float(i * squareSize), 0));
                    
                }
                
            }

            objectPoints.push_back(singleObjectPoints);
        }
        else
        {
            cout << "Chessboard not found in image: " << imagePath << endl;
            continue;
        }
    }
    
    if (objectPoints.empty() || imagePoints.empty() || objectPoints.size() != imagePoints.size()) {
        cerr << "Input data is invalid or insufficient." << endl;
        cerr<<objectPoints.size() <<" "<< imagePoints.size()<<endl;
        return -1;
    }

    //初始化
    Mat cameraMatrix = Mat::eye(3, 3, CV_64F); 
    Mat distCoeffs = (Mat_<double>(1, 5) << 0, 0, 0, 0, 0); 
    vector<Mat> rvecs, tvecs;
    
    double rms = calibrateCamera(objectPoints, imagePoints, imgsize, cameraMatrix, distCoeffs, rvecs, tvecs);
    
    cout << "Reprojection Error" << rms << endl;
    cout << "Camera Matrix:\n" << cameraMatrix << endl;
    cout << "Distortion Coefficients:\n" << distCoeffs << endl;
    
    return 0;
}