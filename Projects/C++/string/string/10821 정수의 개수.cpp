#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num = 0;
	string s;
	while (getline(cin, s, ','))
	{
		num++;
	}

	cout << num<< '\n';
}