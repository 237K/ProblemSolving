//
//	OS Windows
//	2019.04.13
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5650] <�ɺ� ����> (���� SW �����׽�Ʈ)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> coor;

struct WH
{
	int n_wh;
	coor hole1, hole2;
};

struct BALL
{
	int r, c, d;
};

const static int SIZE = 101;
const static int MAX_WH = 6;
const static int DIRECT = 4;

static int map[SIZE][SIZE];
static WH wh[MAX_WH];
static BALL ball;
static vector<coor> es;
static int dir[DIRECT][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
static int N;
static int idx_wh;

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	for (register int i = 0; i < MAX_WH; ++i)
	{
		wh[i] = { 0, {0, 0}, {0, 0} };
	}
	ball = { 0, 0, 0 };
	idx_wh = 0;
}
inline int brick(int kind, int d)
{
	switch (kind)
	{
	case 1:
		if (d == 0) return (d + 2) % 4;
		else if (d == 1) return (d + 3) % 4;
		else if (d == 2) return (d + 1) % 4;
		else if (d == 3) return (d + 2) % 4;
		break;
	case 2:
		if (d == 0) return (d + 2) % 4;
		else if (d == 1) return (d + 2) % 4;
		else if (d == 2) return (d + 3) % 4;
		else if (d == 3) return (d + 1) % 4;
		break;
	case 3:
		if (d == 0) return (d + 1) % 4;
		else if (d == 1) return (d + 2) % 4;
		else if (d == 2) return (d + 2) % 4;
		else if (d == 3) return (d + 3) % 4;
		break;
	case 4:
		if (d == 0) return (d + 3) % 4;
		else if (d == 1) return (d + 1) % 4;
		else if (d == 2) return (d + 2) % 4;
		else if (d == 3) return (d + 2) % 4;
		break;
	case 5:
		return (d + 2) % 4;
		break;
	default:
		break;
	}
}
inline coor move_wh(int row, int col, int num_wh)
{
	coor where_is_ball_going;
	for (register int i = 0; i < idx_wh; ++i)
	{
		if (wh[i].n_wh == num_wh)
		{
			if (wh[i].hole1.first == row && wh[i].hole1.second == col)
			{
				where_is_ball_going = wh[i].hole2;
				break;
			}
			else
			{
				where_is_ball_going = wh[i].hole1;
				break;
			}
		}
	}
	return where_is_ball_going;
}
inline int simulation()
{
	int answer = 0;
	//	��� �� �������� 4�������� ����

	for (vector<coor>::size_type i = 0; i < es.size(); ++i)
	{
		coor start_point = es[i];


		//cout << "==============================================================================\n";
		//cout << "starting point (" << start_point.first << ", " << start_point.second << ")\n";




		for (register int d = 0; d < DIRECT; ++d)
		{



			//cout << "direct " << d << "\n\n";



			int score = 0;
			ball = { es[i].first, es[i].second, d };

			while (1)
			{
				int nr = ball.r + dir[ball.d][0];
				int nc = ball.c + dir[ball.d][1];


				//cout << "(" << nr << ", " << nc << ") direct " << ball.d << '\n';


				//	���� ���� 1. �������� ���ƿ��� ���
				if (nr == start_point.first && nc == start_point.second)
					break;
				//	���� ���� 2. ��Ȧ�� ���� ���
				else if (map[nr][nc] == -1)
					break;
				//	���� �ε����� ���⸸ 180�� ��ȯ
				else if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				{
					ball.d = (ball.d + 2) % 4;
					ball.r = nr;
					ball.c = nc;
					score++;
					continue;
				}
				//	������ �ε����� ���
				else if (map[nr][nc] >= 1 && map[nr][nc] <= 5)
				{
					int nd = brick(map[nr][nc], ball.d);
					ball.d = nd;
					ball.r = nr;
					ball.c = nc;
					score++;
					continue;
				}
				//	��Ȧ�� ���� ���
				else if (map[nr][nc] >= 6 && map[nr][nc] <= 10)
				{


					//cout << map[nr][nc] << "�� ��Ȧ�� ����!!" << '\n';


					coor tp = move_wh(nr, nc, map[nr][nc]);
					ball.r = tp.first;
					ball.c = tp.second;
					continue;
				}
				//	������� ���
				else if (!map[nr][nc])
				{
					ball.r = nr;
					ball.c = nc;
				}
			}
			answer = max(answer, score);
			//cout << "answer " << answer << "\n\n";
		}

		//cout << "===============================================================\n\n";

	}
	return answer;
}

int main(int argc, char** argv)
{
	freopen("s_input5650.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	register int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N;
		for (register int r = 0; r < N; ++r)
		{
			for (register int c = 0; c < N; ++c)
			{
				cin >> map[r][c];
				if (!map[r][c])
					es.push_back({ r, c });
				else if (map[r][c] >= 6 && map[r][c] <= 10)
				{
					int there_is_wh_pair = -1;
					for (register int i = 0; i < MAX_WH; ++i)
					{
						if (map[r][c] == wh[i].n_wh)
						{
							there_is_wh_pair = i;
							break;
						}
					}
					if (there_is_wh_pair == -1)
						wh[idx_wh++] = { map[r][c], {r, c}, {0, 0} };
					else
						wh[there_is_wh_pair].hole2 = { r, c };
				}
			}
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';


		//cout << "\n\n";

	}
	return 0;
}