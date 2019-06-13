//
//	OS Windows
//	2019.06.11
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10815	숫자 카드
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static vector<int> find_card;
static vector<int> card_deck;
static int N, M;

inline bool binary_search(int n, int left, int right)
{
	if (card_deck[left] == n || card_deck[right] == n) return true;
	int mid = (left + right) / 2;
	if (card_deck[mid] == n) return true;
	if (mid == left || mid == right) return false;
	if (card_deck[mid] > n) return binary_search(n, left, mid);
	else return binary_search(n, mid, right);
}
inline void print()
{
	for (register int i = 0; i < M; ++i)
		cout << find_card[i] << ' ';
}
inline void find()
{
	sort(card_deck.begin(), card_deck.end());
	for (register int i = 0; i < M; ++i)
	{
		if (binary_search(find_card[i], 0, N - 1)) find_card[i] = 1;
		else find_card[i] = 0;
	}
	print();
}

int main(int argc, char** argv)
{
	freopen("input10815.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int i;
	cin >> N;
	card_deck.resize(N, 0);
	for (i = 0; i < N; ++i) cin >> card_deck[i];
	cin >> M;
	find_card.resize(M, 0);
	for (i = 0; i < M; ++i) cin >> find_card[i];
	find();
	return 0;
}