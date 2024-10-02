#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include <fstream>
#include <vector>

#include <opencv2/core/eigen.hpp>



int main() {
    const std::vector<cv::Point3d> PW_BIG{// 灯条坐标，单位：m
                                             {-0.115, 0.0265, 0.},
                                             {-0.115, -0.0265, 0.},
                                             {0.115, -0.0265, 0.},
                                             {0.115, 0.0265, 0.}};

    // 读取像素坐标
    std::vector<cv::Point2f> pixel_coords;
    pixel_coords.push_back(cv::Point2f(575.508, 282.175));
    pixel_coords.push_back(cv::Point2f(573.93, 331.819));
    pixel_coords.push_back(cv::Point2f(764.518, 337.652));
    pixel_coords.push_back(cv::Point2f(765.729, 286.741));

    // 读取四元数
    Eigen::Quaterniond q;
    q.x() = 0.994363;    q.y() = -0.0676645;    q.z() = -0.00122528;    q.w() = -0.0816168;


    // 读取相机内参和畸变矩阵       data: [ 1.4142055480888289e+03, 0., 6.5792667877101735e+02, 0.,
       //1.4137212634286254e+03, 4.0455967287503142e+02, 0., 0., 1. ]
    cv::Mat K(3, 3, CV_64F);
    K.at<double>(0, 0) = 1.4142055480888289e+03;   K.at<double>(0, 1) = 0.;    K.at<double>(0, 2) = 6.5792667877101735e+02;
    K.at<double>(1, 0) = 0.;    K.at<double>(1, 1) = 1.4137212634286254e+03;    K.at<double>(1, 2) = 4.0455967287503142e+02;
    K.at<double>(2, 0) = 0.;    K.at<double>(2, 1) = 0.;    K.at<double>(2, 2) = 1.;


    cv::Mat dist_coeffs(5, 1, CV_64F);

    dist_coeffs.at<double>(0) = -1.5713532786218060e-01;   dist_coeffs.at<double>(1) = 3.3883933349759310e-01;  
    dist_coeffs.at<double>(2) = 7.0103028435554145e-04;    dist_coeffs.at<double>(3) = -2.9035486504482461e-04;
    dist_coeffs.at<double>(4) = -4.2372708010388316e-01;


    // 求解位姿
    cv::Mat rvec, tvec;
    cv::solvePnP(PW_BIG, pixel_coords, K, dist_coeffs, rvec, tvec);//solve camera pose related to real world coordinate

    cv::Mat R;
    // 将旋转向量转换为旋转矩阵
    cv::Rodrigues(rvec,R);

    // 将相机坐标系下的位姿转换为陀螺仪坐标系下的位姿
    Eigen::Matrix3d R_cam_to_gyro = q.toRotationMatrix();
    Eigen::Matrix3d R_armor_to_cam;
    cv::cv2eigen(R, R_armor_to_cam);
    Eigen::Matrix3d R_armor_to_gyro = R_cam_to_gyro * R_armor_to_cam;

    // camera center in armour coordinate
    cv::Point3f center_cam = cv::Point3f(tvec.at<double>(0), tvec.at<double>(1), tvec.at<double>(2));

    // get the center in gyro coordinate
    Eigen::Vector3d center_gyro = R_armor_to_gyro * Eigen::Vector3d(-center_cam.x, -center_cam.y, -center_cam.z);

    // 输出结果
    std::cout << "装甲板中心在陀螺仪坐标系下的坐标: " << center_gyro.transpose() << std::endl;

    return 0;