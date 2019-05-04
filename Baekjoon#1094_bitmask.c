//
//	OS Windows
//	2019.05.01
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1094	¸·´ë±â
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bitset>

int stick[7] = { 64, 32, 16, 8, 4, 2, 1 };
int check[7] = { 0, };
int X;

int bitmask()
{
	for (register int mask = 0; mask < (1 << 8); ++mask)
	{
		int temp = 0;
		int cnt = 0;
		for (register int flag = 0; flag < 7; ++flag)
		{
			//printf("mask : %d, flag : %d, stick : %d, temp : %d\n", mask, flag, stick[flag], temp);
			if (mask & (1 << flag))
			{
				temp += stick[flag];
				cnt++;
				//printf("mask : %d, flag : %d, stick : %d, temp : %d\n", mask, flag, stick[flag], temp);
				if (temp > X)
					break;
				if (temp == X)
					return cnt;
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input1094.txt", "r", stdin);
	scanf("%d", &X);
	printf("%d\n", bitmask());
	return 0;
}