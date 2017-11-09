#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string str = "1S2D*3T";
	int n = str.length();
	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '1' || str[i] == '2' || str[i] == '3')
		{
			sum += (str[i] - '0');
		}

		if (str[i] == 'S' || str[i] == 'D' || str[i] == 'T')
		{
			if (str[i] == 'S')
			{
				(str[i - 1] - '0')*(str[i - 1] - '0');
			}
			else if (str[i] == 'D')
			{
				(str[i - 1] - '0')*(str[i - 1] - '0');
			}
			else//T
			{
				(str[i - 1] - '0')*(str[i - 1] - '0')*(str[i - 1] - '0');
			}
		}
	}

}