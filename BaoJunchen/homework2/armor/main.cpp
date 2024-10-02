#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 装甲板中心即世界坐标系原点
    vector<cv::Point3d> objectPoints = {
        {-0.115, 0.0265, 0.},
        {-0.115, -0.0265, 0.},
        {0.115, -0.0265, 0.},
        {0.115, 0.0265, 0.}
    };

    Mat cameraMatrix = (Mat_<double>(3, 3) << 1.4142055480888289e+03,0,6.5792667877101735e+02, 0.,
       1.4137212634286254e+03, 4.0455967287503142e+02, 0., 0., 1. );
    Mat distCoeffs = (Mat_<double>(1, 5)<<-1.5713532786218060e-01, 3.3883933349759310e-01,
       7.0103028435554145e-04, -2.9035486504482461e-04,-4.2372708010388316e-01 ); 

    Eigen::Quaterniond ROTq_CAMtoWRD(-0.0816168, 0.994363, -0.0676645, -0.00122528);
    Eigen::Matrix3d ROTmat_CAMtoWRD = ROTq_CAMtoWRD.toRotationMatrix();

    vector<cv::Point2d> imagePoints = {
        {575.508, 282.175},
        {573.93, 331.819},
        {764.518, 337.652},
        {765.729, 286.741}
    };

    Mat rvec, tvec;
    solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec);

    //tvec代表世界坐标系原点在相机坐标系下的坐标
    Eigen::Vector3d center_world(tvec.at<double>(0), tvec.at<double>(1), tvec.at<double>(2));
    Eigen::Vector3d center_imu=ROTmat_CAMtoWRD*center_world;
    
    cout<<center_imu[0]<<endl;
    cout<<center_imu[1]<<endl;
    cout<<center_imu[2]<<endl;

    return 0;
}