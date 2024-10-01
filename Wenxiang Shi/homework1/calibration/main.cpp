#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    // Arrays to store object points for each image
    vector<vector<Point3f>> objectPoints;

    // Arrays to store image points for each image
    vector<vector<Point2f>> imagePoints;

    // Prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
    Size boardSize = Size(9, 6); // Replace with your chessboard size
    vector<Point3f> obj;
    for(int i = 0; i < boardSize.height; ++i) {
        for(int j = 0; j < boardSize.width; ++j) {
            obj.push_back(Point3f((float)j, (float)i, 0.0f));
        }
    }
    Size imageSize;
    // Load images
    for(int i = 0; i < 40; ++i) {
        string filename = format("../chess/%d.jpg", i);
        Mat image = imread(filename, IMREAD_COLOR);
        imageSize = image.size();

        if(image.empty()) {
            cerr << "Cannot load image " << filename << endl;
            return -1;
        }
        Mat grayImage;
        cvtColor(image, grayImage, COLOR_BGR2GRAY);

        vector<Point2f> corners;
        bool found = findChessboardCorners(image, boardSize, corners,
                                           CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE +
                                           CALIB_CB_FAST_CHECK);

        if(found) {
            cornerSubPix(grayImage, corners, Size(5, 5), Size(-1, -1),
                         TermCriteria(TermCriteria::EPS + TermCriteria::MAX_ITER, 30, 0.1));
            imagePoints.push_back(corners);
            objectPoints.push_back(obj);
        }
    }

    // Calibrate camera
    


    Mat cameraMatrix;
    Mat distCoeffs;
    vector<Mat> rvecs, tvecs;
    double rms = calibrateCamera(objectPoints, imagePoints, imageSize,
                                 cameraMatrix, distCoeffs, rvecs, tvecs);

    cout << "Camera Matrix: " << cameraMatrix << endl;
    cout << "Distortion Coefficients: " << distCoeffs << endl;

    return 0;
}