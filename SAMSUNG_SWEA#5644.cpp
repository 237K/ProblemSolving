//
//	OS Windows
//	2019.04.12
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#5644> (모의) 무선 충전
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

const static int SIZE = 11;
const static int MAX_TIME = 101;
const static int MAX_BC = 9;
const static int DIRECT = 5;

struct BC
{
	int r, c, coverage, performance;
};
struct USER
{
	int r, c;
};
static BC bc[MAX_BC];
static USER userA, userB;
static int user_route[2][MAX_TIME];
static int M, A;
static int dir[DIRECT][2] = { {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

inline void init()
{
	(void)memset(user_route, 0, sizeof(user_route));
	for (register int i = 0; i < MAX_BC; ++i)
		bc[i] = { 0, 0, 0, 0 };
}

//	*핵심 함수
//	현재 위치에서 어떻게 충전하는 것이 효과적일 지 선택해서 최대값 리턴
//	사용자 2명이고 발전소 최대 8개이므로 모든 경우의 수를 살펴봐도 64가지 밖에 안됨
//	64번씩 최대 100초 동안 이동하면서 조사해도 6400번 밖에 안됨
inline int Charge(int a_row, int a_col, int b_row, int b_col)
{
	int max_value = 0;
	vector<int> A_can_select;
	vector<int> B_can_select;
	int A_dist = 0, B_dist = 0;
	for (register int i = 1; i <= A; ++i)
	{
		int bcr = bc[i].r;
		int bcc = bc[i].c;
		A_dist = abs(a_row - bcr) + abs(a_col - bcc);
		B_dist = abs(b_row - bcr) + abs(b_col - bcc);
		if (A_dist <= bc[i].coverage)
			A_can_select.push_back(i);
		if (B_dist <= bc[i].coverage)
			B_can_select.push_back(i);
	}
	int A_size = A_can_select.size();
	int B_size = B_can_select.size();
	//	A, B 둘 다 충전할 수 없는 경우
	if (!A_size && !B_size)
		return 0;
	//	A만 충전할 수 있는 경우
	else if (A_size && !B_size)
	{
		for (register int i = 0; i < A_size; ++i)
		{
			max_value = max(max_value, bc[A_can_select[i]].performance);
		}
	}
	//	B만 충전할 수 있는 경우
	else if (!A_size && B_size)
	{
		for (register int i = 0; i < B_size; ++i)
		{
			max_value = max(max_value, bc[B_can_select[i]].performance);
		}
	}
	//	A, B 둘다 충전할 수 있는 경우
	else if (A_size && B_size)
	{
		for (register int i = 0 ; i < A_size ; ++i)
		{
			for (register int j = 0 ; j < B_size ; ++j)
			{
				int temp = 0;
				if (A_can_select[i] == B_can_select[j])
					temp = max(bc[A_can_select[i]].performance, bc[B_can_select[j]].performance);
				else
					temp = bc[A_can_select[i]].performance + bc[B_can_select[j]].performance;
				max_value = max(max_value, temp);
			}
		}
	}
	//cout << "A : (" << a_row << ", " << a_col << ")  B : (" << b_row << ", " << b_col << ") value : " << max_value << '\n';
	return max_value;
}

//	시뮬레이션 실행 함수
inline int simulation()
{
	int result = 0;
	//	1. 유저들의 초기위치를 설정
	userA = { 1, 1 };
	userB = { 10, 10 };

	//	2. 0초에서도 충전할 수 있음
	result += Charge(userA.r, userA.c, userB.r, userB.c);

	//	3. 시뮬레이션 시작
	int time = 0;
	while (1)
	{
		time++;
		//cout << "time " << time << '\n';
		int A_cur_dir = user_route[0][time];
		int A_nr = userA.r + dir[A_cur_dir][0];
		int A_nc = userA.c + dir[A_cur_dir][1];

		int B_cur_dir = user_route[1][time];
		int B_nr = userB.r + dir[B_cur_dir][0];
		int B_nc = userB.c + dir[B_cur_dir][1];

		//	사용자가 지도 밖으로 이동하는 경우는 없음.
		if (A_nr < 1 || A_nc < 1 || A_nr >= SIZE || A_nc >= SIZE ||
			B_nr < 1 || B_nc < 1 || B_nr >= SIZE || B_nc >= SIZE)
			break;

		//	지시한 방향으로 한 칸씩 이동
		userA.r = A_nr;
		userA.c = A_nc;
		userB.r = B_nr;
		userB.c = B_nc;
		//	충전
		result += Charge(userA.r, userA.c, userB.r, userB.c);

		//	종료
		if (time == M)
			break;
	}
	return result;
}

int main(int argc, char** argv)
{
	freopen("s_input5644.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> M >> A;
		//	유저들의 이동경로 받아옴
		for (register int u = 0; u < 2; ++u)
		{
			for (register int m = 1; m <= M; ++m)
			{
				cin >> user_route[u][m];
			}
		}
		//	BC정보 읽어옴
		for (register int i = 1; i <= A; ++i)
		{
			cin >> bc[i].c >> bc[i].r >> bc[i].coverage >> bc[i].performance;
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}