#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	int temp, N;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &temp);
		vec.push_back(temp);
	}

	auto it = min_element(vec.begin(), vec.end());
	cout << (*it) << " ";
	it = max_element(vec.begin(), vec.end());
	cout << (*it) << '\n';
}