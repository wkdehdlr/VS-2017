#include<stdio.h>

int arr[8] = { 3,7,6,2,5,4,8,9 };

void func(int n, int k);

int main()
{
	func(0, 8);
}
void func(int n, int k)
{
	if (n == k)
	{
		
	}
	else if(arr[n]==5)
	{
		printf("Ã£¾Ò´Ù\n");
		return;
	}
	else
	{
		func(n + 1, k);
	}
}