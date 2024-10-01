#include <Eigen/Dense>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;
using namespace Eigen;

// 将四元数转换为旋转矩阵
Matrix3f quaternionToRotationMatrix(float qx, float qy, float qz, float qw) {
    Matrix3f R;
    R << 1 - 2 * (qy * qy + qz * qz),
         2 * (qx * qy - qz * qw),
         2 * (qx * qz + qy * qw),

         2 * (qx * qy + qz * qw),
         1 - 2 * (qx * qx + qz * qz),
         2 * (qy * qz - qx * qw),

         2 * (qx * qz - qy * qw),
         2 * (qy * qz + qx * qw),
         1 - 2 * (qx * qx + qy * qy);
    return R;
}

int main() {
    // Reading points.txt under current file
    ifstream file("../points.txt");
    if (!file.is_open()) {
        cout << "Cannot Open the File." << endl;
        exit(-1);
    }

    // Get first word as the numbet of points
    int num_points;
    file >> num_points;

    // Creating the overall vector for points.
    vector<Vector3f> worldPoints(num_points);
    for (int i = 0; i < num_points; ++i) {
        float x, y, z;
        file >> x >> y >> z;
        worldPoints[i] = Vector3f(x, y, z);
    }

    // Close the file.
    file.close();

    // Set the internal parameter matrix.
    Matrix<float,3,4> K; 
    K << 400, 0, 190,0,
        0, 400, 160,0,
        0, 0, 1,0;

    // Load the given quaternion and trandslation.
    Vector3f camera_position(2, 2, 2);  
    float qx = 0.5, qy = 0.5, qz = -0.5, qw = -0.5; 

    // Using expert funtion to turn quaternion into matrix. 
    Matrix3f R = quaternionToRotationMatrix(qx, qy, qz, qw);

    // Initialize the image.
    Mat image(1024, 1657, CV_8UC3, Scalar(0, 0, 0));  

    // Set the external parameter matrix.
    Matrix4f T = Matrix4f::Identity();
    T.block<3, 3>(0, 0) = R;  
    T.block<3, 1>(0, 3) = camera_position; 

    // Project 3D into 2D:::
    for (const auto& world_point : worldPoints) {
        // Calculation
        Matrix<float,4,1> point;
        point<<world_point[0],world_point[1],world_point[2],1;
        Vector4f camera_point = T * point;
        cout << "Rotation Matrix R:\n" << R << endl;
        cout << "Translation Matrix T:\n" << T << endl;
        cout << "Paramater Matrix K:\n" << K << endl;
        cout << "Point Matrix point:\n" << point << endl;
        cout << "Resulat 11111 Matrix camerapoint:\n" << camera_point << endl;
        Vector3f image_point = K * camera_point; 
        cout << "RResult22222 aksj:\n" << image_point << endl;
        cout<<image_point(0)<<"  "<<image_point(1)<<"   "<<image_point(2)<<endl;
        float u = image_point(0) / image_point(2);
        float v = image_point(1) / image_point(2);

        // Painting points
        if (u >= 0 && u < image.cols && v >= 0 && v < image.rows) {
            circle(image, Point2f(u, v), 3, Scalar(0, 255, 0), -1);  // 在图像中画出点
        }
    }

    // Dispict the image
    imshow("Projected Points", image);
    waitKey(0);

    // Keep the image
    imwrite("projected_image.png", image);

    return 0;
}
