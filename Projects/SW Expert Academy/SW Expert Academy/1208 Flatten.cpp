#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec(100);
int N;
int dump;

int main()
{
	for (int tc = 0; tc < 10; ++tc)
	{
		scanf("%d", &dump);
		for (int i = 0; i < 100; ++i)
		{
			scanf("%d", &vec[i]);
		}

		int res;
		int flag = 0;
		sort(vec.begin(), vec.end());
		for (int i = 0; i < dump; ++i)
		{
			res = vec[99] - vec[0];
			if (res <= 1)
			{
				flag = 1;
				printf("#%d %d\n", tc + 1, res);
				break;
			}
			else
			{
				vec[0] += 1;
				vec[99] -= 1;
				sort(vec.begin(), vec.end());
			}
		}
		if (flag == 0)
		{
			printf("#%d %d\n", tc + 1, vec[99] - vec[0]);
		}
	}
}