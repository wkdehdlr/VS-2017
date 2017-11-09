#include<iostream>
#include<vector>
using namespace std;

vector<int> num;
vector<vector<int> > dp(2001, vector<int>(2001,0));
int N,M,S,E;

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	num.resize(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &num[i]);
	}


	for (int i = N; i >= 1; --i)
	{
		for (int j = i; j <= N; ++j)
		{
			if (i > j)continue;
			if (i == j)
			{
				dp[i][j] = 1; continue;
			}
			if (i == j - 1 && num[i] == num[j])
			{
				dp[i][j] = 1; continue;
			}
			if (dp[i + 1][j - 1] == 1 && num[i] == num[j])
			{
				dp[i][j] = 1; continue;
			}
		}
	}

	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &S, &E);
		printf("%d\n", dp[S][E]);
	}
}