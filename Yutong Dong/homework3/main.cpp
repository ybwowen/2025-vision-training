#include "kalman/kalman.h"
#include "kalman/AdaptiveEKF.h"
#include <eigen3/Eigen/src/Core/Matrix.h>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>



int main(){
    std::string filename="../dollar.txt";
    std::vector<double>data;
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr<<"failed to open the file"<<std::endl;
        return -1;
    }

    std::string line;
    double value;

    while(std::getline(file,line)){
        std::istringstream iss(line);
        if(!(iss>>value)){
            std::cerr<<"failed to get the value from the line"<<std::endl;
            return -1;
        }
        //std::cout<<value<<"nihao"<<std::endl;
        
        data.push_back(value);

    }

    file.close();

    int i=data.size();//一共有30个数据 
    Kalman<1, 2>::Matrix_xxd A;  // 状态转移矩阵 (2x2)
    Kalman<1, 2>::Matrix_zxd H;  // 观测矩阵 (1x2)
    Kalman<1, 2>::Matrix_xxd R;  // 过程噪声协方差矩阵 (2x2)
    Kalman<1, 2>::Matrix_zzd Q;  // 测量噪声协方差矩阵 (1x1)
    Kalman<1, 2>::Matrix_x1d init_state; // 初始状态 (2x1)

    double delta_t=1.0;//表示传感器获得的距离有10ms的延迟

    // 初始化设置各个矩阵的值
    A(0, 0) = 1.0; A(0, 1) = delta_t;  // 状态转移矩阵
    A(1, 0) = 0.0; A(1, 1) = 1.0;

    H(0, 0) = 1.0; H(0, 1) = 0.0;  // 观测矩阵，只观测位置

    R(0, 0) = 1; R(1, 1) = 1;  // 过程噪声
    R(1,0)=0.0;     R(0,1)=0.0;

    Q(0, 0) = 0.1;  // 测量噪声

    init_state(0, 0) = data[0];  // 初始位置
    init_state(1, 0) = 0;  // 初始速度

    static Kalman<1,2> filter(A, H, R, Q, init_state, 0);

    Kalman<1,2> ::Matrix_x1d filtered_value; //滤波之后输出的
    for(int j=1;j<i;j++){//一共循环29次
        Kalman<1, 2>::Matrix_z1d sensor_data_matrix;
        sensor_data_matrix(0, 0) = data[j];
        filtered_value = filter.update(sensor_data_matrix, j);
        std::cout<<filtered_value(1,0)<<std::endl;
        // std::cout<<filtered_value(0,0)<<std::endl;

    }

    double v=filtered_value(1,0);
    std::cout<<v;

}