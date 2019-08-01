//
//	OS Windows
//	2019.08.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5554	심부름 가는 길
//

#include <stdio.h>
int main(void)
{
	freopen("input5554.txt", "r", stdin);
	int A, B, C, D;
	register int S;
	scanf("%d\n%d\n%d\n%d", &A, &B, &C, &D);
	S = A + B + C + D;
	printf("%d\n%d", S / 60, S % 60);
}