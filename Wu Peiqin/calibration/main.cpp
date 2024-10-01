//目前只能检测出十张，估计是其他的图片太倾斜了，解决方案寻找中
#include <iostream>

#include <opencv2/calib3d.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/persistence.hpp>

#include <vector>
#include <string>

#include <dirent.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

cv::Size boardSize(9, 6);
std::vector<std::vector<cv::Point3f>> objectPoints;
std::vector<std::vector<cv::Point2f>> imagePoints;
cv::Mat cameraMatrix,distCoeffs;


std::vector<std::string> get_path()
{
    std::string folder_path="../calibration/chess";
    std::vector<std::string> img_path;
    DIR *dir=opendir(folder_path.c_str());

    if (dir==NULL){
        std::cerr<<"WRONG! can't open:"<<folder_path<<std::endl;
    }

    struct dirent *ent;
    while ((ent=readdir(dir))!=NULL)
    {
        img_path.emplace_back(folder_path+"/"+ent->d_name);
    }

    return img_path;
}


void findCorners(const std::vector<std::string>& imagePaths) {
    cv::Mat grayImage;
    cv::Mat drawImage;
    std::vector<cv::Point2f> corners;
    std::vector<cv::Point3f> object_p;

    //生成3d世界坐标点
    for(int i=0;i<boardSize.height;i++)
    {
        for(int j=0;j<boardSize.width;j++)
        {
            object_p.emplace_back(j,i,0);
        }
    }

    for (const auto& imagePath : imagePaths) {
        // 读取图像
        cv::Mat image = cv::imread(imagePath);
        if (image.empty()) {
            std::cerr << "Could not open or find the image: " << imagePath << std::endl;
            continue;
        }

        // 转换为灰度图
        cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
        cv::GaussianBlur(grayImage, grayImage, cv::Size(7,7),0);

        // 寻找棋盘格角点
        bool found = cv::findChessboardCorners(grayImage, boardSize, corners,
            cv::CALIB_CB_ADAPTIVE_THRESH + cv::CALIB_CB_FAST_CHECK + cv::CALIB_CB_NORMALIZE_IMAGE);

        if (found) {
            // 提升亚像素精度
            cv::find4QuadCornerSubpix(grayImage, corners, cv::Size(5, 5));

            imagePoints.push_back(corners);
            objectPoints.push_back(object_p);

            // 绘制角点
            drawImage = image.clone();
            cv::drawChessboardCorners(drawImage, boardSize, corners, found);
            cv::imshow("Chessboard Corners", drawImage);
            cv::waitKey(500); // 显示图像并暂停
        } 
        else {
            std::cout << "Chessboard corners not found in: " << imagePath << std::endl;
        }
    }
    cv::destroyAllWindows(); // 关闭所有窗口
}


// 实现相机标定
void calibrateCamera()
{
    std::vector<cv::Mat> rotation_vector,translate_vector;

    double root_mean_square=cv::calibrateCamera(objectPoints,imagePoints,boardSize,
                                                cameraMatrix,distCoeffs,
                                                rotation_vector,translate_vector);
    std::cout<<"RMS:"<<root_mean_square<<std::endl;
    std::cout<<"Camera Matrix:\n"<<cameraMatrix<<std::endl;
    std::cout<<"Distortion Coefficients:\n"<<distCoeffs<<std::endl;
}



//储存相机标定的结果
void saveCalibration(const std::string& filename)
{
    cv::FileStorage fs(filename,cv::FileStorage::WRITE);
    fs<<"camera_matrix:\n"<<cameraMatrix;
    fs<<"distortion_coefficients:\n"<<distCoeffs;
    fs.release();
}



int main()
{
    std::vector<std::string> img_path=get_path();
    std::vector<std::vector<cv::Point2f>> results;
    findCorners(img_path);
    calibrateCamera();
    saveCalibration("camera_calibration.yml");
}