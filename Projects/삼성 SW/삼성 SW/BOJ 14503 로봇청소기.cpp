#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

int vec[50][50];
int N, M;
int r, c, w;
queue<pair<int,int> > q;
int sum = 0;

int main()
{
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &w);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &vec[i][j]);
		}
	}
	vec[r][c] = 2;
	q.push(make_pair(r, c));
	sum = 1;


	while (!q.empty())
	{
		int R = q.front().first;
		int C = q.front().second;
		q.pop();
		int cnt = 0;
		int i = w;
		while(1)
		{
			//int i = w;
			int x = R + dr[i];
			int y = C + dc[i];

			if (x >= 0 && x < N && y >= 0 && y < M && vec[x][y] == 0)
			{
				vec[x][y] = 2;
				sum++;
				q.push(make_pair(x, y));
				w = 3 - i;
				if (w == 4)
					w = 0;
				break;
			}
			i++;
			cnt++;
			if (cnt == 4)
			{
				if ((w + 2) == 5)
				{
					if (vec[R + dr[0]][C + dc[0]] == 1)
					{
						printf("%d\n", sum);
						return 0;
					}
					q.push(make_pair(R + dr[0], C + dc[0]));
					break;
				}
				if (vec[R + dr[w + 1]][C + dc[w + 1]] == 1)
				{
					printf("%d\n", sum);
					return 0;
				}
				q.push(make_pair(R + dr[w + 1], C + dc[w + 1]));
				break;
			}
			if (i == 4)
				i = 0;
		}
	}
}