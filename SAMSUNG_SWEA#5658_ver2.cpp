//
//	OS Windows
//	2019.05.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5658] <보물상자 비밀번호> (모의)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

inline void right_shift(string& str)
{
	int size = str.length();
	char temp = str[size - 1];
	for (register int i = size - 1; i > 0; --i)
		str[i] = str[i - 1];
	str[0] = temp;
}
inline void cut_and_paste(string& str, int l, vector<int>& v)
{
	string str_temp;
	char ch_temp[8] = { NULL, };
	char *pEnd;
	int int_temp;
	for (register int i = 0; i < 4; ++i)
	{
		str_temp = str.substr(i*l, l);
		strcpy(ch_temp, str_temp.c_str());
		int_temp = (int)strtol(ch_temp, &pEnd, 16);
		v.push_back(int_temp);
	}
}
int main(int argc, char** argv)
{
	freopen("s_input5658.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int test_case, n;
	int N, K;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		int len = N / 4;
		string input;
		vector<int> v;
		cin >> input;
		cut_and_paste(input, len, v);
		for (n = 0; n < len-1; ++n)
		{
			right_shift(input);
			cut_and_paste(input, len, v);
		}
		sort(v.begin(), v.end(), greater<int>());
		v.erase(unique(v.begin(), v.end()), v.end());
		cout << "#" << test_case << ' ' << v[K - 1] << '\n';
	}
	return 0;
}