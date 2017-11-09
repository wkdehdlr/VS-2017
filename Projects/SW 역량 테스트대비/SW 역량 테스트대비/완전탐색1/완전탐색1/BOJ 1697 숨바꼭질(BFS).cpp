#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> q;
int N, K;
vector<int> visited;//
void BFS(int, int);

int main()
{
	visited.resize(100001, 0x7fffffff);
	scanf("%d %d", &N, &K);
	q.push(N);
	BFS(N, K);
}

void BFS(int n, int k)
{
	visited[n] = 0;

	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		if (num < 100000 && visited[num] + 1 < visited[num + 1])
		{
			visited[num + 1] = visited[num] + 1;
			q.push(num + 1);
		}

		if (1 <= num && visited[num] + 1 < visited[num - 1])
		{
			visited[num - 1] = visited[num] + 1;
			q.push(num - 1);
		}

		if (num <= 50000 && visited[num] + 1 < visited[num * 2])
		{
			visited[2 * num] = visited[num] + 1;
			q.push(num * 2);
		}

		if (num + 1 == K || num - 1 == K || 2 * num == k)
		{
			break;
		}
	}
	printf("%d\n", visited[k]);
}