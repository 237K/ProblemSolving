//
//
//  2019.04.05

//  ProblemSolving
//
//  [Algorithm Problem Solving]
//
//  <파스칼의 삼각형>
//
//					1
//				1		1
//			1		2		1
//		1		3		3		1
//	1		4		6		4		1
//
//
//	높이가 N일때 K번째 숫자 출력

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

const static int MAX = 1002;

static int pascal_triangle[MAX][MAX];
static int N, K;

inline void print()
{
	for (register int r = 0; r <= N; ++r)
	{
		for (register int c = 0; c <= N + 2; ++c)
		{
			cout << pascal_triangle[r][c] << ' ';
		}
		cout << endl << endl;
	}
}

inline int make_pascal_triangle()
{
	int count = 1;
	pascal_triangle[0][N / 2] = 1;
	for (register int r = 1; r <= N+1; ++r)
	{
		for (register int c = 1; c <= N + 2; ++c)
		{
			pascal_triangle[r][c] = pascal_triangle[r - 1][c - 1] + pascal_triangle[r - 1][c + 1];
			if (pascal_triangle[r][c])
			{
				if (++count == K)
					return pascal_triangle[r][c];
			}
		}
	}
	return -1;
}

int main(int argc, char** argv)
{
	freopen("testcase_Pascal.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(pascal_triangle, 0, sizeof(pascal_triangle));
		cin >> N >> K;
		cout << "#" << test_case << ' ' << make_pascal_triangle() << '\n';
		print();
	}
	return 0;
}