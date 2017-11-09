#include<stdio.h>

int arr[100][100];
//int map[100][100];
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int N;
int x1,y1;

int next(int nr, int nc);

int main()
{
	int res;
	int Tc;
	
	freopen("input.txt", "r", stdin);

	scanf("%d", &Tc);
	for (int i = 1; i <= Tc; i++)
	{
		scanf("%d", &N);
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++)
			{
				scanf("%1d", &arr[x][y]);
			}
		}
		int x = 0, y = 0;
		while (x < N && y < N)
		{
			if (arr[x][y] == 2)
			{
				break;
			}
			x++; y++;
		}
		x1 = x; y1 = y;
		res = next(x1, y1);

		if (res == 1)
		{
			printf("#%d 1\n",i);
		}
		else
		{
			printf("#%d 0\n",i);
		}

		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++)
			{
				arr[x][y] = 0;
			}
		}
	}
}

int next(int nr, int nc)
{
	if (arr[nr][nc] == 3)
	{
		return 1;
	}
	else
	{
		arr[nr][nc] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nr1, nc1;
			nr1 = nr + dr[i];
			nc1 = nc + dc[i];
			if (nr1 >= 0 && nr1 < N && nc1 >= 0 && nc1 < N)
			{
				if (arr[nr1][nc1] != 1)
				{
					//x1 = nr; y1 = nc;
					//return
					if (next(nr1, nc1) == 1)
						return 1;
				}
			}
		}
		return 0;
	}
	//return 0;
}