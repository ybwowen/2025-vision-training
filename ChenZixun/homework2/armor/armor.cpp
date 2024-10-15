#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include "assets/big_armor_scale.hpp"

using namespace std;
using namespace cv;
using namespace Eigen;

int main() {

  Filestorage Fm("../assets/f_mat_and_c_mat.yml", Filestorage::READ);
  Mat CameraMatrix, DistortMatrix;
  Fm["F"] >> CameraMatrix; Fm["C"] >> DistortMatrix;

  vector<Point2d> ArmorPoints = {{575.508, 282.175}, {573.93, 331.819}
  , {764.518, 337.652}, {765.729, 286.741}};

  Mat rvec, tvec;
  solvePnP(PW_BIG, ArmorPoints, CameraMatrix, DistortMatrix, rvec, tvec);

  Vector3d ArmorCenter;
  cv2eigen(tvec, ArmorCenter);

  Quaterniond q(-0.0816168, 0.994363, -0.0676645, -0.00122528);
  ArmorCenter = q * ArmorCenter;

  cout << ArmorCenter << endl;

  return 0;
}
