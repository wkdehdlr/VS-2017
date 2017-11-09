#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector< vector<int> > vec;
vector<int> vTime,vTime2;//vTime은 갱신전, vTime2는 갱신후
vector<int> degree;
int N;
queue<int> q;

int main()
{
	int temp,temp2;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	vec.resize(N + 1);
	vTime.resize(N + 1);	vTime2.resize(N + 1);
	degree.resize(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &temp);//시간입력
		vTime[i] = vTime2[i] = temp;

		while (1)
		{
			scanf("%d", &temp);
			if (temp == -1)
				break;
			vec[temp].push_back(i);
			degree[i]++;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (degree[i] == 0)//진입차수 0인것들 일단 다 enQ
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		for (int x : vec[temp])
		{
			vTime2[x] = max(vTime2[x], vTime[x] + vTime2[temp]);
			degree[x]--;
			if (degree[x] == 0)
			{
				q.push(x);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << vTime2[i] << '\n';
	}
}