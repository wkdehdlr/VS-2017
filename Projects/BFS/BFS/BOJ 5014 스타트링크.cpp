#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> q;
vector<int> vec;
int F, S, G, U, D;

void BFS(int, int);

int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	vec.resize(F + 1, 0x7fffffff);


	if (S == G)
	{
		printf("0\n");
		return 0;
	}
	vec[S] = 0;
	q.push(S);
	BFS(S, F);

}
void BFS(int n, int k)
{
	int flag = 0;
	while (!q.empty())
	{
		int num = q.front(); q.pop();

		if (U !=0 && num + U <= F && vec[num] + 1 < vec[num + U])
		{
			vec[num + U] = vec[num] + 1;
			q.push(num + U);
		}

		if (D != 0 && num - D >= 1 && vec[num] + 1 < vec[num - D])
		{
			vec[num - D] = vec[num] + 1;
			q.push(num - D);
		}

		if (num + U == G || num - D == G)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		printf("%d\n", vec[G]);
	}
	else
	{
		printf("use the stairs\n");
	}
}