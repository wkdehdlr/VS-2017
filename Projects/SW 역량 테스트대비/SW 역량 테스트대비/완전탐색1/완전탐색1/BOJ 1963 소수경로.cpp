#include<iostream>
#include<vector>
using namespace std;

vector<int> vec(10001, 1);
int Tc;

int main()
{
	for (int i = 2; i < 10000; ++i)
	{
		int cnt = 2;
		if (vec[i] == 1)
		{
			vec[i] = 1;
			while (1)
			{
				if (i*cnt > 10000)
					break;

				vec[i*cnt] = 0;
				cnt++;
			}
		}
	}

	scanf("%d", &Tc);

}