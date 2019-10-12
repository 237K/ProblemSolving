//
//	OS Windows
//	2019.10.12
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #15649 N°úM 1
//

#include <stdio.h>
#include <memory.h>
int N, M;
int arr[9], check[9];
void recur(int cnt)
{
	if (cnt == M)
	{
		for (register int i = 0; i < cnt; ++i)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (register int j = 1; j <= N; ++j)
	{
		if (!check[j])
		{
			check[j] = 1;
			arr[cnt] = j;
			recur(cnt + 1);
			check[j] = 0;
		}
	}
}
int main(void)
{
	freopen("input15649.txt", "r", stdin);
	(void)memset(check, 0, sizeof(check));
	scanf("%d %d", &N, &M);
	recur(0);
	return 0;
}