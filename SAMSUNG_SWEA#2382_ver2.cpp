//
//	OS Windows
//	2019.05.09
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2382> (모의) 미생물 격리
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
typedef pair<int, int> coor;
const static int SIZE = 100;
const static int MAX_MICROORGA = 1000;
const static int DIRECT = 5;

struct MICROORGA
{
	int r, c, k, d;
};

static int dir[DIRECT][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
static MICROORGA mo[MAX_MICROORGA];
static vector<int> crush[SIZE][SIZE];
static vector<coor> crush_loc;
static int N, M, K;

inline void print()
{
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			cout << crush[r][c].size() << ' ';
		}
		cout << "\n\n";
	}
	cout << "\n\n";
}
inline void crush_init()
{
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < N; ++c)
		{
			crush[r][c].clear();
		}
	}
	crush_loc.clear();
}
inline int change_direct(int cur_dir)
{
	int next_dir = 0;
	if (cur_dir == 1 || cur_dir == 3) next_dir = cur_dir + 1;
	else next_dir = cur_dir - 1;
	return next_dir;
}
inline int cal_ret()
{
	int sum = 0;
	for (register int i = 0; i < K; ++i)
		sum += mo[i].k;
	return sum;
}
inline int simulation()
{
	while (M--)
	{
		/*cout << "time : " << M << '\n';
		print();*/
		
		for (register int i = 0; i < K; ++i)
		{
			if (mo[i].k > 0)
			{
				int cr = mo[i].r;
				int cc = mo[i].c;
				int cd = mo[i].d;
				int nr = cr + dir[cd][0];
				int nc = cc + dir[cd][1];

				mo[i].r = nr;
				mo[i].c = nc;

				if (nr == 0 || nc == 0 || nr == N - 1 || nc == N - 1)
				{
					mo[i].d = change_direct(cd);
					mo[i].k /= 2;
					continue;
				}

				crush[nr][nc].push_back(i);
				if (crush[nr][nc].size() > 1)
					crush_loc.push_back({ nr, nc });
			}
		}
		if (crush_loc.size())
		{
			int first_order_mo = 0, idx = 0;
			int num_crush = crush_loc.size();
			for (register int j = 0; j < num_crush; ++j)
			{
				int ccr = crush_loc[j].first;
				int ccc = crush_loc[j].second;

				//	제일 큰 미생물 군집을 찾고
				int temp = 0;
				for (vector<int>::size_type s = 0; s < crush[ccr][ccc].size(); ++s)
				{
					int cur_mo_idx = crush[ccr][ccc][s];
					temp += mo[cur_mo_idx].k;
					if (first_order_mo < mo[cur_mo_idx].k)
					{
						first_order_mo = mo[cur_mo_idx].k;
						idx = cur_mo_idx;
					}
				}
				//	제일 큰 미생물 군집으로 합침
				for (vector<int>::size_type s = 0; s < crush[ccr][ccc].size(); ++s)
				{
					int cur_mo_idx = crush[ccr][ccc][s];
					if (idx != cur_mo_idx)
						mo[cur_mo_idx].k = 0;
				}
				mo[idx].k = temp;
			}
		}
		crush_init();
	}
	return cal_ret();
}
int main(int argc, char** argv)
{
	freopen("s_input2382.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int test_case, i;
	int _r, _c, _k, _d;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K;
		for (i = 0; i < K; ++i)
		{
			cin >> _r >> _c >> _k >> _d;
			mo[i] = { _r, _c, _k, _d };
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}