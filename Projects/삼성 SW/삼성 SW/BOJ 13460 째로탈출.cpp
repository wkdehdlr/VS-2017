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
					//째로 범위안에 있고 아직 방문안한곳이 있으면 벽에 닿을때까지 굴린다
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
							if (check_blue == 1)//빨간공보다 파란공이 먼저 구멍에 빠지면
							{
								break;
							}
							if (n_rx == n_bx && n_ry == n_by)//굴렸는데 둘이 겹치면
							{
								if (q_rx == q_bx)//같은행에서 굴렸을때
								{
									if (q_ry > q_by)//빨간공이 더 오른쪽에서 시작
									{
										if (i == 0)//왼쪽으로 굴릴때
										{
											n_ry++;
										}
										else//오른쪽으로 굴릴때
										{
											n_by--;
										}
									}
									else//빨간공이 더 왼쪽에서 시작
									{
										if (i == 0)//왼쪽으로 굴릴때
										{
											n_by++;
										}
										else//오른쪽으로 굴릴때
										{
											n_ry--;
										}
									}
								}
								else//같은 열에서 굴렸을때
								{
									if (q_rx < q_bx)//빨간공이 더 위쪽에서 시작
									{
										if (i == 1)//아래쪽으로 굴릴때
										{
											n_rx--;
										}
										else//위쪽으로 굴릴때
										{
											n_bx++;
										}
									}
									else//빨간공이 더 아래쪽에서 시작
									{
										if (i == 1)//아래쪽으로 굴릴때
										{
											n_bx--;
										}
										else//위쪽으로 굴릴때
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
						if (vec[n_rx][n_ry] == 'O')//구멍이면
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
								if (vec[n_bx][n_by] == 'O')//파란색도 같이 구멍으로 빠져나가면
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
							if (cnt + 1 < minN)//빨간색만 빠져나왔을때
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