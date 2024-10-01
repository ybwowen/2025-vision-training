//
// Created by cwlm on 2024/10/1.
//
#include <iostream>
#include <vector>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

// 棋盘格的尺寸：横向 10 格，纵向 7 格
const int boardWidth = 10;
const int boardHeight = 7;
const Size boardSize = Size(boardWidth - 1, boardHeight - 1);  // 减 1 是因为角点数量少于格子数量

// 读取图片路径
vector<string> getImageList() {
    vector<string> imageList;
    for (int i = 0; i <= 40; i++) {
        string filename = "chess/" + to_string(i) + ".jpg";
        imageList.emplace_back(filename);
    }
    return imageList;
}

int main() {
    // 获取图片列表
    vector<string> image_list = getImageList();

    // 存储世界坐标系下的点
    vector<vector<Point3f>> objectPoints;

    // 存储每张图片的角点坐标
    vector<vector<Point2f>> imagePoints;

    // 设置棋盘格角点的实际物理尺寸，假设每个格子的大小是 1 个单位
    vector<Point3f> obj;
    for (int j = 0; j < boardHeight - 1; j++) {
        for (int i = 0; i < boardWidth - 1; i++) {
            obj.emplace_back(i, j, 0.0f);
        }
    }

    // 遍历每张图片，查找棋盘格角点
    for (const string& imagePath : image_list) {
        Mat image = imread(imagePath);
        if (image.empty()) {
            cout << "无法加载图片: " << imagePath << endl;
            continue;
        }

        // 转为灰度图
        Mat gray;
        cvtColor(image, gray, COLOR_BGR2GRAY);

        // 查找角点
        vector<Point2f> corners;
        bool found = findChessboardCorners(gray, boardSize, corners,
                                           CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE);

        if (found) {
            // 提高角点精度
            cornerSubPix(gray, corners, Size(11, 11), Size(-1, -1),
                         TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 30, 0.001));
            imagePoints.push_back(corners);
            objectPoints.push_back(obj);

            // 在图片中显示角点
            drawChessboardCorners(image, boardSize, corners, found);
            imshow("Chessboard Corners", image);
            waitKey(100);  // 暂停一段时间以便观察结果
        }
    }

    destroyAllWindows();

    if (imagePoints.size() < 10) {
        cout << "没有足够的有效角点检测来进行标定。" << endl;
        return -1;
    }

    // 相机标定
    Mat cameraMatrix, distCoeffs;
    vector<Mat> rvecs, tvecs;
    double rms = calibrateCamera(objectPoints, imagePoints, Size(boardWidth, boardHeight),
                                 cameraMatrix, distCoeffs, rvecs, tvecs);

    // 输出标定结果
    cout << "标定完成！重投影误差: " << rms << endl;
    cout << "相机内参矩阵: " << endl << cameraMatrix << endl;
    cout << "畸变系数: " << endl << distCoeffs << endl;

    // 保存标定结果
    FileStorage fs("camera_calibration.yml", FileStorage::WRITE);
    fs << "CameraMatrix" << cameraMatrix;
    fs << "DistCoeffs" << distCoeffs;
    fs.release();

    return 0;
}
