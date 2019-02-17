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
using namespace std;

bool IsTheEnd;

void Play(int Number, int Count)
{
	while (!IsTheEnd)
	{
		int Quotient = 0;
		int Remainder = 0;
		if (Number < 10)
		{
			IsTheEnd = true;
			if (Count % 2 == 0)
				printf("B\n");
			else
				printf("A\n");
			break;
		}
		else if (Number >= 10 && Number < 100)
		{
			Quotient = Number / 10;
			Remainder = Number % 10;
			Play(Quotient + Remainder, Count + 1);
		}
		else if (Number >= 100 && Number < 1000)
		{
			Quotient = Number / 100;
			Remainder = Number % 100;
			Play(Quotient * 10 + Remainder, Count + 1);
		}
		else if (Number >= 1000)
		{
			Quotient = Number / 1000;
			Remainder = Number % 1000;
			Play(Quotient * 100 + Remainder, Count + 1);
		}
		else if (Number >= 10000 || Number <= 0)
		{
			printf("Error\n");
			IsTheEnd = true;
			break;
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("s_input6959.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int _Number = 0;
		IsTheEnd = false;
		scanf("%d", &_Number);
		printf("#%d ", test_case);
		Play(_Number, 0);
	}
	return 0;
}