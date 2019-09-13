//
//	OS Windows
//	2019.09.12
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1933] (D1) 간단한 N의 약수
//

#include <stdio.h>
int main(void)
{
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		if (!(N%i)) printf("%d ", i);
	}
	return 0;
}