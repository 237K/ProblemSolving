//
//	OS Windows
//	2019.04.09
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#1952> (모의) 수영장
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
const static int YEAR = 13;
const static int INF = 2147000000;
static int plan[YEAR];
static int cal[YEAR];
static int check[YEAR];
static int price_day, price_one_month, price_three_month, price_year;
static int total_usage;
static int result;

inline void init()
{
	(void)memset(plan, 0, sizeof(plan));
	(void)memset(cal, 0, sizeof(cal));
	(void)memset(check, 0, sizeof(check));
	total_usage = 0;
}

inline int sum(int d, int om, int tm)
{
	return (d*price_day) + (om*price_one_month) + (tm*price_three_month);
}

inline void simulation(int i, int count, int day, int o_month, int t_month)
{
	if (i > YEAR)
		return;
	if (count == total_usage)
	{
		int temp = sum(day, o_month, t_month);
		result = min(result, temp);
		/*
		cout << "===========================\n";
		cout << "current month : " << i << '\n';
		cout << "count : " << count << '\n';
		cout << "day : " << day << '\n';
		cout << "one month : " << o_month << '\n';
		cout << "three month : " << t_month << '\n';
		cout << "**price : " << temp << '\n';
		cout << "===========================\n";
		*/

		(void)memcpy(plan, cal, sizeof(plan));
		(void)memset(check, 0, sizeof(check));
		return;
	}
	if (!plan[i])
		simulation(i + 1, count, day, o_month, t_month);
	else
	{
		//	세 달 이용권
		if (plan[i] && !check[i])
		{
			if (i < YEAR - 2)
			{
				int tp = 0, tpp = 0, tppp = 0;
				tp = plan[i];
				tpp = plan[i + 1];
				tppp = plan[i + 2];
				plan[i] = 0;
				plan[i + 1] = 0;
				plan[i + 2] = 0;
				check[i] = 1;
				check[i + 1] = 1;
				check[i + 2] = 1;
				simulation(i + 3, count + tp + tpp + tppp, day, o_month, t_month + 1);
				check[i] = 0;
				check[i + 1] = 0;
				check[i + 2] = 0;

			}
			else if (i < YEAR - 1)
			{
				int op = 0, opp = 0, oppp = 0;
				op = plan[i];
				opp = plan[i + 1];
				plan[i] = 0;
				plan[i + 1] = 0;
				check[i] = 1;
				check[i + 1] = 1;
				simulation(i + 2, count + op + opp, day, o_month, t_month + 1);
				check[i] = 0;
				check[i + 1] = 0;

			}
			else if (i < YEAR)
			{
				int ip = 0;
				ip = plan[i];
				plan[i] = 0;
				check[i] = 1;
				simulation(i + 1, count + ip, day, o_month, t_month + 1);
				check[i] = 0;
			}
		}
		//	한 달 이용권
		if (plan[i] && price_one_month < price_three_month && !check[i])
		{
			int temp_usage = plan[i];
			plan[i] = 0;
			check[i] = 1;
			simulation(i + 1, count + temp_usage, day, o_month + 1, t_month);
			check[i] = 0;
		}
		//	1일 이용권
		if (plan[i] && !check[i])
		{
			int temp_usage = plan[i];
			plan[i] = 0;
			check[i] = 1;
			simulation(i + 1, count + temp_usage, day + temp_usage, o_month, t_month);
			check[i] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	freopen("s_input1952.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> price_day >> price_one_month >> price_three_month >> price_year;
		for (register int i = 1; i < YEAR; ++i)
		{
			cin >> plan[i];
			cal[i] = plan[i];
			total_usage += plan[i];
			result = price_year;
		}
		simulation(1, 0, 0, 0, 0);
		cout << "#" << test_case << ' '<<result << '\n';
	}
	return 0;
}