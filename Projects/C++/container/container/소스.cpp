#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v4 = { 1, 2, 3, 4, 5 };
	for (int &x : v4)
	{
		cout << x << ' ';
	}
}