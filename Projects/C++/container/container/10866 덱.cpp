#include<iostream>
#include<deque>
#include<string>
#include<sstream>
using namespace std;


int main()
{

	deque<int> d1;
	string s;
	int num,temp;

	freopen("input.txt", "r", stdin);

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> s;

		if (s.find("back") != string::npos)
		{ 
			if (s.find("push_back") != string::npos)
			{
				cin >> temp;
				d1.push_back(temp);
			}
			else if (s.find("pop_back") != string::npos)
			{
				if (d1.empty() == 0)
				{
					cout << d1.back() << '\n';
					d1.pop_back();
				}
				else
				{
					cout << -1 << '\n';
				}
			}
			else
			{
				if (d1.empty() == 0)
				{
					cout << d1.back() << '\n';
				}
				else
				{
					cout << -1 << '\n';
				}
			}
		}
		else if (s.find("front") != string::npos)
		{ 
			if (s.find("push_front") != string::npos)
			{
				cin >> temp;
				d1.push_front(temp);
			}
			else if (s.find("pop_front") != string::npos)
			{
				if (d1.empty() == 0)
				{
					cout << d1.front() << '\n';
					d1.pop_front();
				}
				else
				{
					cout << -1<<'\n';
				}
			}
			else
			{
				if (d1.empty() == 0)
				{
					cout << d1.front() << '\n';
				}
				else
				{
					cout << -1 << '\n';
				}
			}
		}

		else if (s.find("size") != string::npos)
		{ 
			cout << d1.size() << '\n';
		}
		else if (s.find("empty") != string::npos)
		{ 
			if (d1.empty() == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << 1 << '\n';
			}
		}	
	}



}