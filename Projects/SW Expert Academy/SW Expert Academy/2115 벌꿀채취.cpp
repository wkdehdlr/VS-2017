#include<iostream>
using namespace std;

int N,M,C;
int arr[11][11];
int maxN = 0;
int maxN2 = 0;
int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++)
	{
		maxN = 0; maxN2 = 0;
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N - M + 1; ++j)
			{
				int temp = 0;
				int temp2 = 0;
				for (int k = j; k <= j + M - 1; k++)
				{
					temp += arr[i][k];
					if (temp <= C)
					{
						temp2 += (arr[i][k] * arr[i][k]);
					}
				}
				if (maxN < temp2)
					maxN = temp2;
				if (maxN2 < temp2 && temp2 < maxN)
					maxN2 = temp2;
			}
		}
		printf("#%d %d\n", tc + 1, maxN + maxN2);
	}
}