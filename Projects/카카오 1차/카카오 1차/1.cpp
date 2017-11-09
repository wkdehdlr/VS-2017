#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int cnt = 0;
	int n = 6;
	int tempNum;
	vector<int> arr1 = { 46, 33, 33, 22, 31, 50 };
	vector<int> arr2 = { 27, 56, 19, 14, 14, 10 };
	vector<string> vec;
	string str;


	tempNum = n;
	vec.resize(n);
	str.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cnt = n - 1;
		int num = arr1[i] | arr2[i];
		
		while (1)
		{
			if (num % 2 == 1)
			{
				str[cnt] = '#';//#
			}
			else
			{
				str[cnt] = ' ';//ฐ๘น้
			}
			cnt--;
			num /= 2;
			tempNum--;
			if (tempNum == 0)
				break;
		}
		vec[i] = str;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << vec[i] << '\n';
	}
}