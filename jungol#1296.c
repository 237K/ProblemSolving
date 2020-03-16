//
//	OS Windows
//	2020.03.12
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1296> 시험보기
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 3
#define SZ 101
#define Adr 4
#define Bru 5
#define Gor 7
char winner[MAX][7] = { "Adrian", "Bruno", "Goran" };
char Adrian[Adr] = { 'A', 'B', 'C' };
char Bruno[Bru] = { 'B', 'A', 'B', 'C' };
char Goran[Gor] = { 'C', 'C', 'A', 'A', 'B', 'B' };
char input[SZ];
int main(void)
{
	freopen("jinput1296.txt", "r", stdin);
	int N, n, a, b, c, Ad = 0, Br = 0, Go = 0, win, i;
	scanf("%d\n%s", &N, &input);
	for (n = 0; n < N; ++n)
	{
		a = n % (Adr-1); b = n % (Bru-1); c = n % (Gor-1);
		if (input[n] == Adrian[a]) Ad++;
		if (input[n] == Bruno[b]) Br++;
		if (input[n] == Goran[c]) Go++;
	}
	if (Ad == Br && Br == Go)
	{
		printf("%d\n", Ad);
		for (i = 0; i < MAX; ++i)
			printf("%s\n", winner[i]);
	}
	else if (Ad == Br && Ad > Go)
	{
		printf("%d\n", Ad);
		printf("%s\n%s", winner[0], winner[1]);
	}
	else if (Ad == Go && Ad > Br)
	{
		printf("%d\n", Ad);
		printf("%s\n%s", winner[0], winner[2]);
	}
	else if (Br == Go && Br > Ad)
	{
		printf("%d\n", Br);
		printf("%s\n%s", winner[1], winner[2]);
	}
	else
	{
		if (Ad > Br)
		{
			if (Ad > Go)
			{
				printf("%d\n", Ad);
				win = 0;
			}
			else
			{
				printf("%d\n", Go);
				win = 2;
			}
		}
		else
		{
			if (Br > Go)
			{
				printf("%d\n", Br);
				win = 1;
			}
			else
			{
				printf("%d\n", Go);
				win = 2;
			}
		}
		printf("%s", winner[win]);
	}
	return 0;
}