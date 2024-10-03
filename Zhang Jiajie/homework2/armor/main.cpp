#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
#include<Eigen/Dense>
#include <eigen3/Eigen/src/Geometry/Quaternion.h>

using namespace std;
using namespace cv;
using namespace Eigen;

int main(){
    Quaterniond imu(-0.0816168, 0.994363, -0.0676645, -0.00122528);
    Matrix3d rot = imu.normalized().toRotationMatrix();
    vector<Point2d> armor{{575.508, 282.175},
                          {573.93, 331.819},
                          {764.518, 337.652},
                          {765.729, 286.741}};
    vector<Point3d> PW_BIG{{-0.115, 0.0265, 0.},
                           {-0.115, -0.0265, 0.},
                           {0.115, -0.0265, 0.},
                           {0.115, 0.0265, 0.}};
    Mat f_mat = (Mat_<double>(3, 3) << 1.4142055480888289e+03, 0., 6.5792667877101735e+02,
                                                  0., 1.4137212634286254e+03, 4.0455967287503142e+02,
                                                  0., 0., 1.);
    
    Mat c_mat = (Mat_<double>(1, 5) << -1.5713532786218060e-01, 3.3883933349759310e-01,
                                                  7.0103028435554145e-04, -2.9035486504482461e-04,
                                                  -4.2372708010388316e-01);
    Mat rvec, tvec;
    solvePnP(PW_BIG, armor, f_mat, c_mat, rvec, tvec);
    cout<<tvec<<endl;
    return 0;
}