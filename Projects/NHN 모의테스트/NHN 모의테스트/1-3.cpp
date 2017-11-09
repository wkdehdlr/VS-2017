#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

vector<string> vec;
string str;
int num1 = 0, num2 = 0;

void func(int);
int main()
{
	string temp;
	getline(cin, str);
	istringstream str2(str);
	while (getline(str2, temp, ' '))
	{
		vec.push_back(temp);
	}

	int len = vec.size();

	for (int i = 0; i < len; ++i)
	{
		func(i);
	}

	printf("%d\n%d\n", num1, num2);
}
void func(int i)
{
	int len = vec[i].length();

	for (int k = 0; k < len - 1; ++k)
	{
		if (vec[i][k] == 'a' || vec[i][k] == 'e' || vec[i][k] == 'i' || vec[i][k] == 'o' || vec[i][k] == 'u')
		{
			if (vec[i][k + 1] == 'a' || vec[i][k + 1] == 'e' || vec[i][k + 1] == 'i' || vec[i][k + 1] == 'o' || vec[i][k + 1] == 'u')
			{
				num1++;
				break;
			}
		}
	}

	for (int k = 0; k < len - 2; ++k)
	{
		if (!(vec[i][k] == 'a' || vec[i][k] == 'e' || vec[i][k] == 'i' || vec[i][k] == 'o' || vec[i][k] == 'u'))
		{
			if (!(vec[i][k+1] == 'a' || vec[i][k+1] == 'e' || vec[i][k+1] == 'i' || vec[i][k+1] == 'o' || vec[i][k+1] == 'u'))
			{
				if (!(vec[i][k+2] == 'a' || vec[i][k+2] == 'e' || vec[i][k+2] == 'i' || vec[i][k+2] == 'o' || vec[i][k+2] == 'u'))
				{
					num2++;
					break;
				}
			}
		}
	}
}