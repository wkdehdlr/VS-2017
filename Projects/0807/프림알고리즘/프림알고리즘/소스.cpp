#include<stdio.h>

int adj[6][6];
int mst[6];

int V;
int E;
int mstEdge[4][2];
int t[3];//deQ()의 결과 저장.....t[0], t[1] node 번 t[2] 비용


int prim(int n);
void enQ(int n, int i,int w);
int deQ();

int main()
{
	int Tc;

	freopen("input.txt", "r", stdin);
	scanf("%d", &Tc);

	for (int i = 0; i < Tc; i++)
	{
		int n1, n2, w;
		scanf("%d %d %d", &n1, &n2, &w);
		//////////////////////////////방향성이 있는 그래프로 취급해야한다
		adj[n1][n2] = w;//////////////
		adj[n2][n1] = w;//////////////
	}
	prim(1);
}

int prim(int n)
{
	int cost = 0;
	int cnt;
	mst[n] = 1;
	//n번 노드를 mst에 추가

	while (cnt <= V)
	{	
		int min = 0x7fffffff;
		int minV;
		for (int i = 1; i <= V; i++)/////mst에 포함되어있는 노드의 인접을 검사
		{
			if (mst[i] == 1)//mst에  포함된 노드 i에 대해
			{
				for (int j = 1; j <= V; j++)
				{
					if (adj[i][j] != 0 && mst[j] == 0)//인접이면서 mst에 포함되지않은 j에 대해 비용이 최소인지 확인
					{
						if (adj[i][j] < min)
						{
							min = adj[i][j];
							minV = j;
							mstEdge[cnt - 1][0] = i;
							mstEdge[cnt - 1][1] = j;
						}
					}
				}
			}
		}
		mst[minV] = 1;//minV를 mst에 포함
		cnt++;
		cost += min;
	}
	return cost;
}

////우선순위를 사용한 prim 알고리즘
int prim2(int n)
{
	int sum = 0;
	int cnt = 1;
	//시작노드의 모든 인접에 대해 enQ();
	for (int i = 1; i <= V; i++)
	{
		if (adj[n][i] != 0)
		{
			enQ(n, i, adj[n][i]);////n, i 를 알기때문에 굳이 adj[n][i]를 보내지않고 불러와서 사용해도됨
		}
	}
	mst[n] = 1;//시작노드를 mst에 포함


	while (cnt < V)
	{
		deQ();
		if (mst[t[1]] != 0)// t[1] 노드가 mst에 포함되어있지 않으면
		{
			mst[t[1]] = 1;//t[1]노드를 mst에 추가
			cnt++;
			sum += adj[t[0]][t[1]];
			for (int i = 1; i <= V; i++)
			{
				if (adj[t[1]][i] != 0 && mst[i] == 0)//t[1]과 인접이면서 mst에 포함이 안되어있으면
				{
					enQ(t[1], i, adj[t[1]][i]);
				}
			}
		}
	}
	return sum;
}