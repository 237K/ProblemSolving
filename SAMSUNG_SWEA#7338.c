//
//	OS Windows
//	2019.05.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7338] <현규의 연봉계산법> (D4)
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long Y, trans_Y;
int M, trans_M;
void cal();

int main(int argc, char** argv)
{
	freopen("s_input7338.txt", "r", stdin);
	int T;
	register int test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld %d\n", &Y, &M);
		cal();
		printf("#%d %lld %d\n", test_case, trans_Y, trans_M);
	}
	return 0;
}

void cal()
{
	long long temp = (Y - 2016) * 12 + M;
	trans_Y = temp / 13 + 2016;
	trans_M = temp % 13;
	if (!trans_M)
	{
		trans_Y--;
		trans_M = 13;
	}
}