//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6959] <ÀÌ»óÇÑ ³ª¶óÀÇ µ¡¼À°ÔÀÓ> (D4)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;
const static int MAX = 1001;
char Input[MAX] = { NULL, };
char Empty[2];
int Num;
int Count;

int ATOI(char ch)
{
	switch (ch)
	{
	case 48:
		return 0;
		break;
	case 49:
		return 1;
		break;
	case 50:
		return 2;
		break;
	case 51:
		return 3;
		break;
	case 52:
		return 4;
		break;
	case 53:
		return 5;
		break;
	case 54:
		return 6;
		break;
	case 55:
		return 7;
		break;
	case 56:
		return 8;
		break;
	case 57:
		return 9;
		break;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("s_input6959.txt", "r", stdin);
	scanf("%d", &T); cin.getline(Empty, 2);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		*Input = '\n'; Num = 0; Count = 0;
		cin.getline(Input, 1001);
		for (int i = 0; Input[i] != NULL; ++i)
		{
			Num += ATOI(Input[i]);
			if (Num < 10)
			{
				Count += 1;
				continue;
			}
			else if (Num >= 10)
			{
				Count += 2;
				Num = Num % 10;
				continue;
			}
		}
		if (Count % 2 == 0)
			printf("#%d A\n", test_case);
		else
			printf("#%d B\n", test_case);
	}
	return 0;
}