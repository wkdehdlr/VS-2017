#include<iostream>
#include<string>
using namespace std;


int main()
{
	int sum = 0;
	string s;
	while (getline(cin, s, ','))
	{
		sum += stoi(s);
	}

	cout << sum << '\n';

}