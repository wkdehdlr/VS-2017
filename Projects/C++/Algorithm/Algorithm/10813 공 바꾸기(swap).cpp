#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	int N, M, temp1, temp2;

	freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i <= N; i++)
	{
		vec.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2;
		swap(vec[temp1], vec[temp2]);
	}

	for (int i = 1; i <= N; i++)
	{
		cout << vec[i] << " ";
	}
}