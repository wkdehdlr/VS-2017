#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	//
	//단어1_단어2_단어3
	//이런식으로 입력받을때
	vector<string> vec;
	string str,temp;


	getline(cin, str);
	istringstream str2(str);

	while (getline(str2, temp, ' '))
	{
		vec.push_back(temp);
	}
	

	//1
	//1_2_3_4 
	//이런식으로 숫자입력받을때는
	//그냥 scanf()로 순차적으로 읽음

	//소문자변환
	void makeLowerChar(char&);

	for (int i = 0; i < str.length(); ++i)
	{
		for_each(str.begin(), str.end(), makeLowerChar);
	}

	void makeLowerChar(char& c)
	{
		c = tolower(c);
	}


}