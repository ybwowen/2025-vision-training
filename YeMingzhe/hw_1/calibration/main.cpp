#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

int main() {
    int board_width = 9; // 横向角点数
    int board_height = 6; // 纵向角点数
    Size pattern_size(board_width, board_height);
    
    // 创建保存棋盘格世界坐标系下的角点的3D坐标和图像坐标的容器
    vector<vector<Point3f>> object_points; // 世界坐标系中的点
    vector<vector<Point2f>> image_points;  // 图像坐标系中的点

    // 定义棋盘格3D坐标的原点
    vector<Point3f> obj;
    for (int j = 0; j < board_height; j++) {
        for (int i = 0; i < board_width; i++) {
            obj.push_back(Point3f(float(i) * 10, float(j) * 10, 0));
        }
    }

    // 读取图像文件并检测角点
    vector<String> images;
    glob("/home/ymz/Codes/2025-vision-training/homework1/calibration/chess/*.jpg", images); 

    Mat image;
    for (int i = 0; i < images.size(); i++) {
        image = imread(images[i]);
        if (image.empty()) {
            cout << "无法加载图像: " << images[i] << endl;
            continue;
        }

        vector<Point2f> corners; // 保存检测到的角点

        // 找到棋盘格角点
        bool found = findChessboardCorners(image, pattern_size, corners,
                                           CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE);

        if (found) {
            // 提高角点精度
            Mat gray;
            cvtColor(image, gray, COLOR_BGR2GRAY);
            cornerSubPix(gray, corners, Size(11, 11), Size(-1, -1),
                         TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 30, 0.1));

            // 保存检测到的角点
            image_points.push_back(corners);
            object_points.push_back(obj);

            // 显示检测结果
            for (int k = 0; k < corners.size(); k++) {
                circle(image, corners[k], 5, Scalar(0, 0, 255), -1);  // 红色圆，半径为5
            }

            // 保存标定后的图像到指定路径
            string output_image_path = "/home/ymz/Codes/2025-vision-training/hw1_ymz/calibration/calibrationResult/calibrated_image_" + to_string(i) + ".jpg";
            imwrite(output_image_path, image);

            imshow("Corners", image);
            waitKey(500);  // 暂停 500ms 以便查看结果
        }
    }
    destroyAllWindows();

    // 标定相机
    Mat camera_matrix, dist_coeffs;
    vector<Mat> rvecs, tvecs;
    calibrateCamera(object_points, image_points, image.size(), camera_matrix, dist_coeffs, rvecs, tvecs);

    // 打印标定结果
    cout << "Camera Matrix: " << endl << camera_matrix << endl;
    cout << "Distortion Coefficients: " << endl << dist_coeffs << endl;

    // 保存标定结果到文件
    FileStorage fs("/home/ymz/Codes/2025-vision-training/hw1_ymz/calibration/calibrationResult/calibrationResult.yml", FileStorage::WRITE);
    fs << "Camera_Matrix" << camera_matrix;
    fs << "Distortion_Coefficients" << dist_coeffs;
    fs << "Rotation_Vectors" << rvecs;
    fs << "Translation_Vectors" << tvecs;
    fs.release();

    cout << "标定完成，结果已保存到 calibrationResult 文件夹中。" << endl;

    return 0;
}

