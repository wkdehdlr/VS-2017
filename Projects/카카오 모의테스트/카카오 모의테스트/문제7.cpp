#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> str = { "app", "ap", "p", "l", "e", "ple", "pp" };
	vector<int> dp;
	string t = "apple";
	int flag = 0;
	int n=1, k=0,temp;

	dp.resize(t.length(),0x7fffffff);

	for (int i = 0; i < t.length(); ++i)
	{
		for (int k = 0; k < str.size(); ++k)
		{
			temp = str[k].length();
			if (temp > t.substr(0, i + 1).length()) continue;

			if (temp == t.substr(0, i + 1).length())
			{
				if (t.substr(i - temp + 1, temp).compare(str[k]) == 0)
				{
					dp[i] = 1;
					break;
				}
			}
			else if (temp < t.substr(0, i + 1).length())
			{
				if (t.substr(i - temp + 1, temp).compare(str[k]) == 0)
				{
					if (i == 0)
					{
						dp[i] = 1;
					}
					else
					{
						if (dp[i - temp]  == 0x7fffffff) continue;
						if (dp[i - temp] + 1 < dp[i])
						{
							dp[i] = dp[i - temp] + 1;
						}
					}
				}
			}
		}
	}
	if (dp[t.length() - 1] == 0x7fffffff)
	{
		cout << -1 << '\n';
	}
	cout << dp[t.length()-1] << '\n';
//========================================================================
}