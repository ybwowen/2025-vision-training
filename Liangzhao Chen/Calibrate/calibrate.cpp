#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem> // C++17 for directory iteration

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

int main() {
    // 设置棋盘格的大小
    Size patternSize(9, 6); 
    
    // 存储棋盘角点的二维图像坐标和三维世界坐标
    vector<vector<Point2f>> imagePoints;
    vector<vector<Point3f>> objectPoints;

    // 准备棋盘格的三维坐标 (z=0, 仅在 x-y 平面上)
    vector<Point3f> obj;
    for (int i = 0; i < patternSize.height; ++i) {
        for (int j = 0; j < patternSize.width; ++j) {
            obj.push_back(Point3f(j, i, 0));
        }
    }

    // 指定相对路径，指向 chess 文件夹
    string folderPath = "../chess/";

    Mat image;
    // 遍历 chess 文件夹中的所有图像文件
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        string filename = entry.path().string();
        // cout<<filename<<endl;
        // 仅处理 .jpg 文件
        if (filename.find(".jpg") != string::npos) {
             image = imread(filename);

            if (image.empty()) {
                cout << "无法读取图像文件: " << filename << endl;
                continue;
            }

            vector<Point2f> corners;
            bool found = findChessboardCorners(image, patternSize, corners,
                                               CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE);
            
            if (found) {
                Mat gray;
                cvtColor(image, gray, COLOR_BGR2GRAY);

                // 使用 find4QuadCornerSubpix 进行亚像素精化
                find4QuadCornerSubpix(gray, corners, Size(7, 7));
                //这里在调第三个参数的时候，
                //我发现Size(3,3), Size(5,5), Size(7,7)标定出来的结果还是有不同的，
                //我在网上查，说参数越大计算时间越长，精度越高，所以我想着用（7，7），
                //但是我觉得这可能过于草率，想问问，在实际标标定过程中，
                //参数是根据哪些因素选取的啊


                // 存储图像点和对应的三维世界坐标
                imagePoints.push_back(corners);
                objectPoints.push_back(obj);
            } else {
                cout << "未找到棋盘角点: " << filename << endl;
            }
        }
    }

    // 检查是否找到足够的图片进行标定
    if (imagePoints.size() < 1) {
        cout << "未找到足够的有效图像用于相机标定。" << endl;
        return -1;
    }

    // 进行相机标定
    Mat cameraMatrix, distCoeffs;
    vector<Mat> rvecs, tvecs;
    Size imagesize= image.size();
    calibrateCamera(objectPoints, imagePoints, imagesize, cameraMatrix, distCoeffs, rvecs, tvecs);

    // 输出相机内参矩阵和畸变系数
    cout << "相机内参矩阵: " << cameraMatrix << endl;
    cout << "畸变系数: " << distCoeffs << endl;

    // 保存标定结果
    FileStorage fs("calibration_result.xml", FileStorage::WRITE);
    fs << "CameraMatrix" << cameraMatrix;
    fs << "DistCoeffs" << distCoeffs;
    fs.release();

    cout << "标定完成，结果已保存到 calibration_result.xml" << endl;
    // cout<<imagesize.width<<endl<<imagesize.height<<endl;

    return 0;
}
