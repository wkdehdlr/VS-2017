#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
int n;

int main()
{
	scanf("%d", &n);
	if (n <= 2)
	{
		if (n == 1)
		{
			printf("1\n");
		}
		else
		{
			printf("3\n");
		}
		return 0;
	}
	dp.resize(n + 1);
	dp[1] = 1; dp[2] = 3;
	for (int i = 3; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + (dp[i - 2]*2);
		dp[i] %= 10007;
	}

	printf("%d\n", dp[n] % 10007);
}