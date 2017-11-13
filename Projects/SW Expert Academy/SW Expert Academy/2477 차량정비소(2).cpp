#pragma warning(disable : 4996)
#include<iostream>
#include<queue>
using namespace std;

struct person {
	int cusNum;//����ȣ
	int recepNum;//���� �̿��� ����â����ȣ
	int repairNum;//���� �̿��� ����â����ȣ

	int total_time;
	int now_time;
};

queue<person> first_ready;//����â������ ���
queue<person> second_ready;//����â������ ���

person recep[11];//����â��
person repair[11];//����â��
int N, M;//N ����â������, M ����â������
int tk[1001];
int res_tk[1001];
int K;//�湮�� ����
int A, B;
int cnt = 0;
int temp = 0;

int start_time;//�������ð�

int second_ready_start();
void first_ready_start();
int check_end();
void start();
int main()
{
	int Tc;
	scanf("%d", &Tc);
	for (int t = 0; t < Tc; t++)
	{
		temp = 0;
		cnt = 0;
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &(recep[i].total_time));
			recep[i].now_time = -1;
		}
		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &(repair[i].total_time));
			repair[i].now_time = -1;
		}
		for (int i = 1; i <= K; i++)
		{
			scanf("%d", &tk[i]);
			res_tk[i] = 0;
		}

		



		int end;
		while (1)
		{
			start();
			first_ready_start();
			end = second_ready_start();
			if (end == 1)
				break;
			temp++;
		}
		if (cnt == 0)
		{
			printf("#%d %d\n", t + 1, -1);
		}
		else
		{
			printf("#%d %d\n", t + 1, cnt);
		}
	}
}

void start()
{
	for (int i = 1; i <= K; ++i)
	{
		if (temp == tk[i])
		{
			person p;
			p.cusNum = i;
			first_ready.push(p);
		}
	}
}

void first_ready_start()
{
	for (int i = 1; i <= N; ++i)
	{
		if (recep[i].now_time == -1)//â���� ���������
		{
			if (!first_ready.empty())
			{
				first_ready.front().recepNum = i;
				first_ready.front().total_time = recep[i].total_time;
				recep[i] = first_ready.front();
				first_ready.pop();
				recep[i].now_time = recep[i].total_time;
				recep[i].now_time--;
			}
		}
		else
		{
			recep[i].now_time--;
			if (recep[i].now_time == -1)
			{
				second_ready.push(recep[i]);
				if (!first_ready.empty())
				{
					first_ready.front().recepNum = i;
					first_ready.front().total_time = recep[i].total_time;
					recep[i] = first_ready.front();
					first_ready.pop();
					recep[i].now_time = recep[i].total_time;
					recep[i].now_time--;
				}
			}
		}
	}
}

int second_ready_start()
{
	for (int i = 1; i <= M; ++i)
	{
		if (repair[i].now_time == -1)//â���� ���������
		{
			if (!second_ready.empty())
			{
				second_ready.front().repairNum = i;
				second_ready.front().total_time = repair[i].total_time;
				repair[i] = second_ready.front();
				second_ready.pop();
				repair[i].now_time = repair[i].total_time;
				repair[i].now_time--;
			}
		}
		else
		{
			repair[i].now_time--;
			if (repair[i].now_time == -1)
			{
				res_tk[repair[i].cusNum] = 1;
				if (repair[i].recepNum == A && repair[i].repairNum == B)
				{
					cnt += repair[i].cusNum;
				}

				if (!second_ready.empty())
				{
					second_ready.front().repairNum = i;
					second_ready.front().total_time = repair[i].total_time;
					repair[i] = second_ready.front();
					second_ready.pop();
					repair[i].now_time = repair[i].total_time;
					repair[i].now_time--;
				}
			}
		}
	}
	return check_end();
}

int check_end()
{
	int sum = 0;
	for (int i = 1; i <= K; ++i)
	{
		sum += res_tk[i];
	}
	if (sum == K)
		return 1;
	else
		return -1;
}