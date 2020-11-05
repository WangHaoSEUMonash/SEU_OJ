#include <cstdio>
#include <algorithm>
#include <string.h>
#define INF (1<<30)
using namespace std;

const int  N=10000;
int r[N];

int get(int n, int *p)
{
    r[0]=0;
    for(int j=1;j<=n;j++)
    {
        int q=-INF;
        for(int i=1;i<=j;i++)
            q=max(q, p[i]+r[j-i]);
        r[j]=q;
    }
 return r[n];
}
int main()
{
    int m, n, k;
    scanf("%d", &m);
    for(int x = 0; x < m; x++)
    {
        scanf("%d %d", &n, &k);
        int p[10001];
        memset(p, 0, sizeof(p));
        for(int i = 0; i < k; i++)
        {
            int t1, t2;
            scanf("%d %d", &t1, &t2);
            p[t1] = t2;
        }
        printf("%d\n", get(n, p));
    }
    return 0;
}
