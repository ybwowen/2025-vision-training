#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <vector>

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Geometry/Quaternion.h>
#include <eigen3/Eigen/src/Core/Matrix.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>


// 声明已知的相机参数
cv::Mat cameraMatrix, rotationMatrix; // 相机内参矩阵和旋转矩阵
cv::Mat translationVector; // 平移向量

    std::string filename = "../points.txt";
// 读取坐标
void readDataFromFile(std::vector<cv::Point3f>& points) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }


    int n;
    file >> n;
    points.reserve(n);

    for (int i = 0; i < n; ++i) {
        float x, y, z;
        file >> x >> y >> z;
        points.emplace_back(x, y, z);
    }
    file.close();
}


int main() {
    std::vector<cv::Point3f> worldPoints;
    
    // 初始化相机参数
    cameraMatrix = (cv::Mat_<float>(3,3) << 400., 0., 190., 0.,// 相机内参矩阵
                                                        0., 400., 160., 0.,
                                                        0., 0., 1., 0.); 

    Eigen::Quaterniond quaterniond(0.5,0.5,-0.5,-0.5);// 通过四元数转换得到的旋转矩阵
    Eigen::Matrix3f rot_Matrix = quaterniond.toRotationMatrix().cast<float>(); 
    rotationMatrix=cv::Mat(rot_Matrix.rows(),rot_Matrix.cols(),CV_32F,rot_Matrix.data());

    translationVector = cv::Mat(3,1,CV_32F,cv::Scalar(2,2,2)); // 平移向量


    // 读取数据
    readDataFromFile( worldPoints);

    // 创建图像并设置大小（根据需要调整）
    cv::Mat image(720, 720, CV_8UC3, cv::Scalar(255,255, 255));

    // 投影并绘制点

    for (const cv::Point3f& point3D : worldPoints) 
    {
        // 将3D点转换为相机坐标系下的点
        cv::Mat point3D_cv = (cv::Mat_<float>(3, 1) << point3D.x, point3D.y, point3D.z);
        cv::Mat pointCam=rotationMatrix*point3D_cv+translationVector;

        // 投影到图像平面
        cv::Mat point2D=cameraMatrix*pointCam;
        point2D=point2D/point2D.at<float>(2,0);

        // 绘制点
        cv::circle(image, cv::Point(cvRound(point2D.at<double>(0, 0)), cvRound(point2D.at<double>(1, 0))), 2, cv::Scalar(0, 0, 255), -1);
    }

    // 显示图像
    cv::imshow("Projected Points", image);
    cv::waitKey(0);

}
