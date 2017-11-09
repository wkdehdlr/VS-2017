#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<pair<int,int>> list;
	int num, temp, temp2, cnt = 0, ct = 0;

	freopen("input.txt", "r", stdin);

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		list.push_back(make_pair(i + 1,temp));
		//list.push_back({ i+1,temp });
	}

	/*auto i = list.begin();
	list.remove((*i));
	cout << (*i).first << '\n';*/
	

	for (auto it = list.begin(); cnt < num;)
	{
		auto it2 = it; 
		auto it3 = list.end(); it3--;//it2¿¡
		ct = 0;
		cout << (*it).first;
		if (cnt == num - 1)
		{
			cout << '\n';
			break;
		}
		else
		{
			cout << ' ';
		}
		temp2 = (*it).second;
		it = list.erase(it2);
		if (it == list.end())
		{
			it = list.begin();
			it3 = list.end(); it3--;
		}

		/*if (cnt == num - 1)
			break;*/
		if (temp2 > 0)
		{
			while (ct < temp2 - 1)
			{
				if (it == it3)
				{
					it = list.begin();
				}
				else
				{
					it++;
				}
				ct++;
			}
		}
		else
		{
			while (ct > temp2)
			{
				if (it == list.begin())
				{
					it = it3;
				}
				else
				{
					it--;
				}
				ct--;
			}
		}
		//list.erase(it2);
		//list.remove(*it2);
		cnt++;
	}
}