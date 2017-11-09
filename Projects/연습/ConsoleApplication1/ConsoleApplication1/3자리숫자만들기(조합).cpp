#include<stdio.h>


int arr[3] = { 1,2,3 };
int arr2[2];
void nck(int n, int k);

int main()
{
	nck(3, 2);
}

void nck(int n, int k)
{
	if (k == 0)
	{
		printf("%d%d\n", arr2[0], arr2[1]);
	}
	else if (n < k)
	{
		return;
	}
	else
	{
		arr2[k - 1] = arr[n - 1];
		nck(n - 1, k - 1);
		nck(n - 1, k);
	}
}