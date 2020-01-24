//
//	OS Windows
//	2019.11.12
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #6679	신기한 네자리 숫자
//
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define START 2992
#define END 10000
int check10(int n)
{
	register int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int check12(int n)
{
	register int sum = 0;
	while (n)
	{
		sum += n % 12;
		n /= 12;
	}
	return sum;
}
int check16(int n)
{
	register int sum = 0;
	while (n)
	{
		sum += n % 16;
		n /= 16;
	}
	return sum;
}
void check()
{
	int ten, twv, six, i;
	for (i = START; i < END; ++i)
	{
		ten = check10(i);
		twv = check12(i);
		six = check16(i);
		if (ten == twv && twv == six) printf("%d\n", i);
	}
}
int main(void)
{
	freopen("input3460.txt", "r", stdin);
	check();
	return 0;
}