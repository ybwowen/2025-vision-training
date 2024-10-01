#include <iostream>
#include <opencv4/opencv2/core/base.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

vector<Point2f> Corners;
vector<vector<Point2f>> ImagePoints;
vector<Point3f> obj;
vector<vector<Point3f>> ObjectPoints;
Mat CameraMatrix, DistCoeffs;
vector<Mat> rvecs, tvecs;

int main() {

  Size ImageSize;

  for (int i = 0; i < 41; ++i) {
    string BoardPath = "../chess/" + to_string(i) + ".jpg";
    // cout << BoardPath << endl;
    Mat INmage = imread(BoardPath);
    Mat Image;
    cvtColor(INmage, Image, COLOR_BGR2GRAY);
    ImageSize = Image.size();
    // if (Image.empty()) {
    //   cerr << "Error!" << endl;
    // }
    // imshow("Image", Image);
    // waitKey(0);

    findChessboardCorners(Image, Size(9, 6), Corners);
    find4QuadCornerSubpix(Image, Corners, Size(11, 7));
    ImagePoints.push_back(Corners); ObjectPoints.push_back(obj);
  }

  double SquareSize = 0.1;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 6; ++j) {
      obj.push_back(Point3f(j * SquareSize, i * SquareSize, 0));
    }
  }

  ObjectPoints.push_back(obj);
  calibrateCamera(ObjectPoints, ImagePoints, ImageSize, CameraMatrix, DistCoeffs, rvecs, tvecs);

  cout <<  CameraMatrix << endl;
  cout << DistCoeffs << endl;

  return 0;
}
