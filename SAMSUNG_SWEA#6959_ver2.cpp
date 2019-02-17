//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6959] <ÀÌ»óÇÑ ³ª¶óÀÇ µ¡¼À°ÔÀÓ> (D4)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("s_input6959.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int Number = 0;
		int Quotient = 0;
		int Remainder = 0;
		int Count = 0;
		int Recent = 0;
		scanf("%d", &Number);
		printf("#%d ", test_case);
		if (Number < 10)
		{
			if (Count % 2 == 0)
				printf("B\n");
			else
				printf("A\n");
			continue;
		}
		else if (Number >= 1000)
		{
			Quotient = Number / 1000;
			Remainder = Number % 1000;
			Remainder = Remainder / 100;
			Recent = Quotient + Remainder;
			if (Recent < 10)
				Count += 1;
			else
				Count += 2;

			printf("%d, Count : %d\n", Recent, Count);

			Remainder = Number % 100;
			Remainder = Remainder / 10;
			Recent = Recent + Remainder;
			if (Recent < 10)
				Count += 1;
			else
				Count += 2;

			printf("%d, Count : %d\n", Recent, Count);

			Remainder = Number % 10;
			if (Recent + Remainder >= 10)
				Count += 2;
			else
				Count += 1;

			printf("%d, Count : %d\n", Recent + Remainder, Count);

			if (Count % 2 == 0)
				printf("B\n");
			else
				printf("A\n");
			continue;
		}
		else if (Number >= 100 && Number < 1000)
		{
			Quotient = Number / 100;
			Remainder = Number % 100;
			Remainder = Remainder / 10;
			Recent = Quotient + Remainder;
			if (Recent < 10)
				Count += 1;
			else
				Count += 2;

			printf("%d, Count : %d\n", Recent, Count);

			Remainder = Number % 10;
			if (Recent + Remainder >= 10)
				Count += 2;
			else
				Count += 1;

			printf("%d, Count : %d\n", Recent + Remainder, Count);

			if (Count % 2 == 0)
				printf("B\n");
			else
				printf("A\n");
			continue;
		}
		else if (Number >= 10 && Number < 100)
		{
			Quotient = Number / 10;
			Remainder = Number % 10;
			Recent = Quotient + Remainder;
			if (Recent >= 10)
				Count += 2;
			else
				Count += 1;

			printf("%d, Count : %d\n", Recent, Count);

			if (Count % 2 == 0)
				printf("B\n");
			else
				printf("A\n");
			continue;
		}
	}
	return 0;
}