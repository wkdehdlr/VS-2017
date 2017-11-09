#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{

	string str;

	freopen("input.txt", "r", stdin);
	cin >> str;

	for (int i = 0; i < 26; i++)
	{
		auto it = find(str.begin(), str.end(), i + 'a');

		//cout << i << " ";
		if (it == str.end())
		{
			cout << -1 << " ";
		}
		else
		{
			cout << (it - str.begin()) << " ";
		}
	}


}