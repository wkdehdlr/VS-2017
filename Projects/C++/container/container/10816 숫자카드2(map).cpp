#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int, int> m1;
vector<int> v4 = { 1, 2, 3, 4, 5 };
int main()
{
	int N, M, temp;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		m1[temp]++;
	}
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &temp);
		if (m1[temp] != 0)
		{
			cout << m1[temp] << ' ';
		}
		else
		{
			cout << 0 << ' ';
		}
	}
	cout << '\n';
}