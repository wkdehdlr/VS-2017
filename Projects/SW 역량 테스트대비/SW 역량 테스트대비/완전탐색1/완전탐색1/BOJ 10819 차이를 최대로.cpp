#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vec1,vec2;

	int N, temp, x,max=0,sum = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &temp);
		vec1.push_back(temp);
		vec2.push_back(temp);
	}
	temp = 0;

	do {
		sum = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			x = vec1.at(i) - vec1.at(i + 1);
			if (x < 0)
			{
				sum += (-x);
			}
			else
			{
				sum += x;
			}
		}
		if(max < sum)
			max = sum;
	} while (prev_permutation(vec1.begin(), vec1.end()));

	do {
		sum = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			x = vec2.at(i) - vec2.at(i + 1);
			if (x < 0)
			{
				sum += (-x);
			}
			else
			{
				sum += x;
			}
		}
		if (max < sum)
			max = sum;

	} while (next_permutation(vec2.begin(), vec2.end()));

	cout << max << '\n';
}