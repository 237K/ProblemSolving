//
//	OS Windows
//	2019.05.03
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1062	°¡¸£Ä§
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
static int N, K;
static int sentence[50][26];
static int result;
inline int check(int mask)
{
	int cnt = 0;
	for (register int n = 0; n < N; ++n)
	{
		bool flag = true;
		for (register int i = 0; i < 26; ++i)
		{
			if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19)
				continue;
			if ((mask & (sentence[n][1 << i])) == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	return cnt;
}
inline void learn(int word, int k, int mask)
{
	if (word == K)
	{
		int temp = check(mask);
		if (result < temp) result = temp;
		return;
	}
	if (k < 0) return;

	learn(word + 1, k - 1, mask | (1 << word));
	learn(word + 1, k, mask);
}
int main(int argc, char** argv)
{
	freopen("input1062.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	string str;
	result = 0;
	for (register int n = 0; n < N; ++n)
	{
		cin >> str;
		int len = str.length();
		for (register int l = 0; l < len; ++l)
			sentence[n][str[l]-'a'] = 1;
		learn(0, K, 0);
	}
	cout << result;
	return 0;
}