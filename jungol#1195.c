//
//	OS Windows
//	2020.03.03
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1195> 최대값과 최소값
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 10
int arr[LEN], index;
int main(void)
{
	register int i, lowtop, highbottom;
	for (i = 0; i < LEN; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &index);
	lowtop = 0; highbottom = 2147000000;
	for (i = 0; i < LEN; ++i)
	{
		if (index < arr[i])
		{
			if (highbottom > arr[i])
				highbottom = arr[i];
		}
		else
		{
			if (lowtop < arr[i])
				lowtop = arr[i];
		}
	}
	if (!lowtop) lowtop = index;
	if (highbottom == 2147000000) highbottom = index;
	printf("%d\n%d", lowtop, highbottom);
	return 0;
}