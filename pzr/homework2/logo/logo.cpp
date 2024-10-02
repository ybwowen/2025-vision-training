#include<iostream>
#include<fstream>
#include<vector>
#include<random>
#include<Eigen/Dense>
#include<Eigen/Geometry>
#include<opencv2/opencv.hpp>
#include<cmath>

using Point = Eigen::Matrix<double, 3, 1>;
using Transform = Eigen::Matrix<double, 3, 3>;

const double camera_c = 1.0;
const int frames = 90;
const double z_max = 1000;
const int frame_x = 2000;
const int frame_y = 2000;

class Camera
{
private:
    Eigen::Matrix<double, 3, 4> camera_param_;
    Point camera_point_;
    Transform camera_rotate_;

public:
    Camera(Eigen::Matrix<double, 3, 4> _camera_param, Point _camera_point, Eigen::Quaterniond q):
    camera_param_(_camera_param), camera_point_ (_camera_point){
        q.normalize();
        camera_rotate_ = q.toRotationMatrix();
    }

    void change_pos(Point _camera_point, Eigen::Quaterniond q){
        camera_point_ = _camera_point;
        camera_rotate_ = q.toRotationMatrix();
    }

    void change_pos(Point _camera_point, Eigen::Vector3d rotate_vec){
        camera_point_ = _camera_point;
        Eigen::AngleAxisd rotate_aa(rotate_vec.norm(), rotate_vec.normalized());
        camera_rotate_ = rotate_aa.toRotationMatrix();
    }

    Eigen::MatrixXd take_picture(Eigen::MatrixXd oirgin_points){
        // 变换到相机坐标系
        Eigen::MatrixXd A = (oirgin_points.colwise() - camera_point_);
        // std::cout<< A << std::endl;
        A = camera_rotate_* A;
        // 转为齐次坐标
        A.conservativeResize(A.rows() + 1, A.cols());
        A.row(A.rows() - 1).setConstant(1);
        // 计算成像平面上的齐次坐标
        A = camera_param_ * A;
        return A;
    }
};

void make_circle_pic(const Eigen::MatrixXd & mat, cv::Mat data_buf, int ind){
    data_buf = cv::Mat::zeros(frame_x, frame_y, CV_8UC3);

    int radius = 3; // 圆的半径
    // 定义圆的颜色（BGR格式）
    cv::Scalar color(0, 255, 0); // 绿色
    // 定义圆的厚度，-1表示实心圆
    int thickness = -1;
    // std::cout<< mat<< std::endl;
    // std::cout<< "size of mat:" << mat.cols() <<std::endl;
    for(int i=0; i< mat.cols(); i++){
        cv::Point center(mat(0, i) / mat(2,i) +frame_x/2 , mat(1, i) / mat(2,i) +frame_y/2);
        // 绘制圆
        cv::circle(data_buf, center, radius, color, thickness);
    }
    
    cv::imwrite(std::to_string(ind)+".png" ,data_buf);
}

int main(int argc, char* argv[]){
    cv::Mat image = cv::imread("../img.png", cv::IMREAD_COLOR);
    std::cout<< "image size: "<< image.size() << std::endl;

    int x_max = image.cols;
    int y_max = image.rows;
    if (image.empty()) {
        std::cout << "Could not read the image" << std::endl;
        return 1;
    }

    std::vector<cv::Point> whitePoints;
    // 遍历图片中的每个像素
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            cv::Vec3b pixel = image.at<cv::Vec3b>(y, x);
            int threshold = 254; // 可以根据需要调整阈值
            // 检查像素是否为白色
            if (pixel[0] > threshold && pixel[1] > threshold && pixel[2] > threshold) {
                whitePoints.push_back(cv::Point(x, y));
            }
        }
    }

    std::cout << "white points: "<< whitePoints.size() << std::endl;
    std::random_device rd;  // 用于获取种子
    std::mt19937 gen(rd()); // 以随机设备生成的种子初始化 Mersenne Twister 生成器
    int min = -500; // 范围的最小值
    int max = 500; // 范围的最大值
    std::uniform_int_distribution<> distrib(min, max);

    Eigen::Matrix<double, 3, -1> mat(3, whitePoints.size());
    for(int i=0; i< whitePoints.size() ; i++){
            mat(0, i) = whitePoints[i].x;
            mat(1, i) = whitePoints[i].y;
            mat(2, i) = distrib(gen);
    }
    
    // std::cout<< mat <<std::endl;
    Eigen::Matrix<double, 3, 4> camera_param;
    camera_param << z_max, 0., 0, 0.,
                    0., z_max, 0, 0.,
                    0., 0., -1., 0.;
    Point point;
    point << x_max/2 , y_max/2 , z_max;
    Eigen::Quaterniond q(1, 0, 0, 0);
    Camera camera(camera_param, point, q);

    Eigen::MatrixXd result;
    double per_theta = M_PI/ 2.0 /frames;
    double now_theta;
    
    // 视频文件名
    std::string videoFileName = "output.avi";

    // 视频编码器参数
    int fourcc = cv::VideoWriter::fourcc('M', 'J', 'P', 'G'); // 编码器格式
    double fps = 30.0; // 帧率
    cv::Size frameSize = cv::Size(frame_x, frame_y); // 帧大小，根据实际图片大小调整

    // 创建视频编码器
    cv::VideoWriter videoWriter(videoFileName, fourcc, fps, frameSize);

    if (!videoWriter.isOpened()) {
        std::cerr << "无法打开视频文件" << std::endl;
        return -1;
    }
    Eigen::Vector3d base_rotate(-1, 0 , 0);
    base_rotate.normalize();
    cv::Mat data_buf = cv::Mat::zeros(frame_x, frame_y, CV_8UC3);
    for(int i=0; i <= frames ; i++){
        now_theta = per_theta*i;
        point(0) = x_max/2*(1 - cos(now_theta));
        point(1) = y_max/2*(1 - cos(now_theta));
        point(2) = z_max*sin(now_theta);
        camera.change_pos(point, base_rotate * (M_PI/2 - now_theta));
        result = camera.take_picture(mat);
        make_circle_pic(result, data_buf, i);
        videoWriter.write(data_buf);
        std::cout<< "pic "<< i <<" / "<< frames <<"finished" <<std::endl;
    }

    // 视频最后停留
    for(int i=0 ; i<10 ; i++ ){
        videoWriter.write(data_buf);
    }

    videoWriter.release();

    return 0;
}