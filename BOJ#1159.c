//
//	OS Windows
//	2019.10.10
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1159 ³ó±¸ °æ±â
//

#include <stdio.h>
#include <memory.h>
char name[31], ret[31];
int cnt[26];
int main(void)
{
	freopen("input1159.txt", "r", stdin);
	(void)memset(cnt, 0, sizeof(cnt));
	int N, n, r = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n)
	{
		scanf("%s", &name);
		cnt[name[0] - 'a']++;
	}
	for (n = 0; n < 26; ++n)
	{
		if (cnt[n] > 4)
		{
			ret[r++] = n + 'a';
		}
	}
	if (!r) printf("PREDAJA");
	else
	{
		for (n = 0; n < r; ++n)
			printf("%c", ret[n]);
	}
	return 0;
}