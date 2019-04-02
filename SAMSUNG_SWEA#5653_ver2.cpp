//
//	OS Windows
//	2019.04.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5653] <줄기세포배양> (모의 SW 역량테스트)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

const static int MAP_SIZE = 310;
const static int DIRECT = 4;

static int N, M, K;
static int map[MAP_SIZE * 2 + 51][MAP_SIZE * 2 + 51];
static int dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

struct cell									//세포의 좌표와 생명력을 가지고 있는 구조체
{
	int x, y, life;
	bool operator<(const cell& c) const		//우선순위큐에서 우선순위 비교를 위한 연산자 오버로딩
	{
		return life < c.life;
	}
};
static priority_queue<cell> PQ;
static queue<cell> Q;

inline int tiktok()							
{
	int sleep = 0;							//비활성화된 세포수
	int wakeup = 0;							//활성화된 세포수

	while (!PQ.empty())
	{
		Q.push(PQ.top());
		PQ.pop();
	}
	while (K--)								//1시간 동안
	{
		int tik = Q.size();					//현재 Q에 담긴 세포들이 활동함
		while (tik--)
		{
			cell cur_cell = Q.front();
			Q.pop();

			if (cur_cell.life-- == 0)		//세포가 활성화될 때가 되면
			{
				if (map[cur_cell.x][cur_cell.y] - 1 > K)	//시간이 다 지날때까지 활성화가 안될 세포++
					sleep++;
				for (register int d = 0; d < DIRECT; ++d)	//4방향으로 살펴보고
				{
					int x = cur_cell.x + dir[d][0];
					int y = cur_cell.y + dir[d][1];

					if (map[x][y])
						continue;
					else if (!map[x][y])					//비어있으면
					{
						map[x][y] = map[cur_cell.x][cur_cell.y];	//번식
						Q.push({ x, y, map[x][y] });
					}
				}
			}
			else
				Q.push({ cur_cell.x, cur_cell.y, cur_cell.life });
		}
	}
	wakeup = Q.size();
	return sleep + wakeup;
}

int main(int argc, char** argv)
{
	freopen("s_input5653.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(map, 0, sizeof(map));
		while (!PQ.empty()) { PQ.pop(); }
		while (!Q.empty()) { Q.pop(); }
		cin >> N >> M >> K;
		for (register int r = MAP_SIZE; r < MAP_SIZE + N; ++r)
		{
			for (register int c = MAP_SIZE; c < MAP_SIZE + M; ++c)
			{
				cin >> map[r][c];
				if (map[r][c])
					PQ.push({ r, c, map[r][c] });
			}
		}
		cout << "#" << test_case << ' ' << tiktok() << '\n';
	}
	return 0;
}