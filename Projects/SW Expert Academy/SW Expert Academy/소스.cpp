#include<cstdio>

int arr[4] = { 0,1,2,3 };
int y = 0;
int main()
{
	int mask = 1 << 3;
	int y = 1;
	for (int i = 0; i < mask; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i & (1 << j))
			{
				printf("%d", arr[y+j]);
			}
		}
		printf("\n");
	}
}