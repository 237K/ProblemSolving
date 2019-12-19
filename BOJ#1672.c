//
//	OS Windows
//	2019.12.10
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션]	<BOJ #1672>	DNA 해독
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 1000001
char table[4][4] = { {'A', 'C', 'A', 'G'},
					 {'C', 'G', 'T', 'A'},
					 {'A', 'T', 'C', 'G'},
					 {'G', 'A', 'G', 'T'} };
char arr[SZ];
int chartoint(char ch)
{
	if (ch == 'A') return 0;
	else if (ch == 'G') return 1;
	else if (ch == 'C') return 2;
	else return 3;
}
char inttochar(int i)
{
	if (!i) return 'A';
	else if (i == 1) return 'G';
	else if (i == 2) return 'C';
	else return 'T';
}
void cal(char ch1, char ch2, int idx)
{
	int n1, n2;
	n1 = chartoint(ch1);
	n2 = chartoint(ch2);
	arr[idx] = table[n1][n2];
}
int N;
int main(void)
{
	freopen("input1672.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%s", &arr);
	register int n;
	for (n = N - 1; n > 0; --n)
	{
		cal(arr[n], arr[n - 1], n-1);
	}
	printf("%c", arr[0]);
	return 0;
}