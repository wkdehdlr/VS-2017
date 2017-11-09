#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	vector<int> vec;
	int N, M, temp;
	freopen("input.txt", "r", stdin);
	//cin >> N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		//cin >> temp;
		scanf("%d", &temp);
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	//cin >> M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &temp);
		//cin >> temp;
		if (binary_search(vec.begin(), vec.end(), temp))
		{
			printf("1 ");
			//cout << 1 << " ";
		}
		else
		{
			printf("0 ");
			//cout << 0 << " ";
		}
	}
}