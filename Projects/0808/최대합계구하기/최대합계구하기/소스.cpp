#include<stdio.h>

int arr[101][101];
int mrr[101][101];//DP문제는 1번부터 쓰는게 일반적이

int max(int num1, int num2);
int min(int num1, int num2);

int main()
{
	int Tc;
	int N, M;

	freopen("input.txt", "r", stdin);
	scanf("%d", &Tc);

	for (int t = 1; t <= Tc; t++)
	{
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (i == 1 && j > 1)
				{
					arr[i][j] = arr[i][j] + arr[i][j-1];
				}

				if (j == 1 && i > 1)
				{
					arr[i][j] = arr[i][j] + arr[i-1][j];
				}

				if (i >= 2 && j >= 2)
				{
					arr[i][j] = arr[i][j] + min(arr[i][j - 1], arr[i - 1][j]);
				}
			}
		}
		printf("#%d %d\n", t, arr[N][M]);
	}
}
int min(int num1, int num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}
int max(int num1, int num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;
}