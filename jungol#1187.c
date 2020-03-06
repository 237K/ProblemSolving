//
//	OS Windows
//	2020.03.03
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1187> Å»°Í
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 7
char hyeseong[LEN], group[LEN];
int main(void)
{
	freopen("jinput1187.txt", "r", stdin);
	scanf("%s\n%s", &hyeseong, &group);
	register int i, hye = 1, gro = 1;
	for (i = 0; hyeseong[i]; ++i)
	{
		hye *= hyeseong[i] - 'A' + 1;
	}
	for (i = 0; group[i]; ++i)
	{
		gro *= group[i] - 'A' + 1;
	}
	hye %= 47; gro %= 47;
	if (hye == gro) printf("GO");
	else printf("STAY");
	return 0;
}