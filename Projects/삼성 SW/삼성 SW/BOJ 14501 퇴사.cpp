#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vecT(16);
vector<int> vecP(16);
vector<int> dp(16);
//vector<vector<int> > dp(16, vector<int>(16));
int N;
int sum = 0;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d", &vecT[i], &vecP[i]);
	}

	if (vecT[N] == 1)
	{
		dp[N] = vecP[N];
	}
	else
	{
		dp[N] = 0;
	}


	for (int i = N-1; 1 <= i; --i)
	{
		int tmp = vecT[i] + i - 1;
		if (tmp <= N)
		{
			if (tmp == N)
			{
				dp[i] = max(dp[i + 1], vecP[i]);
			}
			else
			{
				dp[i] = max(dp[i + 1], vecP[i] + dp[i + vecT[i]]);
			}
		}
		else
		{
			dp[i] = dp[i + 1];
		}
	}
	printf("%d\n", dp[1]);
}