//
// Created by cwlm on 2024/10/3.
//
#include <iostream>
#include <fstream>
#include <vector>

#include "Kalman.h"

Kalman<1, 2> kalman;

Eigen::Matrix<double, 2, 2> A; // 状态转移矩阵
Eigen::Matrix<double, 1, 2> H; // 观测矩阵
Eigen::Matrix<double, 2, 2> R; // 过程噪声协方差
Eigen::Matrix<double, 1, 1> Q; // 测量噪声协方差
Eigen::Matrix<double, 2, 1> init_state; // 初始状态 [位置, 速度]

void initialize_kalman() {
    // 初始化矩阵
    A <<
        1, 1,
        0, 1;
    H <<
        1, 0;
    R <<
        1e-2, 0,
        0, 1e-2;
    Q <<
        0.03;

    init_state << 7, 0;

    double t = 0.0;
    kalman.reset(A, H, R, Q, init_state, t);
}

int main() {
    // 读取dollar.txt
    std::ifstream fin("dollar.txt");
    if (!fin) {
        std::cerr << "Cannot open file: dollar.txt" << std::endl;
        return 1;
    }

    std::vector<double> rates;
    while (fin) {
        double rate;
        fin >> rate;
        rates.push_back(rate);
    }
    fin.close();

    // 初始化 Kalman 滤波器
    initialize_kalman();

    // 使用 Kalman 滤波器处理数据
    std::ofstream fout("filtered_dollar.txt");
    double t = 0.0;
    for (auto& rate : rates) {
        Eigen::Matrix<double, 1, 1> z_k;
        z_k << rate;
        Eigen::Matrix<double, 2, 1> x_k = kalman.update(z_k, t);
        fout << x_k(0, 0) << std::endl; // 位置
        t += 0.01; // 时间间隔 10ms
    }
    fout.close();

    return 0;
}
