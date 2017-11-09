#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	vector<vector<int> > vec(N + 1, vector<int>(N + 1));
	vector<vector<long long> > dp(N + 1, vector<long long>(N + 1));
	queue<pair<int, int> >q;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &vec[i][j]);
		}
	}
	dp[1][1] = 1;
	q.push(make_pair(1 + vec[1][1], 1));
	dp[1 + vec[1][1]][1] = 1;
	q.push(make_pair(1, 1 + vec[1][1]));
	dp[1][1 + vec[1][1]] = 1;


	while (!(q.empty()))
	{
		int num1 = q.front().first;
		int num2 = q.front().second;
		int num3 = vec[num1][num2];
		q.pop();

		if (num1 == N && num2 == N)continue;
		if (num3 == 0)
		{
			dp[num1][num2] = 0;
			continue;
		}
		if (num1 + num3 <= N)
		{
			dp[num1 + num3][num2] += dp[num1][num2];
			q.push(make_pair(num1 + num3, num2));
		}

		if (num2 + num3 <= N)
		{
			dp[num1][num2 + num3] += dp[num1][num2];
			q.push(make_pair(num1, num2 + num3));
		}
	}

	printf("%lld\n", dp[N][N]);
}