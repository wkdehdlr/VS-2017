#include<iostream>
#include<vector>
#include<map>
using namespace std;

int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
vector<int> check(27);
vector<vector<char> > vec(21, vector<char>(21));
int C, R;
int maxN = 0;
void next(int, int, int);

int main()
{
	char temp;

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &R, &C); scanf("%c", &temp);
	for (int x = 1; x <= R; ++x)
	{
		for (int y = 1; y <= C; ++y)
		{
			scanf("%c", &vec[x][y]);
		}
		scanf("%c", &temp);
	}
	next(1, 1, 1);
	cout << maxN << '\n';
}

void next(int r, int c, int cnt)
{
	if (maxN < cnt)
		maxN = cnt;

	check[vec[r][c] - 'A' + 1] = 1;
	
	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if ((nr >= 1) && (nr <= R) && (nc >= 1) && (nc <= C) && (check[vec[nr][nc] - 'A' + 1] == 0))
		{
			next(nr, nc, cnt + 1);
		}
	}
	check[vec[r][c] - 'A' + 1] = 0;
}