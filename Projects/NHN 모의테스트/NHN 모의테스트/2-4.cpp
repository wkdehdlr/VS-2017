#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;



void makeLowerChar(char&);

int main()
{
	int tmpN;
	string str,tmp;
	string str1;
	map<string, int> map2;
	vector<pair<int, string> > vec;

	freopen("input.txt", "r", stdin);

	while (getline(cin, str))
	{
		str1.append(str);
	}

	for (int i = 0; i < str1.length(); ++i)
	{
		for_each(str1.begin(), str1.end(), makeLowerChar);
	}


	tmpN = 0;
	for (int i = 0; i < str1.length(); ++i)
	{		
		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			int j = i; ++j;
			while (str1[j] >= 'a' && str1[j] <= 'z')
			{
				++j;
			}
			tmp = str1.substr(i, j - i);
			++(map2[tmp]);
			i = j;
		}
	}


	for (auto it = map2.begin(); it != map2.end(); ++it)
	{
		vec.push_back(make_pair(it->second, it->first));
	}
	sort(vec.rbegin(), vec.rend());
//	scanf("%d", &tmpN);
	for (int i = 0; i < vec.size();)
	{
		int cnt = vec[i].first;
		int j = i;
		while (1)
		{
			++j;
			if (j == vec.size())
				break;
			if (cnt != vec[j].first)
				break;
		}

		for (int k = i; k < j; ++k)
		{
			for (int t = i; t < j - k - 1; ++t)
			{
				if (vec[t].first == vec[t + 1].first)
				{
					if (vec[t].second > vec[t + 1].second)
					{
						swap(vec[t], vec[t + 1]);
					}
				}
			}
		}
		i = j;
	}


	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i].second << '\n';
	}
}

void makeLowerChar(char& c)
{
	c = tolower(c);
}

