#include<iostream>
using namespace std;

int arr[21][21];
int N, M;
int maxN = 0;
int maxN2 = 0;
void func(int,int,int);
int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++)
	{
		maxN2 = 0;
		maxN = 0;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int k = 1; k <=31; k++)
		{
			int money = k * k + (k - 1) * (k - 1);

			for (int i = 1; i <= N; ++i)
			{
				for (int j = 1; j <= N; ++j)
				{
					func(k, i, j);
					int tmp2 = maxN * M - money;
					if (tmp2 > 0)
					{
						if (maxN2 < maxN)
							maxN2 = maxN;
					}
				}
			}
		}
		printf("#%d %d\n", tc+1,maxN2);
	}
}

void func(int k, int x, int y)
{
	int flag = 0;
	int temp = 0;
	int cnt = 0;
	for (int c = y + k - 1; c >= y - k + 1; --c)
	{
		if (flag == 0)
		{
			if (c < y)
			{
				flag = 1;
				temp -= 2;
			}
		}
		for (int r = x - temp; r <= x + temp; r++)
		{
			if (r >= 1 && r <= N && c >= 1 && c <= N &&arr[r][c] != 0)
			{
				cnt++;
			}
		}

		if (flag == 0)
		{
			temp++;
		}
		else
		{
			temp--;
		}
	}

	if (maxN < cnt)
		maxN = cnt;
}