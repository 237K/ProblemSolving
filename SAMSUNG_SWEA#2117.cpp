//
//	OS Windows
//	2019.03.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2117> (모의)
//	
//	범위가 거리에 비례해서 증가함. 예를 들어 k = 2일 때는 출발점으로부터 거리( abs(end_x - start_x) + abs(end_y - start_y) )가 2인 곳들을 커버함
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> coor;

const static int SIZE = 20;
const static int COVERAGE = SIZE * 2;

static int map[SIZE][SIZE];
static int cover[COVERAGE];
static coor house[SIZE*SIZE];
static int N, M;
static int Result;
static int house_count;

void Simulation()
{
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			(void)memset(&cover[0], 0, sizeof(cover));
			int distance = 0;
			for(int i = 0 ; i <= house_count ; ++i)
			{
				coor cur = house[i];
				distance = abs(cur.first - r) + abs(cur.second - c);
				cover[distance]++;
			}
			int cnt = 0;
			for (int k = 1; k <= COVERAGE; ++k)
			{
				cnt += cover[k];
				int leverage = cnt * M;
				int cost = (k*k) + ((k - 1)*(k - 1));
				if (leverage >= cost)
				{
					Result = max(Result, cnt);
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	freopen("s_input2117.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(&map[0][0], 0, sizeof(map));
		(void)memset(house, 0, sizeof(house));
		Result = 0;	house_count = 0;

		cin >> N >> M;

		int max_coverage = N - 3;
		int cost = (max_coverage * max_coverage) + ((max_coverage - 1) * (max_coverage - 1));

		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				cin >> map[r][c];
				if (map[r][c])
				{
					house[house_count++] = coor(r, c);
				}
			}
		}
		if ((house_count * M) > cost)
			Result = house_count;
		else
			Simulation();

		cout << "#" << test_case << ' ' << Result << '\n';
	}
	return 0;
}