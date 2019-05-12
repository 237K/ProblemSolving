//
//	OS Windows
//	2019.04.04
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6808] <�Կ��̿� �ο����� ī�����> (D3)
//	
//	ver2. ��ͷ� Ǯ�
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

const static int MAX = 19;
const static int IRREVERSIBLE_SCORE = 171 / 2;		//	����� ������ �� ���� ����

static bool Deck[MAX];
static int In0Card[MAX / 2];
static int Gyu0Card[MAX / 2];
static int Win, Lose;

inline void Play(int game, int gyu0score, int in0score)
{
	if (game == MAX / 2)
	{
		if (gyu0score < in0score)
			Win++;
		else
			Lose++;
		return;
	}
	if (in0score > IRREVERSIBLE_SCORE || gyu0score > IRREVERSIBLE_SCORE)
	{
		//	*****���� �ٽ� �κ�*****	//
		//	�񰡿����� ������ �Ǽ� �ºθ� ������ ��, ������ ���ӿ� ���� �¼� Ȥ�� �й���� ������� ��
		//	������� 5��° ���ӿ��� �ºΰ� �����Ǹ� ���� 3���� ���ӿ��� ���� �� �ִ� ����� ��(3 * 2 * 1) ��ŭ ����� ���ؾ� ��
		int left_case = 1;
		for (register int i = game; i < MAX / 2; ++i)
		{
			left_case *= (MAX / 2) - i;
		}
		if (gyu0score < in0score)
			Win += left_case;
		else
			Lose += left_case;
		return;
	}
	else
	{
		for (register int i = 1; i < MAX; ++i)
		{
			if (!Deck[i])
			{
				Deck[i] = true;
				Gyu0Card[game] = i;
				if (Gyu0Card[game] < In0Card[game])
				{
					Play(game + 1, gyu0score, in0score + Gyu0Card[game] + In0Card[game]);
				}
				else
				{
					Play(game + 1, gyu0score + Gyu0Card[game] + In0Card[game], in0score);
				}
				Gyu0Card[game] = 0;
				Deck[i] = false;
			}
		}
	}
}

int main(int argc, char** argv)
{
	freopen("s_input6808.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(Deck, false, sizeof(Deck));
		(void)memset(In0Card, 0, sizeof(In0Card));
		(void)memset(Gyu0Card, 0, sizeof(Gyu0Card));
		Win = 0; Lose = 0;
		for (register int c = 0; c < MAX / 2; ++c)
		{
			int card = 0;
			cin >> card;
			Deck[card] = true;
			In0Card[c] = card;
		}
		Play(0, 0, 0);
		cout << "#" << test_case << ' ' << Win << ' ' << Lose << '\n';
	}
	return 0;
}