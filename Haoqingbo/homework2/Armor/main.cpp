#include "assets/big_armor_scale.hpp"
#include <Eigen/Dense>
#include <Eigen/Core>
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <fstream>

using namespace cv;
using namespace Eigen;

int main(){
    std::vector<Point2d> PP{{575.508, 282.175},
                            {573.93, 331.819},
                            {764.518, 337.652},
                            {765.729, 286.741}}; 
    Mat camera =(Mat_<double>(3,3) << 1.4142055480888289e+03, 0., 6.5792667877101735e+02, 0.,
       1.4137212634286254e+03, 4.0455967287503142e+02, 0., 0., 1.);
    Mat distort =(Mat_<double>(1,5)<< -1.5713532786218060e-01, 3.3883933349759310e-01,
       7.0103028435554145e-04, -2.9035486504482461e-04,
       -4.2372708010388316e-01);
    Mat rvec, tvec;
    solvePnP(PW_BIG, PP, camera, distort, rvec, tvec);
    Quaterniond rotate;
    rotate.x() = 0.994363;
    rotate.y() = -0.0676645;
    rotate.z() = -0.00122528;
    rotate.w() = -0.0816168;
    Matrix3d rotmat = rotate.normalized().toRotationMatrix();
    Mat rotvec;
    eigen2cv(rotmat, rotvec);
    Mat t_p = rotvec * tvec;
    std::ofstream of("../ans/ans.txt");
    of << "装甲板中心在陀螺仪坐标系下的坐标："<< std::endl;
    of <<  t_p;
    return 0;
}