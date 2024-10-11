#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

vector<double> Dollar;

int main() {
  ifstream File("../dollar.txt");
  for (int i = 0; i < 30; ++i) {
    double temp; File >> temp;
    Dollar.push_back(temp);
  }

  Vector2d x(Dollar[0], 0), H(1, 0);
  Matrix2d P, F, Q, Ones;
  P << 1 << 0 << 0 << 1; Ones = P;
  F << 1 << 1 << 1 << 0;
  Q << 0.01 << 0 << 0 << 0.01;
  MatrixXd R(1, 1); R << 1;

  for (double data : Dollar) {
    x = F * x;
    P = F * P * F.transpose() + Q;

    VectorXd y = data - H * x;
    MatrixXd S = H * P * H.transpose() + R;
    VectorXd K = P * H.transpose() * S.inverse();
    x = x + K * y;
    P = (Ones - K * H) * P;
  }

  ofstream Output("../Prediction.txt");
  for (i = 0; i < 10; ++i) {
    x = F * x;
    // cout << x(0) << endl;
    Output << x << endl;
  }
  Output.close();

  return 0;
}
