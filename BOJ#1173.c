//
//	OS Windows
//	2019.05.21
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1173	¿îµ¿
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N, m, M, T, R, X, tik;
int main(int argc, char** argv)
{
	freopen("input1173.txt", "r", stdin);
	scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);
	X = m;
	while (N)
	{
		tik++;
		if (m + T > M)
		{
			tik = -1;
			break;
		}
		if (X + T <= M)
		{
			N--;
			X += T;
			continue;
		}
		else
		{
			int tmp = X - R;
			if (tmp <= m) tmp = m;
			X = tmp;
		}
	}
	printf("%d", tik);
	return 0;
}