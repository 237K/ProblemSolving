//
//	OS Windows
//	2020.06.01
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#2117> 야바위
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define SZ 3
#define MAX 51
int cup[SZ];
char order[MAX];
void swap(int left, int right)
{
	int tmp = cup[right];
	cup[right] = cup[left];
	cup[left] = tmp;
}
void go(char o)
{
	if (o == 'A') swap(0, 1);
	else if (o == 'B') swap(1, 2);
	else swap(0, 2);
}
int find()
{
	register int i, ret;
	for (i = 0; i < SZ; ++i)
		if (cup[i]) ret = i+1;
	return ret;
}
int main(void)
{
	freopen("jinput2117.txt", "r", stdin);
	(void)memset(cup, 0, sizeof(cup));
	cup[0] = 1;
	scanf("%s", &order);
	for (register int i = 0; order[i]; ++i)
	{
		go(order[i]);
	}
	printf("%d", find());
	return 0;
}