#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
vector<vector<int> > vec(11, vector<int>(11));
vector<vector<int> > dp(11, vector<int>(11));
int cnt = 0;
int n;

void DFS(int, int);

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &vec[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			DFS(i, j);
		}
	}
}


void DFS(int i, int j)
{
	if (i == n && j == n)
	{
		
	}
	else
	{
		if (vec[i][j] == 1)
		{
			vec[i][j] = 2;
			for (int i = 0; i < 4; ++i)
			{
				int nr = i + dr[i];
				int nc = j + dc[i];

				if ((nr >= 1) && (nr <= n) && (nc >= 1) && (nc <= n) && (vec[i][j] == 1))
				{
					DFS(nr, nc);
				}
			}			
		}
	}
}


