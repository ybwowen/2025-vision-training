#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    const int board_width = 9, board_height = 6;
    Size board_size(board_width, board_height);

    vector<Point2f> corner_pos;
    vector<vector<Point2f>> corner_pos_vec;
    Size image_size;
    vector<vector<Point3f>> object_points;
    vector<Point3f> object_point;

    Mat camera_matrix, dist_coeffs; // OUTPUT
    vector<Mat> rvecs, tvecs;  //OUTPUT

    for (int i = 0; i < board_height; i++) {
        for (int j = 0; j < board_width; j++) {
            object_point.push_back(Point3f(0.1*j, 0.1*i, 0));
        }
    }

    int i=0;
    while(true){
        Mat image=imread("../chess/"+to_string(i)+".jpg"); // Every round reload the image.
        if (image.empty()){ // If not exist, exit the loop.
            cout<< "It's the end or failure loading the image." <<endl;
            break;
        }
        else{ // if exist
            if (i==0){ // store the size of the image
                image_size.width=image.cols;
                image_size.height=image.rows;
            }

            bool found = findChessboardCorners(image, board_size, corner_pos);

            if (found){
                Mat gray_image;
                cvtColor(image, gray_image, COLOR_BGR2GRAY);
                find4QuadCornerSubpix(gray_image, corner_pos, Size(5, 5));
                corner_pos_vec.push_back(corner_pos);
                corner_pos.clear();
                object_points.push_back(object_point);
            }
        }
        i++;
    }
    double rms_error=calibrateCamera(object_points, corner_pos_vec, image_size, camera_matrix, dist_coeffs, rvecs, tvecs);
    cout << "Re-projection error: " << rms_error << endl;
    cout << "Camera Matrix: " << endl << camera_matrix << endl;
    cout << "Distortion Coefficients: " << endl << dist_coeffs << endl;
}