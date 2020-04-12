//
//	OS Windows
//	2020.04.10
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1534> 10진수를 2, 8, 16진수로
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 20
char arr[SZ];
int cnt;
void to2(int n)
{
	while (n)
	{
		arr[cnt++] = (n % 2) + '0';
		n /= 2;
	}
}
void to8(int n)
{
	while (n)
	{
		arr[cnt++] = (n % 8) + '0';
		n /= 8;
	}
}
void to16(int n)
{
	register int tmp;
	char c;
	while (n)
	{
		tmp = n % 16;
		if (tmp >= 10)
		{
			if (tmp == 10) c = 'A';
			else if (tmp == 11) c = 'B';
			else if (tmp == 12) c = 'C';
			else if (tmp == 13) c = 'D';
			else if (tmp == 14) c = 'E';
			else c = 'F';
		}
		else
			c = tmp + '0';
		arr[cnt++] = c;
		n /= 16;
	}
}
void print()
{
	register int i;
	for (i = cnt - 1; i >= 0; --i)
		printf("%c", arr[i]);
}
int main(void)
{
	freopen("jinput1534.txt", "r", stdin);
	int N, jin;
	cnt = 0;
	scanf("%d %d", &N, &jin);
	if (jin == 2) to2(N);
	else if (jin == 8) to8(N);
	else to16(N);
	print();
	return 0;
}