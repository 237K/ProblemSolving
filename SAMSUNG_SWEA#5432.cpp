//
//	OS Windows
//	2019.05.26
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5432] <쇠막대기 자르기> (D4)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
	freopen("s_input5432.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, tc, razer, stick;
	string input;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		input.clear();
		razer = stick = 0;
		cin >> input;
		for (string::iterator i = input.begin(); i != input.end(); ++i)
		{
			if (*i == '(')
			{
				if (*(i + 1) == ')')
				{
					stick += razer;
					i++;
					continue;
				}
				else
				{
					razer++;
					stick++;
					continue;
				}
			}
			else
			{
				razer--;
			}
		}
		cout << "#" << tc << ' ' << stick << '\n';
	}
	return 0;
}