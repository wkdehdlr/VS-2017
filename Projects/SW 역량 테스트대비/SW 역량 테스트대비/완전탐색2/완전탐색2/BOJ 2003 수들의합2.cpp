#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;
int N, M;
int sum,cnt;

int main()
{
	scanf("%d %d", &N, &M);
	vec.resize(N + 1);
	cnt = 0;

	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &vec[i]);
	}

	for (int i = 1; i <= N; ++i)
	{
		sum = 0;
		for (int j = i; j <= N; ++j)
		{
			sum += vec[j];
			if (sum == M)
			{
				cnt++;
				break;
			}

			if (sum > M)
			{
				break;
			}
		}
	}

	printf("%d\n", cnt);
}
