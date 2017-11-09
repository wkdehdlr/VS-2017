#include<iostream>
#include<vector>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int arr[50][50];
int N, M;
int r, c, w;
int sum = 0;

void dfs(int,int);
int main()
{
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &w);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(r,c);
}
void dfs(int x, int y)
{
	int tmp = 0;
	arr[x][y] = 2;
	sum++;


	if (w == 0)
	{
		for (int i = 0; i < 4; ++i)
		{
			int dx = x + dr[i];
			int dy = y + dc[i];
			if (dx >= 0 && dx < N && dy >= 0 && dy < M && arr[dx][dy] == 0)
			{
				w = 3 - i;
				dfs(dx, dy);
				return;
			}
		}

		if (x + 1 >= 0 && x + 1 < N && y >= 0 && y < M && arr[x + 1][y] == 1)
		{
			printf("%d\n", sum);
			return;
		}

		if (x + 1 >= 0 && x + 1 < N && y >= 0 && y < M && arr[x + 1][y] == 2)
		{
			sum--;
			dfs(x + 1, y);
		}
	}
	else
	{
		for (int i = 4 - w; i < 5; ++i)
		{
			if (i == 4)
				i = 0;
			if (tmp == 4)
				break;
			{
				tmp++;
				int dx = x + dr[i];
				int dy = y + dc[i];
				if (dx >= 0 && dx < N && dy >= 0 && dy < M && arr[dx][dy] == 0)
				{
					w = 3 - i;
					dfs(dx, dy);
					return;
				}
			}
		}

		if (w == 3)
		{
			if (x >= 0 && x < N && y + 1 >= 0 && y + 1 < M && arr[x][y + 1] == 1)
			{
				printf("%d\n", sum);
				return;
			}

			if (x >= 0 && x < N && y + 1 >= 0 && y + 1 < M && arr[x][y + 1] == 2)
			{
				sum--;
				dfs(x, y + 1);
				return;
			}
		}
		else if (w == 2)
		{
			if (x - 1 >= 0 && x - 1 < N && y >= 0 && y < M && arr[x - 1][y] == 1)
			{
				printf("%d\n", sum);
				return;
			}

			if (x - 1 >= 0 && x - 1 < N && y >= 0 && y < M && arr[x - 1][y] == 2)
			{
				sum--;
				dfs(x - 1, y);
				return;
			}
		}
		else
		{
			if (x >= 0 && x < N && y - 1 >= 0 && y - 1 < M && arr[x][y - 1] == 1)
			{
				printf("%d\n", sum);
				return;
			}

			if (x >= 0 && x < N && y - 1 >= 0 && y - 1 < M && arr[x][y - 1] == 2)
			{
				sum--;
				dfs(x, y - 1);
				return;
			}
		}
	}

}