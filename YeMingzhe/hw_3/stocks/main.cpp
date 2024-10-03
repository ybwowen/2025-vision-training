#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>

class Kalman {
public:
    Kalman(const Eigen::VectorXd& x0, const Eigen::MatrixXd& P0, const Eigen::MatrixXd& H0)
        : x(x0), P(P0), H(H0) {}

    void predict(const Eigen::MatrixXd& F, const Eigen::MatrixXd& Q) {
        x = F * x;
        P = F * P * F.transpose() + Q;
    }

    void update(const Eigen::VectorXd& z, const Eigen::MatrixXd& R) {
        Eigen::VectorXd y = z - (H * x);
        Eigen::MatrixXd S = H * P * H.transpose() + R;
        Eigen::MatrixXd K = P * H.transpose() * S.inverse();
        x = x + K * y;
        P = P - K * H * P;
    }

    Eigen::VectorXd getState() const {
        return x;
    }

private:
    Eigen::VectorXd x; 
    Eigen::MatrixXd P; 
    Eigen::MatrixXd H; 
};

void plotResults(const std::vector<double>& prices, const std::vector<Eigen::VectorXd>& estimated_states) {
    int num_points = prices.size() + 10; // 包括未来10天
    
    // 创建图像
    cv::Mat plot_image(500, 1000, CV_8UC3, cv::Scalar(255, 255, 255));

    // 绘制坐标轴
    cv::line(plot_image, cv::Point(50, 450), cv::Point(50, 0), cv::Scalar(0, 0, 0), 2); // y轴
    cv::line(plot_image, cv::Point(50, 450), cv::Point(1000, 450), cv::Scalar(0, 0, 0), 2); // x轴
    
    // 计算最大值和最小值
    double max_price = *std::max_element(prices.begin(), prices.end());
    double min_price = *std::min_element(prices.begin(), prices.end());

    // 绘制实际汇率
    for (int i = 1; i < prices.size(); ++i) {
        cv::line(plot_image,
                 cv::Point((i - 1) * (700 / (num_points - 10)) + 50, 450 - (prices[i - 1] - min_price) / (max_price - min_price) * 300),
                 cv::Point(i * (700 / (num_points - 10)) + 50, 450 - (prices[i] - min_price) / (max_price - min_price) * 300),
                 cv::Scalar(0, 0, 255), 2);
    }

    // 绘制卡尔曼估计
    for (int i = 1; i < estimated_states.size(); ++i) {
        cv::line(plot_image,
                 cv::Point((i - 1) * (700 / (num_points - 10)) + 50, 450 - (estimated_states[i - 1][0] - min_price) / (max_price - min_price) * 300),
                 cv::Point(i * (700 / (num_points - 10)) + 50, 450 - (estimated_states[i][0] - min_price) / (max_price - min_price) * 300),
                 cv::Scalar(255, 0, 0), 2);
    }

    // 添加时间标记
    for (int i = 0; i <= num_points; i += 10) {
        cv::putText(plot_image, std::to_string(i), 
                    cv::Point((i * (700 / (num_points - 10)) + 50), 465), 
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 1);
    }

    // 添加实际价格标记
    for (int i = 0; i <= 15; ++i) { // 根据需要调整范围
    double value = min_price + (estimated_states.back()[0] - min_price) * i / 15.0; // 在y轴上均匀分布
    std::ostringstream oss; // 使用ostringstream
    oss << std::fixed << std::setprecision(2) << value; // 保留两位小数
    std::string value_str = oss.str(); // 转换为字符串

    cv::putText(plot_image, value_str,
                cv::Point(10, 450 - (value - min_price) / (max_price - min_price) * 300), 
                cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 1);
    }
    // 显示结果
    cv::imshow("Dollar Exchange Rate Prediction", plot_image);
    cv::waitKey(0);
}

int main() {
    // 读取美元汇率数据
    std::ifstream infile("/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_3/stocks/dollar.txt");
    std::vector<double> prices;
    double price;

    while (infile >> price) {
        prices.push_back(price);
    }

    // 初始化卡尔曼滤波器
    Eigen::VectorXd x0(2); 
    x0 << 0, 0;
    Eigen::MatrixXd P0(2, 2);
    P0 << 1e6, 0,
          0, 1e6; 
    Eigen::MatrixXd H(1, 2);
    H << 1, 0; 

    Kalman kalman(x0, P0, H);

    std::vector<Eigen::VectorXd> pos_v_kalman; 

    // 卡尔曼滤波过程
    for (size_t i = 0; i < prices.size(); ++i) {
        double dt = (i > 0) ? 1.0 : 0.0;
        Eigen::MatrixXd F(2, 2);
        F << 1, dt,
             0, 1;
        Eigen::MatrixXd Q(2, 2);
        Q << 0.1, 0,
             0, 10; 

        kalman.predict(F, Q);
        Eigen::VectorXd z(1);
        z << prices[i];
        Eigen::MatrixXd R(1, 1);
        R << 20; // 观测噪声协方差
        kalman.update(z, R);

        pos_v_kalman.push_back(kalman.getState());
    }

    // 预测未来10天
    for (int i = 0; i < 10; ++i) {
        double dt = 1.0; 
        Eigen::MatrixXd F(2, 2);
        F << 1, dt,
             0, 1; 
        Eigen::MatrixXd Q(2, 2);
        Q << 0.1, 0,
             0, 10; 

        kalman.predict(F, Q);
        pos_v_kalman.push_back(kalman.getState());
    }

    // 保存估计结果到文件
    std::ofstream outfile("/home/ymz/Codes/2025-vision-training/YeMingzhe/hw_3/stocks/kalman_estimates.txt");
    for (const auto& state : pos_v_kalman) {
        outfile << state.transpose() << std::endl; // 将状态以行形式写入文件
    }
    outfile.close();

    // 绘制结果
    plotResults(prices, pos_v_kalman);

    return 0;
}