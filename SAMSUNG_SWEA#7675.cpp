//
//	OS Windows
//	2019.04.13
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7675] <통역사 성경이> (D3)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
const static int MAX_LEN = 1000;
const static int MAX_SENTENCE = 5;

static string str[MAX_SENTENCE][MAX_LEN];
static int num_word[MAX_SENTENCE];

inline int check(string& s)
{
	char fnt = s.front();
	char rear = s.back();
	int len = s.length();
	if (fnt >= 'A' && fnt <= 'Z')
	{
		if (len == 1) return 1;
		for (register int i = 1; i < len; ++i)
		{
			if (s[i] == '.' || s[i] == '?' || s[i] == '!')
				continue;
			if (s[i] < 'a' || s[i] > 'z' || (s[i] >= '0' && s[i] <= '9'))
				return 0;
		}
	}
	else
		return 0;

	return 1;
}

int main(int argc, char** argv)
{
	freopen("s_input7675.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int test_case, n, s, w;
	int N;
	string input;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (n = 0; n < N; ++n)
		{
			int idx = 0;
			while (1)
			{
				cin >> input;
				str[n][idx++] = input;
				if (input.back() == '.' || input.back() == '?' || input.back() == '!')
					break;
			}
			num_word[n] = idx;
		}
		cout << "#" << test_case << ' ';
		for (s = 0; s < N; ++s)
		{
			int cnt = 0;
			for (w = 0; w < num_word[s]; ++w)
			{
				cnt += check(str[s][w]);
			}
			cout << cnt << ' ';
		}
		cout << '\n';
	}
	return 0;
}