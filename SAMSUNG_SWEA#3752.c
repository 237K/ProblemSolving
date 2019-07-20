//
//	OS Windows
//	2019.07.19
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#3752] (D4) 가능한 시험 점수
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
int T, N;
int score[101];
int pick[101];
int pos[10001];
int ret;
void print_arr(int cnt)
{
	for (register int i = 0; i < cnt; ++i)
	{
		printf("%d ", pick[i]);
	}
	printf("\n\n");
}
void recur(int cnt, int idx)
{
	if (cnt > N) return;
	if (cnt >= 1)
	{
		//print_arr(cnt);
		register int sum = 0, i;
		for (i = 0; i < cnt; ++i) sum += score[pick[i]];
		if (!pos[sum])
		{
			pos[sum] = 1;
			ret++;
		}
	}
	for (register int i = idx; i < N; ++i)
	{
		pick[cnt] = i;
		recur(cnt + 1, i + 1);
	}
}
int main(void)
{
	freopen("s_input3752.txt", "r", stdin);
	register int tc, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
		(void)memset(pos, 0, sizeof(pos));
		ret = 0;
		for (i = 0; i < N; ++i) scanf("%d", &score[i]);
		recur(0, 0);
		printf("#%d %d\n", tc, ret+1);
	}
	return 0;
}