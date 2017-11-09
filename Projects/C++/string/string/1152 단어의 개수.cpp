#include<iostream>
#include<string>
using namespace std;


int main()
{
	int cnt = 0;
	string s;

	getline(cin, s);
	if (s.empty())
	{
		cout << cnt << '\n';
		return 0;
	}

	for (char x : s)
	{
		if (x == ' ')
			cnt++;
	}

	if (s.at(s.length() - 1) == ' ')
	{
		cnt--;
	}
	if (s.at(0) == ' ')
	{
		cnt--;
	}

	cout << cnt + 1 << '\n';

	return 0;
}