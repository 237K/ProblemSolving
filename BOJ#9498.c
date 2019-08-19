//
//	OS Windows
//	2019.08.09
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #9498	시험 성적
//

#include <stdio.h>
int main(void)
{
	int S;
	scanf("%d", &S);
	if (S >= 90) printf("A");
	else if (S >= 80) printf("B");
	else if (S >= 70) printf("C");
	else if (S >= 60) printf("D");
	else printf("F");
	return 0;
}