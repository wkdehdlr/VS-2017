#include<iostream>
#include<algorithm>
using namespace std;

int arr[20][20];
int dice[7] = { 0, };
int N, M;
int X, Y, K;
int ground = 6;

int main()
{
	scanf("%d %d %d %d %d", &N, &M, &X, &Y, &K);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < K; ++i)
	{
		int move;
		scanf("%d", &move);
		if (move == 1)//동
		{
			if (Y + 1 < M)
			{
				swap(dice[6], dice[3]);
				swap(dice[3], dice[1]);
				swap(dice[1], dice[4]);
				if (arr[X][Y + 1] == 0)//지도가 0이면 주사위를 지도에 찍는다
				{
					arr[X][Y + 1] = dice[6];
				}
				else
				{
					dice[6] = arr[X][Y + 1];
					arr[X][Y + 1] = 0;
				}
				printf("%d\n", dice[1]);
				Y++;
			}
		}
		else if (move == 2)//서
		{
			if (1 <= Y)
			{
				swap(dice[4], dice[1]);
				swap(dice[1], dice[3]);
				swap(dice[3], dice[6]);
				if (arr[X][Y - 1] == 0)//지도가 0이면 주사위를 지도에 찍는다
				{
					arr[X][Y - 1] = dice[6];
				}
				else
				{
					dice[6] = arr[X][Y - 1];
					arr[X][Y - 1] = 0;
				}
				printf("%d\n", dice[1]);
				Y--;
			}
		}
		else if (move == 3)//북
		{
			if (1 <= X)
			{
				swap(dice[2], dice[1]);
				swap(dice[1], dice[5]);
				swap(dice[5], dice[6]);
				if (arr[X-1][Y] == 0)//지도가 0이면 주사위를 지도에 찍는다
				{
					arr[X-1][Y] = dice[6];
				}
				else
				{
					dice[6] = arr[X-1][Y];
					arr[X-1][Y] = 0;
				}
				printf("%d\n", dice[1]);
				X--;
			}
		}
		else//남
		{
			if (X + 1 < N)
			{
				swap(dice[6], dice[5]);
				swap(dice[5], dice[1]);
				swap(dice[1], dice[2]);
				if (arr[X + 1][Y] == 0)//지도가 0이면 주사위를 지도에 찍는다
				{
					arr[X + 1][Y] = dice[6];
				}
				else
				{
					dice[6] = arr[X + 1][Y];
					arr[X + 1][Y] = 0;
				}
				printf("%d\n", dice[1]);
				X++;
			}
		}
	}	
}