//
//	OS Windows
//	2019.04.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7193] <승현이의 수학공부> (D3)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, char** argv)
{
	freopen("s_input7193.txt", "r", stdin);
	int T;
	register int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		string X;
		cin >> N >> X;
		int X_size = X.length();
		char X_char[X_size+1];
		char *p_end;
		strcpy(X_char, X, c_str());
		int transform = (int)strtol(X_char, &p_end, N);
		printf("#%d %d\n", test_case, transform % N);
	}
}