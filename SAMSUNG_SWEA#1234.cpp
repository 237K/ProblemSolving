//
//	OS Windows
//	2019.04.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#1234> 비밀번호 (D3)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
const static int T = 10;
static int N;
inline string password(string& in)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (register int i = 1 ; i <= N ; ++i)
		{
			if (in[i] == in[i-1])
			{
				in.erase(i-1, 2);
				N -= 2;
				flag = true;
			}
		}
	}
	return in;
}
int main(int argc, char** argv)
{
	freopen("s_input1234.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		string input;
		cin >> N >> input;
		cout << "#" << test_case << ' ' << password(input) << '\n';
	}
	return 0;
}