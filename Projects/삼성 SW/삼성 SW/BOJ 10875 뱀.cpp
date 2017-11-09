#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };
int L,N;

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
	int turn_time;
	char turn_dir;
	if (!q.empty())
	{
		turn_time = q.front().first;
		turn_dir = q.front().second;
		q.pop();
	}
	else
	{
		turn_time = -1;
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
		if (total_sec == turn_time)
		{
			//vec.push_back(make_tuple(start_x, start_y, x, y));
			if (turn_dir == 'L')
			{
				dir = (dir + 1 + 4) % 4;
			}
			else
			{
				dir = (dir - 1 + 4) % 4;
			}

			if (!q.empty())
			{
				turn_time += q.front().first;
				turn_dir = q.front().second;
				q.pop();
			}

			if (dir == 0 || dir == 2)//앞으로 가로방향으로 진행
			{
				//세로선분을 세로벡터에 저장하고
				vec2.push_back(make_tuple(min(start_x, x), min(start_y, y), max(start_x, x), max(start_y, y)));
				//가로벡터중에 세로선분과 겹치는게 있나 검사
				sizeV = vec.size();
				for (int t = 0; t < sizeV; ++t)
				{
					x1 = get<0>(vec[t]);
					y1 = get<1>(vec[t]);
					x2 = get<2>(vec[t]);
					if (x >= x1 && x <= x2 && y1 >= min(start_y,y) && y1 <= max(start_y, y))
					{
						printf("%lld\n", total_sec + 1);
						return 0;
						//die;
					}
				}
			}
			else//앞으로 세로방향진행
			{
				vec.push_back(make_tuple(min(start_x, x), min(start_y, y), max(start_x, x), max(start_y, y)));
				//세로벡터중에서 가로선분과 겹치는거 있나 검사
				sizeV = vec2.size();
				for (int t = 0; t < sizeV; ++t)
				{
					x1 = get<0>(vec2[t]);
					y1 = get<1>(vec2[t]);
					y2 = get<3>(vec2[t]);
					if (x1 >= min(start_x,x) && x <= max(start_x, x) && y >= y1 && y <= y2)
					{
						printf("%lld\n", total_sec + 1);
						return 0;
						//die;
					}
				}

			}
			start_x = x;
			start_y = y;
		}
		x += dr[dir];
		y += dc[dir];
		if ((!(x >= -L && x <= L && y >= -L && y <= L)) || (x == 0 && y == 0))
		{
			printf("%lld\n", total_sec + 1);
			return 0;
			//die;
		}

		/*
		for (int t = 0; t < sizeV; ++t)
		{
			if (dir == 0 || dir == 2)
			{
				x1 = get<0>(vec2[t]);
				y1 = get<1>(vec2[t]);
				x2 = get<2>(vec2[t]);
				y2 = get<3>(vec2[t]);
			}
			else
			{
				x1 = get<0>(vec[t]);
				y1 = get<1>(vec[t]);
				x2 = get<2>(vec[t]);
				y2 = get<3>(vec[t]);
			}
			if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
			{
				printf("%lld\n", total_sec + 1);
				return 0;
				//die;
			}
		}
		*/
		total_sec++;
	}
}