#include<iostream>
using namespace std;

int arr[500][500];
int N, M;
int maxN = 0;
void func1(int,int);
void func2(int, int);
void func3(int, int);
void func4(int, int);
void func5(int, int);
void func6(int, int);
void func7(int, int);

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			func1(i, j);
			func2(i, j);
			func3(i, j);
			func4(i, j);
			func5(i, j);
			func6(i, j);
			func7(i, j);
		}
	}
	printf("%d\n", maxN);
}

void func1(int x, int y)
{
	if (y + 3 < M)//오른쪽 가로
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x][y + 3];
		if (maxN < sum)
			maxN = sum;
	}

	if (x >= 3)//위 세로
	{
		int sum = 0;
		sum = arr[x][y] + arr[x - 1][y] + arr[x - 2][y] + arr[x - 3][y];
		if (maxN < sum)
			maxN = sum;
	}

	if (y >= 3)//왼쪽 가로
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y - 1] + arr[x][y - 2] + arr[x][y - 3];
		if (maxN < sum)
			maxN = sum;
	}

	if (x + 3 < N)//아래 세로
	{
		int sum = 0;
		sum = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 3][y];
		if (maxN < sum)
			maxN = sum;
	}
}
void func2(int x, int y)
{
	if (x + 1 < N && y + 1 < M)//오른쪽 아래
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y + 1] + arr[x + 1][y] + arr[x + 1][y + 1];
		if (maxN < sum)
			maxN = sum;
	}

	if (x >= 1 && y + 1 < M)//오른쪽 위
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y + 1] + arr[x - 1][y] + arr[x - 1][y + 1];
		if (maxN < sum)
			maxN = sum;
	}

	if (x >= 1 && y >= 1)//왼쪽 위
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y - 1] + arr[x - 1][y] + arr[x - 1][y - 1];
		if (maxN < sum)
			maxN = sum;
	}

	if (x + 1 < N && y >= 1)//왼쪽 아래
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y - 1] + arr[x + 1][y] + arr[x + 1][y - 1];
		if (maxN < sum)
			maxN = sum;
	}
}
void func3(int x, int y)
{
	if (x + 2 < N && y + 1 < M)//오른쪽 아래
	{
		int sum = 0;
		sum = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 2][y + 1];
		if (maxN < sum)
			maxN = sum;
	}

	if (x >= 1 && y + 2 < M)//오른쪽 위
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x - 1][y + 2];
		if (maxN < sum)
			maxN = sum;
	}

	if (x >= 2 && y >= 1)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x - 1][y] + arr[x - 2][y] + arr[x - 2][y - 1];
		if (maxN < sum)
			maxN = sum;
	}
	if (x + 1 < N && y >= 2)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y - 1] + arr[x][y - 2] + arr[x + 1][y - 2];
		if (maxN < sum)
			maxN = sum;
	}
}
void func4(int x, int y)
{
	if (x + 2 < N && y + 1 < M)//오른쪽 아래
	{
		int sum = 0;
		sum = arr[x][y] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y + 1];
		if (maxN < sum)
			maxN = sum;
	}

	if (x >= 1 && y + 2 < M)//오른쪽 위
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x - 1][y + 2];
		if (maxN < sum)
			maxN = sum;
	}

	if (x >= 2 && y >= 1)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x-1][y] + arr[x - 1][y - 1] + arr[x - 2][y - 1];
		if (maxN < sum)
			maxN = sum;
	}

	if (x + 1 < N && y >= 2)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y - 1] + arr[x + 1][y - 1] + arr[x + 1][y - 2];
		if (maxN < sum)
			maxN = sum;
	}
}
void func5(int x, int y)
{
	if (x + 1 < N && y + 2 < M)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y+1] + arr[x][y + 2] + arr[x + 1][y + 1];
		if (maxN < sum)
			maxN = sum;
	}

	if (x >= 2 && y + 1 < M)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x - 1][y] + arr[x - 2][y] + arr[x - 1][y + 1];
		if (maxN < sum)
			maxN = sum;
	}

	if (x >= 1 && y >= 2)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y - 1] + arr[x][y - 2] + arr[x - 1][y - 1];
		if (maxN < sum)
			maxN = sum;
	}
	if (x + 2 < N && y >= 1)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 1][y - 1];
		if (maxN < sum)
			maxN = sum;
	}
}
void func6(int x, int y)
{
	if (x + 2 < N && y >= 1)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 2][y - 1];
		if (maxN < sum)
			maxN = sum;
	}
	if (x + 1 < N && y + 2 < M)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 2];
		if (maxN < sum)
			maxN = sum;
	}
	if (x >= 2 && y + 1 < M)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x - 1][y] + arr[x - 2][y] + arr[x - 2][y + 1];
		if (maxN < sum)
			maxN = sum;
	}
	if (x >= 1 && y >= 2)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y - 1] + arr[x][y - 2] + arr[x - 1][y - 2];
		if (maxN < sum)
			maxN = sum;
	}
}
void func7(int x, int y)
{
	if (x + 2 < N && y >= 1)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x + 1][y] + arr[x + 1][y - 1] + arr[x + 2][y - 1];
		if (maxN < sum)
			maxN = sum;
	}
	if (x + 1 < N && y + 2 < M)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y + 1] + arr[x + 1][y + 1] + arr[x + 1][y + 2];
		if (maxN < sum)
			maxN = sum;
	}
	if (x >= 2 && y + 1 < M)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x - 1][y] + arr[x - 1][y + 1] + arr[x - 2][y + 1];
		if (maxN < sum)
			maxN = sum;
	}
	if (x >= 1 && y >= 2)
	{
		int sum = 0;
		sum = arr[x][y] + arr[x][y - 1] + arr[x - 1][y - 1] + arr[x - 1][y - 2];
		if (maxN < sum)
			maxN = sum;
	}
}