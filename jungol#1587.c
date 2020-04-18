//
//	OS Windows
//	2020.04.12
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1587> 버스
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BUS 4
#define STOP 5
#define TERM 15
int main(void)
{
	freopen("jinput1587.txt", "r", stdin);
	int M, in, out, cnt, top, low = 2147000000, ret;
	register int b, s;
	scanf("7:%d", &M);
	for (b = 0; b < BUS; ++b)
	{
		scanf("%d", &cnt);
		if(b) M += TERM;
		top = 0;
		for (s = 0; s < STOP; ++s)
		{
			scanf("%d %d", &out, &in);
			cnt += in - out;
			if (top < cnt) top = cnt;
		}
		if (low > top)
		{
			ret = M;
			low = top;
		}
	}
	if (ret < 10) printf("7:0%d", ret);
	else printf("7:%d", ret);
	return 0;
}