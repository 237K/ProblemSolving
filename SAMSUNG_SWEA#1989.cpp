//
//	OS Windows
//	2019.02.20
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1989] <초심자의 회문 검사> (D2)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int T;
	int test_case;
	string Palindrome;
	string TC;
	bool Flag;
	freopen("s_input1989.txt", "r", stdin);
	getline(cin, TC);
	T = stoi(TC);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Flag = true;
		int cnt = 0;
		getline(cin, Palindrome);

		int Start = 0;
		int End = Palindrome.length() - 1;
		while (Start <= End)
		{
			if (Palindrome[Start] != Palindrome[End])
			{
				Flag = false;
				break;
			}
			else
			{
				Start++;
				End--;
			}
		}
		if (Flag)
			printf("#%d 1\n", test_case);
		else
			printf("#%d 0\n", test_case);
	}
	return 0;
}