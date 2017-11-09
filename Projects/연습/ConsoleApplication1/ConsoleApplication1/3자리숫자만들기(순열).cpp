#include<stdio.h>

int arr[5] = { 1,2,3,4,5 };
int arr2[3];
int used[5] = { 0, };


void func(int n, int k);


int main()
{
	func(0, 3);
}
void func(int n, int k)
{
	if (n == k)
	{
		for (int i = 0; i < 3; i++)
		{
			printf("%d", arr2[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if(used[i] == 0)
			{
				used[i] = 1;
				arr2[n] = arr[i];
				func(n + 1, k);
				used[i] = 0;
			}
		}
		
	}
}