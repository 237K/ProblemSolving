//
//	OS Windows
//	2020.01.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#8931> (D3) Á¦·Î
//
#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <iostream>
using namespace std;
static stack<int> ST;
int main(int argc, char** argv)
{
	freopen("s_input8931.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, tc, K, k, input, ret;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		while (!ST.empty()) { ST.pop(); }
		ret = 0;
		cin >> K;
		for (k = 0; k < K; ++k)
		{
			cin >> input;
			if (input) ST.push(input);
			else ST.pop();
		}
		while (!ST.empty())
		{
			ret += ST.top();
			ST.pop();
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}