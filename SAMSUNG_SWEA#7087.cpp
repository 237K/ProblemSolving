//
//	OS Windows
//	2019.02.22
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7087] <문제 제목 붙이기> (D3)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void Comp(char s[], bool _Flag[], int Length);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	string Input;
	char FrontChar[101];
	bool Flag[26];
	freopen("s_input7087.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		for (int in = 0; in < N; ++in)
		{
			Input.clear();
			for (int init = 0; init < 26; ++init)
				Flag[init] = false;

			cin >> Input;
			string temp;
			temp = Input.substr(0, 1);
			FrontChar[in] = temp[0];
		}
		Comp(FrontChar, Flag, N);
		int Idx = 0;
		int Count = 0;
		while (1)
		{
			if (!Flag[Idx])
				break;
			else
			{
				Idx++;
				Count++;
			}
		}
		printf("#%d %d\n", test_case, Count);
	}
	return 0;
}

void Comp(char s[], bool _Flag[], int Length)
{
	for (int i = 0; i < Length; ++i)
	{
		if (s[i] == 'A')
			_Flag[0] = true;
		if (s[i] == 'B')
			_Flag[1] = true;
		if (s[i] == 'C')
			_Flag[2] = true;
		if (s[i] == 'D')
			_Flag[3] = true;
		if (s[i] == 'E')
			_Flag[4] = true;
		if (s[i] == 'F')
			_Flag[5] = true;
		if (s[i] == 'G')
			_Flag[6] = true;
		if (s[i] == 'H')
			_Flag[7] = true;
		if (s[i] == 'I')
			_Flag[8] = true;
		if (s[i] == 'J')
			_Flag[9] = true;
		if (s[i] == 'K')
			_Flag[10] = true;
		if (s[i] == 'L')
			_Flag[11] = true;
		if (s[i] == 'M')
			_Flag[12] = true;
		if (s[i] == 'N')
			_Flag[13] = true;
		if (s[i] == 'O')
			_Flag[14] = true;
		if (s[i] == 'P')
			_Flag[15] = true;
		if (s[i] == 'Q')
			_Flag[16] = true;
		if (s[i] == 'R')
			_Flag[17] = true;
		if (s[i] == 'S')
			_Flag[18] = true;
		if (s[i] == 'T')
			_Flag[19] = true;
		if (s[i] == 'U')
			_Flag[20] = true;
		if (s[i] == 'V')
			_Flag[21] = true;
		if (s[i] == 'W')
			_Flag[22] = true;
		if (s[i] == 'X')
			_Flag[23] = true;
		if (s[i] == 'Y')
			_Flag[24] = true;
		if (s[i] == 'Z')
			_Flag[25] = true;
	}
}