//
//	OS Windows
//	2019.03.15
//
//	[Algorithm Problem Solving]
//
//	<도어락 비밀번호>
//		1. 입력된 번호 중 지정된 비밀번호 숫자가 포함되어 있으면 문을 열어줌
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class Doorlock
{
private:
	string PW;
public:
	Doorlock(string pw) : PW(pw) {}
	bool Comp(const string& in)
	{
		bool check = false;
		int L = in.length();
		for (int i = 0; i < L; ++i)
		{
			if (PW[0] == in[i])
			{
				int cnt = 0;
				for (int j = 1; j < 4; ++j)
				{
					if (PW[j] != in[i + j])
					{
						j = 4;
						continue;
					}
					else
						cnt = j;
				}
				if (cnt == 3)
				{
					check = true;
					return check;
				}
			}
		}
		return false;
	}
};

int main(int argc, char** argv)
{
	int T;
	int test_case;
	string pw;
	freopen("testcase_Doorlock.txt", "r", stdin);
	scanf("%d\n", &T);
	getline(cin, pw);
	Doorlock dl(pw);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string in;
		getline(cin, in);
		if (dl.Comp(in))
			printf("#%d 1\n", test_case);
		else
			printf("#%d 0\n", test_case);
	}

	return 0;
}