#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
vector<string> vec;
string str, tmp;;
string stru, strd;

void usort(int, int);
void dsort(int, int);
void pluss(int);
int main()
{

	getline(cin, str);
	istringstream str2(str);

	while (getline(str2,str,' '))
	{
		vec.push_back(str);
	}
	int len = vec.size();

	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1; ++j)
		{
			usort(i, j);
		}
	}

	for (int i = 0; i < len; ++i)
	{
		stru.append(vec[i]);
	}

	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1; ++j)
		{
			dsort(i, j);
		}
	}

	for (int i = 0; i < len; ++i)
	{
		strd.append(vec[i]);
	}

	pluss(strd.length());

	cout << stru << '\n';
	cout << strd << '\n';
}
void usort(int i, int j)
{
	int num1 = stoi(vec[j]);
	int num2 = stoi(vec[j + 1]);

	if (vec[j].length() == vec[j + 1].length())//같은자리수
	{
		if (num1 > num2)
		{
			tmp = vec[j];
			vec[j] = vec[j + 1];
			vec[j + 1] = tmp;
		}
	}
	else//자리수가 다른 비교
	{
		if (num1 > num2)//num1이 2자리수 num2가 1자리수
		{
			if (num1 / 10 > num2 % 10)
			{
				tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
			}

			if (num1 / 10 == num2 % 10)
			{
				if (num1 % 10 > num2 % 10)
				{
					tmp = vec[j];
					vec[j] = vec[j + 1];
					vec[j + 1] = tmp;
				}
			}
		}
		else//num1가 1자리수 num2가 2자리수
		{
			if (num1 % 10 > num2 / 10)
			{
				tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
			}

			if (num1 % 10 == num2 / 10)
			{
				if (num1 % 10 > num2 % 10)
				{
					tmp = vec[j];
					vec[j] = vec[j + 1];
					vec[j + 1] = tmp;
				}
			}
		}
	}
	/*		tmp = vec[j];
		vec[j] = vec[j + 1];
		vec[j + 1] = vec[j];
*/
}
void dsort(int i, int j)
{
	int num1 = stoi(vec[j]);
	int num2 = stoi(vec[j + 1]);

	if (vec[j].length() == vec[j + 1].length())//같은자리수
	{
		if (num1 < num2)
		{
			tmp = vec[j];
			vec[j] = vec[j + 1];
			vec[j + 1] = tmp;
		}
	}
	else//자리수가 다른 비교
	{
		if (num1 > num2)//num1이 2자리수 num2가 1자리수
		{
			if (num1 / 10 < num2 % 10)
			{
				tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
			}

			if (num1 / 10 == num2 % 10)
			{
				if (num1 % 10 < num2 % 10)
				{
					tmp = vec[j];
					vec[j] = vec[j + 1];
					vec[j + 1] = tmp;
				}
			}
		}
		else//num1가 1자리수 num2가 2자리수
		{
			if (num1 % 10 < num2 / 10)
			{
				tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;
			}

			if (num1 % 10 == num2 / 10)
			{
				if (num1 % 10 < num2 % 10)
				{
					tmp = vec[j];
					vec[j] = vec[j + 1];
					vec[j + 1] = tmp;
				}
			}
		}
	}
	/*		tmp = vec[j];
	vec[j] = vec[j + 1];
	vec[j + 1] = vec[j];
	*/
}
void pluss(int n)
{
	int flag = 0;
	string tmp;
	tmp.resize(n + 1);

	for (int i = n - 1; i > 0; --i)
	{
		int num1 = stru[i] - '0';
		int num2 = strd[i] - '0';


		tmp[i + 1] = ((num1 + num2) % 10) + '0';
		if ((num1 + num2) >= 10)//10이상이면
		{
			flag = 1;
		}
	}
}