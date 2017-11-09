#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	int N, temp;

	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		cout << vec[i] << '\n';
	}
}