#include<iostream>
#include<algorithm>
using namespace std;

int money[4];
int month[13];
int dp[13];

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; ++tc)
	{
		for (int i = 0; i < 4; ++i)
		{
			scanf("%d", &money[i]);
		}
		for (int i = 1; i <= 12; ++i)
		{
			scanf("%d", &month[i]);
		}

		
		if (month[1] != 0)
		{
			dp[1] = min(money[0] * month[1], money[1]);
		}
		else
		{
			dp[1] = 0;
		}

		if (month[2] != 0)
		{
			dp[2] = dp[1] + min(money[0] * month[2], money[1]);
		}
		else
		{
			dp[2] = dp[1];
		}

		if (month[3] != 0)
		{
			dp[3] = min(money[2], dp[2] + min(money[0] * month[3], money[1]));
		}
		else
		{
			dp[3] = dp[2];
		}

		for (int i = 4; i <= 12; ++i)
		{
			if (month[i] != 0)
			{
				dp[i] = min(dp[i - 3] + money[2], dp[i - 1] + min(month[i] * money[0], money[1]));
			}
			else
			{
				dp[i] = dp[i - 1];
			}
		}

		dp[12] = min(dp[12], money[3]);
		printf("#%d %d\n", tc + 1, dp[12]);
	}
}