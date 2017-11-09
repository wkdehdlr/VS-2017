#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;

	v1.push_back(0);
	v1.push_back(1);
	v1.pop_back();

	v1.clear();
	v1.resize(5);
	v1.front();
	v1.back();

	v1.size();

	for (int &x : v1)
	{
		cout << x << '\n';
	}

	for (auto it = v1.begin(); it != v1.end(); it++);

	auto it = v1.begin();

}