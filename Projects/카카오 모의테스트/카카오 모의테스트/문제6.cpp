#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{

	vector<int> vec = { 14, 6, 5, 11, 3, 9, 2, 10 };
	vector<int> dp;
	int temp;
	int max1, max2, max3;

	if (vec.size() >= 5)
	{
		dp.push_back(vec[0]);		dp.push_back(vec[0]);		dp.push_back(vec[0] + vec[2]);
		for (int i = 3; i < vec.size() - 1; ++i)
		{
			temp = max(dp[i - 3], dp[i - 2]);
			temp = max(temp + vec[i], dp[i - 1]);
			dp.push_back(temp);
			max1 = temp;
		}

		dp.clear();
		dp.push_back(vec[1]);		dp.push_back(vec[1]);		dp.push_back(vec[1]);
		for (int i = 3; i < vec.size(); ++i)
		{
			temp = max(dp[i - 3], dp[i - 2]);
			temp = max(temp + vec[i], dp[i - 1]);
			dp.push_back(temp);
			max2 = temp;
		}


		dp.clear();
		dp.push_back(vec[2]);		dp.push_back(vec[2]);		dp.push_back(vec[2]);
		for (int i = 3; i < vec.size(); ++i)
		{
			temp = max(dp[i - 3], dp[i - 2]);
			if (i == vec.size()-1)
			{
				temp = max(temp + vec[0], dp[i - 1]);
			}
			else
			{
				temp = max(temp + vec[i+1], dp[i - 1]);
			}
			dp.push_back(temp);
			max3 = temp;
		}
		//cout << max3<<'\n';
		cout << max(max3, max(max1, max2)) << '\n';
	}
	else//크기가 4이하일때
	{
		if (vec.size() <= 3)
		{
			auto it = max_element(vec.begin(), vec.end());
			cout << (*it) << '\n';
		}
		else
		{
			cout << max(vec[0] + vec[2], vec[1] + vec[3]) << '\n';
		}
	}
}