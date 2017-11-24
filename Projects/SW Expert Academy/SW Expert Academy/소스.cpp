#include<cstdio>

int new_arr[6];
int arr[6] = { 1,2,3,4,5,6 };
int y = 0;
int main()
{
	int mask = 1 << 6;
	for (int i = 0; i < mask; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < 6; ++j)
		{
			if(i & (1<<j))
			{
				new_arr[cnt] = arr[j];
				cnt++;
			}
		}
		if (cnt <= 3)
		{
			for (int k = 0; k < cnt; ++k)
			{
				printf("%d", new_arr[k]);
			}
			printf("\n");
		}
	}
}