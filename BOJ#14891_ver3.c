//
//	OS Windows
//	2019.07.23
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14891	Åé´Ï¹ÙÄû
//	ver.3
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <math.h>
#define GEAR 4
#define TEETH 8
#define ORDER 100
int gear[GEAR][TEETH];
int K;
int order_gear_num[ORDER];
int order_direction[ORDER];
int fetch[GEAR];
//void print()
//{
//	register int i, j;
//	for (i = 0; i < GEAR; ++i)
//	{
//		printf("%d¹ø ±â¾î : ", i + 1);
//		for (j = 0; j < TEETH; ++j)
//		{
//			printf("%d ", gear[i][j]);
//		}
//		printf("\n\n");
//	}
//	printf("\n\n");
//}
void clockwise(int gear_num)
{
	int tmp = gear[gear_num][7];
	for (register int i = 7; i > 0; --i)
		gear[gear_num][i] = gear[gear_num][i - 1];
	gear[gear_num][0] = tmp;
}
void counterclockwise(int gear_num)
{
	int tmp = gear[gear_num][0];
	for (register int i = 0; i < 7; ++i)
		gear[gear_num][i] = gear[gear_num][i + 1];
	gear[gear_num][7] = tmp;
}
int check(int left, int right, int d)
{
	if (gear[left][2] != gear[right][6]) return d * (-1);
	else return 0;
}
void gear_fetch(int cog, int cod)
{
	(void)memset(fetch, 0, sizeof(fetch));
	register int i, tmp;
	fetch[cog] = cod;
	if (cog == 0)
	{
		for (i = 0; i < GEAR - 1; ++i)
		{
			tmp = check(i, i + 1, fetch[i]);
			if (!tmp) break;
			fetch[i + 1] = tmp;
		}
	}
	else if (cog == 1)
	{
		tmp = check(0, 1, cod);
		if (tmp) fetch[0] = tmp;
		for (i = 1; i < GEAR - 1; ++i)
		{
			tmp = check(i, i + 1, fetch[i]);
			if (!tmp) break;
			fetch[i + 1] = tmp;
		}
	}
	else if (cog == 2)
	{
		tmp = check(2, 3, cod);
		if (tmp) fetch[3] = tmp;
		for (i = 2; i > 0; --i)
		{
			tmp = check(i - 1, i, fetch[i]);
			if (!tmp) break;
			fetch[i - 1] = tmp;
		}
	}
	else if (cog == 3)
	{
		for (i = 3; i > 0; --i)
		{
			tmp = check(i - 1, i, fetch[i]);
			if (!tmp) break;
			fetch[i - 1] = tmp;
		}
	}
}
int simul()
{
	register int i, j, k, cur_order_gear, cur_order_dir, ret = 0;
	for (i = 0; i < K; ++i)
	{
		cur_order_gear = order_gear_num[i] - 1;
		cur_order_dir = order_direction[i];
		gear_fetch(cur_order_gear, cur_order_dir);
		for (j = 0; j < GEAR; ++j)
		{
			if (fetch[j] == 1) clockwise(j);
			else if (fetch[j] == -1) counterclockwise(j);
		}
		//print();
	}
	for (k = 0; k < GEAR; ++k)
		ret += gear[k][0] * ((int)(pow(2, k)));
	return ret;
}
int main(void)
{
	freopen("input14891.txt", "r", stdin);
	char input[9];
	register int i, j, k;
	for (i = 0; i < GEAR; ++i)
	{
		scanf("%s\n", &input);
		for (j = 0; j < TEETH; ++j)
		{
			gear[i][j] = input[j] - '0';
		}
	}
	scanf("%d", &K);
	for (k = 0; k < K; ++k)
	{
		scanf("%d %d", &order_gear_num[k], &order_direction[k]);
	}
	printf("%d", simul());
	return 0;
}