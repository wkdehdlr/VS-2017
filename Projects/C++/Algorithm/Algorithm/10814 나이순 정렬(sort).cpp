#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Member
{
	string name;
	int age;
	int num;
};
bool cmp(const Member &m1, const Member &m2)
{
	if (m1.age < m2.age)
	{
		return true;
	}
	else if (m1.age == m2.age)
	{
		if (m1.num < m2.num)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	string str;
	vector<Member> vec;
	int N, age;

	freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> age >> str;
		vec.push_back({ str,age,i + 1 });
	}

	stable_sort(vec.begin(), vec.end(),cmp);
	//sort(vec.begin(), vec.end(), cmp);

	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		cout << it->age << " " << it->name << '\n';
	}

}