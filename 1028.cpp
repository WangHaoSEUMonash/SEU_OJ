#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXV = 1000;//最大顶点数
const int INF = 10000000;

int G[MAXV][MAXV];     //n是顶点数，m是边数，s为起点, t是终点
int d[MAXV];                           // 起点到各个顶点的最短路径长度


void Dijkstra(int s, int n)             //s是起点
{
    bool vis[MAXV] = {false};  //标记数组，vis[i]==true表示已经访问
    fill(d, d + MAXV, INF);   //将整个d数组赋为INF
    d[s] = 0;                       //起点到自身的距离为0
    for(int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF; //u使d[u]最小，MIN存放最小的d[u]
        for(int j = 0; j < n; j++)   //找到未访问的顶点中d[]最小的
            if(vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        if(u == -1) return;
        vis[u] = true;  //标记u为已访问
        for(int v = 0; v < n; v++)
        {
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
                d[v] = d[u] + G[u][v]; //优化d[v]
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int e = 0; e < T; e++)
    {
        int u, v, w;
        int n, m, s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);         //顶点个数，边数，起点
        fill(G[0], G[0] + MAXV * MAXV, INF);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            if(G[u - 1][v - 1] > w )
                G[u - 1][v - 1] = w;
            if(G[v - 1][u - 1] > w )
                G[v - 1][u - 1] = w;
        }
        Dijkstra(s - 1, n);
        if(d[t - 1] == INF) d[t - 1] = -1;
        printf("%d\n", d[t - 1]);
    }
    return 0;
}
