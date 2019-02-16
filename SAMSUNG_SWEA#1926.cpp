//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1926] <간단한 369게임> (D2)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

void Test(int num)
{
	if (num > 100)
	{
		int Recent = num / 10;
		int count = 0;
		if (num / 100 == 3 || num / 100 == 6 || num / 100 == 9)
		{
			printf("-");
			count++;
			if (Recent / 10 == 3 || Recent / 10 == 6 || Recent / 10 == 9)
			{
				printf("-");
				count++;
				if (Recent % 10 == 3 || Recent % 10 == 6 || Recent % 10 == 9)
				{
					printf("-");
					count++;
				}
			}
		}
		else
		{
			if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9)
			{
				printf("-");
				count++;
			}
			if (Recent % 10 == 3 || Recent % 10 == 6 || Recent % 10 == 9)
			{
				printf("-");
				count++;
			}
		}
		if(count == 0)
			printf("%d", num);
	}
	else if (num <= 100)
	{
		if (num / 10 == 3 || num / 10 == 6 || num / 10 == 9)
		{
			printf("-");
			if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9)
				printf("-");
		}
		else if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9)
			printf("-");
		else
			printf("%d", num);
	}
	printf(" ");
}

int main(int argc, char** argv)
{
	int N;
	freopen("s_input1926.txt", "r", stdin);
	scanf("%d", &N);
	for (int number = 1; number <= N; ++number)
	{
		Test(number);
	}
	return 0;
}