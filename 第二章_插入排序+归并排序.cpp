//第二章_插入排序+归并排序

#include<bits/stdc++.h>
using namespace std;

//以"algorithm"中sort函数的参数表为标准

//对给定数组的 范围[start,end)部分，使用插入排序进行从小到大排序
inline void Inserion_Sort(int* start, int* end) {
    auto it = start;
    //从start+1位置开始插入
    it++;
    while(it!=end) {    //直到插入end-1位置
        auto insertPos=it-1;
        int key = *it;
        //寻找it应该被放在的位置
        while(insertPos+1!=start && *insertPos>key) {
            *(insertPos+1) = *insertPos;
            insertPos--;
        }
        *(insertPos+1) = key;
        it++;
    }
}

//对给定数组的 范围[start,end)部分，使用归并排序进行从小到大排序
inline void Merge_Sort(int *start, int* end) {

    int len = end-start;

    if(len<=1) return;    //若长度小于等于1，则不用排序

    auto mid = start+len/2;   //mid=start+长度/2的地板数+1
    int len2 = mid-start;
    //将数组分为[start, mid)和[mid,end)两部分
    Merge_Sort(start, mid);
    Merge_Sort(mid, end);

    //将两部分合并
    auto tmp = new int[len];
    auto p1=start, p2=mid, p3=tmp;
    while(p1!=mid && p2!=end) {
        if(*p1<*p2) {
            *p3 = *p1;
            p1++;
        } else {
            *p3 = *p2;
            p2++;
        }
        p3++;
    }
    while(p1!=mid) {
        *p3 = *p1;
        p1++;
        p3++;
    }
    while(p2!=end) {
        *p3 = *p2;
        p2++;
        p3++;
    }

    //将tmp中的内容传回原数组
    auto p4 = start, p5 = tmp;
    while(p5 != p3) {
        *p4 = *p5;
        p4++;
        p5++;
    }

    //释放内存
    delete[] tmp;
}

//随机生成数组a
int a[10], b[10], c[10];
inline void init() {
    srand(time(0));
    for(int i=0; i<10; i++) {
        a[i] = rand()%100;
        b[i] = c[i] = a[i];
    }
}

//输出结果
inline void print() {

    cout << "原数组:\t\t";
    for(int i=0; i<10; i++) {
        cout << a[i] << '\t';
    }
    cout << '\n';

    cout << "插入排序数组:\t";
    for(int i=0; i<10; i++) {
        cout << b[i] << '\t';
    }
    cout << '\n';

    cout << "合并排序数组:\t";
    for(int i=0; i<10; i++) {
        cout << c[i] << '\t';
    }
    cout << '\n';

}

int main() {

    //创建数组
    init();

    //排序
    Inserion_Sort(b, b+10);
    Merge_Sort(c, c+10);

    //输出
    print();

    return 0;
}
