//
//	OS Windows
//	2019.07.03
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1222] (D4) °è»ê±â1
//

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	register int tc, i, sum;
	string input;
	for (tc = 1; tc <= 10; ++tc)
	{
		sum = 0;
		cin >> N;
		cin >> input;
		for (i = 0; i < N; i += 2) sum += input[i] - '0';
		cout << "#" << tc << ' ' << sum << '\n';
	}
	return 0;
}