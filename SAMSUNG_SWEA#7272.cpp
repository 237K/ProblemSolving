//
//	OS Windows
//	2019.03.20
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7272] <안경이 없어> (D3)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int Check(const char& ch)
{
	switch (ch)
	{
	case 'A':
	case 'D':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
		return 1;
		break;
	case 'B':
		return 3;
		break;
	default:
		return 2;
		break;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("s_input7272.txt", "r", stdin);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str1, str2;
		int str1_length = 0, str2_length = 0;

		cin >> str1 >> str2;
		str1_length = str1.length();
		str2_length = str2.length();

		if (str1_length != str2_length)
		{
			cout << "#" << test_case << " DIFF\n";
			continue;
		}
		else
		{
			bool diff = true;

			for (int i = 0; i < str1_length; ++i)
			{
				str1[i] = Check(str1[i]);
				str2[i] = Check(str2[i]);

				if (str1[i] != str2[i])
				{
					diff = false;
					break;
				}
			}
			if (diff)
				cout << "#" << test_case << " SAME\n";
			else
				cout << "#" << test_case << " DIFF\n";
		}
	}
	return 0;
}