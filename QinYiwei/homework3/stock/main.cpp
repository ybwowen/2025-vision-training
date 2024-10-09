#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include "AdaptiveEKF.h"

const int N = 2;
const int M = 1;

void input(Eigen::Matrix<double, M, 1>*x, int len, std::string Path)
{
    double tmp;
    std::ifstream inFile;
    inFile.open(Path);
    for(int i=0; i<len; i++) inFile >> tmp, x[i] << tmp;
    inFile.close();
}

void state_transition(const ceres::Jet<double, N>* x, ceres::Jet<double, N>* x_out) 
{
    x_out[0] = x[0] + x[1];
    x_out[1] = x[1];
};

void output(Eigen::Matrix<double, M, 1>*x, int len, std::string Path)
{
    std::ofstream outFile;
    outFile.open(Path);
    for(int i=0; i<len; i++) outFile << x[i]<<"\n";
    outFile.close();
}

int main() 
{
    int n = 30, m = 10;
    Eigen::Matrix<double, M, 1> dollar[55], pred[55];
    input(dollar,n,"./dollar.txt");

    Eigen::Matrix<double, N, 1> initial_state;
    initial_state << dollar[0], 0;
    //pred[0]=dollar[0];
    AdaptiveEKF<N, M> ekf(initial_state);

    Eigen::Matrix<double, N, N> Q = 0.1 * Eigen::Matrix<double, N, N>::Identity();
    ekf.Q = Q;
    Eigen::Matrix<double, M, M> R = 0.1 * Eigen::Matrix<double, M, M>::Identity();
    ekf.R = R;

    for(int i=0; i<n; i++)
    {
        Eigen::Matrix<double, N, 1> predicted_state = ekf.predict(state_transition);
        Eigen::Matrix<double, M, 1> measurement;
        measurement<<dollar[i];
        ekf.update(state_transition, measurement);
        Eigen::Matrix<double, N, 1> filtered_state = ekf.Xe;
        pred[i] << filtered_state[0];
        //std::cerr<<filtered_state<<'\n';
        //std::cerr<<predicted_state<<'\n';
    }
    for(int i=0;i<m;i++)
    {
        Eigen::Matrix<double, N, 1> predicted_state = ekf.predict(state_transition);
        pred[i+n]<<predicted_state[0];
        std::cerr<<predicted_state<<'\n';
        ekf.update(state_transition, pred[i+n]);
    }
    output(pred, n+m, "./stock.out");
}
