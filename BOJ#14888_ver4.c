//
//	OS Windows
//	2019.08.05
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14888	연산자 끼워넣기
//
//	ver.4
//	

#include <stdio.h>
int num[12];
char fix[11];
int N, plus, minus, mul, div, max_value, min_value;
void print()
{
	register int i;
	printf("%d", num[0]);
	for (i = 1; i < N; ++i) printf(" %d %c ", num[i], fix[i - 1]);
}
int operation(int left, char op, int right)
{
	if (op == '+') return left + right;
	else if (op == '-') return left - right;
	else if (op == '*') return left * right;
	else return left / right;
}
int cal()
{
	register int i, ac = 0;
	ac = num[0];
	for (i = 1; i < N; ++i) ac = operation(ac, fix[i-1], num[i]);
	return ac;
}
void simul(int cnt, int plus, int minus, int mul, int div)
{
	if (cnt == N - 1)
	{
		print();
		int tmp = cal();
		if (max_value < tmp) max_value = tmp;
		if (min_value > tmp) min_value = tmp;
		return;
	}
	if (plus >= 1)
	{
		fix[cnt] = '+';
		simul(cnt + 1, plus - 1, minus, mul, div);
	}
	if (minus >= 1)
	{
		fix[cnt] = '-';
		simul(cnt + 1, plus, minus - 1, mul, div);
	}
	if (mul >= 1)
	{
		fix[cnt] = '*';
		simul(cnt + 1, plus, minus, mul - 1, div);
	}
	if (div >= 1)
	{
		fix[cnt] = '/';
		simul(cnt + 1, plus, minus, mul, div - 1);
	}
}
int main(void)
{
	freopen("input14888.txt", "r", stdin);
	register int i, j;
	max_value = 0; min_value = 2147000000;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) scanf("%d", &num[i]);
	scanf("%d %d %d %d", &plus, &minus, &mul, &div);
	simul(0, plus, minus, mul, div);
	return 0;
}