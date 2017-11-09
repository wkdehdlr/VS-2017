/*
3
2 2 2
2 0 2
2 2 2
´ä 16
*/
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

deque<int> new_deq;
deque<int> deq;
int max2 = 0;
int maxN = 0;
int N, M;
void func(int, vector<vector<int> >);

int main()
{
	vector<vector<int> > arr(21, vector<int>(21));

	scanf("%d",&N);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0)
			{
				if (maxN < arr[i][j])
					maxN = arr[i][j];
			}
		}
	}

	int cnt = 0;
	func(cnt,arr);
	printf("%d\n", max2);
}
void func(int cnt, vector<vector<int> > arr)
{
	vector<vector<int> > arr2;
	if (cnt == 5)
	{
		if (max2 < maxN)
			max2 = maxN;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			arr2 = arr;

			/*for (int q = 1; q <= N; q++)
			{
				for (int w = 1; w <= N; ++w)
				{
					printf("%d", arr2[q][w]);
				}
				printf("\n");
			}
			printf("\n");
			*/
			if (i == 0)
			{
				for (int x = 1; x <= N; ++x)
				{
					vector<int> new_vec(21, 0);
					deq.clear();
					new_deq.clear();
					for (int y = 1; y <= N; ++y)
					{
						deq.push_back(arr2[x][y]);
					}
					int keep = -1;
					int tmp;
					while (!deq.empty())
					{
						tmp = deq.front();
						deq.pop_front();
						if (tmp != 0)
						{
							if (keep == -1 && keep != tmp)
							{
								keep = tmp;
								continue;
							}
							if (keep == tmp)
							{
								keep += tmp;
								if (maxN < keep)
									maxN = keep;
								new_deq.push_back(keep);
								keep = -1;
							}
							else
							{
								new_deq.push_back(keep);
								keep = tmp;
							}
						}
					}
					if (keep != -1)
					{
						new_deq.push_back(keep);
					}
					int k = 1;
					while (!new_deq.empty())
					{
						new_vec[k] = new_deq.front();
						new_deq.pop_front();
						k++;
					}
					arr2[x] = new_vec;
				}
				func(cnt + 1, arr2);
			}
			else if (i == 1)
			{
				for (int y = 1; y <= N; ++y)
				{
					vector<int> new_vec(21, 0);
					deq.clear();
					new_deq.clear();
					for (int x = N; x >= 1; --x)
					{
						deq.push_back(arr2[x][y]);
					}
					int keep = -1;
					int tmp;
					while (!deq.empty())
					{
						tmp = deq.front();
						deq.pop_front();
						if (tmp != 0)
						{
							if (keep == -1 && keep != tmp)
							{
								keep = tmp;
								continue;
							}
							if (keep == tmp)
							{
								keep += tmp;
								if (maxN < keep)
									maxN = keep;
								new_deq.push_back(keep);
								keep = -1;
							}
							else
							{
								new_deq.push_back(keep);
								keep = tmp;
							}
						}
					}
					if (keep != -1)
					{
						new_deq.push_back(keep);
					}

					int k = N;
					while (!new_deq.empty())
					{
						new_vec[k] = new_deq.front();
						new_deq.pop_front();
						k--;
					}
					for (int p = 1; p <= N; ++p)
					{
						arr2[p][y] = new_vec[p];
					}
					//arr2[x] = new_vec;
				}
				func(cnt + 1, arr2);
			}
			else if (i == 2)
			{
				for (int x = 1; x <= N; ++x)
				{
					vector<int> new_vec(21, 0);
					deq.clear();
					new_deq.clear();
					for (int y = N; y >= 1; --y)
					{
						deq.push_front(arr2[x][y]);
					}
					int keep = -1;
					int tmp;
					while (!deq.empty())
					{
						tmp = deq.back();
						deq.pop_back();
						if (tmp != 0)
						{
							if (keep == -1 && keep != tmp)
							{
								keep = tmp;
								continue;
							}
							if (keep == tmp)
							{
								keep += tmp;
								if (maxN < keep)
									maxN = keep;
								new_deq.push_front(keep);
								keep = -1;
							}
							else
							{
								new_deq.push_front(keep);
								keep = tmp;
							}
						}
					}
					if (keep != -1)
					{
						new_deq.push_front(keep);
					}
					int k = N;
					while (!new_deq.empty())
					{
						new_vec[k] = new_deq.back();
						new_deq.pop_back();
						k--;
					}
					arr2[x] = new_vec;
				}
				func(cnt + 1, arr2);
			}
			else
			{
				for (int y = 1; y <= N; ++y)
				{
					vector<int> new_vec(21, 0);
					deq.clear();
					new_deq.clear();
					for (int x = 1; x <=N ; ++x)
					{
						deq.push_back(arr2[x][y]);
					}
					int keep = -1;
					int tmp;
					while (!deq.empty())
					{
						tmp = deq.front();
						deq.pop_front();
						if (tmp != 0)
						{
							if (keep == -1 && keep != tmp)
							{
								keep = tmp;
								continue;
							}
							if (keep == tmp)
							{
								keep += tmp;
								if (maxN < keep)
									maxN = keep;
								new_deq.push_back(keep);
								keep = -1;
							}
							else
							{
								new_deq.push_back(keep);
								keep = tmp;
							}
						}
					}
					if (keep != -1)
					{
						new_deq.push_back(keep);
					}

					int k = 1;
					while (!new_deq.empty())
					{
						new_vec[k] = new_deq.front();
						new_deq.pop_front();
						k++;
					}
					for (int p = 1; p <= N; ++p)
					{
						arr2[p][y] = new_vec[p];
					}
				}
				func(cnt + 1, arr2);
			}
		}
	}
}