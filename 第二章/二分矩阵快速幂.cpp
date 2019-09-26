//第二章_二分矩阵快速幂

#include<bits/stdc++.h>
using namespace std;

class Mat {
public:
    long long nm[2][2];
    Mat() {
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                nm[i][j] = 0;
            }
        }
    }
    Mat operator*(const Mat& b) {   //this*b
        Mat c;
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                c.nm[i][j] = nm[0][j]*b.nm[i][0] + nm[1][j]*b.nm[i][1];
            }
        }
        return c;
    }

public:
    inline void init1() {   //创建单位矩阵
        // [ 1  0 ]
        // [      ]
        // [ 0  1 ]
        nm[0][0] = nm[1][1] = 1;
    }
    inline void initSt() {  //创建初始矩阵
        // [ fn   fn-1 ]     [ 1  1 ]
        // [           ]  *  [      ]
        // [ fn-1 fn-2 ]     [ 1  0 ]
        nm[0][0] = nm[0][1] = nm[1][0] = 1;
    }
};

//二分矩阵快速幂
inline Mat binaryMatrixPower(const Mat& st, long long pow) {

    if(pow==1) return st;   //如果只求1次幂，则返回原矩阵

    Mat pow_2(binaryMatrixPower(st, pow>>1));
    if(pow%2) { //如果奇数次幂
        return pow_2*pow_2*st;
    } else {    //如果偶数次幂
        return pow_2*pow_2;
    }

}

int main() {

    srand(time(0));
    Mat s;

    //二分快速幂
    for(int i=0; i<5; i++) {
        long long a=rand()%50+3;
        s.initSt(); //初始化矩阵
        cout << "<二分矩阵快速幂求斐波那契>\t Fibonacci数列 第" << a << "项： \t";
        cout << binaryMatrixPower(s, a-1).nm[0][0] << '\n';
    }


    return 0;
}
