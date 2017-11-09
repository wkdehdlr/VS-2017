#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N, M;

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	vector<vector<int> > vec(N + 1, vector<int>(M + 1));
	vector<vector<int> > dp(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			scanf("%d", &vec[i][j]);
		}
	}

	//dp[1][1] = vec[1][1];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (i == 1)
			{
				dp[i][j] = vec[i][j] + dp[i][j - 1];
				continue;
			}

			if (j == 1)
			{
				dp[i][j] = vec[i][j] + dp[i - 1][j];
				continue;
			}
			dp[i][j] = vec[i][j] + max(dp[i][j - 1],max(dp[i - 1][j - 1], dp[i - 1][j]));
		}
	}

	printf("%d\n", dp[N][M]);
}