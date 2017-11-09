#include<iostream>
#include<set>
using namespace std;


int main()
{
	set<int> s1;
	int N, M, temp;

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		s1.insert(temp);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &temp);
		printf("%d ", s1.count(temp));
	}
	printf("\n");
}