#include<iostream>
using namespace std;


int main()
{
	int num;

	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cout << i << '\n'; // endl은 버퍼를 사용하기때문에 오래걸림 그냥 \n을 바로 출력하는게 100배 빠름
	}
}