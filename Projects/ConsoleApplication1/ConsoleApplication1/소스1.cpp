#include<iostream>
using namespace std;

int arr[10];
int N;

void func(int, char,int);
int main()
{
	int open;
	int close;
	scanf("%d", &N);

	open = N;
	close = N;

	open = 0;
	func(0, '(', open);
}
void func(int n, char ch, int open)
{
	if (n == N*2 - 1)
	{
		arr[n] = ')';
		for (int i = 0; i < 4; ++i)
		{
			printf("%c", arr[i]);
		}
		printf("\n");
	}

	else
	{
		arr[n] = ch;
		if (open )
		{
			func(n + 1, '(',open+1);
			func(n + 1, ')', open-1);
		}
		else
		{
			func(n + 1, ')', open-1);
		}
	}
}