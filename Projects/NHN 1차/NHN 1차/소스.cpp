#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
	//
	//�ܾ�1_�ܾ�2_�ܾ�3
	//�̷������� �Է¹�����
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
	//�̷������� �����Է¹�������
	//�׳� scanf()�� ���������� ����

	//�ҹ��ں�ȯ
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