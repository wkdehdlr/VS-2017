#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<long long> vec;
int main()
{
	int min1, min2;
	int N,min = 0x7fffffff;
	long long ans;
	scanf("%d", &N);

	vec.resize(N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%lld", &vec[i]);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N - 1; ++i)
	{
		if (vec[i + 1] - vec[i] < min)
		{
			min = vec[i + 1] - vec[i];
			min1 = i;
		}
	}


	if (vec[min1] < vec[min1 + 1])
	{
		printf("%d %d\n", vec[min1], vec[min1 + 1]);
	}
	else
	{
		printf("%d %d\n", vec[min1 + 1], vec[min1]);
	}
}