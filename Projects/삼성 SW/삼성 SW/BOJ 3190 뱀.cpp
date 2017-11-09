#include<iostream>
#include<queue>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

int N, K, L;
int arr[101][101];
bool mov[101][101];
bool apple[101][101];
queue<pair<int, char> > q;
queue<pair<int, int> > body;

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		apple[x][y] = true;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; ++i)
	{
		int sec;
		char c;
		cin >> sec >> c;
		q.push(make_pair(sec, c));
	}
	int total_sec = 0;
	int i = 2;
	int bx = 1, by = 1;
	mov[bx][by] = true;

	int turn_time = q.front().first;
	char turn_way = q.front().second;
	q.pop();

	while (1)
	{
		if (total_sec == turn_time)
		{
			if (turn_way == 'D')//������
			{
				i -= 1;
				if (i == -1)
					i = 3;
			}
			else//����
			{
				i += 1;
				if (i == 4)
					i = 0;
			}
			if (!q.empty())
			{
				turn_time = q.front().first;
				turn_way = q.front().second;
				q.pop();
			}
		}
		bx += dr[i];
		by += dc[i];
		if ((!(bx >= 1 && bx <= N && by >= 1 && by <= N)) || mov[bx][by] == true)
		{
			total_sec++;
			break;
		}
		mov[bx][by] = true;
		if (apple[bx][by] == true)//����� ������ �Ӹ��� �ø�//������  q�� �ִ´�.
		{
			apple[bx][by] = false;
			body.push(make_pair(bx - dr[i], by - dc[i]));
		}
		else//����� ������ ������ �ڸ�
		{
			if (!body.empty())
			{
				mov[body.front().first][body.front().second] = false;
				body.pop();
				body.push(make_pair(bx - dr[i], by - dc[i]));
			}
			else
			{
				mov[bx - dr[i]][by - dc[i]] = false;
			}
		}
		total_sec++;
	}
	printf("%d\n", total_sec);
}