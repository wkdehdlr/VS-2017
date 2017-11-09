#include<iostream>
#include<vector>
using namespace std;

vector<long long> vec(1000001);
long long N, B, C;
long long cnt = 0;
int main()
{
	scanf("%lld", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%lld", &vec[i]);
	}
	scanf("%lld %lld", &B, &C);

	for (int i = 1; i <= N; ++i)
	{
		if (vec[i] <= B)
		{
			cnt++;
		}
		else
		{
			cnt++;
			vec[i] -= B;
			long long tmp = (vec[i] % C) == 0 ? vec[i] / C : vec[i] / C + 1;
			cnt += tmp;
		}
	}
	printf("%lld\n", cnt);
}