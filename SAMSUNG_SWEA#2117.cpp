//
//	OS Windows
//	2019.03.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2117> (¸ðÀÇ)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const static int SIZE = 20;
const static int DIRECT1 = 4;
const static int DIRECT2 = 4;

static int map[SIZE][SIZE];
static bool check[SIZE][SIZE];
static int N, M;
static int Result;

void Simulation()
{
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			for (int k = 1; k < N; ++k)
			{
				int operating_cost = (k * k) + ((k - 1) * (k - 1));
				int house_cnt = 0;
				int leverage = 0;
				for (int rc = r - (k - 1); rc <= r + (k - 1); ++rc)
				{
					for (int cc = c - ((k - 1) - abs(rc)) ; cc <= c + ((k - 1) - abs(rc)) ; ++cc)
					{
						//cout << "(" << rc << ", " << cc << ")";
						if (rc < 0 || cc < 0 || rc >= N || cc >= N)
							continue;
						else
						{
							if (map[rc][cc] == 1)
								house_cnt++;
							//cout << "count : " << house_cnt << endl << endl;
						}
					}
				}
				leverage = house_cnt * M;

				if (leverage >= operating_cost)
					Result = max(Result, house_cnt);
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
		(void)memset(&check[0][0], 0, sizeof(check));
		Result = 0;

		cin >> N >> M;

		int count = 0;
		int cost = 0;
		int max_size = N - 1;

		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				cin >> map[r][c];
				if (map[r][c])
					count++;
			}
		}

		if ((count * M) > ((max_size * max_size) + ((max_size - 1) * (max_size - 1))))
			Result = count;
		else
			Simulation();

		cout << "#" << test_case << ' ' << Result << '\n';
	}
	return 0;
}