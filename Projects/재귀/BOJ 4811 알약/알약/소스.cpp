#include<stdio.h>

long long arr[31][31];
long long cnt;
void func(double n,double k);

int main()
{
	int N;
	arr[2][2] = 2;
	for (int i = 1; i < 31; i++)
	{
		arr[i][1] = 1;
	}

	for (int i = 3; i < 31; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (i == j)
			{
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
			}
			else
			{
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			}
		}
	}

	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 1000; i++)
	{

		scanf("%d", &N);
		if (N == 0)
			break;
		//cnt = 0;
		//func(N,0);
		printf("%lld\n", arr[N][N]);

	}
}
void func(double n,double k)
{
	if (n == 0 && k == 0)
	{
		cnt++;
	}
	else if (n == 1 && k == 0)
	{
		func(n - 1, k + 0.5);
	}
	else if (n == 0 && k != 0)
	{
		func(n, k - 0.5);
	}
	else
	{
		func(n - 1, k + 0.5);
		if (k != 0)
		{
			func(n, k - 0.5);
		}
	}
}