#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case, N, temp;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N;
		cin >> Answer;
		for (int i = 1; i < N; ++i)
		{
			cin >> temp;
			Answer = Answer^temp;
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}