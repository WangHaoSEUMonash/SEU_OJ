#include<cstdio>
#include<string.h>
using namespace std;
int f[5001], w[501], c[501];
int ans[11];
int main()
{
    int iter;
    scanf("%d", &iter);
    for(int j = 0; j < iter; j ++)
    {
        int t, m;
        scanf("%d %d", &m, &t);
        memset(f, 0, sizeof(f));
        memset(w, 0, sizeof(w));
        memset(c, 0, sizeof(c));
        for(int i = 0; i < m; ++i)
            scanf("%d %d", &w[i], &c[i]);
        for(int i = 0; i < m; ++i)
            for(int v = t; v >= w[i]; --v)
                if(f[v] < f[v - w[i]] + c[i])
                    f[v] = f[v - w[i]] + c[i];
        ans[j] = f[t];
    }
    for(int j = 0; j < iter; j ++)
    {
        if(j == iter - 1) printf("%d", ans[j]);
        else printf("%d\n", ans[j]);
    }
    return 0;
}
