#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

vector<vector<int> > vec(101, vector<int>(101));
vector<vector<bool> > visited(101, vector<bool>(101, false));
deque<tuple<int,int,int> > q;
int N,M;
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int minN = 0x7fffffff;

void BFS(int, int);

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			scanf("%1d", &vec[i][j]);
		}
	}

	visited[1][1] = true;
	q.push_back(make_tuple(1, 1,0));
	BFS(1, 1);	
}
void BFS(int i, int j)
{
	int x, y, z;
	while (!q.empty())
	{
		x = get<0>(q.front());
		y = get<1>(q.front());
		z = get<2>(q.front());
		q.pop_front();

		if (x == N && y == M)
		{
			if (z < minN)
			{
				minN = z;
				break;
			}
		}
		
		for (int k = 0; k < 4; k++)
		{
			int nr = x + dr[k];
			int nc = y + dc[k];
			if (nr >= 1 && nr <= N && nc >= 1 && nc <= M)
			{
				if (visited[nr][nc] == false)
				{
					vec[nr][nc] == 1 ? q.push_back(make_tuple(nr, nc, z + 1)) : q.push_front(make_tuple(nr, nc, z));
					visited[nr][nc] = true;
				}
			}
		}
	}
	printf("%d\n", minN);
}