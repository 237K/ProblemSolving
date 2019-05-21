//
//	OS Windows
//	2019.05.19
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1592	영식이와 친구들
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
int N, M, L;
int arr[1000];
int play()
{
	int ret = 0, ball = 0;
	while (1)
	{
		if ((++arr[ball]) == M) break;
		else
		{
			ret++;
			//	홀수
			if (arr[ball] % 2)
				ball = (ball + L) % N;
			//	짝수
			else if (!(arr[ball] % 2))
				ball = (ball + (N - L)) % N;
		}
	}
	return ret;
}
int main(void)
{
	freopen("input1592.txt", "r", stdin);
	setbuf(stdout, NULL);
	(void)memset(arr, 0, sizeof(arr));
	scanf("%d %d %d", &N, &M, &L);
	printf("%d", play());
	return 0;
}