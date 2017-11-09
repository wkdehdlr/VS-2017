#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#include<math.h>
using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };
int L, N;

queue<pair<int, char> > q;
vector<tuple<int, int, int, int> > vec;
vector<tuple<int, int, int, int> > vec2;

int main()
{
	int x = 0, y = 0, dir = 2;
	long long total_sec = 0;
	scanf("%d", &L);
	scanf("%d", &N);
	for (int k = 0; k < N; ++k)
	{
		int sec;
		char dr;
		cin >> sec >> dr;
		q.push(make_pair(sec, dr));
	}
	int turn_time = -1;
	char turn_dir;
	if (!q.empty())
	{
		turn_time = q.front().first;
		turn_dir = q.front().second;
		q.pop();
	}

	int start_x = 0, start_y = 0;

	int x1, y1, x2, y2;
	int sizeV = 0;

	vec.push_back(make_tuple(-(L + 1), L + 1, L + 1, L + 1));//���μ���
	vec.push_back(make_tuple(-(L + 1), -(L + 1), L + 1, -(L + 1)));

	vec2.push_back(make_tuple(-(L + 1), -(L + 1), -(L + 1), L + 1));//���μ���
	vec2.push_back(make_tuple(L + 1, -(L + 1), L + 1, L + 1));

	if (turn_time == -1)
	{
		printf("%d\n", L + 1);
	}
	else
	{
		while (1)
		{
			if (dir == 0)//��
			{
				x -= turn_time;
			}
			else if (dir == 1)//�Ʒ�
			{
				y -= turn_time;
			}
			else if (dir == 2)//����
			{
				x += turn_time;
			}
			else//��
			{
				y += turn_time;
			}

			if (x == 0 && y == 0)
			{
				printf("%lld\n", total_sec + turn_time);
				return 0;
			}

			if (dir == 0 || dir == 2)//���μ��� ��������ϱ� ���κ��Ͷ� ���ؾ���
			{
				int minX = L;
				int temp = 0;
				for (int i = 0; i < vec2.size(); ++i)
				{
					int x1 = get<0>(vec2[i]);
					int y1 = get<1>(vec2[i]);
					int y2 = get<3>(vec2[i]);
					if (x1 >= start_x && x1 <= x && y >= y1 && y <= y2)
					{
						temp = 1;
						if (abs(x1) < minX)
							minX = abs(x1);
					}
				}

				if (temp == 1)//��ġ�¼����� �ִ�. ������
				{
					printf("%lld\n", total_sec + abs(start_x - minX));
					return 0;
				}
				else//��ġ�� ������ ����. �׷� ���� ���� ���μ����� ���κ��Ϳ� �߰��Ѵ�.
				{
					vec2.push_back(make_tuple(min(start_x, x), min(start_y, y), max(start_x, x), max(start_y, y)));
					
					//q���� ���β����� ���ο� ȸ���ð��� ������ ��´�.
					total_sec += turn_time;
					if (q.empty())//���̻� ����� ������
					{
						if (dir == 2)
						{
							int minX = L;
							int temp = 0;
							for (int i = 0; i < vec2.size(); ++i)
							{
								int x1 = get<0>(vec2[i]);
								int y1 = get<1>(vec2[i]);
								int y2 = get<3>(vec2[i]);
								if (x1 >= start_x && x1 <= L + 1 && y >= y1 && y <= y2)
								{
									temp = 1;
									if (abs(x1) < minX)
										minX = abs(x1);
								}
							}
							if (temp == 0)
							{
								printf("%lld\n", total_sec + L - start_x + 1);
								return 0;
							}
							else
							{
								printf("%lld\n", total_sec + minX - start_x);
								return 0;
							}
						}
						else//���ʳ�
						{
							int minX = L;
							int temp = 0;
							for (int i = 0; i < vec2.size(); ++i)
							{
								int x1 = get<0>(vec2[i]);
								int y1 = get<1>(vec2[i]);
								int y2 = get<3>(vec2[i]);
								if (x1 >= -L-1 && x1 <= start_x && y >= y1 && y <= y2)
								{
									temp = 1;
									if (abs(x1) < minX)
										minX = abs(x1);
								}
							}
							if (temp == 0)
							{
								printf("%lld\n", total_sec + start_x + L+ 1);
								return 0;
							}
							else
							{
								printf("%lld\n", total_sec + start_x - minX);
								return 0;
							}
						}
					}
					else
					{
						turn_time = q.front().first;
						turn_dir = q.front().second;
						q.pop();
					}
				}
			}
			else//���μ��и�������ϱ� ���κ��Ͷ� ���ؾ���
			{
				int minY = L;
				int temp = 0;
				for (int i = 0; i < vec.size(); ++i)
				{
					int x1 = get<0>(vec[i]);
					int y1 = get<1>(vec[i]);
					int x2 = get<2>(vec[i]);
					if (x >= x1 && x <= x2 && y1 >= min(start_y, y) && y1 <= max(start_y, y))
					{
						temp = 1;
						if (abs(y1) < minY)
							minY = abs(y1);
					}
				}

				if (temp == 1)//��ġ�¼����� �ִ�. ������
				{
					printf("%lld\n", total_sec + abs(start_y - minY));
					return 0;
				}
				else//��ġ�� ������ ����. �׷� ���� ���� ���μ����� ���κ��Ϳ� �߰��Ѵ�.
				{
					vec.push_back(make_tuple(min(start_x, x), min(start_y, y), max(start_x, x), max(start_y, y)));

					//q���� ���β����� ���ο� ȸ���ð��� ������ ��´�.
					total_sec += turn_time;
					if (q.empty())//���̻� ����� ������
					{
						if (dir == 1)//�Ʒ���
						{
							int minY = L;
							int temp = 0;
							for (int i = 0; i < vec.size(); ++i)
							{
								int x1 = get<0>(vec[i]);
								int y1 = get<1>(vec[i]);
								int	x2 = get<2>(vec[i]);
								if (x >= x1 && x <= x2 && y1 >= -L-1 && y1 <= y)
								{
									temp = 1;
									if (abs(y1) < minY)
										minY = abs(y1);
								}
							}
							if (temp == 0)
							{
								printf("%lld\n", total_sec + L - start_y + 1);
								return 0;
							}
							else
							{
								printf("%lld\n", total_sec + minY- start_y);
								return 0;
							}
						}
						else//����
						{
							int minY = L;
							int temp = 0;
							for (int i = 0; i < vec.size(); ++i)
							{
								int x1 = get<0>(vec[i]);
								int y1 = get<1>(vec[i]);
								int x2 = get<2>(vec[i]);
								if (x >= x1 && x <= x2 && y1 >= start_y && y <= L+1)
								{
									temp = 1;
									if (abs(y1) < minY)
										minY = abs(y1);
								}
							}
							if (temp == 0)
							{
								printf("%lld\n", total_sec + start_x + L + 1);
								return 0;
							}
							else
							{
								printf("%lld\n", total_sec + start_x - minX);
								return 0;
							}
						}
					}
					else
					{
						turn_time = q.front().first;
						turn_dir = q.front().second;
						q.pop();
					}
				}
			}
			start_x = x;
			start_y = y;
		}
	}
}