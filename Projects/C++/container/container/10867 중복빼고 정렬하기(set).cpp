#include<iostream>
#include<set>
using namespace std;


int main()
{

	set<int> set1;
	int N, temp;

	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		set1.insert(temp);
	}

	for (auto it = set1.begin(); it != set1.end(); ++it)
	{
		cout << *it << ' ';
	}
}