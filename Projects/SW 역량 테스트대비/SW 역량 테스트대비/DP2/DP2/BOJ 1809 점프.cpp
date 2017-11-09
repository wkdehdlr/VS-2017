#include<iostream>
#include<vector>
using namespace std;

int N;


int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	vector<vector<int> > vec(N + 1, vector<int>(N + 1));
	vector<vector<long long> > dp(N + 1, vector<long long>(N + 1));

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &vec[i][j]);
		}
	}

	dp[1][1] = 1;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if ((!(i == N && j == N)) && dp[i][j] != 0)
			{
				int num = vec[i][j];
				if (num == 0)
				{
					dp[i][j] = 0;
					continue;
				}

				if (i + num <= N)
				{
					dp[i + num][j]+=dp[i][j];
				}

				if (j + num <= N)
				{
					dp[i][j + num]+=dp[i][j];
				}
			}
		}
	}
	printf("%lld\n", dp[N][N]);
}