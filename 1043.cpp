#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;

int superEggDrop(int K, int N) {
    vector<int> dp(K+1);
    int step = 0;
    for (; dp[K] < N; step++) {
        for (int i = K; i > 0; i--)
            dp[i] += (1+ dp[i-1]);
    }
    return step;
}

int main()
{
    int nums, N, K;
    scanf("%d", &nums);
    for(int x = 0; x < nums; x++)
    {
        scanf("%d %d", &K, &N);
        printf("%d\n", superEggDrop(K, N));
    }
    return 0;
}
