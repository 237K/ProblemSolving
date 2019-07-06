//
//	OS Windows
//	2019.07.05
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1948] (D2) 날짜 계산기
//

#include <stdio.h>
int cal[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main(void)
{
	int T, sm, sd, tm, td;
	register int tc, ret, i;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d %d %d", &sm, &sd, &tm, &td);
		ret = 0;
		if (sm == tm) ret = td - sd + 1;
		else
		{
			for (i = sm + 1; i < tm; ++i) ret += cal[i];
			ret += cal[sm] - sd + td + 1;
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}