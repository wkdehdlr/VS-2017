#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	int N, M, i1, k, j;
	freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		vec.push_back(i + 1);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> i1 >> j >> k;
		rotate(vec.begin() + i1 - 1, vec.begin() + k - 1, vec.begin() + j);
	}

	for (int i = 0; i < N; i++)
	{
		cout << vec[i] << " ";
	}
}
