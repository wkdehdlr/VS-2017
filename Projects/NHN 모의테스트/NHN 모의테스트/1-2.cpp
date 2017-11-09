#include<iostream>
#include<string>
using namespace std;

int num1, num2, cnt = 0;
string str;

void func();
int main()
{
	
	cin >> str;
	//scanf("%s", &str);
	func();

}
void func()
{
	int num1 = stoi(str);
	int len = str.length();

	for (int i = 0; i < (len / 2); ++i)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}

	int num2 = stoi(str);
	int flag = 0;
	string str3 = to_string(num2 + num1);

	if (num2 + num1 >= 10000)
	{
		printf("-1\n"); return;
	}

	int len2 = str3.length();
	//팰린드롭검사
	for (int i = 0; i < (len2 / 2); ++i)
	{
		if (str3[i] != str3[len2 - i - 1])
		{
			str = str3;
			flag = 1;
			break;
		}
	}

	if (flag == 1)//팰린드롭이 아니면
	{
		cnt++;
		if (cnt == 3)
		{
			printf("-1\n");
			return;
		}
		func();
	}
	else
	{
		printf("%d\n", num2 + num1);
	}
}