#include<stdio.h>

int arr[100][100];
int N, M;
int min;
void dfs(int r, int c,int s);
int main()
{
	int Tc;


	freopen("input.txt", "r", stdin);
	scanf("%d", &Tc);

	for (int t = 1; t <= Tc; t++)
	{

		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		min = 0x7fffffff;
		dfs(0, 0, 0);
		if (min == 0x7fffffff)
			min = 0;
		printf("#%d %d\n", t, min);
	}
}
void dfs(int r, int c, int s)
{
	if ((r == N - 1) && (c == M - 1))
	{
		if (s + arr[N - 1][M - 1] < min)
		{
			min = s + arr[N - 1][M - 1];
		}
	}

	else
	{
		if ((c + 1 < M) && arr[r][c + 1] != 0)//&& arr[t][c] != 0
		{
			dfs(r, c + 1, s + arr[r][c]);
		}
		if ((r + 1 < N) && arr[r + 1][c] != 0)
		{
			dfs(r + 1, c, s + arr[r][c]);////
		}
	}
}