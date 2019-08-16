//
//	OS Windows
//	2019.08.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2822	점수 계산
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[9], ret[5];
	vector<int> sorted(8);
	register int i, idx = 0, pivot, sum = 0;
	for (i = 1; i <= 8; ++i)
	{
		cin >> arr[i];
		sorted[i - 1] = arr[i];
	}
	sort(sorted.begin(), sorted.end(), greater<int>());
	pivot = sorted[5];
	for (i = 1; i <= 8; ++i)
	{
		if (arr[i] > pivot)
		{
			ret[idx++] = i;
			sum += arr[i];
		}
	}
	cout << sum << '\n';
	for (i = 0; i < 5; ++i) cout << ret[i] << ' ';
	return 0;
}