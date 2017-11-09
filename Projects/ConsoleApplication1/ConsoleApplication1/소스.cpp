#include<iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <conio.h>
using namespace std;

int arr[25];


int main()
{
	map<int, int> map;
	srand((unsigned int)time(NULL));

	int cnt = 0;
	char team = 'A';

	printf("%c : ", team);
	while(1)
	{
		int temp = rand() % 19 + 1;
		if (map.count(temp) == 0)
		{
			//getch();
			map[temp] = 1;
			printf("%d//", temp);
			cnt++;
			if (cnt == 6)
			{
				printf("\n%c : ",++team);
				cnt = 0;
			}
		}
	}

}