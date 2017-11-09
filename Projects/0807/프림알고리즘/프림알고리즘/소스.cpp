#include<stdio.h>

int adj[6][6];
int mst[6];

int V;
int E;
int mstEdge[4][2];
int t[3];//deQ()�� ��� ����.....t[0], t[1] node �� t[2] ���


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
		//////////////////////////////���⼺�� �ִ� �׷����� ����ؾ��Ѵ�
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
	//n�� ��带 mst�� �߰�

	while (cnt <= V)
	{	
		int min = 0x7fffffff;
		int minV;
		for (int i = 1; i <= V; i++)/////mst�� ���ԵǾ��ִ� ����� ������ �˻�
		{
			if (mst[i] == 1)//mst��  ���Ե� ��� i�� ����
			{
				for (int j = 1; j <= V; j++)
				{
					if (adj[i][j] != 0 && mst[j] == 0)//�����̸鼭 mst�� ���Ե������� j�� ���� ����� �ּ����� Ȯ��
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
		mst[minV] = 1;//minV�� mst�� ����
		cnt++;
		cost += min;
	}
	return cost;
}

////�켱������ ����� prim �˰���
int prim2(int n)
{
	int sum = 0;
	int cnt = 1;
	//���۳���� ��� ������ ���� enQ();
	for (int i = 1; i <= V; i++)
	{
		if (adj[n][i] != 0)
		{
			enQ(n, i, adj[n][i]);////n, i �� �˱⶧���� ���� adj[n][i]�� �������ʰ� �ҷ��ͼ� ����ص���
		}
	}
	mst[n] = 1;//���۳�带 mst�� ����


	while (cnt < V)
	{
		deQ();
		if (mst[t[1]] != 0)// t[1] ��尡 mst�� ���ԵǾ����� ������
		{
			mst[t[1]] = 1;//t[1]��带 mst�� �߰�
			cnt++;
			sum += adj[t[0]][t[1]];
			for (int i = 1; i <= V; i++)
			{
				if (adj[t[1]][i] != 0 && mst[i] == 0)//t[1]�� �����̸鼭 mst�� ������ �ȵǾ�������
				{
					enQ(t[1], i, adj[t[1]][i]);
				}
			}
		}
	}
	return sum;
}