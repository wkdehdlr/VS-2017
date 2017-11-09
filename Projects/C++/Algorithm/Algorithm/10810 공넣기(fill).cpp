#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, M, temp1,temp2,temp3;
	vector<int> vec;


	freopen("input.txt", "r", stdin);

	for (int i = 0; i < 100; i++)
	{
		vec.push_back(0);
	}
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2 >> temp3;
		fill(vec.begin() + temp1 - 1, vec.begin() + temp2 , temp3);
	}

	for (int i = 0; i < N; i++)
	{
		cout << vec[i] << " ";
	}
}