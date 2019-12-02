//选择出数组中第k小的数字

#include <bits/stdc++.h>
using namespace std;
const int MAXN(2e6+7);

int n;
int raw[MAXN], a[MAXN], b[MAXN];

//生成随机数
inline void makeRand() {
    for(int i=0; i<n; i++) {
        raw[i] = rand() % (5 * n);
        a[i] = b[i] = raw[i];
    }
}

//将比主元小的数放在前面，比主元大的数放在后面
inline int Partition(int* A, int l, int r) {
    int li=l+1, ri=r;           //对后面的所有数字进行选择
    while(li<ri) {
        while(li<ri && A[li]<=A[l]) li++;
        while(ri>li && A[ri]>=A[l]) ri--;
        if(li<ri) {
            swap(A[li], A[ri]); //将比主元小的放到前面，比主元大的放到后面
        }
    }
    if(A[li]<A[l]) {    //若最终位置处元素小于主元，则将主元换到该位置
        swap(A[li], A[l]);
    } else {            //否则将主元换到该位置的前一位
        li--;
        swap(A[li], A[l]);
    }
    return li;
}

//随机选择算法
//返回数组A的 [l,r]范围内第k小的数字的值
inline int randSelect(int* A, int l, int r, int k) {
    if(l==r) return A[l];   //当区间范围内只有一个数字时，返回这个数字

    //随机选择
    int q = rand()%(r-l+1)+l;   //随机选择一个位置做主元
    swap(A[l], A[q]);   //将主元放到第一个位置

    int pos = Partition(A, l, r);   //数组划分，比主元小的数放在前面，比主元大的数放在后面

    //递归
    if(pos-l+1>=k) {     //若主元及其左侧元素比k个多，则在左半块查找
        return randSelect(A, l, pos, k);
    } else {            //否则在右半块查找
        return randSelect(A, pos+1, r, k-(pos-l+1));
    }

}

//插入排序
inline void InsertSort(int* A, int l, int r) {
    for(int i=l+1; i<=r; i++) {
        int key = A[i];
        int j;
        for(j=i-1; j>=l; j--) {
            if(A[j]>A[j+1]) A[j+1] = A[j];
            else break;
        }
        A[j+1] = key;
    }
}

//最坏情况为线性时间的选择算法
//返回数组A的 [l,r]范围内第k小的数字的值
inline int lineBadSelect(int* A, int l, int r, int k) {
    if(r-l+1<=5) {  //只有一组的情况直接简化
        InsertSort(A, l, r);
        return A[l+k-1];
    }

    int groupNum = (r-l)/5+1;
    for(int i=0; i<groupNum; i++) {
        int li = l+i*5;
        int ri = l+(i+1)*5-1;
        if(ri>r) ri=r;  //若右边界超出则置为r
        InsertSort(A, li, ri);
        swap(A[(li+ri)>>1], A[l+i]);  //将中位数放到第i个位置，方便后续排序
    }

    int q = lineBadSelect(A, l, l+groupNum-1, groupNum>>1);    //找到中位数的值
    for(int i=l; i<=l+groupNum-1; i++) {
        if(A[i]==q) {
            q = i;
            break;
        }
    }
    swap(A[l], A[q]);   //将主元放到第一个位置
    int pos = Partition(A, l, r);   //数组划分，比主元小的数放在前面，比主元大的数放在后面

    if(pos-l+1>=k) {    //若主元及其左侧元素比k个多，则在左半块查找
        return lineBadSelect(A, l, pos, k);
    } else {            //否则在右半块查找
        return lineBadSelect(A, pos+1, r, k-(pos-l+1));
    }

}

int main() {

    srand(time(NULL));

    //init
    cout << "请输入想要产生的随机数个数n：";
    cin >> n;
    while(n) {
        makeRand(); //生成随机数

        int k = rand()%n+1; //随机生成k

        //随机选择
        time_t begin_t = clock();
        randSelect(a, 0, n-1, k);
        time_t finish_t = clock();
        cout << "- \t随机选择花费\t\t\t\t\t: " << (double)(finish_t - begin_t )/CLOCKS_PER_SEC*1000 <<" ms"<<endl;

        //最坏情况下为线性时间的选择
        begin_t = clock();
        lineBadSelect(b, 0, n-1, k);
        finish_t = clock();
        cout << "- \t最坏情况下为线性时间的选择花费\t: " << (double)(finish_t - begin_t )/CLOCKS_PER_SEC*1000 <<" ms"<<endl;

        //下一次输入
        cout << endl;
        cout << "请输入想要产生的随机数个数n：";
        cin >> n;
    }

    return 0;

}
