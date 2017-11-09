#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
int N;

int main()
{
	scanf("%d", &N);
	if (N == 1)
	{
		printf("1\n");
		return 0;
	}
	if (N == 2)
	{
		printf("2\n");
		return 0;
	}
	dp.resize(N + 1);
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= N; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}

	printf("%d\n", dp[N] % 10007);
}