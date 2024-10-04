#include <opencv2/opencv.hpp>
#include <vector>
#include <fstream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {
    // 读取点的世界坐标
    ifstream inFile("../points.txt");
    int numPoints;
    inFile >> numPoints;
    cout<<numPoints;
    vector<Vector3d> worldPoints;
    Vector3d temppoint(0,0,0);

    int count = 0;
    for (int i = 0; i < numPoints; ++i) {
        double x,y,z;
        inFile >> x >> y >> z;
        worldPoints.push_back(Vector3d(x,y,z));

        count++;
    }
    inFile.close();

    // 相机内参矩阵
    Matrix3d K;
    K << 400, 0, 190,
         0, 400, 160,
         0, 0, 1;

    // 相机坐标和姿态四元数
    Vector3d camPos(2, 2, 2);
    Quaterniond q(-0.5, 0.5, 0.5, -0.5);
    Matrix3d R = q.toRotationMatrix();
    Matrix3d R_t = R.transpose();
    // 创建图像
    cv::Mat image = cv::Mat::zeros(1080, 1960, CV_8UC3);
    //write all the points in a file
    ofstream outFile("../points_output.txt");
    outFile<<count<<endl;


    // 投影点到图像
    for (const auto& point : worldPoints) {
        Vector3d camPoint = R_t * (point - camPos);
        Eigen::Vector3d imgPoint = K * camPoint;
        imgPoint /= imgPoint(2);

        int x = imgPoint(0);
        int y = imgPoint(1);

        // 绘制点
        cv::circle(image, cv::Point(x, y), 3, cv::Scalar(0, 0, 255), -1);
        outFile<<x<<" "<<y<<endl;
    }

    


    // 显示图像
    cv::imshow("Image", image);
    cv::imwrite("../output.jpg", image);
    cv::waitKey(0);

    return 0;
}