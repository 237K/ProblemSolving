//
//	OS Windows
//	2019.04.12
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#7465> (D4) 창용 마을 무리의 개수
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
const static int MAX = 101;

static vector<int> Graph[MAX];
static vector<int> Group[MAX];
static int check[MAX];
static int N, M;
static queue<int> Q;

inline void init()
{
	for (register int i = 0; i < MAX; ++i)
	{
		Graph[i].clear();
		Group[i].clear();
	}
	(void)memset(check, 0, sizeof(check));
}
inline bool is_there_left_person()
{
	for (register int i = 1; i <= N ; ++i)
	{
		if (!check[i])
			return false;
	}
	return true;
}
inline int how_much_group()
{
	int num_of_group = 1;
	while (1)
	{
		for (register int i = 1; i <= N; ++i)
		{
			if (!check[i])
			{
				Q.push(i);
				check[i] = 1;
				Group[num_of_group].push_back(i);
				break;
			}
		}

		while (!Q.empty())
		{
			int cur_person = Q.front();
			Q.pop();
			for (auto iter = Graph[cur_person].begin(); iter != Graph[cur_person].end(); ++iter)
			{
				if (!check[*iter])
				{
					check[*iter] = 1;
					Group[num_of_group].push_back(*iter);
					Q.push(*iter);
				}
			}
		}

		if (is_there_left_person())
			break;
		else
			num_of_group++;
	}
	return num_of_group;
}

int main(int argc, char** argv)
{
	freopen("s_input7465.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> M;
		//	그래프 만들기
		for (register int m = 0; m < M; ++m)
		{
			int left_person, right_person;
			cin >> left_person >> right_person;
			Graph[left_person].push_back(right_person);
			Graph[right_person].push_back(left_person);
		}
		cout << "#" << test_case << ' ' << how_much_group() << '\n';
	}
	return 0;
}