//
//	OS Windows
//	2019.05.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14889	스타트와 링크
//	
//	bitmask 사용
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const static int SIZE = 20;
static int map[SIZE][SIZE];
static int N;

inline int getscore(vector<int> v)
{
	int sum = 0;
	for (vector<int>::iterator iter1 = v.begin(); iter1 != v.end(); ++iter1)
	{
		for (vector<int>::iterator iter2 = v.begin(); iter2 != v.end(); ++iter2)
		{
			if (iter1 == iter2)	continue;
			sum += map[*iter1][*iter2];
		}
	}
	return sum;
}

inline int bitmask()
{
	int result = 2147000000;
	//	스타트팀 mask = 1, 링크팀 mask = 0
	for (register int mask = 0; mask < (1 << N); ++mask)
	{
		int score_start = 0, score_link = 0;
		vector<int> team_start, team_link;
		int cnt = 0;
		for (register int i = 0; i < N; ++i)
		{
			if ((mask & (1 << i)))	cnt++;
		}
		if (cnt != N / 2)	continue;

		for (register int j = 0; j < N; ++j)
		{
			if ((mask & (1 << j)))	team_start.push_back(j);
			else team_link.push_back(j);
		}
		score_start = getscore(team_start);
		score_link = getscore(team_link);
		int diff = score_start - score_link;
		if (diff < 0) diff *= -1;
		if (result > diff) result = diff;
	}
	return result;
}
int main(int argc, char** argv)
{
	freopen("s_input#14889.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			cin >> map[r][c];
		}
	}
	cout << bitmask();
	return 0;
}