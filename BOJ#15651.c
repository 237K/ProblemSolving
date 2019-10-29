//
//	OS Windows
//	2019.10.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #15651	N°ú M 3
//	

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 8
int arr[SZ];
int N, M;
void print()
{
	register int i;
	for (i = 0; i < M; ++i) printf("%d ", arr[i]);
	printf("\n");
}
void recur(int cnt)
{
	if (cnt == M)
	{
		print();
		return;
	}
	for (register int i = 1; i <= N; ++i)
	{
		arr[cnt] = i;
		recur(cnt + 1);
	}
}
int main(void)
{
	freopen("input15651.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	recur(0);
	return;
}