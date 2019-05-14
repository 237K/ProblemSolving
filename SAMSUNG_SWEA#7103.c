//
//	OS Windows
//	2019.05.10
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7103] <D4> 준홍이의 네 개의 제곱수
//	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 181
int T, N, max, ret;
int num[MAX];
void cal(int cnt, int idx)
{
	int temp = 0;
	if (cnt > 4)
		return;
	for (register int i = 0; i < cnt; ++i)
	{
		temp += num[i] * num[i];
	}
	if (temp == N)
	{
		ret++;
		return;
	}
	for (register int i = idx; i <= max; ++i)
	{
		num[cnt] = i;
		cal(cnt + 1, i);
		num[cnt] = 0;
	}
}
int main(int argc, char** argv)
{
	freopen("s_input7103.txt", "r", stdin);
	register int test_case;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 0;
		scanf("%d", &N);
		max = (int)sqrt(N);
		cal(0, 1);
		printf("#%d %d\n", test_case, ret);
	}
	return 0;
}