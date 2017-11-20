#pragma warning(disable : 4996)
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

struct save {
	int data;
	int x;
	int y;
};
bool operator<(save t, save u) {
	return t.data < u.data;
}

priority_queue<save> pq;

int arr[11][11];
int T, N, M, C;
int maxN = 0;

void nck(int, int, int);
int start();
int main()
{
	priority_queue<save> pq_temp;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		pq = pq_temp;
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		printf("#%d %d\n", tc + 1, start());
	}
}
int start()
{
	int mask = 1 << M;

	for (int x = 1; x <= N; ++x)
	{
		for (int y = 0; y <= N - M; ++y)
		{
			nck(x, y, mask);
		}
	}
	int sum = 0;
	int data = pq.top().data;
	int x = pq.top().x;
	int y = pq.top().y;
	pq.pop();

	while (!pq.empty())
	{
		int data2 = pq.top().data;
		int x2 = pq.top().x;
		int y2 = pq.top().y;
		pq.pop();
		if (x == x2)//두값이 같은 행이면
		{
			if (abs(y - y2) < M)//열이 겹치면 안된다
			{
				continue;
			}
		}
		return data += data2;
	}
}
void nck(int x, int y, int mask)
{
	int sum = 0;
	int total_sum = 0;
	int max = 0;

	for (int i = 0; i < mask; ++i)
	{
		total_sum = 0;
		sum = 0;
		for (int j = 0; j < M; ++j)
		{
			if (i & (1 << j))
			{
				int data = arr[x][y + j + 1];
				sum += data;
				if (sum <= C)
				{
					total_sum += (data*data);
				}
			}
		}
		if (max < total_sum)
			max = total_sum;
	}
	pq.push({ max,x,y + 1 });
	if (maxN < max)
		maxN = max;
}