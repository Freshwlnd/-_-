#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN(1e2+7);
const int MAXM(1e5+7);
const int INF(0x3f3f3f3f);  //无穷大
int n, m;   //点数、边数

int mapp[MAXN][MAXN];
int len[MAXN];    //每个点到s的最短距离
int vis[MAXN];    //Dijkstra 是否已被确定最短路标记

//Dijkstra
void Dijkstra(int u) {
    for(int i=1; i<=n; i++) {
        vis[i] = 0;
        len[i] = INF;   //将距离初始化为无穷大
    }
    vis[u] = 1;
    len[u] = 0;

    for(int i=1; i<n; i++) {
        int mp = u, mm = INF;
        for(int j=1; j<=n; j++) {
            if (!vis[j]) {      //若已确定了最短路则不再考虑
                len[j] = min(len[j], mapp[u][j] + len[u]);  //通过u更新距离
                if (len[j] < mm) {
                    mm = len[j];    //令mm为剩下点中到s的最短距离
                    mp = j;         //令mp为剩下点中到s的最近点
                }
            }
        }
        u = mp;                 //选mp为新点，继续更新
        vis[u] = 1;
    }
}

//Bellman_Ford
//可以判断负环
struct node{
    int u, v, w;    //起点、终点、权值
}edge[MAXM];
void Bellman_Ford(int s) {
    for(int i=1; i<=n; i++) {
        len[i] = INF;       //初始化距离为无穷大
    }
    len[s] = 0;

    for(int i=1; i<n; i++) {//一条最短路最多经过n-1条边
        int cg=1;           //优化标记，标记本轮是否有修改，无修改则说明达到最终状态，则直接退出
        for(int j=1; j<=m; j++) {
            if (len[edge[j].v] > len[edge[j].u] + edge[j].w) {
                len[edge[j].v] = len[edge[j].u] + edge[j].w;   //更新点距离
                cg = 0;
            }
        }
        if(cg) break;       //若无点被更新，则说明到达最终状态，可直接退出
    }

#ifdef panFuHuan    //若要判断负环
    //可以判断是否存在负环
    int cg = 0;
    for(int j=1; j<=m; j++) {
        if(len[edge[j].v] > len[edge[j].u] + edge[j].w) {
            cg = 1; //存在负环
            break;
        }
    }
    if(cg) {
        //存在负环
    }
#endif
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
        edge[i].u=start,edge[i].v=end,edge[i].w=power;
    }

    //起始时间
    time_t begin_t  = clock();
    //运行
    Dijkstra(1);
    //结束时间
    time_t finish_t = clock();
    //输出
    cout << "Dijkstra算法花费" << (double)(finish_t - begin_t )/CLOCKS_PER_SEC*1000 <<" ms"<<endl;

    //起始时间
    begin_t  = clock();
    //运行
    Bellman_Ford(1);
    //结束时间
    finish_t = clock();
    //输出
    cout << "Bellman-Ford算法花费" << (double)(finish_t - begin_t )/CLOCKS_PER_SEC*1000 <<" ms"<<endl;

    return 0;
}

