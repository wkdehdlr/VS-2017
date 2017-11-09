#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string str;
vector<int> vec;
vector<int> vec2(6);
int N;


void nck(int, int);
int main()
{
	int start = 1;
	freopen("input.txt", "r", stdin);
	while (1)
	{
		scanf("%d", &N);
		if (N == 0)break;
		if(start==0)printf("\n");
		vec.clear();
		for (int i = 0; i < N; ++i)
		{
			int temp;
			scanf("%d", &temp);
			vec.push_back(temp);
		}
		nck(N, 6);
		start = 0;
	}
}

void nck(int n, int k)
{
	if (k == 0)
	{
		for (int x : vec2)
		{
			printf("%d ", x);
		}
		printf("\n");
	}
	else if (n < k)
	{
		return;
	}
	else
	{
		vec2[6 - k] = vec[N - n];
		nck(n - 1, k - 1);
		nck(n - 1, k);
	}
}