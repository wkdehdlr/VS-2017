#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<vector<int> > dp(2501, vector<int>(2501,0));
vector<int> dp2(2501);
string str;

int main()
{
	freopen("input.txt", "r", stdin);
	getline(cin, str);
	str.insert(0, " ");
	int n = str.length();
	int x, y;

	for (int i = n - 1; 0 < i; --i)
	{
		for (int j = i; j < n; ++j)
		{
			if (i == j)
			{
				dp[i][j] = 1; continue;
			}
			if (i > j)continue;
			if (i == j - 1 && str[i] == str[j])
			{
					dp[i][j] = 1; continue;
			}			
			if (dp[i + 1][j - 1] == 1 && str[i] == str[j])
			{
					dp[i][j] = 1;
			}
		}
	}
	dp2[1] = 1;
	for (int i = 2; i < n; ++i)
	{
		dp2[i] = 0x7fffffff;
		for (int j = 1; j <= i; ++j)
		{
			if (dp[j][i] == 1)
			{
				dp2[i] = min(dp2[i], dp2[j - 1] + 1);
			}
		}
	}
	printf("%d\n", dp2[n-1]);
}