//
//	OS Windows
//	2019.12.09
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö]	<BOJ #1408>	24
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int start_h, end_h, start_m, end_m, start_s, end_s, h, m, s;
char start[9], end[9], hour[3], min[3], sec[3];
int toint(char first, char second)
{
	return (first-'0') * 10 + (second-'0');
}
int main(void)
{
	freopen("input1408.txt", "r", stdin);
	scanf("%s\n%s", &start, &end);
	start_h = toint(start[0], start[1]);
	start_m = toint(start[3], start[4]);
	start_s = toint(start[6], start[7]);
	end_h = toint(end[0], end[1]);
	end_m = toint(end[3], end[4]);
	end_s = toint(end[6], end[7]);
	s = end_s - start_s;
	if (s < 0)
	{
		if (!end_m)
		{
			end_h--;
			end_m = 60;
		}
		end_m--;
		s += 60;
	}
	m = end_m - start_m;
	if (m < 0)
	{
		if (!end_h) end_h = 24;
		end_h--;
		m += 60;
	}
	h = end_h - start_h;
	hour[0] = (h / 10) + '0';
	hour[1] = (h % 10) + '0';
	min[0] = (m / 10) + '0';
	min[1] = (m % 10) + '0';
	sec[0] = (s / 10) + '0';
	sec[1] = (s % 10) + '0';
	printf("%s:%s:%s", hour, min, sec);
	return 0;
}