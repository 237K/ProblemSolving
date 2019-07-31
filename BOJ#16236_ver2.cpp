//
//	OS Windows
//	2019.07.31
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #16236	아기 상어
//	ver.2
//

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;

const static int SZ = 21;
const static int DIR = 4;
static int dir[DIR][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
static int map[SZ][SZ];
static int check[SZ][SZ];
static int N;
/////////////////////////////////////////////////////////////////////////////////////////
class SHARK
{
private:
	int rpos;
	int cpos;
	int feed;
public:
	int size;
public:
	SHARK(int r = 0, int c = 0, int s = 1, int f = 0);
	pii get_shark_loc();
	void move(int r, int c);
	void print();
};
SHARK::SHARK(int r, int c, int s, int f) : rpos(r), cpos(c), size(s), feed(f) {}
pii SHARK::get_shark_loc() { return { rpos, cpos }; }
void SHARK::move(int r, int c)
{
	rpos = r; cpos = c;
	if (map[rpos][cpos] && map[rpos][cpos] < size)
	{
		feed++;
		map[rpos][cpos] = 0;
	}
	if (feed == size)
	{
		feed = 0;
		size++;
	}
}
void SHARK::print()
{
	register int r, c;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			if (r == rpos && c == cpos) cout << "* ";
			else cout << map[r][c] << ' ';
		}
		cout << "\n\n";
	}
}
SHARK shark(0, 0, 1, 0);
/////////////////////////////////////////////////////////////////////////////////////////
inline int find_fish()
{
	(void)memset(check, 0, sizeof(check));
	register int dist = 0, d, nr, nc;
	queue<pii> Q;
	pii start_loc = shark.get_shark_loc();
	Q.push(start_loc);
	map[start_loc.first][start_loc.second] = 1;
	while (!Q.empty())
	{
		pii cur = Q.front();
		Q.pop();
		if (map[cur.first][cur.second] && map[cur.first][cur.second] < shark.size)
		{
			shark.move(cur.first, cur.second);
			return dist;
		}
		dist++;
		for (d = 0; d < DIR; ++d)
		{
			nr = cur.first + dir[d][0];
			nc = cur.second + dir[d][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || check[nr][nc] || map[nr][nc] > shark.size) continue;
			check[nr][nc] = 1;
			Q.push({ nr, nc });
		}
	}
	while (!Q.empty()) { Q.pop(); }
	return -1;
}
inline int simul()
{
	register int r, c, ret = 0, tmp;
	while (1)
	{
		shark.print();
		tmp = find_fish();
		if (tmp == -1) break;
		ret += tmp;
	}
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input16236.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c;
	cin >> N;
	for (r = 0; r < N; ++r)
	{
		for (c = 0; c < N; ++c)
		{
			cin >> map[r][c];
			if (map[r][c] == 9)
			{
				map[r][c] = 0;
				shark.move(r, c);
			}
		}
	}
	cout << simul();
	return 0;
}