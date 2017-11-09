#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int row;
	vector<vector<int>> vec = {{1, 2, 3, 5}, { 5, 6, 7, 8 }, { 4, 3, 2, 1 }};
	vector<int> vecTemp = { 0,0,0,0 };



	for (int i = 0; i < vec.size() - 1; ++i)
	{	
		for (int k = 0; k < 4; ++k)
		{
			row = k;
			for (int z = 0; z < 4; ++z)
			{
				if (row != z)
				{
					vecTemp[z] = max(vecTemp[z], vec[i][k] + vec[i+1][z]);
				}
			}
		}
		vec[i + 1].clear();
		for (int x : vecTemp)
		{
			vec[i + 1].push_back(x);
		}
	}
	auto it = max_element(vecTemp.begin(), vecTemp.end());
	cout << (*it) << '\n';
}