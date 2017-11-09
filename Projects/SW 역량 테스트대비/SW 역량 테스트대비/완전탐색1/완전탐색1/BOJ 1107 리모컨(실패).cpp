#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int N, M, cnt = 0;


int main()
{
	int up = 0x7fffffff, down=0x7fffffff;
	int temp;
	//map <int, int> map;
	vector<bool> map1(10,false);
	string str;	
	string newStr;


	scanf("%d", &N);
	scanf("%d", &M);

	

	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &temp);
		map1[temp] = true;
	}

	if (N == 100)
	{
		printf("0\n");
		return 0;
	}

	if (N > 100)
	{
		up = N - 100;
	}

	if (N < 100)
	{
		down = 100 - N;
	}

	
	str = to_string(N);
	int len = str.length();
	newStr.resize(len);

	for (int i = 0; i < len; ++i)
	{
		int num = str[i] - '0';
		if (map1[num] == false)
		{
			newStr[i] = num + '0';
			cnt++;
			if (cnt > up || cnt > down)
			{
				if (cnt > up)
				{
					printf("%d\n", up);
					return 0;
				}
				if (cnt > down)
				{
					printf("%d\n", down);
					return 0;
				}
			}
		}
		else
		{
			int nump = num;
			int numm = num;

			if (num == 0)
			{
				while (1)
				{
					if (map1[num] == false)
					{
						newStr[i] = num + '0';
						cnt++;
						break;
					}
					num++;
					if (num == 10)
						break;
				}
				if (cnt > up || cnt > down)
				{
					if (cnt > up)
					{
						printf("%d\n", up);
						return 0;
					}
					if (cnt > down)
					{
						printf("%d\n", down);
						return 0;
					}
				}
				continue;
			}
			if (num == 9)
			{
				while (1)
				{
					if (map1[num] == false)
					{
						newStr[i] = num + '0';
						cnt++;
						break;
					}
					num--;
					if (num == -1)
						break;
				}
				if (cnt > up || cnt > down)
				{
					if (cnt > up)
					{
						printf("%d\n", up);
						return 0;
					}
					if (cnt > down)
					{
						printf("%d\n", down);
						return 0;
					}
				}
				continue;
			}

			while (1)
			{
				if (numm >= 1 && map1[--numm] == false)
				{
					newStr[i] = numm + '0';
					cnt++;
					break;
				}

				if (nump <= 8 && map1[++nump] == false)
				{
					newStr[i] = numm + '0';
					cnt++;
					break;
				}
				if (cnt > up || cnt > down)
				{
					if (cnt > up)
					{
						printf("%d\n", up);
						return 0;
					}
					if (cnt > down)
					{
						printf("%d\n", down);
						return 0;
					}
				}
			}
		}
	}

	int fnum = stoi(newStr);

	if (fnum > N)
	{
		while (1)
		{
			cnt++;
			fnum--;
			if (fnum == N)
				break;
		}
	}
	else
	{
		while (1)
		{
			cnt++;
			fnum++;
			if (fnum == N)
				break;
		}
	}

	printf("%d\n", cnt);


	//100에서 99로 이동하면 9 누르고 9 눌러서 2나오는데

	//실제로는 - 한번만 누르면되니까 1이 나와야해 <- 이거 예외처리
}