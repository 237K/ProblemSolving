//
//	OS Windows
//	2019.05.17
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2164	Ä«µå2
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
	freopen("input2164.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	register int i, last, temp;
	queue<int> Q;
	cin >> N;
	for (i = 1; i <= N; ++i) Q.push(i);
	while (1)
	{
		last = Q.front();
		Q.pop();
		if (Q.empty()) break;
		temp = Q.front();
		Q.pop();
		Q.push(temp);
	}
	cout << last;
	return 0;
}