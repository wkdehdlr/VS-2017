#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> vec(1001);
vector<int> dp(1001);

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &vec[i]);
	}

	dp[1] = vec[1];
	if (N == 1)
	{
		printf("%d", dp[1]);
		return 0;
	}
	dp[2] = max(vec[2], dp[1] + vec[1]);
	if (N == 2)
	{
		printf("%d", dp[2]);
		return 0;
	}

	for (int i = 3; i <= N; ++i)
	{
		int maxV = vec[i];
		for (int j = i - 1; 1 <= j; --j) 
		{
			int temp = dp[j] + vec[i - j];
			if (maxV < temp)
			{
				maxV = temp;
			}
		}
		dp[i] = maxV;
	}
	printf("%d\n", dp[N]);
}