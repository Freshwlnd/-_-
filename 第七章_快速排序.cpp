//第七章_快速排序

#include<bits/stdc++.h>
using namespace std;

//以"algorithm"中sort函数的参数表为标准

//对给定数组的 范围[start,end)部分，使用快速排序进行从小到大排序
inline void Quick_Sort(int* start, int* end, int type=0) {

    if(start+1>=end) {return;}

    int pos;    //作为中值的数字所在位置
    switch(type) {
        case 0: {       //开头
            pos = 0;
            break;
        }
        case 1: {       //末尾
            pos = end-start-1;
            break;
        }
        case 2: {       //中间
            pos = (end-start)/2;
            break;
        }
        case 3: {       //随机
            pos = rand()%(end-start);
            break;
        }
    }

    //将待换数字换到第一个
    int tmp = *start;
    *start = *(start+pos);
    *(start+pos) = tmp;

    int *l=start+1, *r=end-1;
    while(l<=r) {
        while (l < r && *l <= *start) {
            l++;
        }
        if(l>=r) {
            if(*r>*start) l--;
            else r++;
            break;
        }
        while (l < r && *r > *start) {
            r--;
        }
        if(l>=r) {
            if(*l<=*start) r++;
            else l--;
            break;
        }
        int tmp = *l;
        *l = *r;
        *r = tmp;
    }

    tmp = *l;
    *l = *start;
    *start = tmp;

    Quick_Sort(start, l, type);
    Quick_Sort(r, end, type);

}

//随机生成数组a
const int MAXN(1e7+7);
int a[MAXN], b[MAXN];
inline void init(const int& num) {
    for(int i=0; i<num; i++) {
        a[i] = rand()%num;
    }
}

//复制原数组
inline void copyy(const int& num) {
    for(int i=0; i<num; i++) {
        b[i] = a[i];
    }
}

//输出结果
inline void print(const int & num) {

    cout << "原数组:\t\t\t";
    for(int i=0; i<num; i++) {
        cout << a[i] << '\t';
    }
    cout << '\n';

    cout << "快速排序后数组:\t";
    for(int i=0; i<num; i++) {
        cout << b[i] << '\t';
    }
    cout << '\n';

}

int main() {

    srand(time(0));

    int type=0, n;

    cout << "请输入想要排序的数字个数： ";
    cin >> n;

    //创建数组
    init(n);

    while(type<4) {

        //复制数组
        copyy(n);

        //起始时间
        time_t begin_t  = clock();

        //排序
        Quick_Sort(b, b + n, type);

        //结束时间
        time_t finish_t = clock();

        //输出
        //print(n);
        cout << "第" << type << "种策略 排序花费 " << (double)(finish_t - begin_t )/CLOCKS_PER_SEC*1000 <<" ms"<<endl;

        type++;

    }

    return 0;
}
