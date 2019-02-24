//
//  OS Windows
//  2019.02.24
//
//  [Algorithm Problem Solving]
//
//  <팰린드롬 찾기>
//
//	주어지는 문자열에서 팰린드롬 개수 출력
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool Palindrome(const string& s, int start, int end)
{
	while (start <= end)
	{
		if (s[start] != s[end])
		{
			return false;
		}
		else
		{
			start++;
			end--;
		}
	}
	return true;
}


int main(int argc, char** argv)
{
	int T;
	int test_case;
	int Length;
	string TC;
	string Input;
	int Count;
	freopen("testcase_Palindrome.txt", "r", stdin);
	getline(cin, TC);
	T = stoi(TC);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Count = 0;
		Input.clear();

		getline(cin, Input);
		Length = Input.length();
	
		printf("#%d ", test_case);
		for (int l = 3; l <= Length; ++l)
		{
			for (int i = 0; i < Length - l + 1; ++i)
			{
					string temp = Input.substr(i, l);
					if (Palindrome(temp, 0, l-1))
					{
						cout << temp<<' ';
						Count++;
					}
			}
		}
		printf("Count : %d\n", Count);
	}
	return 0;
}