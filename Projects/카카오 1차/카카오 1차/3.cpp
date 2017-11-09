#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<list>
#include <algorithm>
using namespace std;

void makeLowerChar(char&);

int main()
{
	
	list<string> list;
	map<string, int> map;
	vector<string> str = { "a","b","c","d","e","f","g","h","i","j","e","f","g","h" };
	int cacheSize = 10;
	int total = 0;
	int strSize;


	strSize = str.size();



	for (int i = 0; i < strSize; ++i)
	{
		for_each(str[i].begin(), str[i].end(), makeLowerChar);
		//transform(str[i].begin(), str[i].end(), str[i].begin(), tolower);
		map[str[i]] = 0;
	}

	if (cacheSize == 0)
	{
		for (int i = 0; i < strSize; ++i)
		{
			if (map[str[i]] == 0)//없으면
			{
				if (list.size() == 0)
				{
					map[str[i]] = 1;
					total += 5;
				}
			}
			else//이미 있으면
			{
				total += 1;
			}
		}
		cout << total;
		return 0;
	}


	for (int i = 0; i < strSize; ++i)
	{
		if (list.size() < cacheSize)
		{
			if (map[str[i]] == 0)
			{
				list.push_back(str[i]);
				map[str[i]] = 1;//miss
				total += 5;
			}
			else
			{
				for (auto it = list.begin(); it != list.end(); ++it)
				{
					if ((*it).compare(str[i]) == 0)
					{
						list.erase(it);
						break;
					}
				}
				list.push_front(str[i]);
				total += 1;
				//hit
			}
		}
		else//꽉참
		{
			if (map[str[i]] == 1)//hit 이미있다.
			{
				for (auto it = list.begin(); it != list.end(); ++it)
				{
					if ((*it).compare(str[i]) == 0)
					{
						list.erase(it);
						break;
					}
				}
				list.push_front(str[i]);
				total += 1;
			}
			else//miss
			{
				map[*(list.begin())] = 0;
				list.erase(list.begin());
				list.push_back(str[i]);
				map[str[i]] = 1;
				total += 5;
			}
		}
	}
	cout << total;
}
void makeLowerChar(char& c)
{
	c = tolower(c);
}