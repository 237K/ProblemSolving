//
//	OS Windows
//	2019.09.15
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1330 �� �� ���ϱ�
//

#include <stdio.h>
int main(void)
{
	int A, B;
	scanf("%d %d", &A, &B);
	if (A > B) printf(">");
	else if (A < B) printf("<");
	else printf("==");
	return 0;
}