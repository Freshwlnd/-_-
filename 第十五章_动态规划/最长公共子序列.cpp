#include <bits/stdc++.h>
using namespace std;

const int MAXN(1e3+7);
string str, ptr;
int commonLenth[MAXN][MAXN];    //Xi与Yj的最长公共子序列的长度
int printMark[MAXN][MAXN];      //Xi与Yj的最长公共子序列的转移方向

inline void solve() {   //处理出长度与转移方向

    //初始化commonLenth[0][j] 和 commonLenth[j][0]
    for(int i=0; i<str.length(); i++) {
        commonLenth[i][0] = 0;
    }
    for(int j=0; j<ptr.length(); j++) {
        commonLenth[0][j] = 0;
    }

    //状态转移
    for(int i=1; i<=str.length(); i++) {
        for(int j=1; j<=ptr.length(); j++) {
            if(str[i-1]==ptr[j-1]) {
                commonLenth[i][j] = commonLenth[i-1][j-1]+1;
                printMark[i][j] = 1;    //向左上转移
            } else if(commonLenth[i][j-1]>commonLenth[i-1][j]) {
                commonLenth[i][j] = commonLenth[i][j-1];
                printMark[i][j] = 2;    //向左转移
            } else {
                commonLenth[i][j] = commonLenth[i-1][j];
                printMark[i][j] = 3;    //向上转移
            }
        }
    }

}

inline void printCommonString(int i, int j) {
    if(i==0 || j==0) return;
    if(printMark[i][j]==1) {
        printCommonString(i-1, j-1);
        cout << str[i-1];
    } else if(printMark[i][j]==2) {
        printCommonString(i, j-1);
    } else {
        printCommonString(i-1, j);
    }
}

int main() {

    //input
    cout << "请输入第一个字符串：";
    cin >> str;
    cout << "请输入第二个字符串：";
    cin >> ptr;

    //solve
    solve();

    //output
    cout << "最长公共子序列的长度为：" << commonLenth[str.length()][ptr.length()] << endl;
    cout << "最长公共子序列为：";
    printCommonString(str.length(), ptr.length());
    cout << endl;


    return 0;

}
