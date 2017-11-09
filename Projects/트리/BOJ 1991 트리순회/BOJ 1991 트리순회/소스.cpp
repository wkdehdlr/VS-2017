#include<stdio.h>

int p[27];
int c1[27];
int c2[27];

void pre(int n);
void visit(int n);
void post(int n);

int main()
{
	int N;
	char node1,node2,node3;
	char temp;


	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%c", &temp);
	for (int i = 1; i <= N; i++)
	{
		scanf("%c", &node1);		scanf("%c", &temp);
		scanf("%c", &node2);		scanf("%c", &temp);
		if (node2 == '.')
		{
			c1[node1 - '0' - 16] = 0;
		}
		else
		{
			c1[node1 - '0' - 16] = node2 - '0' - 16;
		}

		scanf("%c", &node3);
		scanf("%c", &temp);
		if (node3 == '.')
		{
			c2[node1 - '0' - 16] = 0;
		}
		else
		{
			c2[node1 - '0' - 16] = node3 - '0' - 16;
		}
	}
	pre(1); printf("\n");
	visit(1); printf("\n");
	post(1); printf("\n");
}

void pre(int n)
{
	printf("%c", n + '0' + 16);
	if (c1[n] != 0)
	{
		pre(c1[n]);
	}

	if (c2[n] != 0)
	{
		pre(c2[n]);
	}
}
void visit(int n)
{
	if (c1[n] != 0)
	{
		visit(c1[n]);
	}
	printf("%c", n + '0' + 16);
	if (c2[n] != 0)
	{
		visit(c2[n]);
	}
}
void post(int n)
{
	if (c1[n] != 0)
	{
		post(c1[n]);
	}
	if (c2[n] != 0)
	{
		post(c2[n]);
	}
	printf("%c", n + '0' + 16);
}