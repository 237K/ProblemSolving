//
//	OS Windows
//	2019.03.30
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14889	스타트와 링크
//	ver2. 시간초과
//	ver3.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

const static int MAX = 21;
const static int INF = 2147000000;

static int N;
static int table[MAX][MAX] = { 0, };
static int Result = INF;

inline int Score(const vector<int>& team)
{
	int score = 0;
	for (int i = 0; i < N / 2; ++i)
	{
		for (int j = i + 1; j < N / 2; ++j)
		{
			score += table[team[i]][team[j]] + table[team[j]][team[i]];
		}
	}
	return score;
}

inline void Pick(int member, vector<int> team_start, vector<int> team_link)
{
	if (member == N)
	{
		int score_start = Score(team_start);
		int score_link = Score(team_link);
		int diff = abs(score_start - score_link);
		Result = min(Result, diff);
		return;
	}

	if (team_start.size() == N / 2)
	{
		team_link.push_back(member);
		Pick(member + 1, team_start, team_link);
	}
	else if (team_link.size() == N / 2)
	{
		team_start.push_back(member);
		Pick(member + 1, team_start, team_link);
	}
	else
	{
		team_start.push_back(member);
		Pick(member + 1, team_start, team_link);
		team_start.pop_back();

		team_link.push_back(member);
		Pick(member + 1, team_start, team_link);
		team_link.pop_back();
	}
}

int main(int argc, char** argv)
{
	freopen("s_input#14889.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			cin >> table[r][c];
		}
	}
	vector<int> t_start, t_link;
	Pick(0, t_start, t_link);
	cout << Result;
	return 0;
}