#include <Eigen/Core>
#include <Eigen/Geometry>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // 相机内参矩阵 F
    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 
        1.4142055480888289e+03, 0., 6.5792667877101735e+02, 0.,
       1.4137212634286254e+03, 4.0455967287503142e+02, 0., 0., 1.);
    cameraMatrix.convertTo(cameraMatrix, CV_64F);

    // 畸变系数 C
    cv::Mat distCoeffs = (cv::Mat_<double>(1, 5) << 
        -1.5713532786218060e-01, 3.3883933349759310e-01,
       7.0103028435554145e-04, -2.9035486504482461e-04,
       -4.2372708010388316e-01);

    // 矩形的实际高度（真实尺寸，单位：米）
    double W_real = 0.23;  // 0.0265 * 2，矩形的实际高度

    // 图像中的像素坐标，分别为矩形的上中下三个点
    std::vector<cv::Point2d> imagePoints = {
        {575.508, 282.175},  // 左上角
        {573.93, 331.819},   // 左下角
        {764.518, 337.652},  // 右下角
        {765.729, 286.741}   // 右上角
    };

    // 计算左右顶点的像素
    double W_image_up = std::sqrt(std::pow(imagePoints[0].x - imagePoints[3].x, 2) + 
                                  std::pow(imagePoints[0].y - imagePoints[3].y, 2));
    double W_image_down = std::sqrt(std::pow(imagePoints[1].x - imagePoints[2].x, 2) + 
                                    std::pow(imagePoints[1].y - imagePoints[2].y, 2));

    // 相机内参的焦距
    double fx = cameraMatrix.at<double>(0, 0);
    double fy = cameraMatrix.at<double>(1, 1);

    // 通过相似三角形计算上下两组顶点的深度
    double z_c_up = (fx * W_real) / W_image_up;
    double z_c_down = (fx * W_real) / W_image_down;

    // 计算中心点的深度（上下深度的平均值）
    double z_c_center = (z_c_up + z_c_down) / 2;

    std::cout << "中心点的深度 z_c_center: " << z_c_center << " 米" << std::endl;

    // 计算图像中矩形中心点的像素坐标
    double u_center = (imagePoints[0].x + imagePoints[1].x + imagePoints[2].x + imagePoints[3].x) / 4;
    double v_center = (imagePoints[0].y + imagePoints[1].y + imagePoints[2].y + imagePoints[3].y) / 4;

    // 去畸变后的中心点坐标
    std::vector<cv::Point2d> undistortedPoints;
    cv::undistortPoints(std::vector<cv::Point2d>{{u_center, v_center}}, undistortedPoints, cameraMatrix, distCoeffs);

    // 计算相机坐标系中的中心点坐标
    double cx = cameraMatrix.at<double>(0, 2);
    double cy = cameraMatrix.at<double>(1, 2);

    double x_c_center = (undistortedPoints[0].x * fx) + cx;
    double y_c_center = (undistortedPoints[0].y * fy) + cy;

    // 相机坐标系中的中心点
    Eigen::Vector3d camera_center(x_c_center, y_c_center, 1);

    // 四元数
    Eigen::Quaterniond q(0.994363, -0.0676645, -0.00122528, -0.0816168);

    // 将四元数转换为旋转矩阵
    Eigen::Matrix3d R = q.toRotationMatrix();

    // 创建一个4x4的矩阵并初始化为单位矩阵
    Eigen::Matrix4d R_extended = Eigen::Matrix4d::Identity();

    // 将3x3的旋转矩阵拷贝到4x4矩阵的左上角
    R_extended.block<3, 3>(0, 0) = R;

    Eigen::Matrix<double, 3, 4> CameraMatrix;
    CameraMatrix << 1.4142055480888289e+03, 0., 6.5792667877101735e+02, 0.,
                    0., 1.4137212634286254e+03, 4.0455967287503142e+02, 0.,
                    0., 0., 1., 0.;

    // 使用 QR 分解法求解
    Eigen::VectorXd world_center = (CameraMatrix * R_extended).colPivHouseholderQr().solve(z_c_center * camera_center);

    // 输出结果
    std::cout << "世界坐标系中的矩形中心点: (" 
              << world_center.x() << ", " 
              << world_center.y() << ", " 
              << world_center.z() << ")" << std::endl;

    return 0;
}

