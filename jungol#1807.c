//
//	OS Windows
//	2020.04.30
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1807> 대결결과
//
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
int main(void)
{
	int Z = 0, S = 0, z, s, N, n;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%d %d", &z, &s);
		if (z > s) Z++;
		else if (s > z) S++;
	}
	printf("%d %d", Z, S);
	return 0;
}