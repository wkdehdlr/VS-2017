#include<stdio.h>

int main()
{
	int a[] = { 1,2,1,4,3,5,6,8,4 };
	int LIS[9];

	
	for (int i = 0; i < 9; i++)
	{
		LIS[i] = 1;
	}

	for (int i = 1; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j]<a[i] && LIS[j] + 1 > LIS[i])
				LIS[i] = LIS[i] + 1;
		}
	}
	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		if (max < LIS[i])
			max = LIS[i];
	}
	printf("%d\n", max);
}