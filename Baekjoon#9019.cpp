//
//	OS Windows
//	2019.04.10
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #9019	DSLR
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include <memory.h>
#include <string>
using namespace std;

typedef pair<int, int> pii;

const static int MAX = 10000;

static queue<pii> Q;
static stack<char> S;
static int check[MAX];
static int route[MAX];
static char dslr[MAX];
static int A, B;

inline void init()
{
	while (!Q.empty()) { Q.pop(); }
	(void)memset(check, 0, sizeof(check));
	(void)memset(route, 0, sizeof(route));
}
inline int Double(int n)
{
	return (n * 2) % MAX;
}
inline int Sub(int n)
{
	int temp = 0;
	if (!n)
		temp = MAX - 1;
	else
		temp = n - 1;
	return temp;
}
inline int left_shift(int n)
{
	int number[4];
	int idx = 3;
	//	분해
	while (idx > 0)
	{
		number[idx--] = n % 10;
		n /= 10;
		if (!idx)
			number[idx] = n;
	}
	//	left shift
	int temp_left = number[0];
	for (register int i = 0; i < 3; ++i)
	{
		number[i] = number[i + 1];
	}
	number[3] = temp_left;
	//	조립
	int temp_number = 0;
	idx = 0;
	while (idx < 3)
	{
		temp_number = temp_number * 10 + number[idx++];
		if (idx == 3)
			temp_number = temp_number*10 + number[idx];
	}
	return temp_number;
}
inline int right_shift(int n)
{
	int number[4];
	int idx = 3;
	//	분해
	while (idx > 0)
	{
		number[idx--] = n % 10;
		n /= 10;
		if (!idx)
			number[idx] = n;
	}
	//	right shift
	int temp_right = number[3];
	for (register int i = 2; i >= 0; --i)
	{
		number[i+1] = number[i];
	}
	number[0] = temp_right;
	//	조립
	int temp_number = 0;
	idx = 0;
	while (idx < 3)
	{
		temp_number = temp_number * 10 + number[idx++];
		if (idx == 3)
			temp_number = temp_number * 10 + number[idx];
	}
	return temp_number;
}
inline void bfs()
{
	Q.push({ A, 0 });
	check[A] = 1;
	while (!Q.empty())
	{
		pii cur = Q.front();
		Q.pop();
		if (cur.first == B)
		{
			string how_to_make = "";
			while (1)
			{
				how_to_make += dslr[B];
				B = route[B];
			}
			reverse(how_to_make.begin(), how_to_make.end());
			cout << how_to_make << '\n';
		}
		if (!(check[Double(A)]))
		{
			check[Double(A)] = 1;
			route[Double(A)] = cur.first;
			dslr[Double(A)] = 'D';
			Q.push({ Double(A), cur.second + 1 });
		}
		if (!(check[Sub(A)]))
		{
			check[Sub(A)] = 1;
			route[Sub(A)] = cur.first;
			dslr[Sub(A)] = 'S';
			Q.push({ Sub(A), cur.second + 1 });
		}
		if (!(check[left_shift(A)]))
		{
			check[left_shift(A)] = 1;
			route[left_shift(A)] = cur.first;
			dslr[left_shift(A)] = 'L';
			Q.push({ left_shift(A), cur.second + 1 });
		}
		if (!(check[right_shift(A)]))
		{
			check[right_shift(A)] = 1;
			route[right_shift(A)] = cur.first;
			dslr[right_shift(A)] = 'R';
			Q.push({ right_shift(A), cur.second + 1 });
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input9019.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> A >> B;
		bfs();
	}
	return 0;
}