#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int maxN = 0;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int arr[3];
int arr2[65] = { 
1,2,3,4,5,6,7,8,9,10,
11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,
31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,50,
51,52,53,54,55,56,57,58,59,60,
61,62,63,64 };
vector<vector<int> > vec(9, vector<int>(9));
vector<vector<int> > vec2(9, vector<int>(9));
//vector<int> arr2;
vector<pair<int, int> > gd;
queue<pair<int,int> > q;
int N, M;
int cnt_zero = 0;

void prin();
void bfs();
void copy();
void ncr(int,int);
int main()
{
	scanf("%d %d", &N, &M);
	gd.push_back(make_pair(-1, -1));
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			scanf("%d", &vec[i][j]);
			if (vec[i][j] == 0)
			{
				pair<int, int> p(i, j);
				gd.push_back(p);
				cnt_zero++;
				//arr2.push_back(cnt_zero);
			}
		}
	}

	ncr(gd.size()-1, 3);
	printf("%d\n", maxN);
	return 0;
}
void copy()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			vec2[i][j] = vec[i][j];
		}
	}
}


void ncr(int n, int r)
{
	if (r == 0)
	{
		copy();
		for (int i = 0; i < 3; ++i)
		{
			vec2[gd[arr[i]].first][gd[arr[i]].second] = 1;
		}
		bfs();
	}
	else if (n < r)
	{
		return;
	}
	else
	{
		arr[r - 1] = arr2[n - 1];
		ncr(n - 1, r - 1);
		ncr(n - 1, r);
	}
}

void bfs()
{
	int tmp = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (vec2[i][j] == 2)
			{
				q.push(make_pair(i, j));
			}
		}
	}
	int cnt_zero2 = cnt_zero-3;
	//prin();
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = r + dr[i];
			int y = c + dc[i];
			if (x >= 1 && x <= N && y >= 1 && y <= M && vec2[x][y] == 0)
			{
				vec2[x][y] = 2;
				q.push(make_pair(x, y));
				cnt_zero2--;
				if (cnt_zero2 < maxN)
				{
					while (!q.empty())
					{
						q.pop();
					}
					return;
				}
			}
		}
	}
	//prin();
	int zero = cnt_zero2;
	/*for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (vec2[i][j] == 0)
			{
				zero++;
			}
		*/
	if (maxN < zero)
		maxN = zero;

}