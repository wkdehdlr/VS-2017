#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, x, y;
	freopen("input.txt", "r", stdin);

	cin >> N;
	vector<pair<int,int>> vec;
	
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		vec.push_back({ x,y });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].first << " " << vec[i].second << '\n';
	}
}