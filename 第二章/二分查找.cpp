//第二章_二分查找

#include<bits/stdc++.h>
using namespace std;

//随机生成数组a
int a[10];
inline void init() {
    srand(time(0));
    for(int i=0; i<10; i++) {
        a[i] = rand()%100;
    }
    sort(a, a+10);
}

//输出结果
inline void print() {
    cout << "原数组:\t\t";
    for(int i=0; i<10; i++) {
        cout << a[i] << '\t';
    }
    cout << '\n';
}

//二分查找
inline int binarySearch(int numm) {

    int l=0, r=9, mid=(l+r)>>1;
    while(a[mid]!=numm) {   //若找到，则退出循环
        if(a[mid]<numm) {   //若当前数字较小，则要找的数字在右边
            l = mid+1;
        } else {
            r = mid-1;      //若当前数字较大，则要找的数字在左边
        }
        mid = (l+r)>>1;
    }
    return mid;

}

int main() {

    //创建有序数组
    init();

    //输出
    print();

    //搜索
    for(int i=0; i<3; i++) {
        int b=a[rand()%10];
        cout << "<二分查找>\t 数字'" << b << "' \t 所在位置：\t";
        cout << binarySearch(b) << '\n';
    }


    return 0;
}
