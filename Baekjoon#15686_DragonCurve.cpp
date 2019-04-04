//
//	OS Windows
//	2019.04.03
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #15685	드래곤커브
//
//	K-1세대 커브 개수만큼 *시계방향으로 회전하므로 방향을 기준으로 나열해보면,
//	
//	1세대	｜ 2세대		｜ 3세대			｜ 4세대
//	0 1		｜ 2 1		｜ 2 3 2 1		｜
//	1 2		｜ 3 2		｜ 3 0 3 2		｜
//	2 3		｜ 0 3		｜ 0 1 0 3		｜ 2 3 0 3 2 3 2 1	...
//
//	K-1세대 방향을 역순으로 +1한 후 %4 하면 K세대 방향이 됨
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

const static int MAP_SIZE = 101;
const static int DIRECT = 4;
const static int CYCLE = 4;

static int dir[DIRECT][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
static int check_square[DIRECT][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };


int main(int argc, char** argv)
{
	freopen("s_input15685.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int map[MAP_SIZE][MAP_SIZE];
	vector<int> dragon_curve;
	(void)memset(map, 0, sizeof(map));
	cin >> N;
	for (register int n = 0; n < N; ++n)
	{
		int x, y, direct, generation;
		dragon_curve.clear();
		cin >> x >> y >> direct >> generation;
		map[y][x] = 1;
		dragon_curve.push_back(direct);
		for (register int g = 0; g < generation; ++g)
		{
			int size = dragon_curve.size();
			for (register int dc = size - 1; dc >= 0; --dc)
				dragon_curve.push_back((dragon_curve[dc] + 1) % 4);
		}
		int ny = y;
		int nx = x;
		for (vector<int>::iterator iter = dragon_curve.begin(); iter != dragon_curve.end(); ++iter)
		{
			//cout << *iter << ' ';
			ny += dir[*iter][0];
			nx += dir[*iter][1];
			map[ny][nx] = 1;
			//cout << "(" << ny << ", " << nx << ")" << endl;
		}
		//cout << endl;
	}
	/*
	for (register int r = 0; r < MAP_SIZE - 1; ++r)
	{
		for (register int c = 0; c < MAP_SIZE - 1; ++c)
		{
			cout << map[r][c] << ' ';
		}
		cout << endl << endl;
	}
	*/
	int result = 0;
	for (register int r = 0; r < MAP_SIZE-1; ++r)
	{
		for (register int c = 0; c < MAP_SIZE-1; ++c)
		{
			bool flag = true;
			for (register int cs = 0; cs < DIRECT; ++cs)
			{
				int cur_y = r + check_square[cs][0];
				int cur_x = c + check_square[cs][1];
				if (!map[cur_y][cur_x])
				{
					flag = false;
					continue;
				}
			}
			if (flag)
				result++;
		}
	}
	cout << result;
	return 0;
}