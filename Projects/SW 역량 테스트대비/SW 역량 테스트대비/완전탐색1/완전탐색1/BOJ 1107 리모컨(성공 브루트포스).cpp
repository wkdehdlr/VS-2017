#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<bool> vec(10,false);
int N, M;
int absNum;

int main()
{
	int temp;
	scanf("%d", &N);
	scanf("%d", &M);


	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &temp);
		vec[temp] = true;
	}
	
	absNum = abs(100 - N);

	for (int i = 0; i <= 1000000; ++i)
	{
		int flag = 0;
		string str = to_string(i);
		int len = str.length();

		for (int k = 0; k < len; ++k)
		{
			if (vec[str[k] - '0'] == true)
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
		{
			if (absNum > abs(i - N) + len)
			{
				absNum = abs(i - N) + len;
			}
		}
	}

	printf("%d\n", absNum);


}