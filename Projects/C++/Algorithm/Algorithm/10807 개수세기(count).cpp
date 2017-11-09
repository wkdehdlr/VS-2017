#include<iostream>
#include<vector>
#include<algorithm>//-> 이거 안하면 백준에서 검사할때 컴파일에러난다
using namespace std;

int main()
{
	vector<int> vec;
	int num,temp;

	freopen("input.txt", "r", stdin);

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	cin >> temp;
	cout << count(vec.begin(), vec.end(), temp) << '\n';
}