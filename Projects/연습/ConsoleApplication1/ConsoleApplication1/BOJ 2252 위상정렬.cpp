#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, n1, n2,temp;
queue<int> q;
vector< vector<int> > vec;//�������
vector<int> degree; //��������

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;//�л���
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
		if (degree[i] == 0)//���������� 0�� ��� ť�� ����
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