#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	vector<int> vec;
	int temp1,temp2,temp3,ma;

	freopen("input.txt", "r", stdin);
	cin >> temp1; vec.push_back(temp1);
	cin >> temp2; vec.push_back(temp2);
	cin >> temp3; vec.push_back(temp3);

	while (1)
	{
		ma = max({ temp1, temp2, temp3 });
		if (ma == temp1)
		{
			ma = max(temp2, temp3);
			break;
		}
		else if (ma == temp2)
		{
			ma = max(temp1, temp3);
			break;
		}
		else if (ma == temp3)
		{
			ma = max(temp2, temp1);
			break;
		}
	}
	cout << ma << '\n';
}