//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2072] <홀수만 더하기> (D1)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const static int MAX = 10000;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N = 10;
	//freopen("s_input2.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int Answer = 0;
		int Num = 0;
		for (int i = 0; i < N; ++i)
		{
			try
			{
				scanf("%d", &Num);
				if (Num > MAX)
					throw Num;
				if (Num % 2 != 0)
					Answer += Num;
			}
			catch (int expn)
			{
				printf("입력값(%d)이 범위를 초과했습니다.\n", expn);
			}
		}
		printf("#%d %d\n", test_case, Answer);
	}
	return 0;
}