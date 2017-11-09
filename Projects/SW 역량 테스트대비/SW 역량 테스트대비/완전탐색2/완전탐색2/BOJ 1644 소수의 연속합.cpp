#include<iostream>
#include<vector>
using namespace std;

vector<int> vec(4000001,1);
vector<int> vec2;
int num;
int lp,rp;

int main()
{
	scanf("%d", &num);

	for (int i = 2; i <= num; ++i)
	{
		int cnt = 1;
		int j = i;
		if (vec[j] == 1)
		{
			vec2.push_back(j);
			while (1)
			{
				vec[j] = 0;
				j = i * cnt;
				cnt++;
				if (j > num)
					break;
			}
		}
	}
	int len = vec2.size();
	int sum = 0;
	int cnt = 0;
	for (lp = 0, rp = 0; rp < len; ++rp)
	{
		sum += vec2[rp];
		if (sum >= num)
		{
			if (sum == num)
			{
				cnt++;
				continue;
			}
			
			if (sum > num)
			{
				while (1)
				{
					sum -= vec2[lp];
					if (sum < num)
					{
						lp++;
						break;
					}

					if (sum == num)
					{
						lp++;
						cnt++;
						break;
					}
					lp++;
					if (lp == rp)
					{
						sum = 0; 
						break;
					}
				}
			}		
		}
	}

	printf("%d\n", cnt);
}