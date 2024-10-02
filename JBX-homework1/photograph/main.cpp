#include <Eigen/Geometry> // 包含Eigen库中的几何模块
#include <opencv2/opencv.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <Eigen/Dense>

Eigen::Matrix3d inverseMatrix(const Eigen::Matrix3d& matrix) {
    // 计算矩阵的逆
    Eigen::Matrix3d inverse = matrix.inverse();
    return inverse;
}


Eigen::Matrix3d quaternionToRotationMatrix(const Eigen::Quaterniond& quaternion) {
    // 将四元数转换为旋转矩阵
    Eigen::Matrix3d rotation_matrix = quaternion.toRotationMatrix();
    return rotation_matrix;
}

std::vector<Eigen::Vector3d> readPointsFromFile(const std::string& filename) {
    std::vector<Eigen::Vector3d> points_eigen;
    std::vector<cv::Point3f> points;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open the file.");
    }

    while (getline(file, line)) {
        std::istringstream iss(line);
        float x, y, z;
        if (!(iss >> x >> y >> z)) {
            // 出错处理：跳过不能正确读取的行
            continue;
        }
        points.emplace_back(x, y, z);
    }

    file.close();
    for (int i=0; i<points.size(); i++){
        Eigen::Vector3d vector(points[i].x, points[i].y, points[i].z);
        points_eigen.push_back(vector);
    }
    return points_eigen;
}

int main() {
    std::vector<Eigen::Vector3d> Points = readPointsFromFile("/home/andy/桌面/2025-vision-homework/JBX-homework1/photograph/points.txt");
    Eigen::Matrix<double, 3, 3> cam_matrix;
    cam_matrix << 400., 0., 190.,
                0., 400., 160.,
                0., 0., 1.;
    Eigen::Vector3d trans_inverse(-2, -2, -2);
    Eigen::Quaterniond quaternion = Eigen::Quaterniond(-0.5, 0.5, 0.5, -0.5);
    Eigen::Matrix3d rotation = quaternionToRotationMatrix(quaternion);
    Eigen::Matrix3d rot_inverse = inverseMatrix(rotation);
    std::vector<Eigen::Vector3d> Points_cam;
    for (int i=0; i<Points.size(); i++){
        Eigen::Vector3d point=Points[i];
        point+=trans_inverse;
        point=rot_inverse*point;
        double z_c = point(2);
        point=point/z_c;
        point=cam_matrix*point;
        Points_cam.push_back(point);
    }
    std::vector<cv::Point2f> Points_cam_cv;
    for (int i=0; i<Points_cam.size(); i++){
        if (0<Points_cam[i](0)<1600 && 0<Points_cam[i](1)<1600){
            cv::Point2f point;
            point.x=Points_cam[i](0);
            point.y=Points_cam[i](1);
            Points_cam_cv.push_back(point);
        }
    }


    for (int i=0; i<100; i++){
        std::cout<<Points_cam[i](0)<<" "<<Points_cam[i](1)<<" "<<Points_cam[i](2)<<std::endl;
    }

    cv::Mat image(1600, 1600, CV_8UC3, cv::Scalar(0, 0, 0));
    
    for (const auto& point : Points_cam_cv) {
        cv::circle(image, point, 2, cv::Scalar(0, 0, 255), -1);
    }

    cv::imshow("Points", image);
    cv::imwrite("/home/andy/桌面/2025-vision-homework/photograph/Jiaoloong.png", image);
    cv::waitKey(0);

    // std::cout<<quaternion<<std::endl;
    // std::cout<<rot_inverse<<std::endl;
    // std::cout<<rot_inverse*Points[0]<<std::endl;
    // std::cout<<rot_inv_cv<<std::endl;



    return 0;
}