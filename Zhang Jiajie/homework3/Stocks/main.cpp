#include<iostream>
#include<vector>
#include<Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>

using namespace std;
using namespace Eigen;

class Kalman{
    public:
        VectorXd x;
        MatrixXd P;
        Kalman(VectorXd x, MatrixXd P, RowVectorXd H, MatrixXd F ,MatrixXd Q, VectorXd R):
            x(x), P(P), H(H), F(F), Q(Q), R(R) {}
        
        void predict(){
            x = F * x;
            P = F * P * F.transpose() + Q;
        }

        void update(VectorXd z){
            VectorXd y = z - (H*x);
            VectorXd S = H * P * H.transpose() + R;
            VectorXd K = P * H.transpose() * S.inverse();
            x = x + K * y;
            P = P - K * H * P;
        }
    private:
        RowVectorXd H;
        MatrixXd F;
        MatrixXd Q;
        VectorXd R;
};

int main(){
    freopen("../dollar.txt", "r", stdin);
    freopen("../prediction.txt", "w", stdout);
    vector<double> data;
    double read;
    while(cin>>read) data.push_back(read);
    int n = data.size();

    VectorXd x0(2);
    x0 << data[0], 0;
    MatrixXd P0(2, 2);
    P0 << 1e6, 0,
          0, 0;
    RowVectorXd H(2);
    H << 1, 0;
    MatrixXd F(2, 2);
    F << 1, 1,
         0, 1;
    MatrixXd Q(2, 2);
    Q << 0.1, 0,
         0, 10;
    VectorXd R(1);
    R << 50;
    
    Kalman Km(x0, P0, H, F, Q, R);


    for(int i=1; i<n; i++){
        Km.predict();
        VectorXd z(1);
        z << data[i];
        Km.update(z);
    }
    for(int i=0; i<10; i++){
        Km.predict();
        cout<<Km.x(0)<<endl;
    }
    return 0;
}