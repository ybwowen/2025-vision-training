#include <iostream>
#include <opencv2/calib3d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
  const int board_width = 9, board_height = 6;
  Size board_size(board_width, board_height);

  string folder = "../chess/";
  vector<string> images;
  glob(folder + "*.jpg", images);

  if (images.empty()) {
    cout << "Can't open the image." << endl;
    exit(-1);
  }

  vector<Point2f> corner_pos;
  vector<vector<Point2f>> corner_pos_vec;

  vector<vector<Point3f>> object_points;
  vector<Point3f> object_point;
  Size square_size(25, 25);

  for (int i = 0; i < board_height; i++) {
    for (int j = 0; j < board_width; j++) {
      object_point.push_back(
          Point3f(j * square_size.width, i * square_size.height, 0));
    }
  }

  for (size_t i = 0; i < images.size(); i++) {
    Mat image = imread(images[i]);

    if (image.empty()) {
      cout << "Failed to load image: " << images[i] << endl;
      continue;
    }

    // imshow("image", image);
    // waitKey(50);

    bool found = findChessboardCorners(image, board_size, corner_pos);

    if (found) {
      Mat gray;
      cvtColor(image, gray, COLOR_BGR2GRAY);

      find4QuadCornerSubpix(gray, corner_pos, Size(5, 5));

      corner_pos_vec.push_back(corner_pos);
      object_points.push_back(object_point);

      Mat draw_corner = image.clone();
      drawChessboardCorners(draw_corner, board_size, corner_pos, found);
      imshow("corners", draw_corner);
      waitKey(50);
    } else {
      cout << "Can't find corners in image: " << images[i] << endl;
    }

    corner_pos.clear();
  }

  Mat camera_matrix, dist_coeffs;
  vector<Mat> rvecs, tvecs;
  if (corner_pos_vec.size()) {
  }

  calibrateCamera(
      object_points, corner_pos_vec,
      Size(imread(images[0]).cols, imread(images[0]).rows), camera_matrix,
      dist_coeffs, rvecs, tvecs, 0,
      TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON));
  cout << "Camera Matrix: " << endl << camera_matrix << endl;
  cout << "Distortion Coefficients: " << endl << dist_coeffs << endl;

  return 0;
}
