#include "assets/big_armor_scale.hpp"
#include <Eigen/Dense>
#include <bits/stdc++.h>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <eigen3/Eigen/src/Geometry/Quaternion.h>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/core/persistence.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;
using namespace Eigen;

int main() {
  Mat camera_matrix;
  Mat distort_matrix;

  FileStorage reader("../assets/f_mat_and_c_mat.yml", FileStorage::READ);
  reader["F"] >> camera_matrix;
  reader["C"] >> distort_matrix;

  vector<Point3d> object_points = PW_BIG;

  Quaterniond q(-0.0816168, 0.994363, -0.0676645, -0.00122528);
  Matrix3d R_camera_to_world = q.toRotationMatrix();

  vector<Point2d> image_points;
  image_points.push_back(Point2d(575.508, 282.175));
  image_points.push_back(Point2d(573.93, 331.819));
  image_points.push_back(Point2d(764.518, 337.652));
  image_points.push_back(Point2d(765.729, 286.741));

  Mat rvec, tvec;
  solvePnP(PW_BIG, image_points, camera_matrix, distort_matrix, rvec, tvec);

  // Convert rvec to rotation matrix
  Mat rotation_matrix;
  Rodrigues(rvec, rotation_matrix);

  Point3d center_point(0, 0, 0);
  for (int i = 0; i < 4; i++) {
    center_point += PW_BIG[i];
  }
  center_point.x /= 4;
  center_point.y /= 4;
  center_point.z /= 4;

  Mat center_point_cam =
      (Mat_<double>(3, 1) << center_point.x, center_point.y, center_point.z);

  // Apply the rotation and translation to transform the center point to the
  // camera coordinate system
  Mat center_point_cam_transformed = rotation_matrix * center_point_cam + tvec;

  Vector3d center_cam_eigen(center_point_cam_transformed.at<double>(0),
                            center_point_cam_transformed.at<double>(1),
                            center_point_cam_transformed.at<double>(2));

  // Convert the center point from the camera coordinate system to the world
  // coordinate system
  Vector3d center_world = R_camera_to_world * center_cam_eigen;

  cout << "Armor center in world coordinates: " << center_world.transpose()
       << endl;

  return 0;
}