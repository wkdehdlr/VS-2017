#include <iostream>
#include <vector>
using namespace std;

vector<int> num(2);
int maxN = 0;
int minN = 0x7fffffff;
int Answer;
int cnt = 0;
int N, temp;
vector<int> vec;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N;
		num[0] = 0;
		num[1] = 0;
		vec.clear();
		cnt = 0;
		maxN = 0;
		minN = 0x7fffffff;
		for (int i = 0; i<N; ++i)
		{
			cin >> temp;
			if (temp < minN)
				minN = temp;
			if (maxN < temp)
				maxN = temp;
			vec.push_back(temp);
		}

		for (int i = 0; i<N; ++i)
		{
			if (vec[i] == minN)
			{
				num[0]++;
				continue;
			}
			if (vec[i] == maxN)
			{
				num[1]++;
				continue;
			}
		}

		for (int i = 0; i<N; ++i)
		{
			if (vec[i] == maxN)//최대값이면
			{
				cnt++;
				continue;
			}

			if (vec[i] == minN)//최소값이면
			{
				if (num[1] != 1)
				{
					if (vec[i] + N >= maxN + N - 1)
					{
						cnt++;
						continue;
					}
				}
				else
				{
					if (vec[i] + N >= maxN + 1)
					{
						cnt++;
						continue;
					}
				}
			}

			if (vec[i] >= maxN - 1)
			{
				cnt++;
			}
		}


		Answer = cnt;
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}