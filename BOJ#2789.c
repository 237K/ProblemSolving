//
//	OS Windows
//	2019.11.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2789	유학 금지
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101
char comp[10] = { 'C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E' };
int main(void)
{
	freopen("input2789.txt", "r", stdin);
	char ret[MAX], input[MAX];
	register int i, j, flag, idx = 0;
	scanf("%s", &input);
	for (i = 0; input[i]; ++i)
	{
		flag = 1;
		for (j = 0; j < 10; ++j)
		{
			if (input[i] == comp[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			ret[idx++] = input[i];
		}
	}
	printf("%s", ret);
	return 0;
}