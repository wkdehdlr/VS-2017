#include<stdio.h>

int arr[3] = { 1,2,3 };
int arr2[3] = { 0, };

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
			if (arr2[i] == 1)
			{
				printf("%d", arr[i]);
			}
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			arr2[n] = i;
			func(n + 1, k);
		}
	}
}