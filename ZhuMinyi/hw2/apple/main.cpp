#include <Eigen/Dense>
#include <bits/stdc++.h>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main() {

  Mat image = imread("../apple.png");
  if (image.empty()) {
    cerr << "Can't open the image." << endl;
    return -1;
  }

  // separate channels
  vector<Mat> channels;
  split(image, channels);
  Mat red = channels[2];
  Mat green = channels[1];

  Mat diff;
  subtract(red, green, diff);

  // imshow("Red - Green Difference", diff);
  // waitKey(0);

  // 二值化
  Mat binary;
  adaptiveThreshold(diff, binary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY,
                    11, 0);

  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;
  findContours(binary, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

  Mat result = image.clone();

  // // draw counters
  // for (size_t i = 0; i < contours.size(); i++) {
  //   drawContours(result, contours, (int)i, Scalar(0, 255, 0), 2);
  // }

  // find the largest counter
  int largest_contour_index = -1;
  double max_area = 0;
  for (size_t i = 0; i < contours.size(); i++) {
    double area = contourArea(contours[i]);
    if (area > max_area) {
      max_area = area;
      largest_contour_index = i;
    }
  }

  if (largest_contour_index == -1) {
    cerr << "No contours found." << endl;
    return -1;
  }

  drawContours(result, contours, largest_contour_index, Scalar(255, 255, 0), 1);

  // find the bounding rectangle
  Rect bounding_box = boundingRect(contours[largest_contour_index]);

  rectangle(result, bounding_box, Scalar(255, 0, 0), 1); // 使用蓝色绘制矩形

  imwrite("../detect.png", result);

  imshow("Detected Contours", result);
  waitKey(0);

  return 0;
}
