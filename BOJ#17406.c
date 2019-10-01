//
//	OS Windows
//	2019.10.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17406 배열 돌리기4
//

#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
const static int SZ = 51;
const static int MAX = 6;
static int map[SZ][SZ];
static ppi magic[MAX];
static int N, M, K;

inline void print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		cout << "  ";
		for (c = 0; c < N; ++c)
		{
			cout << map[r][c] << "  ";
		}
		cout << "\n\n";
	}
}
inline void maigc(int r, int c, int range)
{
	register int rr, rc, tmp1, tmp2, tmp3;

	tmp1 = map[r - range][c + range];
	for (rc = c + range; rc > c - range; --rc) map[r - range][rc] = map[r - range][rc - 1];

	tmp2 = map[r + range][c + range];
	for (rr = r + range; rr > r - range + 1; --rr) map[rr][c + range] = map[rr - 1][c + range];
	map[r - range + 1][c + range] = tmp1;

	tmp3 = map[r + range][c - range];
	for (rc = c - range; rc < c + range - 1; ++rc) map[r + range][rc] = map[r + range][rc + 1];
	map[r + range][c + range - 1] = tmp2;

	for (rr = r - range; rr < r + range - 1; ++rr) map[rr][c - range] = map[rr + 1][c - range];
	map[r + range - 1][c - range] = tmp3;
}
inline void simul(int r, int c, int range)
{
	register int i;
	for (i = 1; i <= range; ++i) maigc(r, c, i);
	print();
}
int main(int argc, char** argv)
{
	freopen("20190810Q2.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int magic_r, magic_c, magic_range;
	register int r, c;
	cin >> N;
	for (r = 0; r < N; ++r)
		for (c = 0; c < N; ++c)
			cin >> map[r][c];
	cin >> magic_r >> magic_c >> magic_range;
	simul(magic_r, magic_c, magic_range);
	return 0;
}