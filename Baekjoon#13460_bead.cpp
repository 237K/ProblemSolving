//
//	OS Windows
//	2019.04.10
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #13460	구슬 탈출2
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

typedef pair<int, int> coor;
typedef pair<coor, int> flags;

const static int SIZE = 10;
const static int DIRECT = 4;
const static int INF = 11;

//	동 : 0, 남 : 1, 서 : 2, 북 : 3
static int dir[DIRECT][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static char map[SIZE][SIZE][SIZE];
static int N, M;
static coor hole;
static int result;
static int answer;
static bool flag_program_end;
static bool red_terminate;
static bool blue_terminate;

inline void print_vector(vector<int> v)
{
	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ' ';
	cout << '\n';
}
inline void print_map(int cnt)
{
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < M; ++c)
		{
			cout << map[cnt][r][c] << ' ';
		}
		cout << "\n\n";
	}
}
inline flags move_bead(int cnt, vector<int> v)
{
	//이전 회차에서 변경된 구슬들의 위치를 복사해옴
	if (cnt)
	{
		for (register int r = 0; r < N; ++r)
		{
			//for (register int c = 0; c < M; ++c)
			//{
				(void)memcpy(&map[cnt][r][0], &map[cnt - 1][r][0], sizeof(char)*M);
			//}
		}
	}
	/*
	cout << "====================================\n";
	cout << "count : " << cnt << endl;
	print_vector(v);
	print_map(cnt);
	cout << "====================================\n\n";
	*/
	coor red_loc, blue_loc;
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < M; ++c)
		{
			if (map[cnt][r][c] == 'R')
				red_loc = { r, c };
			else if (map[cnt][r][c] == 'B')
				blue_loc = { r, c };
		}
	}
	//더 이상 공이 움직이지 않을 때까지 굴러감
	bool red_stop = false, blue_stop = false;
	bool red_end = false, blue_end = false;
	bool flag_move = false;
	int rr = 0, rc = 0, br = 0, bc = 0;
	while (1)
	{
		if ((red_stop || red_end) && (blue_stop || blue_end))
			break;
		int cur_direct = v[cnt];
		rr = red_loc.first + dir[cur_direct][0];
		rc = red_loc.second + dir[cur_direct][1];
		br = blue_loc.first + dir[cur_direct][0];
		bc = blue_loc.second + dir[cur_direct][1];

		//	빨간구슬
			if (rr == hole.first && rc == hole.second)
			{
				red_end = true;
				map[cnt][red_loc.first][red_loc.second] = '.';
				flag_move = true;
				red_stop = true;
			}
			if (map[cnt][rr][rc] == '#' || map[cnt][rr][rc] == 'B')
			{
				red_stop = true;
			}
			if (map[cnt][rr][rc] == '.')
			{
				swap(map[cnt][rr][rc], map[cnt][red_loc.first][red_loc.second]);
				red_loc = { rr, rc };
				flag_move = true;
			}
			if (!flag_move && !red_stop)
				red_stop = true;
		//	파란구슬
			if (br == hole.first && bc == hole.second)
			{
				blue_end = true;
				map[cnt][blue_loc.first][blue_loc.second] = '.';
				flag_move = true;
				blue_stop = true;
			}
			if (map[cnt][br][bc] == '#' || map[cnt][br][bc] == 'R')
			{
				blue_stop = true;
			}
			if (map[cnt][br][bc] == '.')
			{
				swap(map[cnt][br][bc], map[cnt][blue_loc.first][blue_loc.second]);
				blue_loc = { br, bc };
				flag_move = true;
			}
			if (!flag_move && !blue_stop)
				blue_stop = true;
	}
	return { {red_end, blue_end}, flag_move };
}
inline bool valid(int cnt, int d, vector<int> v)
{
	if (!v.size())
		return true;
	else
	{
		if (v[cnt - 1] == d || v[cnt - 1] == (d + 2) % 4)
			return false;
	}
	return true;
}
inline void recur(int count, bool red_end, bool blue_end, bool flag_move, vector<int>& v)
{
	if (count >= 10)
	{
		return;
	}
	if (!flag_move)
	{
		return;
	}
	if (red_end && blue_end)
	{
		return;
	}
	if (!red_end && blue_end)
	{
		return;
	}
	if (red_end && !blue_end)
	{
		answer = min(answer, count);
		return;
	}
	else
	{
		for (register int d = 0; d < DIRECT; ++d)
		{
			if (!valid(count, d, v))
				continue;
			else
			{
				v.push_back(d);
				flags cur_end = move_bead(count, v);
				recur(count + 1, cur_end.first.first, cur_end.first.second, cur_end.second, v);
				v.pop_back();
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input13460.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	result = -1;
	answer = 11;
	flag_program_end = false;
	cin >> N >> M;
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < M; ++c)
		{
			cin >> map[0][r][c];
			if (map[0][r][c] == 'O')
				hole = { r, c };
		}
	}
	vector<int> order;
	recur(0, false, false, true, order);
	if (answer >= 10)
		answer = -1;
	cout << answer;
	return 0;
}