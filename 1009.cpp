#include<iostream>
#include<algorithm>
using namespace std;

const int N = 101;
int A[N], dp[N];

int main()
{
	int M;
	cin >> M;
	for (int x = 0; x < M; x++)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> A[i];
		int ans = -1;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = 1;
			for (int j = 1; j < i; j++)
				if (A[i] <= A[j] && (dp[j] + 1 > dp[i]))
					dp[i] = dp[j] + 1;
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}