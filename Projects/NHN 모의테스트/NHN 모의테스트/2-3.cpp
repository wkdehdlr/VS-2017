#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int Tc;
vector<int> vec;

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
		vec.clear();

		for (int i=0;i<str.length();++i)
		{
			char x = str[i];
			if (x == '(')
			{
				vec.push_back(q.size());
				q.push('(');
				continue;
			}
			if (x == ')')
			{
				if (q.size() == 0)
				{
					flag = 1;
					printf("%d\n", i);
					break;
				}
				tmp = q.top();
				if (tmp == '(')
				{
					vec.push_back(q.size() - 1);
					q.pop();
				}
				else
				{
					flag = 1;
					printf("%d\n",i);
					break;
				}
			}
			if (x == '{')
			{
				vec.push_back(q.size());
				q.push('{'); 
				continue;
			}
			if (x == '}')
			{
				if (q.size() == 0)
				{
					flag = 1;
					printf("%d\n", i);
					break;
				}
				tmp = q.top();
				if (tmp == '{')
				{
					vec.push_back(q.size() - 1);
					q.pop();
				}
				else
				{
					flag = 1;
					printf("%d\n", i);
					break;
				}
			}
			if (x == '[')
			{
				vec.push_back(q.size());
				q.push('['); 
				continue;
			}
			if (x == ']')
			{
				if (q.size() == 0)
				{
					flag = 1;
					printf("%d\n", i);
					break;
				}
				tmp = q.top();
				if (tmp == '[')
				{
					vec.push_back(q.size() - 1);
					q.pop();
				}
				else
				{
					flag = 1;
					printf("%d\n", i);
					break;
				}
			}
		}

		if (flag != 1)//flag가 1이면 비어있는게 아니다
		{
			if (q.size() == 0)
			{
				if (vec.size() == 0)
				{
					printf("-1\n");
					continue;
				}
				for (int i = 0; i < vec.size(); ++i)
				{
					if (i == vec.size() - 1)
					{
						printf("%d\n", vec[i]);
					}
					else
					{
						printf("%d ", vec[i]);
					}
				}
			}
			else
			{
				printf("-1\n");
			}
		}
	}
}