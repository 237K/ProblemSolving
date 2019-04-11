//
//	OS Windows
//	2019.04.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2529	∫ŒµÓ»£
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const static int N = 10;
const static int INF = 2147000000;
static int number[N];
static char symbol[N];
static int K;
static int max_value;
static int min_value;
static string max_str;
static string min_str;
inline void print_vector(vector<int> v)
{
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ' ';
	cout << "\n\n";
}
inline bool int_symbol_int(int left, char s, int right)
{
	if (s == '<')
		return left < right;
	else if (s == '>')
		return left > right;
}
inline bool correct_check(vector<int> v)
{
	int len = v.size();
	for (int n = 0 ; n < K ; ++n)
	{
		if (!(int_symbol_int(v[n], symbol[n], v[n + 1])))
			return false;
	}
	return true;
}
inline string to_str(vector<int> v)
{
	string str;
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		str.push_back(*iter + '0');
	}
	return str;
}
inline int to_number(vector<int> v)
{
	int idx = 0;
	int len = v.size();
	int num = 0;
	while (idx < len)
	{
		num *= 10;
		num += v[idx];
		idx++;
	}
	return num;
}
inline void recur(int count, vector<int>& v)
{
	if (count == K + 1)
	{
		print_vector(v);
		if (correct_check(v))
		{
			int temp = to_number(v);
			if (max_value < temp)
			{
				max_value = temp;
				max_str = to_str(v);
			}
			if (min_value > temp)
			{
				min_value = temp;
				min_str = to_str(v);
			}
		}
		return;
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			if (number[i])
				continue;
			else
			{
				if (!count || int_symbol_int(v[count - 1], symbol[count - 1], i))
				{
					number[i] = 1;
					v.push_back(i);
					recur(count + 1, v);
					number[i] = 0;
					v.pop_back();
				}
			}
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input2529.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	(void)memset(number, 0, sizeof(number));
	max_value = -INF;
	min_value = INF;
	cin >> K;
	for (register int i = 0; i < K; ++i)
		cin >> symbol[i];
	vector<int> v;
	recur(0, v);
	cout << max_str << '\n' << min_str << '\n';
	return 0;
}
