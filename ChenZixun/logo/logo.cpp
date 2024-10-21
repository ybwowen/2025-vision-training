#include <iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace std;
using namespace cv;
using namespace Eigen;

int n;
vector<Vector3d> Points;

int main() {
  ifstream Input("../points.txt");
  Input >> n;
  // cout << n << endl;
  
  for (int i = 0; i < n; ++i) {
    double tx, ty, tz;
    Input >> tx >> ty >> tz;
    Vector3d P(tx, ty, tz);
    Points.push_back(P);
  }

  Vector3d T(2, 2, 2); // T 平移向量
  Matrix3d K;
  K << 400, 0, 190,
      0, 400, 160,
      0, 0, 1; // 相机内参矩阵

  VideoWriter Vout("../Logo.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 30, Size(1024, 1040));

  Quaterniond q0(1, 0, 0, 0), q1(-0.5, 0.5, 0.5, -0.5);

  for (double t = 0; t <= 1; t += 0.1) {
    Quaterniond q = q0.slerp(t, q1);
    Matrix3d Rot = q.toRotationMatrix();
    Matrix3d R = Rot.transpose(); // R 旋转矩阵

    Mat Image = Mat::zeros(1024, 1040, CV_8UC3);
    for (Vector3d Poi : Points) {
      Vector3d P = Poi;
      P = R * (P - T);
      P = K * P;
      P /= P(2);
      double u = P(0), v = P(1);
      circle(Image, Point(u, v), 1, Scalar(255, 255, 255), 1);
    }
    // Mat ImageColor;
    // cvtColor(Image, ImageColor, COLOR_GRAY2BGR);
    // Images.push_back(ImageColor);
    Vout.write(Image);
    // imshow("Image", Image);
    // waitKey(0);
  }

  Vout.release();
  // destroyAllWindows();

  return 0;
}
