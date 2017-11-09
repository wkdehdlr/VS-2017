#include<iostream>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

bool visited[101][101];
int arr[101][101];
int N,L;
int cnt = 0;
pair<int, int> p;


pair<int,int> DFS2(int, int, int);
void DFS(int,int);

int main()
{
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		DFS(i,1);
	}

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			visited[i][j] = false;
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		DFS(i,0);
	}

	printf("%d\n", cnt);
}
void DFS(int i, int flag)
{
	if (flag == 1)//��
	{
		int y1 = 1;
		while (1)
		{
			if (arr[i][y1] - arr[i][y1 + 1] == 0)//����� ������ ���̰� 0�̸� �׳� �� �� ����
			{
				y1++;
			}
			else if (arr[i][y1] - arr[i][y1 + 1] == 1)//���簡 �� ����
			{
				p = DFS2(i, y1 + 1, 2);
				y1 = p.second;
				if (y1 == 0)
					return;
			}
			else if (arr[i][y1] - arr[i][y1 + 1] == -1)//���簡 �� ����
			{
				p = DFS2(i, y1, 0);
				y1 = p.second;
				if (y1 == 0)
					return;
			}
			else
			{
				return;
			}
			if (y1 == N)
				break;
		}
		cnt++;
	}
	else//��
	{
		int x1 = 1;
		while (1)
		{
			if (arr[x1][i] - arr[x1+1][i] == 0)//����� ������ ���̰� 0�̸� �׳� �� �� ����
			{
				x1++;
			}
			else if (arr[x1][i] - arr[x1+1][i] == 1)//����� ������ ���̰� 1�̸� ��������
			{
				p = DFS2(x1 + 1, i, 1);
				x1 = p.first;
				if (x1 == 0)
					return;
			}
			else if (arr[x1][i] - arr[x1 + 1][i] == -1)//����� ������ ���̰� 1�̸� ��������
			{
				p = DFS2(x1, i, 3);
				x1 = p.first;
				if (x1 == 0)
					return;
			}
			else
			{
				return;
			}
			if (x1 == N)
				break;
		}
		cnt++;
	}
}

pair<int,int> DFS2(int x, int y, int dir)
{
	int data = arr[x][y];
	if (visited[x][y] == false)
	{
		visited[x][y] = true;
	}
	else
	{
		return make_pair(0, 0);
	}

	int r = x;
	int c = y;

	for (int i = 0; i < L-1; ++i)
	{
		r += dr[dir];
		c += dc[dir];
		if (r >= 1 && r <= N && c >= 1 && c <= N && arr[r][c] == data && visited[r][c] == false)
		{
			visited[r][c] = true;
		}
		else
		{
			return make_pair(0,0);
		}
	}
	if (dir == 0)//�������� �ǵ��ư��°��
	{
		return make_pair(r, y + 1);
	}

	if (dir == 3)//���� �ǵ��ư��°��
	{
		return make_pair(x + 1, c);
	}
	return make_pair(r, c);
	//��������
}
