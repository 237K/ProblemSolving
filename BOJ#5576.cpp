//
//	OS Windows
//	2019.08.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5576	콘테스트
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	freopen("input5576.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int i, j, w = 0, k = 0;
	vector<int> W(10), K(10);
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			if (!i) cin >> W[j];
			else cin >> K[j];
		}
	}
	sort(W.begin(), W.end());
	sort(K.begin(), K.end());
	for (i = 9; i >= 7; --i)
	{
		w += W[i];
		k += K[i];
	}
	cout << w << ' ' << k;
	return 0;
}