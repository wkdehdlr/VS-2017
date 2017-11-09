#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Student
{
	string name;
	int ko;
	int en;
	int ma;
};
bool cmp(const Student &u, const Student &v)
{
	if (u.ko > v.ko)
	{
		return true;
	}
	else if (u.ko == v.ko)
	{
		if (u.en < v.en)
		{
			return true;
		}
		else if (u.en == v.en)
		{
			if (u.ma > v.ma)
			{
				return true;
			}
			else if (u.ma == v.ma)
			{
				return u.name < v.name;
			}
		}
	}
	return false;
}
int main()
{
	string str;
	int N,ko,en,ma;
	vector<Student> vec;

	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str >> ko >> en >> ma;
		vec.push_back({ str,ko,en,ma });
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].name << '\n';
	}
}