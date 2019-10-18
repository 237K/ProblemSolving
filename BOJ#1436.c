//
//	OS Windows
//	2019.10.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1436 ¿µÈ­°¨µ¶ ¼ò
//

#include <stdio.h>
int sep(int n)
{
	register int cnt = 0;
	while (n)
	{
		if (n % 10 == 6) cnt++;
		else cnt = 0;
		if (cnt == 3) return 1;
		n /= 10;
	}
	return 0;
}
int simul(int t)
{
	register int cnt = 1, i = 666;
	while (1)
	{
		if (cnt == t) break;
		if (sep(++i)) cnt++;
	}
	return i;
}
int main(void)
{
	freopen("input1436.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	printf("%d", simul(N));
	return 0;
}