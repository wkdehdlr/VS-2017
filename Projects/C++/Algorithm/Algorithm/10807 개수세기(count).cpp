#include<iostream>
#include<vector>
#include<algorithm>//-> �̰� ���ϸ� ���ؿ��� �˻��Ҷ� �����Ͽ�������
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