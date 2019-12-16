#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN(1e3+7);
const int INF(0x3f3f3f3f);  //无限大
int n;
int p[MAXN];    //矩阵大小表
int m[MAXN][MAXN];  //代价表   m[i][j]为第i到第j个矩阵组成的链的最小相乘代价
int s[MAXN][MAXN];  //顺序表

void dfsout(int l, int r) {
    if(l==r) {
        cout << " A" << l << " ";
        return;
    }
    if(l!=s[l][r]) cout << "(";
    dfsout(l, s[l][r]);
    if(l!=s[l][r]) cout << ")";
    if(s[l][r]+1 != r) cout << "(";
    dfsout(s[l][r]+1, r);
    if(s[l][r]+1 != r) cout << ")";
}

int main() {

    //input
    cout << "请输入矩阵链中矩阵个数：";
    cin >> n;
    cout << "请输入矩阵链中矩阵尺寸：";
    for(int i=0; i<=n; i++) {
        cin >> p[i];
    }

    //solve
    for(int l=2; l<=n; l++) {   //枚举矩阵链长度
        for(int i=1; i<=n-l+1; i++) {   //枚举长度为l的链的左端点
            int j = i+l-1;      //右端点
            m[i][j] = INF;      //初始化为无限大
            for(int k=i; k<=j; k++) {   //枚举中点
                int tmp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(tmp<m[i][j]) {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }

    //output
    cout << "整条链的最小相乘代价为：" << m[1][n] << endl;
    cout << "链乘法顺序为：";
    dfsout(1, n);

    return 0;
}
