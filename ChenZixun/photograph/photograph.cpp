// #include <eigen3/Eigen/src/Core/Matrix.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

using namespace std;
using namespace cv;
using namespace Eigen;

// p_w -> p_c
// p_c = R * (p_w - T)
// R          T
// 0  0  -1   2
// 1  0  0    2
// 0  -1 0    2
// u = K * x
// v       y
//         z

int n;

int main() {
  ifstream Input("../points.txt");
  Input >> n;
  // cout << n << endl;
  Mat Image(1024, 1043, CV_8UC3, Scalar(0, 0, 0));
  Quaterniond q(-0.5, 0.5, 0.5, -0.5);
  Matrix3d Rot = q.toRotationMatrix();
  Matrix3d R = Rot.transpose(); // R 旋转矩阵
  Vector3d T(2, 2, 2); // T 平移向量
  Matrix3d K;
  K << 400, 0, 190,
       0, 400, 160,
       0, 0, 1; // 相机内参矩阵

  for (int i = 0; i < n; ++i) {
    double tx, ty, tz;
    Input >> tx >> ty >> tz;
    Vector3d P(tx, ty, tz);
    P = R * (P - T);
    P = K * P;
    P /= P(2);
    double u = P(0), v = P(1);
    // cout << u << " " << v << endl;
    circle(Image, Point(u, v), 1, Scalar(255, 255, 255), 1);
  }

  imshow("Image", Image);
  waitKey(0);
  return 0;
}
