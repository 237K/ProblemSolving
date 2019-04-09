//
//	OS Windows
//	2019.04.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1107	채널이동
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
const static int BUTTON = 12;
const static int INF = 2147000000;
const static int MAX = 1000000;
static int base_channel = 100;
static int target_channel;
static int button[BUTTON];
static int E;
static int result;

inline int error_check(int c)
{
	int length = 0;
	if (!c)
	{
		if (button[0])
			return 0;
		else
			return 1;
	}
	while (c)
	{
		length++;
		int remainder = c % 10;
		if (button[remainder])
			return 0;
		else
			c /= 10;
	}
	return length;
}

inline void find_channel()
{
	result = min(result, abs(target_channel - base_channel));
	for (register int i = 0; i < MAX; ++i)
	{
		int length = error_check(i);
		if (length)
			result = min(result, length + abs(target_channel - i));
	}
}

int main(int argc, char** argv)
{
	freopen("input1107.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	result = INF;
	(void)memset(button, 0, sizeof(button));
	cin >> target_channel;
	cin >> E;
	for (register int e = 0; e < E; ++e)
	{
		int error_button;
		cin >> error_button;
		button[error_button] = 1;
	}
	find_channel();
	cout << result << '\n';
	return 0;
}