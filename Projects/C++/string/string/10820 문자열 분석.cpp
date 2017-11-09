#include<iostream>
#include<string>
using namespace std;


int main()
{
	int b, u, d, num;
	string s;
	while (getline(cin, s))
	{
		b = 0; u = 0; d = 0; num = 0;
		for (char x : s)
		{
			if (x == ' ')
				b++;
			else if (x >= 'a' && x <= 'z')
				d++;
			else if (x >= 'A' && x <= 'Z')
				u++;
			else
				num++;
		}
		cout << d << ' ' << u << ' ' << num << ' ' << b << '\n';
	}
}