// use the points from homework1/point.txt

#include <Eigen/Dense>
#include <Eigen/src/Geometry/AngleAxis.h>
#include <Eigen/src/Geometry/Quaternion.h>
#include <fstream>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp>
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
  intrinsics_matrix << 400., 0., 190., 0., 400., 160., 0., 0., 1.;

  // inverse the matrix
  Quaterniond q(-0.5, 0.5, 0.5, -0.5);
  Matrix3d R = q.toRotationMatrix().inverse();

  Vector3d T(2, 2, 2);

  VideoWriter video("../video_2.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'),
                    30, Size(1960, 1080));

  if (!video.isOpened()) {
    cerr << "Can't open the file." << endl;
    exit(-1);
  }

  VideoWriter result("../result_2.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'),
                     30, Size(1960, 1080));

  if (!result.isOpened()) {
    cerr << "Can't open the file." << endl;
    exit(-1);
  }

  vector<Mat> result_frame;

  int frames = 100;
  for (int frame = 0; frame < frames; frame++) {
    Mat image = Mat::zeros(1080, 1960, CV_8UC3);

    vector<Point2d> image_points;
    for (const auto &point : points) {
      Vector3d cam_point = R * (point - T);
      Vector3d uv = intrinsics_matrix * cam_point;
      Point2d image_point(uv(0) / uv(2), uv(1) / uv(2));
      image_points.push_back(image_point);

      if (image_point.x >= 0 && image_point.x < image.cols &&
          image_point.y >= 0 && image_point.y < image.rows) {
        circle(image, image_point, 3, Scalar(0, 255, 0), -1);
      }
    }
    video.write(image);
    result_frame.push_back(image.clone());

    if (frame > frames / 3) {
      T += Vector3d(0.02, 0.02, -0.02);
      Quaterniond rotation_change(AngleAxisd(0.01, Vector3d::UnitY()));
      q = q * rotation_change;
      R = q.toRotationMatrix().inverse();
    }
  }
  video.release();

  for (int i = result_frame.size() - 1; i >= 0; i--) {
    result.write(result_frame[i]);
  }
  result.release();

  return 0;
}
