#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

const int size_of_square = 10;
const int rows = 6;
const int cols = 9;
const int pic_num = 41;

int main() {
    std::vector<std::vector<cv::Point2f>> corners_vec;
    std::vector<std::vector<cv::Point3f>> object_points_vec;
    std::vector<cv::Mat> pic_vec;
    cv::Size imageSize;

    // 读取图像
    for(int pic_id = 0; pic_id < pic_num ; ++pic_id){
        cv::Mat image = cv::imread("../chess/"+ std::to_string(pic_id) +".jpg", cv::IMREAD_GRAYSCALE);
        pic_vec.push_back(image);
        if (image.empty()) {
            std::cerr << "Error loading the image" << std::endl;
            return -1;
        }

        cv::Size boardSize = cv::Size(cols, rows); // 行角点数对应列数

        std::vector<cv::Point2f> corners;
        bool found = cv::findChessboardCorners(image, boardSize, corners);

        if (found) {
            std::cout << pic_id + 1 << " / " << pic_num<<" Chessboard corners found" << std::endl;
            cv::find4QuadCornerSubpix(image, corners, cv::Size(11,11));
            // 绘制角点
            // cv::drawChessboardCorners(image, boardSize, cv::Mat(corners), found);
            // cv::imwrite("1.png", image);
        } else {
            std::cout << "Chessboard corners not found" << std::endl;
            return 1;
        }

        // 假设棋盘左上角为(0,0,0),向右为X轴,向下为Y轴
        std::vector<cv::Point3f> object_points;
        for(int i= 0; i< rows ; i++){
            for(int j=0 ; j< cols ; j++){
                object_points.push_back(cv::Point3f( (j + 1)*size_of_square , (i + 1)*size_of_square,0));
            }
        }
        corners_vec.push_back(corners);
        object_points_vec.push_back(object_points);
        imageSize = image.size() ;
    }
    

    cv::Mat cameraMatrix;
    cv::Mat distCoeffs ;
    std::vector<cv::Mat> rvecs, tvecs;
    double rms = cv::calibrateCamera(object_points_vec, corners_vec, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs);

    // 保存标定结果到文件
    cv::FileStorage fs("camera_parameters.xml", cv::FileStorage::WRITE);
    fs << "camera_matrix" << cameraMatrix;
    fs << "distortion_coefficients" << distCoeffs;
    fs.release();

    std::cout << "Calibration RMS error: " << rms << std::endl;
    cv::Mat newCameraMatrix = cv::getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize);
    cv::Mat undistortedImage;
    for(int i = 0; i< pic_vec.size(); i++){
        
        cv::undistort(pic_vec[i], undistortedImage, cameraMatrix, distCoeffs, newCameraMatrix);

        // 保存去畸变后的图像
        cv::imwrite("../out/" + std::to_string(i) + ".jpg", undistortedImage);
    }
   
    return 0;
}