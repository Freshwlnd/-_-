//第二章_最大和子串

#include<bits/stdc++.h>
using namespace std;

class nd{
public:
    int l, r;
    long long summ;
    nd(int _l=0, int _r=0): l(_l), r(_r), summ(0) {}
};

//随机生成数组a
int a[10];
inline void init() {
    srand(time(0));
    for(int i=0; i<10; i++) {
        a[i] = rand()%100-50;
    }
}

//输出结果
inline void print() {
    cout << "原数组:\t\t";
    for(int i=0; i<10; i++) {
        cout << a[i] << '\t';
    }
    cout << '\n';
}

//二分求最大和子串
inline nd maxSubstring(const int& l, const int& r) {

    nd now(l, r);
    if(l==r) {
        now.summ = a[l];
        return now;
    }
    int mid = (l+r)>>1;
    nd lson = maxSubstring(l, mid), rson = maxSubstring(mid+1, r);

    //当前最大和子串等于左右儿子中较大的一个
    if(lson.summ>rson.summ) {
        now = lson;
    } else {
        now = rson;
    }

    //枚举跨越中点的情况
    nd tmp(mid+1, mid);
    tmp.summ = -100000;
    int summ;
    summ = 0;
    for(int i=mid; i>=l; i--) {
        summ += a[i];
        if(summ>=tmp.summ) {
            tmp.l = i;
            tmp.summ = summ;
        }
    }
    summ = tmp.summ<0?0:tmp.summ;
    for(int i=mid+1; i<=r; i++) {
        summ += a[i];
        if(summ>=tmp.summ) {
            tmp.r = i;
            tmp.summ = summ;
        }
    }
    if(tmp.summ>now.summ) {
        now = tmp;
    }
    return now;


}

int main() {

    //初始化矩阵
    init();
    //输出原矩阵
    print();

    //二分寻找最大和子串
    nd outt = maxSubstring(0, 9);
    cout << "<二分求最大和子串>\n";
    cout << "\t\t 最大区间在：[" << outt.l << ", " << outt.r << "]" << " \n";
    cout << "\t\t 最大和为  ： " << outt.summ << '\n';


    return 0;
}
