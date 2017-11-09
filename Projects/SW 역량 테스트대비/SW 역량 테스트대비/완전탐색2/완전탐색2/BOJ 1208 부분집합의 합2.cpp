#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;
vector<int> vec2;


int N, S;
int cnt = 0;
void func(int, int);
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		vec.push_back(tmp);
	}
	vec2.resize(N, 0);
	func(0, N);
	printf("%d\n", cnt);
}

void func(int n, int k)
{
	if (n == k)
	{
		int sum = 0;
		int flag = 0;
		for (int i = 0; i < N; i++)
		{
			if (vec2[i] == 1)
			{
				//printf("%d", vec[i]);
				sum+=vec[i];
				flag = 1;
			}
		}
		//printf("\n");
		if (sum == S && flag == 1)
			cnt++;
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			vec2[n] = i;
			func(n + 1, k);
		}
	}
}