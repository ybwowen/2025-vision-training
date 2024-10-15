#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <vector>

using namespace std;
using namespace cv;

Mat InputImage, Image;
int hsvH, hsvS, hsvV;

// 19 157 100

// void DetectExtract(int, void*) {
//   Mat P1, P2;
//   inRange(Image, Scalar(0, hsvS, hsvV), Scalar(hsvH, 255, 255), P1);
//   inRange(Image, Scalar(156, hsvS, hsvV), Scalar(180, 255, 255), P2);
//   Mat OnesMat = Mat::ones(Size(Image.cols, Image.rows), CV_8UC1);
//   Mat Detect = 255 * (OnesMat - (OnesMat - P1 / 255).mul(OnesMat - P2 / 255));
//   imshow("AppleDetect", Detect);
// }

int main() {
  InputImage = imread("../apple.png");
  cvtColor(InputImage, Image, COLOR_BGR2HSV);
  // namedWindow("AppleDetect");
  // createTrackbar("H", "AppleDetect", &hsvH, 155, DetectExtract);

  // DetectExtract(0, nullptr);

  // createTrackbar("S", "AppleDetect", &hsvS, 255, DetectExtract);

  // DetectExtract(0, nullptr);

  // createTrackbar("V", "AppleDetect", &hsvV, 255, DetectExtract);

  // DetectExtract(0, nullptr);

  Mat P1, P2;
  inRange(Image, Scalar(0, 157, 100), Scalar(19, 255, 255), P1);
  inRange(Image, Scalar(156, 157, 100), Scalar(180, 255, 255), P2);
  Mat OnesMat = Mat::ones(Size(Image.cols, Image.rows), CV_8UC1);
  Mat Detect = 255 * (OnesMat - (OnesMat - P1 / 255).mul(OnesMat - P2 / 255));

  morphologyEx(Detect, Detect, MORPH_OPEN, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

  vector<vector<Point>> Contours;
  findContours(Detect, Contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

  Mat ContourImage = InputImage.clone();
  drawContours(ContourImage, Contours, -1, Scalar(255, 255, 255), 2);

  // imshow("Contours", ContourImage);

  imwrite("../appleres.png", ContourImage);

  waitKey(0);

  return 0;
}
