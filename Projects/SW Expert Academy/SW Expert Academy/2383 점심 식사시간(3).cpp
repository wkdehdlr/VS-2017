#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;

int new_com[10];
int com[10] = { 1,2,3,4,5,6,7,8,9,10 };

struct person {
	int a1;
	int a2;
	int a3;
	int a4;
};
person arr[11][11];
queue<person> q;
queue<person> q_stair1;
queue<person> q_stair2;
int N;
int first_x, first_y, second_x, second_y;
int first_stair, second_stair;
int cnt;
int minN = 0x7fffffff;

void nck(int, int, int);
void start_stair1();
void start_stair2();
void setStair1(int);
void setStair2(int);
void start();
int main()
{
	int num = 1;
	int temp;
	int Tc;
	scanf("%d", &Tc);
	for (int t = 0; t < Tc; t++)
	{
		minN = 0x7fffffff;
		num = 1;
		cnt = 1;
		first_x = -1;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				person p;
				scanf("%d", &temp);
				p.a1 = temp;
				if (temp == 1)
				{
					p.a4 = num;
					num++;
				}
				if (temp != 1 && temp != 0 && first_x == -1)
				{
					first_stair = temp;
					first_x = i;
					first_y = j;
					continue;
					//get<0>(arr[i][j]) = 1;
				}

				if (temp != 1 && temp != 0 && first_x != -1)
				{
					second_stair = temp;
					second_x = i;
					second_y = j;
					//get<0>(arr[i][j]) = 2;
				}

				arr[i][j] = p;
			}
		}
		num--;
		for (int i = 0; i <= (num / 2); ++i)
		{
			nck(num, i, i);
		}
		printf("#%d %d\n", t + 1, minN);
	}
}
void nck(int n, int k, int w)
{
	if (k == 0)
	{
		queue<person> q_temp;

		cnt = 1;
		q = q_temp;
		q_stair1 = q_temp;
		q_stair2 = q_temp;
		setStair1(w);
		while (!(q.empty() && q_stair1.empty() && q_stair2.empty()))
		{
			start_stair1();
			start_stair2();
			start();
			cnt++;
			if (minN < cnt)
				break;
		}

		if (minN > cnt)
			minN = cnt;

		cnt = 1;
		q = q_temp;
		q_stair1 = q_temp;
		q_stair2 = q_temp;
		setStair2(w);
		while (!(q.empty() && q_stair1.empty() && q_stair2.empty()))
		{
			start_stair1();
			start_stair2();
			start();
			cnt++;
			if (minN < cnt)
				break;
		}
		if (minN > cnt)
			minN = cnt;
	}
	else if (n < k)
	{
		return;
	}
	else
	{
		new_com[k - 1] = com[n - 1];
		nck(n - 1, k - 1, w);
		nck(n - 1, k, w);
	}
}

void setStair1(int k)
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j].a1 == 1)
			{
				int flag = 1;
				for (int w = 0; w < k; ++w)
				{
					if (new_com[w] == arr[i][j].a4)//선택된거면 first_stair
					{
						flag = 0;
						arr[i][j].a2 = 1;
						arr[i][j].a3 = abs(first_x - i) + abs(first_y - j);
					}
				}
				if (flag == 1)
				{
					arr[i][j].a2 = 2;
					arr[i][j].a3 = abs(second_x - i) + abs(second_y - j);
				}
				q.push(arr[i][j]);
			}
		}
	}
}
void setStair2(int k)
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j].a1 == 1)
			{
				int flag = 1;
				for (int w = 0; w < k; ++w)
				{
					if (new_com[w] == arr[i][j].a4)//선택된거면 first_stair
					{
						flag = 0;
						arr[i][j].a2 = 2;
						arr[i][j].a3 = abs(second_x - i) + abs(second_y - j);
					}
				}
				if (flag == 1)
				{
					arr[i][j].a2 = 1;
					arr[i][j].a3 = abs(first_x - i) + abs(first_y - j);
				}
				q.push(arr[i][j]);
			}
		}
	}
}
void start()
{
	queue<person> q_temp;
	while (!q.empty())
	{
		if (q.front().a3 != 0)
		{
			q.front().a3--;
		}

		if (q.front().a3 == 0)
		{
			if (q.front().a2 == 1)//첫번째 계단이면
			{
				if (q_stair1.size() < 3)
				{
					q.front().a3 = first_stair;
					q_stair1.push(q.front());
					q.pop();
				}
				else
				{
					q_temp.push(q.front());
					q.pop();
				}
				//첫번째계단 q에 push
			}
			else//두번째 계단이면
			{
				if (q_stair2.size() < 3)
				{
					q.front().a3 = second_stair;
					q_stair2.push(q.front());
					q.pop();
				}
				else
				{
					q_temp.push(q.front());
					q.pop();
				}
			}
		}
		else
		{
			q_temp.push(q.front());
			q.pop();
		}
	}
	q = q_temp;
}
void start_stair1()
{
	queue<person> q_temp;
	while (!q_stair1.empty())
	{
		q_stair1.front().a3--;

		if (q_stair1.front().a3 == 0)
		{
			q_stair1.pop();
		}
		else
		{
			q_temp.push(q_stair1.front());
			q_stair1.pop();
		}
	}
	q_stair1 = q_temp;
}
void start_stair2()
{
	queue<person> q_temp;
	while (!q_stair2.empty())
	{
		q_stair2.front().a3--;

		if (q_stair2.front().a3 == 0)
		{
			q_stair2.pop();
		}
		else
		{
			q_temp.push(q_stair2.front());
			q_stair2.pop();
		}
	}
	q_stair2 = q_temp;
}