#include<stdio.h>

int arr[6][6];
int visited[6];
int node, V, data1, data2;
void DFS(int n, int k, int e);
int main()
{


	freopen("input.txt", "r", stdin);

	scanf("%d %d", &node, &V);

	for (int i = 0; i < V; i++)
	{
		scanf("%d %d", &data1, &data2);
		arr[data1][data2] = 1;
		arr[data2][data1] = 1;
	}
	DFS(1, node, 1);
}
void DFS(int n, int k, int e)
{
	if (e == k)
	{
		return;
		//printf("\n");
	}
	else
	{
		visited[n] = 1;
		printf("%d", n);
		for (int i = 1; i <= node; i++)
		{
			if (arr[n][i] == 1 && visited[i] == 0)
			{
				DFS(i, k, e+1);
			}
		}
		visited[n] = 0;
	}
}