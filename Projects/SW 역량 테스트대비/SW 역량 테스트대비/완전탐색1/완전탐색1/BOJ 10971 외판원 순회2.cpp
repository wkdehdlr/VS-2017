#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > vec(11, vector<int>(11));
vector<int> num = { 1,2,3,4,5,6,7,8,9,10 };
int N;
int sum = 0;
int minN = 0x7fffffff;

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &vec[i][j]);
		}
	}

	do {
		int flag = 0;
		sum = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			if (vec[num[i]][num[i + 1]] == 0)
			{
				flag = 1;
				break;
			}
			sum += (vec[num[i]][num[i+1]]);
			if (sum > minN)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			if (vec[num[N - 1]][num[0]] == 0)continue;
			sum += (vec[num[N - 1]][num[0]]);
			if (sum < minN)
				minN = sum;
		}
	} while (next_permutation(num.begin(), num.begin() + N));

	printf("%d\n", minN);
}