#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> vec = { {0},{0},{0},{0} };//{ {0, 1, 1, 1}, {1, 1, 1, 1} , { 1, 1, 1, 1 } , { 0, 0, 1, 0 }};

int main()
{
	int maxV = 0;
	int temp = 0;
	int temp2 = 0;

	for (int x = 0; x < vec.size(); ++x)
	{
		for (int y = 0; y < vec[0].size(); ++y)
		{
			if (vec[x][y] == 1)
			{
				temp = 1;
				if (vec.size() != 1 && vec[0].size() != 1 && x != 0 && y != 0)
				{
					if (vec[x - 1][y] != 0 && vec[x][y - 1] != 0 && vec[x - 1][y - 1] != 0)
					{
						temp2 = 1;
						vec[x][y] = min(min(vec[x - 1][y - 1], vec[x][y - 1]), vec[x - 1][y]) + 1;
						if (maxV < vec[x][y])
							maxV = vec[x][y];
					}
				}
			}
		}
	}


	if (temp == 0)
	{
		maxV = 0;
	}

	if (temp == 1 && temp2 == 0)
	{
		maxV = 1;
	}
	maxV *= maxV;

	cout << maxV << '\n';

}