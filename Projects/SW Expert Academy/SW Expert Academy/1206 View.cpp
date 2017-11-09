#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int vec[1001];
int N;

int main()
{
	//freopen("input.txt", "r", stdin);
	for (int tc = 0; tc < 10; tc++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &vec[i]);
		}

		int cnt = 0;
		for (int i = 3; i <= N - 2; ++i)
		{
			int low = min(min(vec[i] - vec[i - 1], vec[i] - vec[i - 2]), min(vec[i] - vec[i + 1], vec[i] - vec[i + 2]));
			if (low > 0)
				cnt += low;
		}
		printf("#%d %d\n", tc + 1, cnt);
	}
}