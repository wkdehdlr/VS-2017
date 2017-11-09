#include<iostream>
#include<list>
using namespace std;


int main()
{
	list<int> list;
	int N, M, cnt = 0, step;

	freopen("input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		list.push_back(i);
	}

	cout << '<';
	for (auto it = list.begin(); cnt < N;)
	{
		step = 1;
		while(step < M)
		{
			it++;
			step++;
			if (it == list.end())
			{
				it = list.begin();
			}
		}
		if (cnt == N - 1)
		{
			cout << (*it); break;
		}
		cout << (*it) <<  ", ";
		it = list.erase(it);
		if (it == list.end())
		{
			it = list.begin();
		}
		cnt++;
	}
	cout << ">\n";
}