//
//	OS Windows
//	2019.05.17
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2161	Ä«µå1
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

inline void left_shift(int a[], int idx, int n)
{
	int temp = a[idx+1];
	for (register int i = idx; i < n - 1; ++i)
		a[i] = a[i + 2];
	a[n - 2] = temp;
}

int main(void)
{
	freopen("input2161.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	register int i, idx;
	int arr[1000];
	cin >> N;
	for (i = 0; i < N; ++i) arr[i] = i + 1;
	idx = 0;
	while (N > 1)
	{
		cout << arr[idx] << ' ';
		left_shift(arr, idx, N--);
	}
	cout << arr[0];
	return 0;
}