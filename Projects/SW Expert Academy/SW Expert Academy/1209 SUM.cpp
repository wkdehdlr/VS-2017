#include<iostream>
using namespace std;

int vec[101][101];
int max = 0;

int main()
{
	for (int tc = 0; tc < 10; tc++)
	{
		max = 0;
		scanf("%d", &vec[1][1]);
		for (int i = 1; i <= 100; ++i)
		{
			for (int j = 1; j <= 100; ++j)
			{
				scanf("%d", &vec[i][j]);
			}
		}

		int temp = 0;
		for (int i = 1; i <= 100; ++i)
		{
			temp = 0;
			for (int j = 1; j <= 100; ++j)
			{
				temp += vec[i][j];
			}
			if (max < temp)
				max = temp;
		}

		for (int j = 1; j <= 100; ++j)
		{
			temp = 0;
			for (int i = 1; i <= 100; ++i)
			{
				temp += vec[i][j];
			}
			if (max < temp)
				max = temp;
		}

		temp = 0;
		for (int j = 1; j <= 100; ++j)
		{
			temp += vec[j][j];
		}
		if (max < temp)
			max = temp;

		temp = 0;
		for (int j = 1; j <= 100; ++j)
		{
			temp += vec[j][101 - j];
		}
		if (max < temp)
			max = temp;


		printf("#%d %d\n", tc + 1, max);
	}
}