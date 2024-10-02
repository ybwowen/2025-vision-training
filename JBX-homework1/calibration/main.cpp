#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

int main() {
    std::vector<std::vector<cv::Point3f>> object_points; // 世界坐标
    std::vector<std::vector<cv::Point2f>> image_points; // 图像坐标

    const int board_height = 9;
    const int board_width = 6;
    const int square_size = 10;
    cv::Size board_size = cv::Size(9, 6);
    cv::Size img_size = cv::Size(0, 0);

    // 读取一下图片
    std::string folder_path = "/home/andy/桌面/2025-vision-homework/calibration/chess";
    std::vector<cv::String> image_files;
    cv::glob(folder_path, image_files, false);

    // 定义标定板的角点世界坐标
    std::vector<cv::Point3f> obj;
    for (int i = 0; i < board_height; ++i) {
        for (int j = 0; j < board_width; ++j) {
            obj.push_back(cv::Point3f(j * square_size, i * square_size, 0));
        }
    }

    // 读取所有标定图片
    for (const auto& file : image_files) {
        cv::Mat image = cv::imread(file, cv::IMREAD_COLOR);

        // 更新一下图片长宽
        if (img_size == cv::Size(0, 0)){
            img_size = cv::Size(image.cols, image.rows);
        }
        // 转化为灰度图
        cv::Mat gray;
        cvtColor(image, gray, cv::COLOR_BGR2GRAY);
        image = gray;

        // 寻找标定板角点
        std::vector<cv::Point2f> corners;
        bool found = cv::findChessboardCorners(image, cv::Size(board_width, board_height), corners,
            cv::CALIB_CB_ADAPTIVE_THRESH + cv::CALIB_CB_NORMALIZE_IMAGE + cv::CALIB_CB_FAST_CHECK);

        if (found) {
            cv::cornerSubPix(gray, corners, cv::Size(11, 11), cv::Size(-1, -1),
                cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 30, 0.1));

            image_points.push_back(corners);
            object_points.push_back(obj);
        }
    }

    // 相机内参矩阵和畸变系数
    cv::Mat camera_matrix, dist_coeffs;
    std::vector<cv::Mat> rvecs, tvecs;

    // 标定相机
    double rms = cv::calibrateCamera(object_points, image_points, img_size, camera_matrix, dist_coeffs, rvecs, tvecs, 0,
cv::TermCriteria(cv::TermCriteria::COUNT+cv::TermCriteria::EPS, 30, DBL_EPSILON));

    std::cout << "Calibration RMS error: " << rms << std::endl;
    std::cout << "Camera matrix: " << camera_matrix << std::endl;
    std::cout << "Distortion coefficients: " << dist_coeffs << std::endl;

    return 0;
}