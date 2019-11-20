//
//	OS Windows
//	2019.11.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2997	네 번째 수
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	freopen("input2997.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v(3);
	register int i, d, gap1, gap2;
	for (i = 0; i < 3; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	gap1 = v[1] - v[0];
	gap2 = v[2] - v[1];
	if (gap1 > gap2)
	{
		d = v[0] + gap2;
	}
	else if (gap1 < gap2)
	{
		d = v[1] + gap1;
	}
	else d = v[2] + gap1;
	cout << d;
	return 0;
}