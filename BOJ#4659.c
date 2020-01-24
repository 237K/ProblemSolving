//
//	OS Windows
//	2019.11.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #4659	비밀번호 발음하기
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 21
int main(void)
{
	freopen("input4659.txt", "r", stdin);
	char pw[MAX];
	int flag_aeiou, flag_con, flag_con_a, flag_con_b, flag_double;
	register int i;
	while (1)
	{
		pw[0] = '/0';
		flag_aeiou = flag_con = flag_con_a = flag_con_b = flag_double = 0;
		scanf("%s", &pw);
		if (pw[0] == 'e' && pw[1] == 'n' && pw[2] == 'd') break;
		for (i = 0; pw[i]; ++i)
		{
			if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u')
			{
				flag_aeiou = 1;
				if (flag_con_b > 2)
				{
					flag_con = 1;
				}
				flag_con_b = 0;
				flag_con_a++;
			}
			else
			{
				if (flag_con_a > 2)
				{
					flag_con = 1;
				}
				flag_con_a = 0;
				flag_con_b++;
			}
			if (i > 0)
			{
				if (pw[i] == pw[i - 1])
				{
					if (pw[i] == 'e' || pw[i] == 'o') continue;
					else flag_double = 1;
				}
			}
		}
		if (flag_con_a > 2 || flag_con_b > 2) flag_con = 1;
		if (flag_aeiou && !flag_con && !flag_double) printf("<%s> is acceptable.\n", pw);
		else printf("<%s> is not acceptable.\n", pw);
	}
	return 0;
}