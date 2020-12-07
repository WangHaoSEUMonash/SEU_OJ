#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXV = 1000;//��󶥵���
const int INF = 10000000;

int G[MAXV][MAXV];     //n�Ƕ�������m�Ǳ�����sΪ���, t���յ�
int d[MAXV];                           // ��㵽������������·������


void Dijkstra(int s, int n)             //s�����
{
    bool vis[MAXV] = {false};  //������飬vis[i]==true��ʾ�Ѿ�����
    fill(d, d + MAXV, INF);   //������d���鸳ΪINF
    d[s] = 0;                       //��㵽����ľ���Ϊ0
    for(int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF; //uʹd[u]��С��MIN�����С��d[u]
        for(int j = 0; j < n; j++)   //�ҵ�δ���ʵĶ�����d[]��С��
            if(vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        //�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
        if(u == -1) return;
        vis[u] = true;  //���uΪ�ѷ���
        for(int v = 0; v < n; v++)
        {
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
                d[v] = d[u] + G[u][v]; //�Ż�d[v]
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
        scanf("%d%d%d%d", &n, &m, &s, &t);         //������������������
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
