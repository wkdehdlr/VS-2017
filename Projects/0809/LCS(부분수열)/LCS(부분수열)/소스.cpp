#include<stdio.h>

int x[11];
int y[11];
int d[11][11];

int main()
{
	int N, M;
	int Tc;
	freopen("input.txt", "r", stdin);
	//scanf("%d", &Tc);

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &x[i]);
	}
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &y[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (x[i] == y[j])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = d[i - 1][j] > d[i][j - 1] ? d[i - 1][j] : d[i][j - 1];
		}
	}

	printf("%d\n", d[N][M]);
}