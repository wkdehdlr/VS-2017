#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string str;
vector<long long> dp;


int main()
{
	long long num;
	freopen("input.txt", "r", stdin);
	while (getline(cin, str))
	{

		num = str.length();

		dp.resize(num);

		if (num == 1)
		{
			if (str[0] == '0')
			{
				printf("0\n");
			}
			else
			{
				printf("1\n");
			}
			continue;
			//return 0;
		}

		if (str[0] == '0')
		{
			printf("0\n");
			continue;
		}
		if (str[num - 1] == '0' && (str[num - 2] != '1' && str[num - 2] != '2'))
		{
			printf("0\n");
			continue;
		}

		dp[0] = 1;

		for (int i = 1; i < num; ++i)
		{
			if (i == 1)
			{
				if (str[i] == '0')
				{
					dp[i] = dp[i - 1];
				}
				else
				{
					if (str[i - 1] == '1')
					{
						dp[i] = dp[i - 1] + 1;
						continue;
					}
					if (str[i - 1] == '2')
					{
						if (str[i] >= '1' && str[i] <= '6')
						{
							dp[i] = dp[i - 1] + 1;
						}
						else
						{
							dp[i] = dp[i - 1];
						}
						continue;
					}
					dp[i] = dp[i - 1];
				}
			}
			else
			{
				if (str[i] == '0')
				{
					if (str[i - 1] == '1' || str[i - 1] == '2')
					{
						dp[i] = dp[i - 2];				dp[i] %= 1000000;
						continue;
					}
				}
				else
				{
					if (str[i - 1] == '1')
					{
						dp[i] = dp[i - 1] + dp[i - 2];				dp[i] %= 1000000;
						continue;
					}

					if (str[i - 1] == '2')
					{
						if (str[i] >= '1' && str[i] <= '6')
						{
							dp[i] = dp[i - 1] + dp[i - 2];				dp[i] %= 1000000;
							continue;
						}
					}
					dp[i] = dp[i - 1];				dp[i] %= 1000000;
				}
			}
		}
		printf("%lld\n", dp[num - 1] % 1000000);
	}
}
