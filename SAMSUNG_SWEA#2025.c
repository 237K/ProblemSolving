//
//	OS Windows
//	2019.09.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#2025] (D1) N¡Ÿ µ°º¿
//

#include <stdio.h>
int acc(int n)
{
	if (n == 1) return 1;
	return n + acc(n - 1);
}
int main(void)
{
	freopen("s_input2025.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	printf("%d", acc(N));
	return 0;
}