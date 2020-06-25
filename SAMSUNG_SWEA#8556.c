//
//	OS Windows
//	2019.09.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#8556] (D3) ºÏºÏ¼­
//

#include <stdio.h>
#include <math.h>
char str[101];
int main(void)
{
	freopen("s_input8556.txt", "r", stdin);
	int T, tc, i, n, w, ret, rmd;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		str[0] = '\0'; n = w = 0;
		scanf("%s", &str);
		for (i = 0; str[i]; ++i)
		{
			if (str[i] == 'n')
			{
				n++;
				i += 4;
			}
			else
			{
				w++;
				i += 3;
			}
		}
		if (n + w == 1)
		{
			if (n) ret = 0;
			else ret = 90;
		}
		
		ret = (90 / (int)pow(2, w)) - (90 / (int)pow(2, n));
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}