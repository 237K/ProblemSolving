//
//	OS Windows
//	2019.05.08
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5644] <무선충전> (모의)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

/*	(row, col) 아님. (x, y)  x : 가로, y : 세로	*/
typedef pair<int, int> coor;

const static int HUMAN = 2;
const static int SIZE = 11;
const static int MAX_ROUTE = 101;
const static int MAX_BC = 8;
const static int DIRECT = 5;

struct BC
{
	int x, y, c, p;
};

static int dir[DIRECT][2] = { {0, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
static coor route[HUMAN][MAX_ROUTE];
static BC bc[MAX_BC];
static vector<int> can_select_bc[HUMAN];
static int M, A;

inline int simulation()
{
	int result = 0;
	register int m, h, a, x_dist, y_dist, dist;
	for (m = 0; m <= M; ++m)
	{
		int can_charge_flag[HUMAN] = { 0, 0 };
		for (h = 0; h < HUMAN; ++h)
		{
			can_select_bc[h].clear();
			for (a = 0; a < A; ++a)
			{
				x_dist = bc[a].x - route[h][m].first;
				y_dist = bc[a].y - route[h][m].second;
				if (x_dist < 0) x_dist *= -1;
				if (y_dist < 0) y_dist *= -1;
				dist = x_dist + y_dist;

				if (bc[a].c >= dist)
				{
					can_charge_flag[h] = 1;
					can_select_bc[h].push_back(a);
				}
			}
		}
		//	충전범위 안에 사람이 있을 때, 충전할 수 있는 최대값 만큼 충전
		int A_charge = 0, B_charge = 0, max_charge = 0, size = 0, cur_bc_idx, A_size, B_size, A_bc_idx, B_bc_idx;
		//	A만 충전할 수 있을 때
		if (can_charge_flag[0] && !can_charge_flag[1])
		{
			size = can_select_bc[0].size();
			for (register int i = 0; i < size; ++i)
			{
				cur_bc_idx = can_select_bc[0][i];
				if (max_charge < bc[cur_bc_idx].p)
					max_charge = bc[cur_bc_idx].p;
			}
		}
		//	B만 충전할 수 있을 때
		else if (!can_charge_flag[0] && can_charge_flag[1])
		{
			size = can_select_bc[1].size();
			for (register int i = 0; i < size; ++i)
			{
				cur_bc_idx = can_select_bc[1][i];
				if (max_charge < bc[cur_bc_idx].p)
					max_charge = bc[cur_bc_idx].p;
			}
		}
		//	A, B 둘 다 충전할 수 있을 때
		else if (can_charge_flag[0] && can_charge_flag[1])
		{
			A_size = can_select_bc[0].size();
			B_size = can_select_bc[1].size();
			for (register int i = 0; i < A_size; ++i)
			{
				for (register int j = 0; j < B_size; ++j)
				{
					A_bc_idx = can_select_bc[0][i];
					B_bc_idx = can_select_bc[1][j];
					//	A, B가 같은 충전소를 선택했을 경우
					if (A_bc_idx == B_bc_idx)
					{
						A_charge = bc[A_bc_idx].p / 2;
						B_charge = A_charge;
					}
					//	A, B가 다른 충전소를 선택했을 경우
					else
					{
						A_charge = bc[A_bc_idx].p;
						B_charge = bc[B_bc_idx].p;
					}

					if (max_charge < A_charge + B_charge)
						max_charge = A_charge + B_charge;
				}
			}
		}
		result += max_charge;
	}
	return result;
}
int main(int argc, char** argv)
{
	freopen("s_input5644.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int test_case, h, m, a;
	int in_dir, in_x, in_y, in_c, in_p;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> M >> A;
		route[0][0] = { 1, 1 };
		route[1][0] = { 10, 10 };
		for (h = 0; h < HUMAN; ++h)
		{
			for (m = 1; m <= M; ++m)
			{
				cin >> in_dir;
				int nx = route[h][m - 1].first + dir[in_dir][0];
				int ny = route[h][m - 1].second + dir[in_dir][1];
				route[h][m] = { nx, ny };
			}
		}
		for (a = 0; a < A; ++a)
		{
			cin >> in_x >> in_y >> in_c>>in_p;
			bc[a] = { in_x, in_y, in_c, in_p };
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}