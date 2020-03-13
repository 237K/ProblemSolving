//
//	OS Windows
//	2020.03.05
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1241> 시간 카드
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> HM;
const static int SZ = 146;
static HM cow[SZ], start[SZ], stop[SZ];
static int N, M;
inline void init()
{
	for (register int i = 1; i <= N; ++i)
		cow[i] = { 0, 0 };
}
inline HM cal(int start_hour, int start_min, int stop_hour, int stop_min)
{
	HM ret;
	if (start_min > stop_min)
	{
		stop_hour--;
		stop_min += 60;
	}
	ret.second = stop_min - start_min;
	ret.first = stop_hour - start_hour;
	return ret;
}
int main(int argc, char** argv)
{
	freopen("jinput1241.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int m, num, hour, min;
	string str;
	HM cur;
	init();
	for (m = 0; m < M; ++m)
	{
		cin >> num >> str >> hour >> min;
		if (str == "START")
		{
			start[num] = { hour, min };
		}
		else
		{
			cur = cal(start[num].first, start[num].second, hour, min);
			cow[num].first += cur.first;
			cow[num].second += cur.second;
			if (cow[num].second > 59)
			{
				cow[num].first++;
				cow[num].second -= 60;
			}
		}
	}
	for (m = 1; m <= N; ++m)
	{
		cout << cow[m].first << ' ' << cow[m].second << '\n';
	}
	return 0;
}