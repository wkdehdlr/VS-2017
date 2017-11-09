#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	stack<int> s1;
	string s;
	int N,temp;
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s.find("push") != string::npos)
		{
			cin >> temp; s1.push(temp);
		}
		else if (s.find("pop") != string::npos)
		{
			if (s1.empty())//�������
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << s1.top() << '\n'; s1.pop();
			}
		}
		else if (s.find("size") != string::npos)
		{
			cout << s1.size() << '\n';
		}
		else if (s.find("empty") != string::npos)
		{
			if (s1.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (s.find("top") != string::npos)
		{
			if (s1.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << s1.top() << '\n';
			}
		}
	}
}