//
//	OS Windows
//	2019.04.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2455	지능형 기차
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
int main(int argc, char** argv)
{
	freopen("input2455.txt", "r", stdin);
	register int stop;
	int out, in;
	int people[4] = { 0, };
	int result = 0;
	for (stop = 0; stop < 4; ++stop)
	{
		scanf("%d %d", &out, &in);
		if (!stop) people[stop] = in;
		else people[stop] = people[stop - 1] - out + in;
		if (people[stop] > result) result = people[stop];
	}
	printf("%d\n", result);
	return 0;
}