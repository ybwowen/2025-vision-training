#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <vector>
using namespace std;

class kalman 
{
public:
    kalman(const Eigen::Vector2d& x0, const Eigen::Matrix2d& P0, const Eigen::Vector2d& H): x(x0), P(P0), H(H) {}

    void predict(const Eigen::Matrix2d& F, const Eigen::Matrix2d& Q) 
    {
        x = F * x;
        P = F * P * F.transpose() + Q;
    }

    void update(const double &z, const double& R) 
    {
        double y = z - H.transpose() * x; 
        double S = H.transpose() * P * H + R;
        Eigen::Vector2d K = P * H / S;  
        x = x + K * y;
        P = P - K * H.transpose() * P;
    }

    double get() const 
    {
        return x(0);
    }

private:
    Eigen::Vector2d x;
    Eigen::Matrix2d P;
    Eigen::Vector2d H;
};

int main(){
    ifstream input("../dollar.txt");
    double z;

    Eigen::Vector2d x0(0, 0);  
    Eigen::Matrix2d P0;
    P0 << 1e5, 0, 0, 1e5; 
    Eigen::Vector2d H(1, 0);
    kalman km(x0, P0, H);

    Eigen::Matrix2d F;
    F << 1, 1, 0, 1; 
    Eigen::Matrix2d Q;
    Q << 1e-7, 0, 0, 1e-7; 
    double R = 50.0;

    for (int i = 0; i < 30; i++)
    {
        input>>z;
        km.predict(F, Q);
        km.update(z, R);
        cout<<"observed: "<<z;
        cout<<"    predicted: "<<km.get()<<endl;
    }

    for (int i = 0; i < 10; i++)
    {
        km.predict(F, Q);
        cout<<"day"<<i+1<<" predicted: "<<km.get()<<endl;;
    }
}
