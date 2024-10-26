
#include<iostream>
#include<vector>
#include<Eigen/Dense>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace Eigen;
using namespace cv;

int main(){
    freopen("../points.txt", "r", stdin);

    int n;
    double a, b, c;

    Matrix<double,3,4> Mc;
    Mc << 400., 0., 190., 0.,
          0., 400., 160., 0.,
          0., 0., 1., 0.;
    Vector3d T(2.0, 2.0, 2.0);
    Quaternion<double> Qr(-0.5, 0.5, 0.5, -0.5);
    Matrix3d Mr = Qr.toRotationMatrix();

    Matrix<double, 4, 4> M0;
    M0 << Mr(0, 0), Mr(0, 1), Mr(0, 2), T(0),
          Mr(1, 0), Mr(1, 1), Mr(1, 2), T(1),
          Mr(2, 0), Mr(2, 1), Mr(2, 2), T(2),
          0, 0, 0, 1;
    
    Mat image = Mat(700, 1200, CV_8UC3);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b>>c;
        Vector<double, 4> pos(a, b, c, 1.0);
        Vector<double, 3> posr = Mc * M0.inverse() * pos;
        Point p(posr(0)/posr(2), posr(1)/posr(2));
        circle(image, p, 1, Scalar(255,0,0), -1);
    }
    imwrite("../photo.jpg", image);
    imshow("Photo", image);
    waitKey();
    return 0;
}