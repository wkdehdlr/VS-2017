#include<stdio.h>


int arr[10];
int last;
int p, c, c1, c2,r;
void enQ(int n);
int deQ();

int main()
{
	int N;
	int data;

	freopen("input.txt", "r", stdin);

	p = c = last = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &data);
		enQ(data);
	}	
	for (int i = 1; i <= N; i++)
	{
		deQ();
		printf("%d", r);
	}
}
void enQ(int n)
{
	int temp = 0;

	last++;
	c = last;
	p = c / 2;
	arr[c] = n;

	while (arr[p] > arr[c] && c > 1)
	{
		temp = arr[p];
		arr[p] = arr[c];
		arr[c] = temp;
		//swap
		c = p;
		p = c / 2;
	}
}

int deQ()
{
	int temp;

	r = arr[1];
	arr[1] = arr[last];
	last--;

	p = 1;
	while (p < last)
	{
		c1 = p * 2;
		c2 = p * 2 + 1;

		if (c2 <= last)
		{
			c = arr[c1] < arr[c2] ? c1 : c2;
			if (arr[c1] < arr[p])
			{
				temp = arr[c1];
				arr[c1] = arr[p];
				arr[p] = temp;

				p = c;
			}
			else
				break;
		}
		else if (c1 <= last)
		{
			if (arr[c1] < arr[p])
			{
				temp = arr[c1];
				arr[c1] = arr[p];
				arr[p] = temp;

				p = c1;
			}
			else
				break;
		}
	}
	return 0;
}