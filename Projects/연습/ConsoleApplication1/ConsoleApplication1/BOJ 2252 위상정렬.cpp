#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, n1, n2,temp;
queue<int> q;
vector< vector<int> > vec;//인접행렬
vector<int> degree; //진입차수

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;//학생수
	degree.resize(N + 1);
	vec.resize(N + 1);




	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &n1, &n2);
		vec[n1].push_back(n2);
		degree[n2]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)//진입차수가 0인 노드 큐에 삽입
		{
			q.push(i);
		}
	}

	while (!(q.empty()))
	{
		temp = q.front(); 
		q.pop();
		printf("%d ", temp);
		for (int x : vec[temp])
		{
			degree[x]--;
			if (degree[x] == 0)
			{
				q.push(x);
			}
		}

	}
	printf("\n");
}