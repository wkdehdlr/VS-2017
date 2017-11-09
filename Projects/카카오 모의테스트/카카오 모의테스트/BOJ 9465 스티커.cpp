#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector< vector<int> > vec(3, vector<int>(100001));
vector< vector<int> > dp(3, vector<int>(100001));
int Tc;
int N;

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &Tc);

	for (int t = 0; t < Tc; ++t)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &vec[1][i]);
		}

		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &vec[2][i]);
		}

		if (N == 1 || N == 2)
		{
			if (N == 1)
			{
				printf("%d\n",max(vec[1][1], vec[2][1]));
			}
			else
			{
				printf("%d\n",max(vec[1][1] + vec[2][2], vec[1][2] + vec[2][1]));
			}
			continue;
		}


		dp[1][1] = vec[1][1]; dp[1][2] = vec[1][2]+vec[2][1]; dp[2][1] = vec[2][1]; dp[2][2] = vec[2][2] + vec[1][1];

		for (int y = 3; y <= N; ++y)
		{
			for (int x = 1; x <= 2; ++x)
			{
				if (x == 2)
				{
					dp[x][y] = max(dp[x - 1][y - 1] + vec[x][y], dp[x - 1][y - 2] + vec[x][y]);
				}
				else//x==1
				{
					dp[x][y] = max(dp[x + 1][y - 1] + vec[x][y], dp[x + 1][y - 2] + vec[x][y]);
				}
			}
		}

		printf("%d\n", max(dp[1][N], dp[2][N]));
	}
}