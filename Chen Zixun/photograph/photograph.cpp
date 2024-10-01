#include <iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

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
  Mat Image(1024, 2000, CV_8UC3, Scalar(0, 0, 0));
  Mat Rot = (Mat_<double>(3, 3) << 0, 0, -1, 1, 0, 0, 0, -1, 0), T = (Mat_<double>(3, 1) << 2, 2, 2); // Rot 旋转矩阵  T 平移向量
  Mat K = (Mat_<double>(3, 3) << 400, 0, 190, 0, 400, 160, 0, 0, 1); // 相机内参矩阵
  for (int i = 0; i < n; ++i) {
    double x, y, z;
    Input >> x >> y >> z;
    Mat P = (Mat_<double>(3, 1) << x, y, z);
    P = Rot * (P - T);
    P = K * P;
    double u = P.at<double>(0, 0), v = P.at<double>(1, 0);
    // cout << u << " " << v << endl;
    circle(Image, Point(u, v), 1, Scalar(255, 255, 255), 1);
  }
  imshow("Image", Image);
  waitKey(0);
  return 0;
}
