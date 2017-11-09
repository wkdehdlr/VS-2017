#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	long long cnt = 0;
	string temp;
	string s;
	map<string, long long> m1 = { {"black",1},{"brown",10},{"red",100}
	,{"orange",1000},{"yellow",10000},{"green",100000},{"blue",1000000},{"violet",10000000}
	,{"grey",100000000},{"white",1000000000} };

	freopen("input.txt", "r", stdin);
	


	while (cnt < 2)
	{
		cin >> s;
		if (s.find("black") != string::npos)
		{
			temp += '0';
		}
		else if (s.find("brown") != string::npos)
		{
			temp += '1';
		}
		else if (s.find("red") != string::npos)
		{
			temp += '2';
		}
		else if (s.find("orange") != string::npos)
		{
			temp += '3';
		}
		else if (s.find("yellow") != string::npos)
		{
			temp += '4';
		}
		else if (s.find("green") != string::npos)
		{
			temp += '5';
		}
		else if (s.find("blue") != string::npos)
		{
			temp += '6';
		}
		else if (s.find("violet") != string::npos)
		{
			temp += '7';
		}
		else if (s.find("grey") != string::npos)
		{
			temp += '8';
		}
		else if (s.find("white") != string::npos)
		{
			temp += '9';
		}
		cnt++;
	}

	cnt = 0;
	cin >> s;
	if (s.find("black") != string::npos)
	{
		cnt = stoi(temp) * m1["black"];
	}
	else if (s.find("brown") != string::npos)
	{
		cnt = stoi(temp) * m1["brown"];
	}
	else if (s.find("red") != string::npos)
	{
		cnt = stoi(temp) * m1["red"];
	}
	else if (s.find("orange") != string::npos)
	{
		cnt = stoi(temp) * m1["orange"];
	}
	else if (s.find("yellow") != string::npos)
	{
		cnt = stoi(temp) * m1["yellow"];
	}
	else if (s.find("green") != string::npos)
	{
		cnt = stoi(temp) * m1["green"];
	}
	else if (s.find("blue") != string::npos)
	{
		cnt = stoi(temp) * m1["blue"];
	}
	else if (s.find("violet") != string::npos)
	{
		cnt = stoi(temp) * m1["violet"];
	}
	else if (s.find("grey") != string::npos)
	{
		cnt = stoi(temp) * m1["grey"];
	}
	else if (s.find("white") != string::npos)
	{
		cnt = stoi(temp) * m1["white"];
	}

	cout << cnt << '\n';
}