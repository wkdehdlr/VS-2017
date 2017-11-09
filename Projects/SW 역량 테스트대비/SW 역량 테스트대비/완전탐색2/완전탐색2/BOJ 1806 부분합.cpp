#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;

int N, S, mins = 0x7fffffff;

int main()
{
	scanf("%d %d", &N, &S);
	vec.resize(N);
	
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &vec[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		int temp = i;
		int sum = 0;
		while (1)
		{
			sum += vec[temp];
			if (sum >= S)
			{
				if (mins > temp - i + 1)
				{
					mins = temp - i + 1;
				}
				break;
			}
			temp++;
			if (temp == N)
				break;
		}
	}
	if (mins == 0x7fffffff)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", mins);
	}
}