//
//	OS Windows
//	2019.09.26
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2920 À½°è
//

#include <stdio.h>
int arr[8];
int main(void)
{
	freopen("input2920.txt", "r", stdin);
	int i, ret = 0, cur = 0;
	for (i = 0; i < 8; ++i)
	{
		scanf("%d", &arr[i]);
		if (!i && (arr[i] != 1 && arr[i] != 8))
		{
			printf("mixed");
			break;
		}
		if (i > 0)
		{
			cur = arr[i] - arr[i - 1];
			if (cur == 1 || cur == -1) ret += cur;
			else
			{
				printf("mixed");
				break;
			}
		}
	}
	if (ret == 7) printf("ascending");
	else if (ret == -7) printf("descending");
	return 0;
}