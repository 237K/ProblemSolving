//
//	OS Windows
//	2019.12.10
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션]	<BOJ #1681>	줄 세우기
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 1000001
int N, L, len;
int arr[7];
void disassemble(int n)
{
	register int idx = 0;
	while (n)
	{
		arr[idx++] = n % 10;
		n /= 10;
	}
	len = idx;
}
int check()
{
	register int i;
	for (i = 0; i < len; ++i)
	{
		if (arr[i] == L) return 0;
	}
	return 1;
}
int simul()
{
	register int cur = 1, cnt = 0;
	while (1)
	{
		disassemble(cur);
		if (check()) cnt++;
		if (cnt == N) break;
		cur++;
	}
	return cur;
}
int main(void)
{
	freopen("input1681.txt", "r", stdin);
	scanf("%d %d", &N, &L);
	printf("%d", simul());
	return 0;
}