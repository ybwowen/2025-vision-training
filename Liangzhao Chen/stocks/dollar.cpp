#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

// 卡尔曼滤波器类
class KalmanFilter {
public:
    // 状态向量 x、协方差矩阵 P、观测矩阵 H
    VectorXd x;
    MatrixXd P, H;

    // 构造函数
    KalmanFilter(VectorXd x0, MatrixXd P0, MatrixXd H0) {
        x = x0;
        P = P0;
        H = H0;
    }

    // 预测步骤
    void predict(const MatrixXd& F, const MatrixXd& Q) {
        x = F * x;                     // 预测状态
        P = F * P * F.transpose() + Q; // 预测协方差
    }

    // 更新步骤
    void update(const VectorXd& Z, const MatrixXd& R) {
        VectorXd y = Z - H * x;  // 观测残差
        MatrixXd S = H * P * H.transpose() + R;  // 残差协方差
        MatrixXd K = P * H.transpose() * S.inverse();  // 卡尔曼增益
        x = x + K * y;  // 更新状态
        P = (MatrixXd::Identity(P.rows(), P.cols()) - K * H) * P;  // 更新协方差
    }
};

// 读取文件数据
vector<double> readDollarData(const string& filename) {
    vector<double> data;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
        return data;
    }
    double value;
    while (file >> value) {
        data.push_back(value);
    }
    file.close();
    return data;
}

int main() {
    // 读取汇率数据
    vector<double> measurements = readDollarData("../dollar.txt");

    if (measurements.empty()) {
        cerr << "没有读取到数据" << endl;
        return -1;
    }

    // 状态向量 x0, 协方差矩阵 P0, 观测矩阵 H
    VectorXd x0(2);  // 初始状态 (位置和速度)
    x0 << measurements[0], 0;  // 初始位置为第一条汇率数据，速度初始为0

    MatrixXd P0 = MatrixXd::Identity(2, 2) * 1e6;  // 初始协方差
    MatrixXd H0(1, 2);  // 观测矩阵
    H0 << 1, 0;  // 仅观测位置

    // 创建卡尔曼滤波器对象
    KalmanFilter kf(x0, P0, H0);

    // 定义状态转移矩阵 F、过程噪声矩阵 Q、观测噪声矩阵 R
    double dt = 1.0;  // 时间步长
    MatrixXd F(2, 2);  // 状态转移矩阵
    F << 1, dt,
         0, 1;  // 位置和速度的状态转移矩阵

    MatrixXd Q(2, 2);  // 过程噪声协方差矩阵
    Q << 0.1, 0,
         0, 10;

    MatrixXd R(1, 1);  // 观测噪声协方差矩阵
    R << 50;

    // 存储卡尔曼滤波器的预测结果
    vector<double> predicted_positions;

    // 卡尔曼滤波器进行当前数据的预测和更新
    for (size_t i = 0; i < measurements.size(); ++i) {
        // 预测步骤
        kf.predict(F, Q);

        // 创建观测值向量
        VectorXd Z(1);
        Z << measurements[i];

        // 更新步骤
        kf.update(Z, R);

        // 存储预测的当前位置
        predicted_positions.push_back(kf.x(0));

        // 输出当前状态
        // cout << "Time step " << i << " - Estimated position: " << kf.x(0) << ", velocity: " << kf.x(1) << endl;
    }

    // 预测未来 10 天
    cout << "\n预测未来 10 天的汇率：" << endl;
    for (int i = 0; i < 10; ++i) {
        // 仅进行预测步骤，不再有新的观测数据
        kf.predict(F, Q);

        // 存储未来 10 天的预测位置
        predicted_positions.push_back(kf.x(0));

        // 输出预测结果
        cout << "未来第 " << i + 1 << " 天预测的汇率: " << kf.x(0) << endl;
    }

    return 0;
}
