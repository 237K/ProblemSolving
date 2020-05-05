//
//	OS Windows
//	2020.04.30
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1744> À·³îÀÌ
//
#define _CRT_SECURE_NO_WARNING
#define YUT 4
#define MAX 3
int main(void)
{
	int cur, cnt, i, j;
	char ret;
	for (i = 0; i < MAX; ++i)
	{
		cnt = 0;
		for (j = 0; j < YUT; ++j)
		{
			scanf("%d", &cur);
			cnt += cur;
		}
		if (cnt == 3) ret = 'A';
		else if (cnt == 2) ret = 'B';
		else if (cnt == 1) ret = 'C';
		else if (!cnt) ret = 'D';
		else ret = 'E';
		printf("%c\n", ret);
	}
	return 0;
}