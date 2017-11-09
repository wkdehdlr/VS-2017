#include<iostream>
using namespace std;

int dr[4] = { 1,1,-1,-1 };
int dc[4] = { 1,-1,-1, 1 };

int kind[101];
bool visited[21][21];

int arr[21][21];
int N;
int tempX, tempY;
int maxN = 0;

void DFS(int,int,int,int);
int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; ++tc)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < 101; ++i)
		{
			kind[i] = 0;
		}

		maxN = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 1; i < N - 1; ++i)
		{
			for (int j = 2; j < N; ++j)
			{
				tempX = i;
				tempY = j;
				DFS(i,j,1,0);
			}
		}
		if (maxN == 0)
			maxN = -1;
		printf("#%d %d\n", tc + 1, maxN);
	}
}
void DFS(int x,int y,int cnt,int dir)
{
	//if (x == tempX && y == tempY && cnt != 0)
	//{
	//	if (maxN < cnt)
	//		maxN = cnt;
	//}
	//else
	//{
		//cnt += arr[x][y];
		visited[x][y] = true;
		kind[arr[x][y]] = 1;
		for (int i = dir; i < dir + 2; ++i)
		{
			int r = x + dr[i];
			int c = y + dc[i];
			if (r == tempX && c == tempY && cnt != 1)
			{
				if (maxN < cnt)
					maxN = cnt;
				continue;
			}

			if (r >= 1 && r <= N && c >= 1 && c <= N && visited[r][c] == false && kind[arr[r][c]] == 0)
			{
				DFS(r, c, cnt + 1, i);
			}
			if (dir == 3)
				break;
		}
		visited[x][y] = false;
		kind[arr[x][y]] = 0;
	//}
}