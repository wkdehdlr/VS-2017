#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int minN = 0x7fffffff;
int N;
int arr[21][21];
int team[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

vector<int> temp;
vector<int> new_team;


void ncr(int, int);
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	new_team.resize(N / 2);
	ncr(N, N / 2);

	printf("%d\n", minN);
}
void ncr(int n, int r)
{
	if (r == 0)
	{
		int num1 = 0;
		int num2 = 0;

		temp.clear();
		temp.resize(21);
		for (int i = 0; i < (N / 2); ++i)
		{
			temp[new_team[i]] = 1;
		}

		for (int i = 1; i <= N; ++i)
		{
			if (temp[i] == 0)
			{
				for (int j = 1; j <= N; ++j)
				{
					if (i == j)continue;
					if (temp[j] == 0)
					{
						num1 += arr[i][j];
					}
				}
			}
			else
			{
				for (int j = 1; j <= N; ++j)
				{
					if (i == j)continue;
					if (temp[j] == 1)
					{
						num2 += arr[i][j];
					}
				}
			}
		}

		num1 = abs(num1 - num2);
		if (num1 < minN)
			minN = num1;
	}
	else if (n < r)
	{
		return;
	}
	else
	{
		new_team[r - 1] = team[n - 1];
		ncr(n - 1, r - 1);
		ncr(n - 1, r);
	}
}