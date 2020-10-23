/*#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

int maxSum(int arr[])
{
    int tmp = arr[0];
    int max1 = arr[0];
    for(int i = 1; i < sizeof(arr)/sizeof(int); i++)
    {
        if(tmp < 0) tmp = 0;
        tmp += arr[i];
        max1 = max(max1, tmp);
    }
    return max1;
}

int main()
{
    int M, N, i, j, a[50001];
    scanf("%d", &M);//cin >> M;
    for(i = 0; i < M; i++)
    {
        scanf("%d", &N);
        for(j = 0; j < N; j++)
            scanf("%d", a[j]);
    }
    return 0;
}*/

#include <stdio.h>

int func(int *num, int N)
{
    for(int i = 1; i <= N; i++)
        scanf("%d", &num[i]);
    num[0] = 0;
    int ans = num[1];
    for(int i = 1; i <= N; i++)
    {
        if(num[i - 1] > 0) num[i] += num[i - 1];
        else num[i] += 0;
        if(num[i] > ans) ans = num[i];
    }
    return ans;
}

int main()
{
    int M, N, num[50002];
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &N);
        printf("%d\n", func(num, N));
    }
    return 0;
}


