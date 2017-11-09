#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<char>> vec(11, vector<char>(11));

int main()
{
	int n;
	scanf("%d", &n);

	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%c", &vec[i][j]);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			func(i, j);
		}
	}
}

void func(int i, int j)
{
	if (vec[i][j] == 'A')
	{
		if (vec[i - 1][j] == A)
		{

		}



	}
}