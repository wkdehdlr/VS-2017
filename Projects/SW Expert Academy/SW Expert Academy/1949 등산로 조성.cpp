#include<iostream>
using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int arr[9][9];
bool visited[9][9];
int N,K;
int maxN = 0;

void DFS(int, int, int, int);
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int te = 0; te < tc; ++te)
	{
		scanf("%d %d", &N, &K);
		int maxT = 0;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
				if (maxT < arr[i][j])
					maxT = arr[i][j];
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (arr[i][j] == maxT)
				{
					int flag = 1; 
					int cnt = 1;
					DFS(i, j, flag, cnt);
				}
			}
		}
		printf("#%d %d\n", te + 1, maxN);
		maxN = 0;
	}
}

void DFS(int x, int y, int flag, int cnt)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		int r = x + dr[i];
		int c = y + dc[i];
		if (r >= 1 && r <= N && c >= 1 && c <= N && visited[r][c] == false)
		{
			if (arr[x][y] > arr[r][c])//안깍아도 갈수있음
			{
				DFS(r, c, flag, cnt + 1);
			}
			else//깍아야 갈수있음
			{
				if (flag == 1)//아직 깍을수있음
				{
					for (int t = 1; t <= K; ++t)
					{
						if (arr[r][c] - t < arr[x][y])
						{
							int temp = arr[r][c];
							arr[r][c] -= t;
							DFS(r, c, 0, cnt + 1);
							arr[r][c] = temp;
						}
					}
				}
			}
		}
	}
	visited[x][y] = false;	
	if (maxN < cnt)
		maxN = cnt;
}