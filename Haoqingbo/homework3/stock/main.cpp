#include <iostream>
#include <Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

class KalmanFilter {
private:
    Vector2d x;    
    Matrix2d P;    
    Matrix2d F;    
    Vector2d H;    
    Matrix2d Q;    
    double R;      
    Vector2d K;    

public:

    KalmanFilter() {
        
        x << 6.9609, 0.0;

        F << 1, 1,   
             0, 1;

        H << 1, 0;   

        P << 1, 0,
             0, 1;

        Q << 0.001, 0,
             0, 0.001;

        R = 0.1;
    }

    void predict() {
        x = F * x;  
        P = F * P * F.transpose() + Q;  
    }

    void update(double z) {
        K = P * H / (H.transpose() * P * H + R);

        x = x + K * (z - H.transpose() * x);

        P = (Matrix2d::Identity() - K * H.transpose()) * P;
    }

    double getRate() {
        return x(0);  
    }

    double getVelocity() {
        return x(1);  
    }
};

int main() {
    vector<double> exchangeRates = {
        6.9609, 6.9804, 7.0054, 7.0183, 7.0496, 7.0693, 7.1271, 7.1339, 7.1765, 7.1995,
        7.1201, 7.1140, 7.1440, 7.1554, 7.1670, 7.1725, 7.1705, 7.1925, 7.1951, 7.2006,
        7.2285, 7.2134, 7.2244, 7.2629, 7.2693, 7.1710, 7.2244, 7.2499, 7.3015, 7.2730
    };

    KalmanFilter kf;

    for (double rate : exchangeRates) {
        kf.predict();      
        kf.update(rate);   
    }

    cout << "\nPredicting next 10 days:" << endl;

    for (int i = 0; i < 10; ++i) {
        kf.predict();  
        cout << "Day " << i + 1 << ": Rate = " << kf.getRate() << endl;
    }

    return 0;
}
