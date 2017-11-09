#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> arr;

arr.siz
}


bool solution(vector<int> arr)
{
	bool answer = true;
	for (int i = 1; i <= arr.size(); ++i)
	{
		auto it = find(arr.begin(), arr.end(), i);
		if (it == arr.end())
		{
			answer = false;
			return answer;
		}
	}
	return answer;
}



bool solution(vector<int> arr)
{
	map<int, int> map;
	bool answer = true;
	for (int x : arr)
	{
		if (map[x] == 0)
		{
			map[x] = 1;
		}
		else
		{
			answer = false;
			return false;
		}
	}

	for (int i = 1; i <= arr.size(); ++i)
	{
		if (map[i] == 0)
		{
			answer = false;
			return false;
		}
	}
	return answer;
}