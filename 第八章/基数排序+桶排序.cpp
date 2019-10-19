//第八章_基数排序+桶排序

#include<bits/stdc++.h>
using namespace std;

//以"algorithm"中sort函数的参数表为标准

int n, m;   //待排序数字个数n，最大位数m

//对给定数组的 范围[start,end)部分，使用桶排序 "对第dex位" 进行从小到大排序
inline void Bucket_Sort(int* start, int* end, int dex) {
    int mod1=pow(10, dex), mod2=pow(10, dex-1); //用以获取数字第dex位的辅助数
    vector<int> Bucket[10]; //创建10个桶
    for(int i=0; i<10; i++) {
        Bucket[i].clear();  //初始化每个桶
    }
    for(auto it=start; it!=end; it++) {
        Bucket[(*it)%mod1/mod2].push_back(*it); //将数字放入对应的桶中
    }
    auto pt = start;
    for(int i=0; i<10; i++) {
        //遍历每个桶，按放入顺序取出每个数字（保证稳定性）
        for(auto it: Bucket[i]) {
            *(pt++) = it;
        }
    }
}

//对给定数组的 范围[start,end)部分，使用基数排序进行从小到大排序
inline void Radix_Sort(int* start, int* end) {
    for(int i=1; i<=m; i++) {
        Bucket_Sort(start, end, i);
    }
}

//随机生成数组a, b
const int MAXN(1e7+7);
int a[MAXN], b[MAXN];
inline void init(const int& num, const int & digit) {
    int maxNum = pow(10, digit);
    for(int i=0; i<num; i++) {
        b[i] = a[i] = rand()%maxNum;
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
    cout << "请输入想要排序的数字最大位数(1~9)： ";
    cin >> m;

    //创建数组
    init(n, m);

    //排序
    Radix_Sort(b, b + n);

    //输出
    print(n);

    return 0;
}