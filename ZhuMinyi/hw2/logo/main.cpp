#include <Eigen/Dense>
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

void savePoints(const vector<Point2f> &points, const string &filename) {
  ofstream file(filename);
  if (file.is_open()) {
    for (const auto &point : points) {
      file << point.x << " " << point.y << "\n";
    }
    file.close();
  } else {
    cout << "Error opening file for writing!" << endl;
  }
}

int main(int argc, char **argv) {
  Mat src = imread("../img.png");
  if (src.empty()) {
    cout << "Error: Could not load image!" << endl;
    return -1;
  }

  // convert to hsv
  Mat hsv;
  cvtColor(src, hsv, COLOR_BGR2HSV);

  // white area
  Mat white_mask;
  inRange(hsv, Scalar(0, 0, 200), Scalar(180, 30, 255), white_mask);

  Mat morph_result;
  morphologyEx(white_mask, morph_result, MORPH_CLOSE, Mat(), Point(-1, -1), 2);

  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;
  findContours(morph_result, contours, hierarchy, RETR_TREE,
               CHAIN_APPROX_SIMPLE);

  // store the points
  vector<Point2f> points2D;
  for (const auto &contour : contours) {
    for (const auto &point : contour) {
      points2D.push_back(point);
    }
  }

  // savePoints(points2D, "point.txt");

  // use the parameter from q2
  Matrix3d intrinsics;
  intrinsics << 400, 0, 190, 0, 400, 160, 0, 0, 1;

  Vector3d camera_position(2, 2, 2);
  Quaterniond camera_orientation(0.5, 0.5, -0.5, -0.5);

  // convert to camera coordinate
  vector<Vector3d> points_camera;
  for (const auto &point : points2D) {
    Vector3d point_camera((point.x - intrinsics(0, 2)) / intrinsics(0, 0),
                          (point.y - intrinsics(1, 2)) / intrinsics(1, 1), 1.0);
    points_camera.push_back(point_camera);
  }

  // camera to world
  vector<Vector3d> points_world;
  Matrix3d rotation_matrix = camera_orientation.toRotationMatrix();
  for (const auto &point : points_camera) {
    Vector3d point_world = rotation_matrix * point + camera_position;
    points_world.push_back(point_world);
  }

  // save the video
  VideoWriter writer("../video.mp4", VideoWriter::fourcc('M', 'P', '4', 'V'),
                     30, src.size());
  if (!writer.isOpened()) {
    cout << "Error: Could not open the video file for writing!" << endl;
    return -1;
  }

  // save each frame
  vector<Mat> frames;

  for (int frame = 0; frame < 100; ++frame) {
    Mat projected_image = Mat::zeros(src.size(), CV_8UC3);

    // simulate the motiction of camera
    camera_position += Vector3d(0.01, 0.02, -0.01);
    Quaterniond rotation_change(AngleAxisd(0.01, Vector3d::UnitY()));
    camera_orientation = camera_orientation * rotation_change;
    rotation_matrix = camera_orientation.toRotationMatrix();

    // world to camera
    for (const auto &point_world : points_world) {
      Vector3d point_camera =
          rotation_matrix.transpose() * (point_world - camera_position);

      // camera to image coordinate
      Vector3d uv = intrinsics * point_camera;
      Point2f image_point(uv(0) / uv(2), uv(1) / uv(2));

      // drraw points
      if (image_point.x >= 0 && image_point.x < src.cols &&
          image_point.y >= 0 && image_point.y < src.rows) {
        circle(projected_image, image_point, 2, Scalar(0, 255, 0), -1);
      }
    }

    writer.write(projected_image);

    frames.push_back(projected_image.clone());

    imshow("Projected Image", projected_image);
    waitKey(30); // intervation between each frame
  }

  writer.release();

  // reverse the vedio
  VideoWriter reverse_writer(
      "../result.mp4", VideoWriter::fourcc('M', 'P', '4', 'V'), 30, src.size());
  if (!reverse_writer.isOpened()) {
    cout << "Error: Could not open the reverse video file for writing!" << endl;
    return -1;
  }

  // start from the last frame
  for (auto it = frames.rbegin(); it != frames.rend(); ++it) {
    reverse_writer.write(*it);
  }

  reverse_writer.release();

  return 0;
}
