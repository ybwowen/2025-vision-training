// 不知为何生成视频文件一直无法打开，而且每一帧的图像都没有问题，过两天再来调。一直看不到最终效果，我想的是有顺序地改变四元数来调整相机位姿，不太确定对不对，没办法看到最终效果
#include <iostream>
#include <vector>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

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

  VideoWriter Logo("../LogoGif.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(1024, 1040));

  for (int i = 10; i >= 0; --i) {
    double t = (double)i;
    Quaterniond q(-0.5 - t, 0.5 - t, 0.5 - t, -0.5 - t);
    Matrix3d Rot = q.toRotationMatrix();
    Matrix3d R = Rot.transpose(); // R 旋转矩阵

    Mat Image = Mat::zeros(1024, 1040, CV_8UC3);
    for (Vector3d Poi : Points) {
      Vector3d P = Poi;
      P = R * (P - T);
      P = K * P;
      P /= P(2);
      double u = P(0), v = P(1);
      circle(Image, Point(u, v), 1, Scalar(255, 0, 0), 1);
    }
    // Mat ImageColor;
    // cvtColor(Image, ImageColor, COLOR_GRAY2BGR);
    // Images.push_back(ImageColor);
    Logo.write(Image);
    // if (qi == -1.5 && qj == 0.5 && qk == 0.5 && qw == -0.5) {
      // imshow("Image", Image);
      // waitKey(0);
    // }
  }

  Logo.release();
  destroyAllWindows();

  return 0;
}
