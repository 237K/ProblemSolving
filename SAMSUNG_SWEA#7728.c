//
//	OS Windows
//	2019.05.22
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#7728> (D3) 다양성 측정
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int T, tc, i, cur, idx, ret;
char in[10];
int arr[10];
int main(int argc, char** argv)
{
	freopen("s_input7728.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		for (i = 0; i < 10; ++i) arr[i] = 0;
		idx = ret = 0;
		scanf("%s", &in);
		for (idx = 0; idx < 10; ++idx)
		{
			cur = in[idx] - '0';
			if (cur == -48) break;
			if (!arr[cur])
			{
				ret++;
				arr[cur]++;
			}
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}