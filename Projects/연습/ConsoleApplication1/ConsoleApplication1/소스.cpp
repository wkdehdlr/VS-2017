



#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> > vec;
int main()
{
	int N, M, temp;
	cin >> N >> M;


	vec.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		cin >> N >> temp;
		vec[N].push_back(temp);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int x : vec[i])
		{

		}
	}
}


