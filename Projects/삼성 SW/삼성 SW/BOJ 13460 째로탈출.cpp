#include <iostream>
#include<queue>
#include<tuple>
using namespace std;

queue<tuple<int, int, int, int, int> > q;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
bool map[11][11][11][11];
char vec[11][11];
int N, M;
int minN = 0x7fffffff;

void BFS();
int main()
{
	char ch[12];
	int bx, by, rx, ry;

	scanf("%d %d", &N, &M); scanf("%c", &ch[0]);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> vec[i][j];
			if (vec[i][j] == 'B')
			{
				bx = i;
				by = j;
				continue;
			}
			if (vec[i][j] == 'R')
			{
				rx = i;
				ry = j;
				continue;
			}
		}
	}
	int cnt = 0;
	map[rx][ry][bx][by] = true;
	q.push(make_tuple(rx, ry, bx, by, cnt));
	BFS();

	if (minN == 0x7fffffff)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", minN);
	}
	return 0;
}
void BFS()
{
	int q_rx, q_ry, q_bx, q_by, cnt;
	int n_rx, n_ry, n_bx, n_by;
	int check_blue;

	while (!q.empty())
	{
		q_rx = get<0>(q.front());
		q_ry = get<1>(q.front());
		q_bx = get<2>(q.front());
		q_by = get<3>(q.front());
		cnt = get<4>(q.front());
		q.pop();

		if (cnt >= 10)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			n_rx = q_rx + dr[i];
			n_ry = q_ry + dc[i];
			n_bx = q_bx;
			n_by = q_by;

			if (n_rx >= 1 && n_rx <= N && n_ry >= 1 && n_ry <= M)
			{
					//°�� �����ȿ� �ְ� ���� �湮���Ѱ��� ������ ���� ���������� ������
					while (1)
					{
						if (vec[n_rx][n_ry] == '#')
						{
							check_blue = 0;
							n_rx -= dr[i];
							n_ry -= dc[i];
							while (1)
							{
								if (vec[n_bx][n_by] == '#')
								{
									n_bx -= dr[i];
									n_by -= dc[i];
									break;
								}
								if (vec[n_bx][n_by] == 'O')
								{
									check_blue = 1;
									break;
								}
								n_bx += dr[i];
								n_by += dc[i];
							}
							if (check_blue == 1)//���������� �Ķ����� ���� ���ۿ� ������
							{
								break;
							}
							if (n_rx == n_bx && n_ry == n_by)//���ȴµ� ���� ��ġ��
							{
								if (q_rx == q_bx)//�����࿡�� ��������
								{
									if (q_ry > q_by)//�������� �� �����ʿ��� ����
									{
										if (i == 0)//�������� ������
										{
											n_ry++;
										}
										else//���������� ������
										{
											n_by--;
										}
									}
									else//�������� �� ���ʿ��� ����
									{
										if (i == 0)//�������� ������
										{
											n_by++;
										}
										else//���������� ������
										{
											n_ry--;
										}
									}
								}
								else//���� ������ ��������
								{
									if (q_rx < q_bx)//�������� �� ���ʿ��� ����
									{
										if (i == 1)//�Ʒ������� ������
										{
											n_rx--;
										}
										else//�������� ������
										{
											n_bx++;
										}
									}
									else//�������� �� �Ʒ��ʿ��� ����
									{
										if (i == 1)//�Ʒ������� ������
										{
											n_bx--;
										}
										else//�������� ������
										{
											n_rx++;
										}
									}
								}
							}
							if (map[n_rx][n_ry][n_bx][n_by] == false && cnt < 10)
							{
								map[n_rx][n_ry][n_bx][n_by] = true;
								q.push(make_tuple(n_rx, n_ry, n_bx, n_by, cnt + 1));
							}
							break;
						}
						if (vec[n_rx][n_ry] == 'O')//�����̸�
						{
							check_blue = 0;
							while (1)
							{
								if (vec[n_bx][n_by] == '#')
								{
									n_bx -= dr[i];
									n_by -= dc[i];
									break;
								}
								if (vec[n_bx][n_by] == 'O')//�Ķ����� ���� �������� ����������
								{
									check_blue = 1;
									break;
								}
								n_bx += dr[i];
								n_by += dc[i];
							}
							if (check_blue == 1)
							{
								break;
							}
							if (cnt + 1 < minN)//�������� ������������
							{
								minN = cnt + 1;
								break;
							}
						}
						n_rx += dr[i];
						n_ry += dc[i];
					}				
			}
		}
	}
}