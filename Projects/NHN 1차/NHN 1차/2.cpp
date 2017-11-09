#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

string str1, str2, tmp;

int main()
{
	freopen("input.txt", "r", stdin);
	vector<string> vec;


	getline(cin, str1);
	istringstream str3(str1);

	while (getline(str3, tmp, ' '))
	{
		vec.push_back(tmp);
	}

	tmp.clear();
	if (vec[0].compare("encrypt") == 0)//암호화
	{
		for (int i = 0; i < vec[1].size(); ++i)
		{
			int num = ((vec[1][i] - 'a') + (vec[3][i] - 'a'));
			if (num > 25)
			{
				num %= 25;
				num--;
			}
			tmp.push_back(num + 'a');
		}
		int len = stoi(vec[2]);
		for (int i = 0; i < len; ++i)
		{
			rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
		}
		cout << tmp << '\n';
	}
	else//복호화
	{
		int len = stoi(vec[2]);
		for (int i = 0; i < len; ++i)
		{
			rotate(vec[3].rbegin(), vec[3].rbegin() + 1, vec[3].rend());
		}


		for (int i = 0; i < vec[1].size(); ++i)
		{
			int num = ((vec[3][i] - 'a') - (vec[1][i] - 'a'));
			if (num < 0)
			{
				num = ((vec[3][i] - 'a') +26) - (vec[1][i] - 'a');
			}
			tmp.push_back(num + 'a');
		}
		cout << tmp << '\n';
	}
}