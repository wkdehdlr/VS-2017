#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main()
{
	int N;
	string temp;

	freopen("input.txt", "r", stdin);
	cin >> N;

	vector<string> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), [](string u, string v)
	{
		if (u.size() < v.size())
		{
			return true;
		}
		else if (u.size() == v.size())
		{
			return u < v;
		}
		else
		{
			return false;
		}
	}
	);

	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (auto it = vec.begin() + 1; it != vec.end(); ++it)
	{
		cout << (*it) << '\n';
	}
}