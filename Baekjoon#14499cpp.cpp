//
//	OS Windows
//	2019.04.11
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14499	林荤困 奔府扁
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;

const static int DIRECT = 5;
const static int DICE_SIZE = 7;
const static int SIZE = 21;

static int map[SIZE][SIZE];
static int dice[DICE_SIZE];
static int N, M, x, y, K;
static int dir[DIRECT][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	(void)memset(dice, 0, sizeof(dice));
}
inline void dice_rotate(int d)
{
	int temp_dice[DICE_SIZE];
	(void)memcpy(temp_dice, dice, sizeof(dice));

	if (d == 1) { dice[1] = temp_dice[4];	dice[3] = temp_dice[1];	dice[4] = temp_dice[6];	dice[6] = temp_dice[3]; }
	else if (d == 2) { dice[1] = temp_dice[3];	dice[3] = temp_dice[6];	dice[4] = temp_dice[1];	dice[6] = temp_dice[4]; }
	else if (d == 3) { dice[1] = temp_dice[5];	dice[2] = temp_dice[1];	dice[5] = temp_dice[6];	dice[6] = temp_dice[2]; }
	else if (d == 4) { dice[1] = temp_dice[2];	dice[2] = temp_dice[6];	dice[5] = temp_dice[1];	dice[6] = temp_dice[5]; }

	/*
	switch (d)
	{
	//	悼率
	case 1:
		dice[1] = temp_dice[4];	dice[3] = temp_dice[1];	dice[4] = temp_dice[6];	dice[6] = temp_dice[3];
		break;
	//	辑率
	case 2:
		dice[1] = temp_dice[3];	dice[3] = temp_dice[6];	dice[4] = temp_dice[1];	dice[6] = temp_dice[4];
		break;
	//	合率
	case 3:
		dice[1] = temp_dice[5];	dice[2] = temp_dice[1];	dice[5] = temp_dice[6];	dice[6] = temp_dice[2];
		break;
	//	巢率
	case 4:
		dice[1] = temp_dice[2];	dice[2] = temp_dice[6];	dice[5] = temp_dice[1];	dice[6] = temp_dice[5];
		break;
	default:
		break;
	}
	*/
}
inline int simulation(int order)
{
	int nr = x + dir[order][0];
	int nc = y + dir[order][1];
	
	if (nr < 0 || nc < 0 || nr >= N || nc >= M)
		return -1;
	else
	{
		x = nr;
		y = nc;
		dice_rotate(order);
		if (!map[nr][nc])
			map[nr][nc] = dice[6];
		else if (map[nr][nc])
		{
			dice[6] = map[nr][nc];
			map[nr][nc] = 0;
		}
	}
	return dice[1];
}

int main(int argc, char** argv)
{
	freopen("input14499.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	init();
	cin >> N >> M >> x >> y >> K;
	for (register int r = 0; r < N; ++r)
	{
		for (register int c = 0; c < M; ++c)
		{
			cin >> map[r][c];
		}
	}

	int order_direct = 0;
	for (register int k = 0; k < K; ++k)
	{
		cin >> order_direct;
		int answer = simulation(order_direct);
		if (answer == -1)
			continue;
		else
			cout << answer << '\n';
	}
	return 0;
}