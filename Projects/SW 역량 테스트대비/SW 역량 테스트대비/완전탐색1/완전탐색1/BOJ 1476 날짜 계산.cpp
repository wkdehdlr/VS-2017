#include<iostream>
using namespace std;

int cnt = 2;
int E, S, M;

int main()
{
	scanf("%d %d %d", &E, &S, &M);
	int E1 = 1, S1 = 1, M1 = 1; 
	int E2, S2, M2;

	if (E == 1 && S == 1 && M == 1)
	{
		printf("1\n");
		return 0;
	}
	E2 = S2 = M2 = cnt;
	while (1)
	{
		if (cnt % 15 == 1)
		{
			E2 = 1;
		}
		if (cnt % 28 == 1)
		{
			S2 = 1;
		}
		if (cnt % 19 == 1)
		{
			M2 = 1;
		}

		if (E2 == E && S2 == S && M2 == M)
		{
			break;
		}
		cnt++;
		E2++; S2++; M2++;
	}
	printf("%d\n", cnt);
}