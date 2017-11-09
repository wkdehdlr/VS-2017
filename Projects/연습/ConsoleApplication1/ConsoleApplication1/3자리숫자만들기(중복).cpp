#include<stdio.h>

int arr[3];

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
			printf("%d", arr[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= 5; i++)
		{
			arr[n] = i;
			func(n + 1, k);
		}
	}
}
