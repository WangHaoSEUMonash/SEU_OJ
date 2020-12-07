#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXV = 501;
const int INF = 100000000;

int G[MAXV][MAXV];

int prim(int n)
{
    int d[MAXV];
    bool vis[MAXV] = {false};
    fill(d, d + MAXV, INF);
    d[0] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++)
            if(vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        if(u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for(int v = 0; v < n; v++)
            if(vis[v] == false && G[u][v] != INF && G[u][v] < d[v])
                d[v] = G[u][v];
    }
    return ans;
}

int main()
{
    int T;
    int n, m;
    scanf("%d", &T);
    for(int e = 0; e < T; e++)
    {
        int u, v, w;
        scanf("%d%d", &n, &m);
        fill(G[0], G[0] + MAXV * MAXV, INF);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            if(G[u-1][v-1] > w) G[u-1][v-1] = w;
            if(G[v-1][u-1] > w) G[v-1][u-1] = w;
        }
        int ans = prim(n);
        printf("%d\n", ans);
    }
    return 0;
}
