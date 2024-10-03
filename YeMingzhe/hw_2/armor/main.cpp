#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include <iostream>

int main()
{
    std::vector<cv::Point3d> objectPoints = {
        {-0.115, 0.0265, 0.},
        {-0.115, -0.0265, 0.},
        {0.115, -0.0265, 0.},
        {0.115, 0.0265, 0.}
    };

    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 
        1.4142055480888289e+03,0,6.5792667877101735e+02, 
        0., 1.4137212634286254e+03, 4.0455967287503142e+02, 
        0., 0., 1. );
    cv::Mat distCoeffs = (cv::Mat_<double>(1, 5)<<-1.5713532786218060e-01, 3.3883933349759310e-01,
       7.0103028435554145e-04, -2.9035486504482461e-04,-4.2372708010388316e-01 ); 

    Eigen::Quaterniond q(-0.0816168, 0.994363, -0.0676645, -0.00122528);
    Eigen::Matrix3d R = q.toRotationMatrix();

    std::vector<cv::Point2d> imagePoints = {
        {575.508, 282.175},
        {573.93, 331.819},
        {764.518, 337.652},
        {765.729, 286.741}
    };

    cv::Mat rvec, tvec;
    cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec);

    Eigen::Vector3d center_world(tvec.at<double>(0), tvec.at<double>(1), tvec.at<double>(2));
    Eigen::Vector3d center_point = R * center_world;
    
    std::cout << "装甲板中心在陀螺仪坐标系下的坐标：(" << center_point[0]<< ", " << center_point[1] << ", "<< center_point[2]<< " )" << std::endl;

    return 0;
}