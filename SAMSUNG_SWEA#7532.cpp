//
//	OS Windows
//	2019.04.25
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7532] <세영이의 SEM력 연도> (D3)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const static int s_cycle = 365, e_cycle = 24, m_cycle = 29;
int main(int argc, char** argv)
{
	freopen("s_input7532.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int S, E, M;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		int idx = 0;
		int result = 0;
		cin >> S >> E >> M;
		while (1)
		{
			result = S - 1 + (s_cycle * idx);
			//cout << result << '\n';
			if (result % m_cycle == M-1)
			{
				if (result % e_cycle == E-1) break;
				else
				{
					idx++;
					continue;
				}
			}
			else idx++;
		}
		cout << "#" << test_case << ' ' << result + 1 << '\n';
	}
	return 0;
}