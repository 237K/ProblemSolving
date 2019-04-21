//
//	OS Windows
//	2019.04.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#7510> (D3) 상원이의 연속 합
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

int main(int argc, char** argv)
{
	freopen("s_input7510.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		int N = 0, cnt = 1;
		cin >> N;
		if (N > 2)
		{
			for (register int n = 1; n <= N / 2 + 1; ++n)
			{
				int sum = 0;
				for (register int d = n; d <= N / 2 + 1; ++d)
				{
					sum += d;
					if (sum > N)
						break;
					else if (sum == N)
						cnt++;
				}
			}
		}
		cout << "#" << test_case << ' ' << cnt << '\n';
	}
	return 0;
}