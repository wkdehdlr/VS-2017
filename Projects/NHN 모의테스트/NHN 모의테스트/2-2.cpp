#include<iostream>
#include<stack>
#include<string>
using namespace std;
int Tc;


int main()
{
	char temp;
	freopen("input.txt", "r", stdin);
	scanf("%d", &Tc); scanf("%c", &temp);
	for (int i = 0; i < Tc; ++i)
	{
		int flag = 0;
		string str;
		char tmp;
		stack<char> q;
		getline(cin, str);
		
		for (char x : str)
		{
			if (x == '(')
			{
				q.push('('); continue;
			}
			if (x == ')')
			{
				tmp = q.top();
				if (tmp == '(')
				{
					q.pop();
				}
				else
				{
					flag = 1;
					printf("NO\n");
					break;
				}
			}
			if (x == '{')
			{
				q.push('{'); continue;
			}
			if (x == '}')
			{
				tmp = q.top();
				if (tmp == '{')
				{
					q.pop();
				}
				else
				{
					flag = 1;
					printf("NO\n");
					break;
				}
			}			
			if (x == '[')
			{
				q.push('['); continue;
			}
			if (x == ']')
			{
				tmp = q.top();
				if (tmp == '[')
				{
					q.pop();
				}
				else
				{
					flag = 1;
					printf("NO\n");
					break;
				}
			}
		}

		if (flag != 1)//flag가 1이면 비어있는게 아니다
		{
			if (q.size() == 0)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}		
	}
}