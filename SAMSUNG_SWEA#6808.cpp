//
//	OS Windows
//	2019.03.30
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6808] <규영이와 인영이의 카드게임> (D3)
//	
//	ver1. STL next_permutation으로 규영카드 조합해서 풀어봄 -> 결과가 1씩 잘못나옴

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const static int MAX = 19;

static bool CheckIN0Card[MAX];
static vector<int> IN0Card;
static vector<int> Gyu0Card;
static int Win;
static int Lose;

inline void CardClear()
{
	IN0Card.clear();
	Gyu0Card.clear();
	IN0Card.resize(9, 0);
	Gyu0Card.resize(9, 0);
	for (int i = 0; i < MAX; ++i)
	{
		CheckIN0Card[i] = false;
	}
	Win = 0;
	Lose = 0;
}
inline void Gyu0()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 1; j < 19; ++j)
		{
			if (!CheckIN0Card[j])
			{
				CheckIN0Card[j] = true;
				Gyu0Card[i] = j;
				break;
			}
		}
	}
}
inline void Game()
{
	while (next_permutation(Gyu0Card.begin(), Gyu0Card.end()))
	{
		int IN0Score = 0;
		int Gyu0Score = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (Gyu0Card[i] > IN0Card[i])
				Gyu0Score += Gyu0Card[i] + IN0Card[i];
			else if (Gyu0Card[i] < IN0Card[i])
				IN0Score += Gyu0Card[i] + IN0Card[i];
		}
		if (Gyu0Score < IN0Score)
			Win++;
	}
	Lose = 362880 - Win;
}
int main(int argc, char** argv)
{
	int T;
	int test_case;
	freopen("s_input6808.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		CardClear();
		for (int i = 0; i < 9; ++i)
		{
			int num;
			scanf("%d", &num);
			IN0Card[i] = num;
			CheckIN0Card[num] = true;
		}

		Gyu0();
		Game();
		printf("#%d %d %d\n", test_case, Win, Lose);
	}
	return 0;
}