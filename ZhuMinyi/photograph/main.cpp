#include <Eigen/Dense>
#include <bits/stdc++.h>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <eigen3/Eigen/src/Geometry/Quaternion.h>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;
using namespace Eigen;

int main() {
  ifstream file("../points.txt");
  if (!file.is_open()) {
    cout << "Can't open the file." << endl;
    exit(-1);
  }

  int point_number;
  file >> point_number;
  vector<Vector3d> points(point_number);
  for (int i = 0; i < point_number; ++i) {
    double x, y, z;
    file >> x >> y >> z;
    points.push_back(Vector3d(x, y, z));
  }

  Matrix3d intrinsics_matrix;
  // Matrix<double, 3, 4> intrinsics_matrix;
  intrinsics_matrix << 400., 0., 190., 0., 400., 160., 0., 0., 1.;

  Quaterniond q(-0.5, 0.5, 0.5, -0.5);
  Matrix3d R = q.toRotationMatrix();
  Vector3d T(2, 2, 2);
  Matrix4d extrinsics_matrix = Matrix4d::Identity();
  // Matrix<double, 4, 4> extrinsics_matrix;
  extrinsics_matrix.block<3, 3>(0, 0) = R;
  extrinsics_matrix.block<3, 1>(0, 3) = T;
  extrinsics_matrix(3, 3) = 1;
  cout << extrinsics_matrix << endl;

  Mat image = Mat::zeros(1080, 1960, CV_8UC3);

  vector<Point2d> image_points;
  for (const auto &point : points) {
    // Vector4d Pw(point.x, point.y, point.z, 1.0);
    // Vector3d uv = intrinsics_matrix * extrinsics_matrix * Pw;
    Vector3d cam_point = R * (point - T);
    Vector3d uv = intrinsics_matrix * cam_point;
    Point2d image_point(uv(0) / uv(2), uv(1) / uv(2));
    // cout << uv(0) << " " << uv(2) << endl;
    image_points.push_back(image_point);

    if (image_point.x >= 0 && image_point.x < image.cols &&
        image_point.y >= 0 && image_point.y < image.rows) {
      circle(image, image_point, 3, Scalar(0, 255, 0), -1);
    }

    // circle(image, image_point, 3, Scalar(0, 255, 0), -1);
  }

  imshow("Photograph", image);
  waitKey(0);

  imwrite("../result.png", image);

  return 0;
}