//第八章_计数排序

#include<bits/stdc++.h>
using namespace std;

//以"algorithm"中sort函数的参数表为标准


int n;  //待排序数字个数及所有数字的范围[0, n)

//对给定数组的 范围[start,end)部分，使用计数排序进行从小到大排序
inline void Counting_Sort(int* start, int* end) {
    vector<int> C;  //C记录每个数字出现次数
    C.resize(n, 0); //初始化vector，大小为n，每个内容为0
    for (auto it = start; it != end; it++) {
        C[*it]++;   //记录每个数字出现次数
    }
    for (int i = 1; i < n; i++) {
        C[i] += C[i - 1]; //求前缀和，相当于计算每个数字最后一次出现的位置
    }
    vector<int> tmp;    //存下排序后的数字序列
    tmp.resize(n);
    for (auto it = start; it != end; it++) {
        tmp[--C[*it]] = *it;    //按C数组中每个数字的应在位置排序，由于位置应该在[0,n)，故每个数字t应在C[t-1]位置
    }
    int i=0;
    for (auto it = start; it != end; it++) {
        *it = tmp[i++];         //将数字放回到原数组
    }
}

//随机生成数组a, b
const int MAXN(1e7+7);
int a[MAXN], b[MAXN];
inline void init(const int& num) {
    for(int i=0; i<num; i++) {
        b[i] = a[i] = rand()%num;
    }
}

//输出结果
inline void print(const int & num) {

    cout << "原数组:\t\t\t";
    for(int i=0; i<num; i++) {
        cout << a[i] << '\t';
    }
    cout << '\n';

    cout << "计数排序后数组:\t";
    for(int i=0; i<num; i++) {
        cout << b[i] << '\t';
    }
    cout << '\n';

}

int main() {

    srand(time(0));

    cout << "请输入想要排序的数字个数： ";
    cin >> n;

    //创建数组
    init(n);

    //排序
    Counting_Sort(b, b + n);

    //输出
    print(n);

    return 0;
}
