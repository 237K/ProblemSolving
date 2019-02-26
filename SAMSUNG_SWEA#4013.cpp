//
//	OS Windows
//	2019.02.26
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#4013] <특이한 자석> (모의 SW 역량테스트)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
const static int GEAR = 4;
const static int TOOTH = 8;

static int Gear[GEAR + 1][TOOTH];
static bool Check[GEAR + 1];

static void Clockwise(int _Gear);
static void CounterClockwise(int _Gear);
static void WhatGearRotate(int _Gear);
static bool isTheEnd();
static void Rotate(int _Gear, int _Direct);
static void Score();
static void Print();

int main(int argc, char** argv)
{
	int T;
	int test_case;
	freopen("s_input4013.txt", "r", stdin);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int K = 0;
		for (int g = 0; g <= GEAR; ++g)
		{
			for (int t = 0; t < TOOTH; ++t)
			{
				Gear[g][t] = 0;
			}
		}
		scanf("%d", &K);
		for (int g = 1; g <= GEAR; ++g)
		{
			for (int t = 0; t < TOOTH; ++t)
			{
				scanf("%d", &Gear[g][t]);
			}
		}
		for (int r = 0; r < K; ++r)
		{
			int RG = 0, RD = 0;
			for (int g = 0; g <= GEAR; ++g)
			{
				Check[g] = false;
			}
			scanf("%d %d", &RG, &RD);
			WhatGearRotate(RG);
			Rotate(RG, RD);
			//Print();
		}
		printf("#%d ", test_case);
		Score();
	}
	return 0;
}

static void Clockwise(int _Gear)
{
	int temp = Gear[_Gear][TOOTH - 1];
	for (int t = TOOTH-1; t >= 0; --t)
	{
		Gear[_Gear][t] = Gear[_Gear][t-1];
	}
	Gear[_Gear][0] = temp;
}
static void CounterClockwise(int _Gear)
{
	int temp = Gear[_Gear][0];
	for (int t = 0; t < TOOTH; ++t)
	{
		Gear[_Gear][t] = Gear[_Gear][t+1];
	}
	Gear[_Gear][TOOTH - 1] = temp;
}

static void WhatGearRotate(int _Gear)
{
	if (_Gear == 1)
	{
		if (Gear[_Gear][2] == Gear[_Gear + 1][6])
		{
			Check[_Gear + 1] = true;
			Check[_Gear + 2] = true;
			Check[_Gear + 3] = true;
		}
		else
		{
			if (Gear[_Gear + 1][2] == Gear[_Gear + 2][6])
			{
				Check[_Gear + 2] = true;
				Check[_Gear + 3] = true;
			}
			else
			{
				if (Gear[_Gear + 2][2] == Gear[_Gear + 3][6])
				{
					Check[_Gear + 3] = true;
				}
			}
		}
	}
	else if (_Gear == 2)
	{
		if (Gear[_Gear][2] == Gear[_Gear + 1][6])
		{
			Check[_Gear + 1] = true;
			Check[_Gear + 2] = true;
		}
		else
		{
			if (Gear[_Gear + 1][2] == Gear[_Gear + 2][6])
			{
				Check[_Gear + 2] = true;
			}
		}
		if (Gear[_Gear][6] == Gear[_Gear - 1][2])
		{
			Check[_Gear - 1] = true;
		}
	}
	else if (_Gear == 3)
	{
		if (Gear[_Gear][2] == Gear[_Gear + 1][6])
		{
			Check[_Gear + 1] = true;
		}
		if (Gear[_Gear][6] == Gear[_Gear - 1][2])
		{
			Check[_Gear - 1] = true;
			Check[_Gear - 2] = true;
		}
		else
		{
			if (Gear[_Gear - 2][2] == Gear[_Gear - 1][6])
			{
				Check[_Gear - 2] = true;
			}
		}
	}
	else if (_Gear == 4)
	{
		if (Gear[_Gear][6] == Gear[_Gear - 1][2])
		{
			Check[_Gear - 1] = true;
			Check[_Gear - 2] = true;
			Check[_Gear - 3] = true;
		}
		else
		{
			if (Gear[_Gear - 2][2] == Gear[_Gear - 1][6])
			{
				Check[_Gear - 2] = true;
				Check[_Gear - 3] = true;
			}
			else
			{
				if (Gear[_Gear - 3][2] == Gear[_Gear - 2][6])
				{
					Check[_Gear - 3] = true;
				}
			}
		}
	}
}

static bool isTheEnd()
{
	int cnt = 0;
	for (int g = 1; g <= GEAR; ++g)
	{
		if (Check[g] == false)
			cnt++;
	}
	if (cnt == 0)
		return true;
	else
		return false;
}

static void Score()
{
	int score = 0;
	score = (Gear[1][0] * 1) + (Gear[2][0] * 2) + (Gear[3][0] * 4) + (Gear[4][0] * 8);
	printf("%d\n", score);
}

static void Rotate(int _Gear, int _Direct)
{
	if (isTheEnd())
	{
		return;
	}
	else
	{
		switch (_Direct)
		{
		case 1:
			Clockwise(_Gear);
			break;
		case -1:
			CounterClockwise(_Gear);
			break;
		}
		Check[_Gear] = true;

		if (_Gear - 1 >= 1 && Check[_Gear - 1] == false)
			Rotate(_Gear - 1, _Direct*(-1));
		if (_Gear + 1 <= GEAR && Check[_Gear + 1] == false)
			Rotate(_Gear + 1, _Direct*(-1));
	}
}

static void Print()
{
	for (int g = 1; g <= GEAR; ++g)
	{
		printf("%d번 기어 : ", g);
		for (int t = 0; t < TOOTH; ++t)
		{
			printf("%d ", Gear[g][t]);
		}
		printf("\n");
	}
	printf("\n");
}