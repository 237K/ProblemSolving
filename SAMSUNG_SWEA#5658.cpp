//
//	OS Windows
//	2019.04.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5658] <보물상자 비밀번호> (모의 SW 역량테스트)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;

const static int MAX = 28;
const static int MAX_NUM_LEN = 8;
static int N, K;

static void Transform10(string& str)
{
	vector<int> Numbers;
	const int num_len = N / 4;
	int start_idx = 0;
	for (int i = 1; i <= 4; ++i)
	{
		char ch_partial[MAX_NUM_LEN];
		string str_partial;
		str_partial = str.substr(start_idx, num_len);
		//cout << i + 1 << " " << str << "  " << num16[i] << endl;
		start_idx = num_len * i;

		strcpy(ch_partial, str_partial.c_str());
		int num10 = (int)strtol(ch_partial, NULL, 16);
	}
}

int main(int argc, char** argv)
{
	freopen("s_input5658.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		string input;
		cin >> input;
		cout << "#" << test_case << endl;
		Transform10(input);
		cout << endl;
	}


	return 0;
}