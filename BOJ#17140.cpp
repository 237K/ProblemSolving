//
//	OS Windows
//	2019.10.19
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17140	이차원 배열과 연산
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const static int MAX = 101;
static vector<int> A[MAX];
static int R, C, K, row, col;
static int check[MAX];
priority_queue<pii, vector<pii>, greater<pii>> PQ;
inline void print()
{
	cout << "===================================\n\n";
	register int r, c;
	for (r = 0; r < row; ++r)
	{
		for (c = 0; c < col; ++c)
		{
			cout << A[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << "===================================\n\n";
}
inline void opR()
{
	register int r, c, num, idx;
	for (r = 0; r < row; ++r)
	{
		while (!PQ.empty()) { PQ.pop(); }
		(void)memset(check, 0, sizeof(check));
		sort(A[r].begin(), A[r].begin() + col);
		for (c = 0; c < col; ++c)
		{
			if (!A[r][c]) continue;
			check[A[r][c]]++;
		}
		for (c = 0; c < col; ++c)
		{
			if (!A[r][c] || !check[A[r][c]]) continue;
			PQ.push({ check[A[r][c]], A[r][c] });
			check[A[r][c]] = 0;
		}
		num = PQ.size() * 2;
		if (col < num) col = num;
		idx = 0;
		while (!PQ.empty())
		{
			pii cur = PQ.top();
			PQ.pop();
			if (idx > 100) break;
			A[r][idx++] = cur.second;
			A[r][idx++] = cur.first;
		}
		if (idx <= col)
		{
			while (idx <= col)
			{
				A[r][idx++] = 0;
			}
		}
	}
}
inline void opC()
{
	register int r, c, num, idx;
	vector<int> v;
	for (c = 0; c < col; ++c)
	{
		while (!PQ.empty()) { PQ.pop(); }
		(void)memset(check, 0, sizeof(check));
		v.resize(row, 0);
		for (r = 0; r < row; ++r)
		{
			v[r] = A[r][c];
		}
		sort(v.begin(), v.end());
		for (r = 0; r < row; ++r)
		{
			if (!v[r]) continue;
			check[v[r]]++;
		}
		for (r = 0; r < row; ++r)
		{
			if (!v[r] || !check[v[r]]) continue;
			PQ.push({ check[v[r]], v[r] });
			check[v[r]] = 0;
		}
		num = PQ.size() * 2;
		if (row < num) row = num;
		idx = 0;
		while (!PQ.empty())
		{
			pii cur = PQ.top();
			PQ.pop();
			if (idx > 100) break;
			A[idx++][c] = cur.second;
			A[idx++][c] = cur.first;
		}
		if (idx <= row)
		{
			while (idx <= row)
			{
				A[idx++][c] = 0;
			}
		}
	}
}
inline int simul()
{
	register int tik = 0;
	while (1)
	{
		//print();
		if (row >= R && col >= C)
		{
			if (A[R][C] == K) break;
		}
		if ((++tik) > 100)
		{
			tik = -1;
			break;
		}
		if (row >= col) opR();
		else opC();
	}
	return tik;
}
int main(int argc, char** argv)
{
	freopen("input17140.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int r, c, init;
	cin >> R >> C >> K;
	R--; C--;
	row = col = 3;
	for (init = 0; init < MAX; ++init) A[init].resize(MAX, 0);
	for (r = 0; r < 3; ++r)
	{
		for (c = 0; c < 3; ++c)
		{
			cin >> A[r][c];
		}
	}
	cout << simul();
	return 0;
}