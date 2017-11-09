#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxN = -0x7fffffff;
int minN = 0x7fffffff;
int N;
int num[101];
vector<int> vec;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &num[i]);
	}
	
	for (int i = 1; i < 5; ++i)
	{
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j < temp; j++)
		{
			vec.push_back(i);
		}
	}

	do {
		int num1 = num[1];
		int num2 = num[2];
		
		int op = vec[0];
		if (op == 1) { num1 += num2; }
		else if (op == 2) { num1 -= num2; }
		else if (op == 3) { num1 *= num2; }
		else { num1 /= num2; }

		for (int i = 3; i <= N; ++i)
		{
			int op = vec[i-2];
			if (op == 1) { num1 += num[i]; }
			else if (op == 2) { num1 -= num[i]; }
			else if (op == 3) { num1 *= num[i]; }
			else { num1 /= num[i]; }
		}

		if (maxN < num1)
			maxN = num1;
		if (num1 < minN)
			minN = num1;
	} while (next_permutation(vec.begin(), vec.end()));

	printf("%d\n%d\n", maxN, minN);
}