#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;

queue<tuple<int, int, int, int> > q;
int N, M, K;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

void BFS(int);
int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++)
	{

		scanf("%d %d %d", &N, &M, &K);
		for (int k = 0; k < K; ++k)
		{
			int x, y, cnt, dir;
			scanf("%d %d %d %d", &x, &y, &cnt, &dir);
			if (dir == 1){dir = 3;}
			else if (dir == 2){dir = 1;}
			else if (dir == 3){dir = 0;}
			else{dir = 2;}
			q.push(make_tuple(x, y, cnt, dir));
		}
		for (int ck = 0; ck < M; ck++)
		{
			BFS(ck);
		}
		int total = 0;
		while (!q.empty())
		{
			total += get<2>(q.front());
			q.pop();
		}
		printf("#%d %d\n", tc + 1, total);
	}
}

void BFS(int ck)
{
	//총합,최대값,최대값일때 dir
	vector<vector<tuple<int, int, int> > > arr(100, vector<tuple<int, int, int> >(100));
	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());
		int dir = get<3>(q.front());
		q.pop();

		if (get<1>(arr[x + dr[dir]][y + dc[dir]]) < cnt)
		{
			get<1>(arr[x + dr[dir]][y + dc[dir]]) = cnt;
			get<2>(arr[x + dr[dir]][y + dc[dir]]) = dir;
		}
		get<0>(arr[x + dr[dir]][y + dc[dir]]) += cnt;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (get<0>(arr[i][j]) != 0)//미생물이 살고있다
			{
				//빨간구역이면
				if ((i == 0 || i == N - 1) || (j == 0 || j == N - 1))//벽에 도착
				{
					q.push(make_tuple(i, j, get<0>(arr[i][j]) / 2, (get<2>(arr[i][j]) + 2 + 4) % 4));
				}
				else
				{
					q.push(make_tuple(i, j, get<0>(arr[i][j]), get<2>(arr[i][j])));
				}
			}
		}
	}
}