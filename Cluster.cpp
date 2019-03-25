//
//	OS Windows
//	2019.03.25
//
//	[Algorithm Problem Solving]
//
//	<논 그룹묶기>
//
//	1. 논 : 1, 밭 : 0 으로 입력받음
//	2. 인접한 논끼리 그룹으로 묶음
//	3. 논 그룹의 개수와 각 그룹 논의 개수를 출력
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> coor;

const static int MAX = 10;
const static int DIRECT = 4;

static int map[MAX][MAX];
static bool check[MAX][MAX];
static int N;
static queue<coor> Q;
static int num_cluster;
static int num_paddyfield;
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void Search()
{
	while (!Q.empty())
	{
		coor cur = Q.front();
		Q.pop();

	}
}

void Cluster()
{
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (map[r][c] == 1 && check[r][c] == false)
			{
				Q.push(coor(r, c));
				check[r][c] = true;
				num_cluster++;
				Search();
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("testcase_Cluster.txt", "r", stdin);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		(void)memset(map, 0, sizeof(map));
		(void)memset(check, false, sizeof(check));
		num_cluster = 0;
		num_paddyfield = 0;
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				cin >> map[r][c];
			}
		}
	}
	return 0;
}