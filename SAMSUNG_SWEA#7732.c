//
//	OS Windows
//	2019.05.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7732] <½Ã°£ °³³ä> (D3)
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int char_to_int(char c1, char c2)
{
	int f, s;
	f = c1 - '0'; s = c2 - '0';
	return f * 10 + s;
}
int main(void)
{
	freopen("s_input7732.txt", "r", stdin);
	int T, tc;
	char c_time[9], t_time[9];
	scanf("%d\n", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%s\n%s", &c_time, &t_time);
		register int ch, cm, cs, th, tm, ts, h, m, s;
		ch = char_to_int(c_time[0], c_time[1]);
		cm = char_to_int(c_time[3], c_time[4]);
		cs = char_to_int(c_time[6], c_time[7]);
		th = char_to_int(t_time[0], t_time[1]);
		tm = char_to_int(t_time[3], t_time[4]);
		ts = char_to_int(t_time[6], t_time[7]);
		s = ts - cs; if (s < 0) s += 60, tm -= 1;
		m = tm - cm; if (m < 0) m += 60, th -= 1;
		h = th - ch; if (h < 0) h += 24;
		printf("#%d %02d:%02d:%02d\n", tc, h, m, s);
	}
	return 0;
}