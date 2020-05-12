//
//	OS Windows
//	2020.05.09
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1850> ABC정렬
//
#define _CRT_SECURE_NO_WARNINGS
#define SZ 4
int main(void)
{
	freopen("jinput1850.txt", "r", stdin);
	int n1, n2, n3, a, b, c;
	char order[SZ];
	scanf("%d %d %d", &n1, &n2, &n3);
	scanf("%s", &order);
	if (n1 > n2)
	{
		if (n1 > n3)
		{
			c = n1;
			if (n2 > n3)
			{
				b = n2;
				a = n3;
			}
			else
			{
				b = n3;
				a = n2;
			}
		}
		else
		{
			c = n3;
			b = n1;
			a = n2;
		}
	}
	else
	{
		if (n2 > n3)
		{
			c = n2;
			if (n1 > n3)
			{
				b = n1;
				a = n3;
			}
			else
			{
				b = n3;
				a = n1;
			}
		}
		else
		{
			c = n3;
			b = n2;
			a = n1;
		}
	}
	for (register int i = 0; i < 3; ++i)
	{
		if (order[i] == 'A') printf("%d ", a);
		else if (order[i] == 'B') printf("%d ", b);
		else printf("%d ", c);
	}
	return 0;
}