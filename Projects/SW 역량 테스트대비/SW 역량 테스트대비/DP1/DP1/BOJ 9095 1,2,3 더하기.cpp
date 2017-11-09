#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
int Tc;
int num;

int main()
{
	scanf("%d", &Tc);

	for (int i = 0; i < Tc; ++i)
	{
		scanf("%d", &num);
		dp.clear();
		dp.resize(num + 1);
		if (num == 1)
		{
			printf("1\n"); continue;
		}
		if (num == 2)
		{
			printf("2\n"); continue;
		}
		if (num == 3)
		{
			printf("4\n"); continue;
		}
		dp[1] = 1; dp[2] = 2; dp[3] = 4;
		for (int k = 4; k <= num; ++k)
		{
			dp[k] = dp[k - 1] + dp[k - 2] + dp[k - 3];
		}
		printf("%d\n", dp[num]);
	}
}