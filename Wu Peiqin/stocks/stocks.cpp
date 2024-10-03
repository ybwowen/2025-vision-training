#include <iostream>
#include <vector>
#include <fstream>
#include <Eigen/Dense>

// 读取数据
std::vector<double> readData(const std::string& filename) {
    std::vector<double> data;
    std::ifstream file(filename);
    double value;
    while (file >> value) {
        data.push_back(value);
    }
    return data;
}

// 卡尔曼滤波器类
class Kalman {
public:
    Kalman(const Eigen::Vector2d& x0, const Eigen::Matrix2d& P0, const Eigen::RowVector2d& H)
        : x(x0), P(P0), H(H) {}

    void predict(const Eigen::Matrix2d& F, const Eigen::Matrix2d& Q) {
        x = F * x;
        P = F * P * F.transpose() + Q;
    }

    void update(const Eigen::VectorXd& z, const Eigen::MatrixXd& R) {
        Eigen::VectorXd y = z - H * x; 
        Eigen::MatrixXd S = H * P * H.transpose() + R;  
        Eigen::VectorXd K = P * H.transpose() * S.inverse();  
        x = x + K * y;
        P = (Eigen::Matrix2d::Identity() - K * H) * P;
    }

    Eigen::Vector2d getState() const {
        return x;
    }

private:
    Eigen::Vector2d x;  // 状态向量
    Eigen::Matrix2d P;  // 协方差矩阵
    Eigen::RowVector2d H;  // 观测矩阵
};

int main() {
    // 读取数据
    std::vector<double> data = readData("../dollar.txt");

    // 初始化卡尔曼滤波器
    Eigen::Vector2d x0(0, 0);  
    Eigen::Matrix2d P0 = Eigen::Matrix2d::Identity()*1e6;  
    Eigen::RowVector2d H;
    H << 1, 0;

    Kalman kalman(x0, P0, H);
    std::vector<Eigen::Vector2d> pos_v_kalman;

    int n = data.size();
    double dt = 1.0;  

    // 状态转移矩阵
    Eigen::Matrix2d F;
    F(0, 0) = 1; F(0, 1) = dt;
    F(1, 0) = 0; F(1, 1) = 1;

    // 过程噪声
    Eigen::Matrix2d Q;
    Q(0, 0) = 1e-5; Q(0, 1) = 0;
    Q(1, 0) = 0; Q(1, 1) = 1e-5;

    // 观测噪声
    Eigen::MatrixXd R = Eigen::MatrixXd::Identity(1, 1) * 50;

    // 卡尔曼滤波
    for (int i = 0; i < n; ++i) {
        Eigen::VectorXd z(1);
        z << data[i];
        kalman.predict(F, Q);
        kalman.update(z, R);
        pos_v_kalman.push_back(kalman.getState());
    }

    // 提取估计的v
    double v_est = pos_v_kalman.back()(1);

    // 预测未来10天的汇率
    int future_days = 10;
    double last_price = data.back();
    std::vector<double> predicted_prices;
    for (int i = 1; i <= future_days; ++i) {
        predicted_prices.push_back(last_price + v_est * i);
    }

    // 输出
    std::cout << "Predicted prices for the next 10 days:" << std::endl;
    for (double price : predicted_prices) {
        std::cout << price << std::endl;
    }

    return 0;
}
