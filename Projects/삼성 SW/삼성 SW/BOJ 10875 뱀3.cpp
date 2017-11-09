#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };
int L, N;

queue<pair<int, char> > q;
vector<tuple<int, int, int, int> > vec;
vector<tuple<int, int, int, int> > vec2;

int func(int,int,int);

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

	vec.push_back(make_tuple(-(L + 1), L + 1, L + 1, L + 1));
	vec.push_back(make_tuple(-(L + 1), -(L + 1), L + 1, -(L + 1)));

	vec2.push_back(make_tuple(-(L + 1), -(L + 1), -(L + 1), L + 1));
	vec2.push_back(make_tuple(L + 1, -(L + 1), L + 1, L + 1));

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
		//**********************************************************
		//�����̶� turn_time ���ߴµ� �׵θ� ����� ��� ó���ؾ���
		//**********************************************************


		if (dir == 0 || dir == 2)//���μ��и��� 
		{
			vec.push_back(make_tuple(min(start_x, x), min(start_y, y), max(start_x, x), max(start_y, y)));
			int minN = 2000050000;
			for (int i = 0; i < vec2.size()-1; ++i)
			{
				int y1 = get<1>(vec2[i]);
				int y2 = get<3>(vec2[i]);
				int x1 = get<0>(vec2[i]);

				if (x1 >= min(start_x, x) && x1 <= max(start_x, x) && y >= y1 && y <= y2)
				{
					//��ġ��
					if (abs(x1-start_x) < minN)//���κ��Ϳ��� ���� ���μ����� x��ǥ
						minN = abs(x1 - start_x);
				}
			}
			start_x = x;
			start_y = y;
			if (minN == 2000050000)//��ġ�°� ������
			{
				total_sec += turn_time;
				if (q.empty())//ť�� ����־ ����� ���������
				{
					printf("%lld\n", total_sec + func(dir, start_x, start_y));
					return 0;
				}
				else//ť�� ���� ����� ����������
				{
					turn_time = q.front().first;
					turn_dir = q.front().second;
					if (turn_dir == 'L')
					{
						dir = (dir + 1 + 4) % 4;
					}
					else
					{
						dir = (dir - 1 + 4) % 4;
					}
					q.pop();
				}
			}
			else//��ġ�°� ������
			{
				printf("%lld\n", total_sec + minN);
				return 0;
			}
		}
		else//���μ��и���
		{
			vec2.push_back(make_tuple(min(start_x, x), min(start_y, y), max(start_x, x), max(start_y, y)));
			int minN = 2000050000;
			for (int i = 0; i < vec.size()-1; ++i)
			{
				int x1 = get<0>(vec[i]);
				int x2 = get<2>(vec[i]);
				int y1 = get<1>(vec[i]);

				if (x >= x1 && x <= x2 && y1 >= min(start_y,y) && y1 <= max(start_y,y))
				{
					//��ġ��
					if (abs(y1 - start_y) < minN)//���κ��Ϳ��� ���� ���μ����� y��ǥ
						minN = abs(y1 - start_y);
				}
			}
			start_x = x;
			start_y = y;
			if (minN == 2000050000)//��ġ�°� ������
			{
				total_sec += turn_time;
				if (q.empty())//ť�� ����־ ����� ���������
				{
					printf("%lld\n", total_sec + func(dir, start_x, start_y));
					return 0;
				}
				else//ť�� ���� ����� ����������
				{
					turn_time = q.front().first;
					turn_dir = q.front().second;
					if (turn_dir == 'L')
					{
						dir = (dir + 1 + 4) % 4;
					}
					else
					{
						dir = (dir - 1 + 4) % 4;
					}
					q.pop();
				}
			}
			else//��ġ�°� ������
			{
				printf("%lld\n", total_sec + minN);
				return 0;
			}
		}
	}
}

int func(int dir, int start_x, int start_y)
{
	if (dir == 0)//���ʳ�
	{
		int minN = 2000050000;
		for (int i = 0; i < vec2.size(); ++i)
		{
			int y1 = get<1>(vec2[i]);
			int y2 = get<3>(vec2[i]);
			int x1 = get<0>(vec2[i]);

			if (x1 >= -L-1 && x1 <= start_x && start_y >= y1 && start_y <= y2)
			{
				//��ġ��
				if (abs(x1 - start_x) < minN)//���κ��Ϳ��� ���� ���μ����� x��ǥ
					minN = abs(x1 - start_x);
			}
		}
		return minN;
	}
	else if (dir == 1)//�Ʒ���
	{
		int minN = 2000050000;
		for (int i = 0; i < vec.size(); ++i)
		{
			int x1 = get<0>(vec[i]);
			int x2 = get<2>(vec[i]);
			int y1 = get<1>(vec[i]);

			if (start_x >= x1 && start_x <= x2 && y1 >= -L-1 && y1 <= start_y)
			{
				//��ġ��
				if (abs(y1 - start_y) < minN)//���κ��Ϳ��� ���� ���μ����� y��ǥ
					minN = abs(y1 - start_y);
			}
		}
		return minN;
	}
	else if (dir == 2)//�����ʳ�
	{
		int minN = 2000050000;
		for (int i = 0; i < vec2.size(); ++i)
		{
			int y1 = get<1>(vec2[i]);
			int y2 = get<3>(vec2[i]);
			int x1 = get<0>(vec2[i]);

			if (x1 >= start_x && x1 <= L+1 && start_y >= y1 && start_y <= y2)
			{
				//��ġ��
				if (abs(x1 - start_x) < minN)//���κ��Ϳ��� ���� ���μ����� x��ǥ
					minN = abs(x1 - start_x);
			}
		}
		return minN;
	}
	else//����
	{
		int minN = 2000050000;
		for (int i = 0; i < vec.size(); ++i)
		{
			int x1 = get<0>(vec[i]);
			int x2 = get<2>(vec[i]);
			int y1 = get<1>(vec[i]);

			if (start_x >= x1 && start_x <= x2 && y1 >= start_y && y1 <= L + 1)
			{
				//��ġ��
				if (abs(y1 - start_y) < minN)//���κ��Ϳ��� ���� ���μ����� y��ǥ
					minN = abs(y1 - start_y);
			}
		}
		return minN;
	}
}