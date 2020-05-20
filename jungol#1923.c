//
//	OS Windows
//	2020.05.20
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1923> 유권자 통계
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ_COL 10
#define SZ_ROW 2
#define COL 10
#define ROW 3
int table[ROW][COL], gender, age;
void print()
{
	register int sum, r, c;
	for (r = 0; r < SZ_ROW; ++r)
	{
		sum = 0;
		for (c = 2; c < SZ_COL-1; ++c)
		{
			sum += table[r][c];
		}
		table[r][9] = sum;
	}
	for (c = 0; c < SZ_COL; ++c)
	{
		table[2][c] = table[0][c] + table[1][c];
	}
	for (r = 0; r < ROW; ++r)
	{
		for (c = 0; c < COL; ++c)
		{
			printf("%d ", table[r][c]);
		}
		printf("\n");
	}
}
void check(int n)
{
	register int col;
	gender = n / 100 - 1;
	age = n % 100;
	if (age >= 0 && age < 10) col = 0;
	else if (age >= 10 && age < 20) col = 1;
	else if (age >= 20 && age < 30) col = 2;
	else if (age >= 30 && age < 40) col = 3;
	else if (age >= 40 && age < 50) col = 4;
	else if (age >= 50 && age < 60) col = 5;
	else if (age >= 60 && age < 70) col = 6;
	else if (age >= 70 && age < 80) col = 7;
	else col = 8;
	table[gender][col]++;
}
int main(void)
{
	freopen("jinput1923.txt", "r", stdin);
	(void)memset(table, 0, sizeof(table));
	int N, r, c;
	for (r = 0; r < SZ_ROW; ++r)
	{
		for (c = 0; c < SZ_COL; ++c)
		{
			scanf("%d", &N);
			check(N);
		}
	}
	print();
	return 0;
}