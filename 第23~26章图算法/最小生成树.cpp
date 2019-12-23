#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN(107);    //最大点数
const int MAXM(10007);  //最大边数
const int INF(0x3f3f3f3f);  //无穷大

int mapp[MAXN][MAXN];   //记录原图状态
int n, m;               //点数
int summP, summK;               //记录路径权值和

int prim(int s) {

    int vis[MAXN];      //记录是否已在点集中
    int len[MAXN];      //记录到当前点集距离
    for(int i=1; i<=n; i++) {
        vis[i] = 0;     //初始化
        len[i] = INF;   //初始化为无穷大
    }

    vis[s] = 1;     //从起始点s开始遍历

    for(int i=1; i<n; i++) {    //每次选择一个点加入树，共循环n-1次
        int mm=INF, mp=s;
        for(int j=1; j<=n; j++) {
            if(!vis[j] && mm>(len[j]=min(len[j],mapp[s][j]))) {
                mm = len[j];    //mm记录未加入树的点中，到树集的最短距离
                mp = j;         //mp记录最短距离的点的标号
            }
        }
        if(mm==INF) {           //某次循环中最短距离为无穷大
            return 0;           //非联通图
        }
        summP += mm;
        s = mp;
        vis[s] = 1;
    }

    return 1;

}

struct node {               //记录边信息
    int start,end,power;    //start为起始点，end为终止点，power为边权值
} edge[MAXM];
int pre[MAXN];              //记录点集信息

int cmp(const node& a, const node& b) {
    return a.power<b.power;             //按照权值排序
}

int find(int x) {       //使用并查集找祖先
    if(x!=pre[x]) {
        pre[x]=find(pre[x]);
    }
    return pre[x];
}

void merge(int x, int y, int p) { //使用并查集合并两个点集，p记录新加入的边的号
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy) {
        pre[fx]=fy;
        summK += edge[p].power;
    }
}

void kruskal() {
    for(int i=1; i<=n; i++) {
        pre[i] = i;             //
    }
    sort(edge+1, edge+m+1, cmp);
    for(int i=1; i<=m; i++) {
        merge(edge[i].start, edge[i].end, i);
    }
}
int main() {

    cout << "请输入点数n：";
    cin >> n;
    cout << "请输入边数m：";
    cin >> m;
    cout << "请输入m条边（按 起点 终点 边权 的格式）：" << endl;

    //初始化Prim算法的图
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            mapp[i][j] = i==j?0:INF;
        }
    }

    int start,end,power;
    for(int i=1; i<=m; i++) {
        cin >> start >> end >> power;
        mapp[start][end] = mapp[end][start] = min(mapp[start][end], power);
        edge[i].start=start,edge[i].end=end,edge[i].power=power;
    }
    prim(1);
    kruskal();

    cout << "Prim算法所得最小生成树的边权和为：" << summP << endl;
    cout << "Kruskal算法所得最小生成树的边权和为：" << summK << endl;

    return 0;
}
