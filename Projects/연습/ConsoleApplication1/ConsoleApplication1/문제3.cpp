#include<iostream>
#include<vector>
using namespace std;



int main()
{
	int x, y;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int x1n = 0, y1n = 0, x2n = 0, y2n = 0;
	vector<vector<int> > vec = { {1,4},{3,4},{3,10} };

	x1 = vec[0][0]; y1 = vec[0][1];
	x1n++; y1n++;

	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i][0] == x1)
		{
			x1n++;
		}
		else
		{
			x2 = vec[i][0];
			x2n++;
		}

		if (vec[i][1] == y1)
		{
			y1n++;
		}
		else
		{
			y2 = vec[i][1];
			y2n++;
		}
	}

	if (x1n == 1)
	{
		x = x1;
	}
	else
	{
		x = x2;
	}
	if (y1n == 1)
	{
		y = y1;
	}
	else
	{
		y = y2;
	}
	
	printf("%d %d\n", x, y);
}