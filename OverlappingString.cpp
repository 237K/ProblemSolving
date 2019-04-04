//
//	OS Windows
//	2019.04.04
//
//	[Algorithm Problem Solving]
//
//	<�ߺ����ڿ� ó��>
//
//	1. ���ع��ڿ��� �񱳹��ڿ��� ���ؼ� ���� ���ڿ��� ã��, �ش� ���ڿ��� ���� ���ڿ��� ������ ���
//	2. ���� ���ڿ��� co, com�ΰ�� com �ϳ��� ħ
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

static string base_str;
static int base_str_length;
static int check[101][101];
static int overlap_num;

inline void clear()
{
	(void)memset(check, 0, sizeof(check));
	overlap_num = 0;
}

inline void result(string& s, int len)
{
	for (register int c = 2; c <= len; ++c)
	{
		for (register int r = 0; r < len; ++r)
		{
			if (check[r][c] == 1)
			{
				cout << s.substr(r, c) << ' ';
				overlap_num++;
			}
		}
	}
	cout << overlap_num << '\n';
}

inline void check_under_len(int index, int len)
{
	if (len == 2)
		return;
	else
	{
		for (register int l = len - 1; l >= 2; --l)
		{
			for (register int i = index; i <= index + len - l; ++i)
			{
				check[i][l] = -1;
			}
		}
	}
}

inline void Test(string& s)
{
	int s_length = s.length();
	
	for (register int l = s_length; l >= 2; --l)
	{
		for (register int i = 0; i <= s_length - l; ++i)
		{
			if (!check[i][l])
			{
				string temp_str = s.substr(i, l);

				if (base_str.find(temp_str) != string::npos)
				{
					check[i][l] = 1;
					check_under_len(i, l);
				}
			}
		}
	}
	result(s, s_length);
}

int main(int argc, char** argv)
{
	freopen("testcase_OverlappingString.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	cin >> base_str;
	base_str_length = base_str.length();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		clear();
		string str;
		cin >> str;
		cout << "#" << test_case << ' '; Test(str);
	}

	return 0;
}