#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

/*标定结果在ans/ans.txt中,第一个为相机内参矩阵，第二个为相机畸变矩阵*/

int main(){
    Mat src, gray_img;
    bool flag;
    int img_count = 0;
    Size board_size(9, 6), img_size; 
    const int point_n = board_size.width * board_size.height;
    vector< Point2f > point_pix_pos_buf;
    vector< vector< Point2f >> point_pix_pos;
    for (int i = 0; i < 41; i++){
        src = imread("../chess/"+__cxx11::to_string(i).append(".jpg"));
        if (i == 0){
            img_size.width = src.cols;
            img_size.height = src.rows;
        }
        flag=findChessboardCorners(src, board_size, point_pix_pos_buf);
        if (flag && point_pix_pos_buf.size() == point_n){
            cvtColor(src, gray_img, COLOR_BGR2GRAY);
            find4QuadCornerSubpix(gray_img, point_pix_pos_buf, Size(5,5));
            point_pix_pos.push_back(point_pix_pos_buf);
            img_count++;
        }
        point_pix_pos_buf.clear();
    }

    vector< Point3f > point_grid_pos_buf;
    vector< vector< Point3f >> point_grid_pos;
    Size square_size(10,10);
    Mat camera_matrix( 3, 3, CV_32FC1, Scalar::all(0));
	Mat distort_coeffs(1,5, CV_32FC1, Scalar::all(0));
	vector<Mat> rvecs;
	vector<Mat> tvecs;

    for (int i = 0; i < img_count; i++){
        for (int j = 0; j < board_size.height; j++){
            for (int k = 0; k < board_size.width; k++){
                Point3f point;
                point.x = k * square_size.width;
                point.y = j * square_size.height;
                point.z = 0;
                point_grid_pos_buf.push_back(point);
            }
        }
        point_grid_pos.push_back(point_grid_pos_buf);
        point_grid_pos_buf.clear();
    }

    calibrateCamera(point_grid_pos, point_pix_pos, img_size, camera_matrix, distort_coeffs, rvecs, tvecs);
    cout << camera_matrix << endl << distort_coeffs << endl;
    return 0;
}