#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<list>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	vector<int> vec;
	vector<int> used(7,0);
	string str, temp;
	list<int> list;
	int flag = 0;


	getline(cin, str);
	istringstream str2(str);

	while (getline(str2, temp, ' '))
	{
		vec.push_back(stoi(temp));
	}


	for (int i : vec)
	{
		if (used[i] == 0 && list.size() < 3)//miss
		{
			list.push_back(i);
			used[i] = 1;
			continue;
		}

		if (used[i] == 0 && list.size() == 3)//사용은 안했는데 리스트가 꽉찼을때
		{
			flag = 1;
			printf("%d\n", list.front());
			used[list.front()] = 0;
			list.pop_front();
			list.push_back(i);
			used[i] = 1;
			continue;
		}

		if (used[i] == 1)//hit 이미 주머니에 있다.
		{
			for (auto it = list.begin(); it != list.end(); ++it)
			{
				if ((*it) == i)
				{
					list.erase(it);
					break;
				}
			}
			list.push_back(i);
			continue;
		}
	}
	if (flag == 0)
	{
		printf("0\n");
	}
}