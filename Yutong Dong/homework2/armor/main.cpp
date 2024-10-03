#include<Eigen/Dense>
#include<Eigen/Core>
#include<eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include<opencv2/core/eigen.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include<opencv2/core/core.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include<iostream>
#include <ostream>
#include<vector>
#include<opencv2/core/mat.hpp>

int main(){
    cv::Mat camera=(cv::Mat_<double>(3,3)<<
    1.4142055480888289e+03, 0., 6.5792667877101735e+02, 0.,
       1.4137212634286254e+03, 4.0455967287503142e+02, 0., 0., 1.);

    cv::Mat distCoeffs=(cv::Mat_<double>(1,5)<<
    -1.5713532786218060e-01, 3.3883933349759310e-01,
       7.0103028435554145e-04, -2.9035486504482461e-04,
       -4.2372708010388316e-01);

    std::vector<cv::Point2f> objectPoints={
        {575.508f ,282.175f},
        {573.93f ,331.819f},
        {764.518f ,337.652f},
        {765.729f ,286.741f}
    };
    
    std::vector<cv::Point3d> PW_BIG{// 灯条坐标，单位：m
                                             {-0.115, 0.0265, 0.},
                                             {-0.115, -0.0265, 0.},
                                             {0.115, -0.0265, 0.},
                                             {0.115, 0.0265, 0.}};

    cv::Mat tvec,rvec;
    
  
    bool success=cv::solvePnP(PW_BIG,objectPoints, camera, distCoeffs, rvec, tvec);
    
    std::cout<<rvec<<" "<<tvec<<std::endl;


    //创建了从陀螺仪到相机的变换矩阵
    Eigen::Quaterniond q;
    q.x()=0.994363;
    q.y()=-0.0676645;
    q.z()=-0.00122528;
    q.w()=-0.0816168;

    Eigen::MatrixXd rveceigen_c_t=q.toRotationMatrix();
    rveceigen_c_t.transpose();
    Eigen::MatrixXd tveceigen_t_c(3,1);
    tveceigen_t_c.setZero();

    Eigen::MatrixXd T_t_c(4,4);
    T_t_c.setZero();
    T_t_c.block<3,3>(0,0)=rveceigen_c_t;
    T_t_c.block<3,1>(0,3)=tveceigen_t_c; 
    T_t_c(3,3)=1;   
    std::cout<<T_t_c<<std::endl;

    std::cout<<rvec.size<<std::endl;
    std::cout<<tvec.size<<std::endl;

    Eigen::MatrixXd rvece(3,1);
    cv::cv2eigen(rvec,rvece);
    double theta = rvece.norm();
    Eigen::Vector3d axis = rvece.normalized();

    Eigen::AngleAxisd angle_axis(theta, axis);

    Eigen::Matrix3d rveceigen_c_w = angle_axis.toRotationMatrix();

    Eigen::MatrixXd tveceigen_c_w(3,1);
    cv::cv2eigen(tvec,tveceigen_c_w);
    

    Eigen::MatrixXd T_c_w(4,4);
    T_c_w.setZero();
    T_c_w.block<3,3>(0,0)=rveceigen_c_w;
    T_c_w.block<3,1>(0,3)=tveceigen_c_w; 
    T_c_w(3,3)=1; 

    std::cout<<T_c_w<<std::endl;

    Eigen::MatrixXd T_t_w(4,4);
    T_t_w=T_t_c*T_c_w;
    std::cout<<T_t_w<<std::endl;
    
    Eigen::Vector4d p1w={-0.115, 0.0265, 0.,1.0};
    Eigen::Vector4d p1t=T_t_w*p1w;
    std::cout<<p1t<<std::endl;
    Eigen::Vector4d p2w={0.115, -0.0265, 0.,1.0};
    Eigen::Vector4d p2t=T_t_w*p2w;
    std::cout<<p2t<<std::endl;
    
    Eigen::Vector4d p3w={-0.115, -0.0265, 0.,1.};
    Eigen::Vector4d p3t=T_t_w*p3w;
    std::cout<<p3t<<std::endl;
    Eigen::Vector4d p4w={0.115, 0.0265, 0.,1.};
    Eigen::Vector4d p4t=T_t_w*p4w;
    std::cout<<p4t<<std::endl;
    

    Eigen::Vector4d center=(p1t+p2t+p3t+p4t)/4.0;

    std::cout<<center<<std::endl;

}