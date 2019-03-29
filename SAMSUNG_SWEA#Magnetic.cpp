//
//	OS Windows
//	2019.03.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <Magnetic> (D3)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

const static int MAX = 100;

int main(int argc, char** argv)
{
	freopen("s_input_Magnetic.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	int DeadLock;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int map[MAX][MAX] = { 0, };
		int N[MAX] = { 0, }, S[MAX] = { 0, };
		DeadLock = 0;
		for (int r = 0; r < MAX; ++r)
		{
			for (int c = 0; c < MAX; ++c)
			{
				cin >> map[r][c];
				if (map[r][c] == 1)
				{
					if(!N[c])
						N[c] = 1;
				}
				if (map[r][c] == 2)
				{
					if (N[c])
					{
						DeadLock++;
						N[c] = 0;
					}
				}
			}
		}
		cout << "#" << test_case << ' ' << DeadLock << '\n';
	}
	return 0;
}