#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > visited(9, vector<int>(9)); 
vector<vector<int> > vec(9, vector<int>(9));

int Tc;
void next(int, int);

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &Tc);
	for (int t = 0; t < Tc; ++t)
	{
		for (int i = 1; i <= 8; ++i)
		{
			for (int j = 1; j <= 8; ++j)
			{
				scanf("%d", &vec[i][j]);
			}
		}
		if (vec[1][1] == 0)
		{
			printf("0\n");
		}
		else
		{
			next(1, 1);
		}
	}

}

void next(int r, int c)
{
	if (r == 8 && c == 8)
	{
		printf("YES\n");
		return;
	}

	if (vec[r][c] == 1 || vec[r][c] == 3)
	{
		if (c + 1 <= 8 && (vec[r][c + 1] == 1 || vec[r][c + 1] == 4))
		{
			next(r, c+1);
		}
		else
		{
			printf("NO\n");
			return;
		}
	}

	if (vec[r][c] == 2 || vec[r][c] == 4)
	{
		if (r + 1 <= 8 && (vec[r+1][c] == 2 || vec[r+1][c] == 3))
		{
			next(r + 1, c);
		}
		else
		{
			printf("NO\n");
			return;
		}
	}
}