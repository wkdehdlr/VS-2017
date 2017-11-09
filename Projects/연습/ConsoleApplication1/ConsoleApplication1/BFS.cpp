#include<stdio.h>

int q[10];
int arr[10][10];
int visited[10];

void enQ(int n);
int deQ();

void BFS(int n);

int node, V,front,rear;

int main()
{
	int data1, data2;
	
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &node, &V);

	for (int i = 1; i <= V; i++)
	{
		scanf("%d %d", &data1, &data2);
		arr[data1][data2] = 1;
		arr[data2][data1] = 1;
	}
	BFS(1);
	
	for (int i = 1; i <= node; i++)
	{
		printf("%d", visited[i]-1);
	}
}
void BFS(int n)
{
	int k;

	enQ(n);
	visited[n] = 1;

	while (front != rear)
	{
		n = deQ();
		for (int i = 1; i <= node; i++)
		{
			if (arr[n][i] == 1 && visited[i] == 0)
			{
				enQ(i);
				visited[i] = visited[n] + 1;
			}
		}
	}
}
void enQ(int n)
{
	if (rear == 9)
	{
		return;
	}
	else
	{
		q[++rear] = n;
	}
}
int deQ()
{
	if (front == rear)
	{
		return -1;
	}
	else
	{
		return q[++front];
	}
}