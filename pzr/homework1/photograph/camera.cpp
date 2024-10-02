#include<iostream>
#include<fstream>
#include<Eigen/Dense>
#include<Eigen/Geometry>
#include<opencv2/opencv.hpp>

using Point = Eigen::Matrix<double, 3, 1>;
using Transform = Eigen::Matrix<double, 3, 3>;

const double camera_c = 1.0;

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
        camera_rotate_ = q.toRotationMatrix().inverse();
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

void make_circle_pic(const Eigen::MatrixXd & mat){
    const int center_p = 2500;
    cv::Mat image = cv::Mat::zeros(center_p*2, center_p*2, CV_8UC3);

    
    int radius = 10; // 圆的半径
    // 定义圆的颜色（BGR格式）
    cv::Scalar color(0, 255, 0); // 绿色
    // 定义圆的厚度，-1表示实心圆
    int thickness = -1;
    // std::cout<< mat<< std::endl;
    // std::cout<< "size of mat:" << mat.cols() <<std::endl;
    for(int i=0; i< mat.cols(); i++){
        cv::Point center(mat(0, i) / mat(2,i) +center_p , mat(1, i) / mat(2,i) +center_p);
        // 绘制圆
        cv::circle(image, center, radius, color, thickness);
    }
    
    cv::imwrite("1.png" , image);
}

int main(int argc, char* argv[]){

    if(argc != 2) {
        std::cout<< "usage: "<<argv[0] << " <filepath>"<<std::endl;
        return 1;
    }
    // 读入数据
    std::fstream file(argv[1]);
    if(!file){
        std::cout<< "file "<< argv[1] << " not exist" <<std::endl;
        return 1;
    }
    int N;
    file >> N;
    Eigen::Matrix<double, 3, -1> mat(3, N);
    double tmp;
    for(int i=0; i< N ; i++){
        for(int j=0; j<3; j++){
            file >> tmp;
            mat(j, i) = tmp;
        }
    }
    
    // std::cout<< mat <<std::endl;
    Eigen::Matrix<double, 3, 4> camera_param;
    camera_param << 400., 0., 190., 0.,
                    0., 400., 160., 0.,
                    0., 0., 1., 0.;
    Point point;
    point << 2, 2, 2;
    Eigen::Quaterniond q( -0.5, 0.5, 0.5, -0.5);
    Camera camera(camera_param, point, q);

    Eigen::MatrixXd result = camera.take_picture(mat);

    make_circle_pic(result);

    return 0;
}