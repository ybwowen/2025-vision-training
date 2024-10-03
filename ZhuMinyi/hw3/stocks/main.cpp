#include <Eigen/Dense>
#include <bits/stdc++.h>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <eigen3/Eigen/src/Geometry/Quaternion.h>
#include <fstream>

using namespace Eigen;
using namespace std;

void predict(Vector2d &x, Matrix2d &P, const Matrix2d F, const Matrix2d Q) {
  x = F * x;
  P = F * P * F.transpose() + Q;
}

void update(Vector2d &x, Matrix2d &P, const double z,
            const Matrix<double, 1, 2> H, const MatrixXd R) {
  VectorXd y = VectorXd::Ones(1) * z - H * x;
  MatrixXd S = H * P * H.transpose() + R;
  MatrixXd K = P * H.transpose() * S.inverse();
  x = x + K * y;
  P = (MatrixXd::Identity(2, 2) - K * H) * P;
}

int main() {
  ifstream file("../dollar.txt");
  vector<double> data;
  vector<double> predict_data;

  double value;
  while (file >> value) {
    data.push_back(value);
  }

  Vector2d x(data[0], 0);
  Matrix2d P;
  P << 1e6, 0, 0, 1;
  Matrix2d F;
  F << 1, 1, 0, 1;
  Matrix2d Q;
  Q << 1, 0, 0, 1.5;
  Matrix<double, 1, 2> H(1, 0);

  for (int i = 0; i < data.size(); i++) {
    predict(x, P, F, Q);
    MatrixXd R = MatrixXd::Identity(1, 1) * 50;
    update(x, P, data[i], H, R);
    predict_data.push_back(x(0));
  }

  for (int i = 0; i < 10; ++i) {
    predict(x, P, F, Q);
    cout << i + 1 << ":" << x(0) << endl;
    predict_data.push_back(x(0));
  }

  return 0;
}