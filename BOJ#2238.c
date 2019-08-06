//
//	OS Windows
//	2019.08.06
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2238	°æ¸Å
//
//	

#include <stdio.h>
#include <memory.h>
char name[100001][11];
int price[100001];
int cnt[10001];
int U, N, max_price, target_price, ret;
int main(void)
{
	freopen("input2238.txt", "r", stdin);
	register int i, tmp;
	(void)memset(cnt, 0, sizeof(cnt));
	tmp = 2147000000; max_price = 0;
	scanf("%d %d", &U, &N);
	for (i = 0; i < N; ++i)
	{
		scanf("%s %d", &name[i], &price[i]);
		if (max_price < price[i]) max_price = price[i];
	}
	for (i = 0; i < N; ++i) cnt[price[i]]++;
	for (i = max_price; i >= 0; --i)
	{
		if (cnt[i] && tmp >= cnt[i])
		{
			target_price = i;
			tmp = cnt[i];
		}
	}
	for (i = 0; i < N; ++i)
	{
		if (target_price == price[i])
		{
			ret = i;
			break;
		}
	}
	printf("%s %d", name[ret], price[ret]);
	return 0;
}