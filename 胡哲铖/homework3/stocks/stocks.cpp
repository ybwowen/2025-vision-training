
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <numeric>
#include <vector>
#include <string>

using namespace std;
using namespace Eigen;

//预测
pair<Matrix<double,4,1>,Matrix4d> predict(Matrix<double,4,1> Xp,Matrix4d P, Matrix4d Q){
    Matrix<double,4,1> Xe;
    Matrix4d P_;
    Matrix<double, 4, 4> F;
    F <<    1.,1.,1.0/2,1.0/6,
            0.,1.,1.,1.0/2,
            0.,0.,1.,1.,
            0.,0.,0.,1.;
    Xe =F*Xp;
    P_ = F*P*F.transpose() +Q;
    pair<Matrix<double,4,1>,Matrix4d> res =make_pair(Xe,P_);
    return res;
}

//更新状态
pair<Matrix<double,4,1>,Matrix4d> update(Matrix<double,4,1> Xp,Matrix4d P,Matrix<double,1,1> z,Matrix<double,1,1> R){
    Matrix<double,4,1> X;
    Matrix4d P_;
    Matrix<double,1,4> H;
    H << 1,0,0,0;
    Matrix4d I = Matrix4d::Identity();
    Matrix<double,1,1> y = z - (H*Xp);
    Matrix<double,1,1> S = H*P*H.transpose() + R;
    Vector4d K = P*H.transpose()*S.inverse();
    X = Xp + K*y;
    P_ = (I-K*H)*P;
    pair<Matrix<double,4,1>,Matrix4d> res =make_pair(X,P_);
    return res;
}

int main(){
    //读入往日数据
    ifstream ifs;
    ifs.open("../dollar.txt");
    vector<double> dollars;
    string dollar;
    while (getline(ifs, dollar))
    {
        dollars.push_back(stod(dollar));
    }
    
    //初始化
    Matrix<double,1,4> Xp;
    Matrix4d P;
    Xp << dollars[0],0,0,0;
    P <<    1,0,0,0,
            0,0,0,0,
            0,0,0,0,
            0,0,0,0;

    //给出协方差矩阵
    Matrix4d Q;
    Matrix<double,1,1> R;    
    Q <<    0.1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1;
    R << 3;

    //套公式计算
    vector<double> avgerr;
    for (int i{0};i< dollars.size();i++){
        pair<Matrix<double,4,1>,Matrix4d> res1 = predict(Xp, P, Q);
        Xp = res1.first;
        avgerr.push_back(abs(Xp(0)-dollars[i]));
        P =res1.second;
        pair<Matrix<double,4,1>,Matrix4d> res2 = update(Xp,P,Matrix<double,1,1>(dollars[i]),R);
        Xp = res2.first;
        P =res2.second;
    }
    
    //估计下一次汇率
    pair<Matrix<double,4,1>,Matrix4d> res1 = predict(Xp, P, Q);
    Xp = res1.first;
    
    //打印到标准输出与文件
    fstream f;
	f.open("../stocks.txt",ios::out);
	f << "预测汇率："<<Xp(0)<<endl;
    f << "平均误差："<<accumulate(begin(avgerr), end(avgerr), 0.0)/avgerr.size()<<endl;
	f.close();
    cout << "预测汇率："<<Xp(0)<<endl;
    cout << "平均误差："<<accumulate(begin(avgerr), end(avgerr), 0.0)/avgerr.size()<<endl;
    return 0;
}