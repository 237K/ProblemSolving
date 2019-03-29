//
//	OS Windows
//	2019.03.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2112] <보호 필름> (모의 SW 역량테스트)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

const static int MAX_THICK = 13;
const static int MAX_CELL = 20;

static int film[MAX_THICK][MAX_THICK][MAX_CELL];
static int check[MAX_CELL];				//각 열에서 같은 특성이 몇 개인지 저장
static bool check_row[MAX_THICK];
static int D, W, K;

inline void Print()
{
	for (int r = 0; r < D; ++r)
	{
		for (int c = 0; c < W; ++c)
		{
			cout << film[0][r][c] << ' ';
		}
		cout << endl<<endl;
	}
}

inline bool Test(int cast)
{
	(void)memset(check, 0, sizeof(check));
	int check_count = 0;
	for (int c = 0; c < W; ++c)
	{
		int cnt = 1;
		for (int r = 1; r < D; ++r)
		{
			if (film[cast][r][c] == film[cast][r - 1][c])
			{
				cnt++;
				if (cnt >= K)
				{
					check[c]++;
					check_count++;
					break;
				}
			}
			else
				cnt = 1;
		}
	}
	if (check_count == W)
		return true;
	else
		return false;
}

inline void A_casting(int cast, int row)
{
	for (int c = 0; c < W; ++c)
	{
		film[cast][row][c] = 0;
	}
}

inline void B_casting(int cast, int row)
{
	for (int c = 0; c < W; ++c)
	{
		film[cast][row][c] = 1;
	}
}

inline int Simulation(int cast)
{
	//cout << "cast : " << cast << endl;
	//Print();
	(void)memcpy(&film[cast][0][0], &film[cast - 1][0][0], sizeof(film));

	if (cast > D)
		return D;
	if (Test(cast))
		return cast;
	else
	{

			for (int a = 0; a <= cast; ++a)
			{
				int b = cast - a;
				for (int r = 0; r < D; ++r)
				{
					if (a)
					{
						if (!check_row[r])
						{
							A_casting(cast, r);
							check_row[r] = true;
							a--;
						}
					}
					if (b)
					{

					}
				}
			}

	}

}

int main(int argc, char** argv)
{
	freopen("s_input2112.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(film, 0, sizeof(film));
		cin >> D >> W >> K;
		for (int r = 0; r < D; ++r)
		{
			for (int c = 0; c < W; ++c)
			{
				cin >> film[0][r][c];
			}
		}
		if(Test())
			cout << "#" << test_case << " 0" << '\n';
		else
			cout << "#" << test_case << ' ' << Simulation(1) << '\n';
	}
	return 0;
}