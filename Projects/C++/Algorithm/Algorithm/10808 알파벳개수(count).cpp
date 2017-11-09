#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	char c;

	freopen("input.txt", "r", stdin);
	cin >> str;

	for (int i = 0; i < 26; i++)//26
	{
		cout << count(str.begin(), str.end(), i+'a') << ' ';
	}
}