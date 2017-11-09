#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;

int N;
int main()
{
	int temp;
	scanf("%d", &N);
	vec.resize(N + 1,0x7fffffff);

	vec[N] = 0;
	while (1)
	{
		temp = N;
		if ((N % 3) == 0)
		{
			if (vec[N] + 1 < vec[N / 3])
			{
				vec[N / 3] = vec[N] + 1;
			}
		}
		if ((N % 2) == 0)
		{
			if (vec[N] + 1 < vec[N / 2])
			{
				vec[N / 2] = vec[N] + 1;
			}
		}

		if ((vec[N] + 1) < vec[--temp])
		{
			vec[temp] = vec[N] + 1;
		}
		--N;
		if (N == 0)
			break;
	}
	cout << vec[1] << '\n';

}