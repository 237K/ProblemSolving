//
//	OS Windows
//	2019.04.30
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1284] <수도 요금 경쟁> (D2)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	freopen("s_input1284.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int test_case;
	int P, Q, R, S, W;
	int A_cost, B_cost, result;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 0;
		cin >> P >> Q >> R >> S >> W;
		A_cost = P * W;
		if (W - R <= 0)	B_cost = Q;
		else if(W - R > 0)	B_cost = Q + S * (W - R);
		if (A_cost >= B_cost)	result = B_cost;
		else result = A_cost;
		cout << "#" << test_case << ' ' << result << '\n';
	}
	return 0;
}