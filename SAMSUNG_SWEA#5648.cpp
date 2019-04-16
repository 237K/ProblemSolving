//
//	OS Windows
//	2019.04.13
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5648] <원자 소멸 시뮬레이션> (모의 SW 역량테스트)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

const static int MAX_ATOM = 1001;
const static int MAX_CRUSH = 500;
const static int DIRECT = 4;

struct ATOM
{
	int r, c, direct, energy, alive;
};
struct CRUSH
{
	int a1, a2;
	double crush_time;
	bool operator< (const CRUSH& c) const
	{
		return crush_time < c.crush_time;
	}
};
static int dir[DIRECT][2] = { {1, 0}, {-1, 0}, {0, -1}, { 0, 1} };
static ATOM atom[MAX_ATOM];
static vector<CRUSH> will_crush;
static int N, K;

inline void init()
{
	for (register int i = 0; i < MAX_ATOM; ++i)
	{
		atom[i] = { 0, 0, 0, 0, 0 };
	}
	will_crush.clear();
}
inline int simulation()
{
	int time = 0;
	int result = 0;
	for (register int i = 0; i < N - 1; ++i)
	{
		for (register int j = i + 1; j < N; ++j)
		{
			//	충돌하는 경우는 6가지가 있음
			if (i != j)
			{
				//	1. 같은 행에 있고 방향이 반대인 경우
				if (atom[i].r == atom[j].r)
				{
					double t_crush = (abs(atom[i].c - atom[j].c)) / 2;
					if (atom[i].c < atom[j].c && atom[i].direct == 3 && atom[j].direct == 2)
					{
						will_crush.push_back({ i, j, t_crush });
					}
					if (atom[i].c > atom[j].c && atom[i].direct == 2 && atom[j].direct == 3)
					{
						will_crush.push_back({ i, j, t_crush });
					}
				}
				//	2. 같은 열에 있고 방향이 반대인 경우
				if (atom[i].c == atom[j].c)
				{
					double t_crush = (abs(atom[i].r - atom[j].r)) / 2;
					if (atom[i].r > atom[j].r && atom[i].direct == 1 && atom[j].direct == 0)
					{
						will_crush.push_back({ i, j, t_crush });
					}
					if (atom[i].r < atom[j].r && atom[i].direct == 0 && atom[j].direct == 1)
					{
						will_crush.push_back({ i, j, t_crush });
					}
				}
				//	3. 첫번째 원자의 열이 두번째 원자의 열보다 작고, 첫번째 원자의 열의 절대값이 두번째 원자 행의 절대값과 같은 경우
				if (atom[i].c < atom[j].c && abs(atom[i].c) == abs(atom[j].r))
					//	3-1. 첫번째 원자 방향 3, 두번째 원자 방향 0인 경우
				{
					double t_crush = abs(atom[i].c - atom[j].c);
					if (atom[i].r > atom[j].r && atom[i].direct == 3 && atom[j].direct == 0)
					{
						will_crush.push_back({ i, j, t_crush });
					}
					//	3-2. 첫번째 원자 방향 3, 두번째 원자 방향 1인 경우
					if (atom[i].r < atom[j].r && atom[i].direct == 3 && atom[j].direct == 1)
					{
						will_crush.push_back({ i, j, t_crush });
					}
				}
				//	4. 첫번째 원자의 열이 두번째 원자의 열보다 크고, 첫번째 원자의 열의 절대값이 두번째 원자 행의 절대값과 같은 경우
				if (atom[i].c > atom[j].c && abs(atom[i].c) == abs(atom[j].r))
					//	4-1. 첫번째 원자 방향 2, 두번째 원자 방향 1인 경우
				{
					double t_crush = abs(atom[i].c - atom[j].c);
					if (atom[i].r < atom[j].r && atom[i].direct == 2 && atom[j].direct == 1)
					{
						will_crush.push_back({ i, j, t_crush });
					}
					//	4-2. 첫번째 원자 방향 2, 두번째 원자 방향 0인 경우
					if (atom[i].r > atom[j].r && atom[i].direct == 2 && atom[j].direct == 0)
					{
						will_crush.push_back({ i, j, t_crush });
					}
				}
			}
		}
	}
	//will_crush_atom.erase(unique(will_crush_atom.begin(), will_crush_atom.end()), will_crush_atom.end());
	sort(will_crush.begin(), will_crush.end());
	int size = will_crush.size();
	if (size)
	{
		for (register int i = 0; i < size; ++i)
		{
			int a1_idx = will_crush[i].a1;
			int a2_idx = will_crush[i].a2;
			if (atom[a1_idx].alive && atom[a2_idx].alive)
			{
				result += atom[a1_idx].energy + atom[a2_idx].energy;
				atom[a1_idx].alive = 0;	atom[a2_idx].alive = 0;
				atom[a1_idx].energy = 0;	atom[a2_idx].energy = 0;
			}
		}
	}
	return result;
}
int main(int argc, char** argv)
{
	freopen("input1.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N;
		for (register int n = 0; n < N; ++n)
		{
			int x = 0, y = 0, d = 0, k = 0;
			cin >> x >> y >> d >> k;
			atom[n] = { y, x, d, k, 1 };
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}