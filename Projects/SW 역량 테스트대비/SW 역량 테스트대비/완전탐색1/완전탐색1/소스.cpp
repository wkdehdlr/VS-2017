#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> num = { 8,9,10 };


int main()
{
	do {
		for (int i = 0; i < 3; ++i)
		{
			printf("%d", num[i]);
		}		
		printf("\n");
	} while (next_permutation(num.begin(),num.end()));
}