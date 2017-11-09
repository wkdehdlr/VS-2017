#include<iostream>
#include<queue>
using namespace std;


int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

queue<pair<int, int> > q;
int visited[50][50];
int arr[50][50];
int N, M, R, C, L;
int cnt = 0;

void BFS();
int main()
{
	int tc;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++)
	{
		for (int dx = 0; dx < 50; dx++)
		{
			for (int dy = 0; dy < 50; dy++)
			{
				visited[dx][dy] = 0;
			}
		}
		cnt = 0;
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		q.push(make_pair(R, C));
		visited[R][C] = 1;
		BFS();
		printf("#%d %d\n", t + 1, cnt);
	}
}
void BFS()
{
	while (!q.empty())
	{
		cnt++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (visited[x][y] == L)continue;

		int dir = arr[x][y];

		for (int i = 0; i < 4; ++i)
		{
			int r = x + dr[i];
			int c = y + dc[i];
			if (r >= 0 && r < N && c >= 0 && c < M && visited[r][c] == 0 && arr[r][c] != 0)
			{
				if (i == 0)
				{
					if (dir == 1 || dir == 3 || dir == 6 || dir == 7)
					{
						if (arr[r][c] == 1 || arr[r][c] == 3 || arr[r][c] == 4 || arr[r][c] == 5)
						{
							visited[r][c] = visited[x][y]+1;
							q.push(make_pair(r, c));
						}
					}
				}
				else if (i == 1)
				{
					if (dir == 1 || dir == 2 || dir == 5 || dir == 6)
					{
						if (arr[r][c] == 1 || arr[r][c] == 2 || arr[r][c] == 4 || arr[r][c] == 7)
						{
							visited[r][c] = visited[x][y] + 1;
							q.push(make_pair(r, c));
						}
					}
				}
				else if (i == 2)
				{
					if (dir == 1 || dir == 3 || dir == 4 || dir == 5)
					{
						if (arr[r][c] == 1 || arr[r][c] == 3 || arr[r][c] == 6 || arr[r][c] == 7)
						{
							visited[r][c] = visited[x][y] + 1;
							q.push(make_pair(r, c));
						}
					}
				}
				else
				{
					if (dir == 1 || dir == 2 || dir == 4 || dir == 7)
					{
						if (arr[r][c] == 1 || arr[r][c] == 2 || arr[r][c] == 5 || arr[r][c] == 6)
						{
							visited[r][c] = visited[x][y] + 1;
							q.push(make_pair(r, c));
						}
					}
				}
			}
		}
	}
}