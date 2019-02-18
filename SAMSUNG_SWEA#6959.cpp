//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6959] <이상한 나라의 덧셈게임> (D4)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

bool IsTheEnd;								//재귀함수 종료조건
void Play(int Number, int Count)
{
	while (!IsTheEnd)
	{
		int Quotient = 0;					//몫
		int Remainder = 0;					//나머지
		if (Number < 10)					//숫자가 10보다 작으면
		{
			IsTheEnd = true;				//종료조건 만족
			if (Count % 2 == 0)				//Count가 짝수이면
				printf("A\n");				//B가 승리
			else
				printf("B\n");				//아니면 A가 승리
			break;
		}
		else if (Number >= 10 && Number < 100)				//두 자리 수이면
		{
			Quotient = Number / 10;							
			Remainder = Number % 10;
			Play(Quotient + Remainder, Count + 1);			//10으로 나눈 몫과 나머지를 더해서 다시 재귀함수로 보냄
		}
		else if (Number >= 100 && Number < 1000)			//세 자리 수이면
		{
			Quotient = Number / 100;
			Remainder = Number % 100;
			Play(Quotient * 10 + Remainder, Count + 1);		//100으로 나눈 몫에 10을 곱한 후 나머지와 더해서 다시 재귀함수로 보냄
		}
		else if (Number >= 1000 && Number <10000)			//네 자리 수이면
		{
			Quotient = Number / 1000;
			Remainder = Number % 1000;
			Play(Quotient * 100 + Remainder, Count + 1);	//1000으로 나눈 몫에 100을 곱한 후 나머지와 더해서 다시 재귀함수로 보냄
		}
		else if (Number >= 10000 && Number < 100000)
		{
			Quotient = Number / 10000;
			Remainder = Number % 10000;
			Play(Quotient * 1000 + Remainder, Count + 1);
		}
		else if (Number >= 100000 && Number < 1000000)
		{
			Quotient = Number / 100000;
			Remainder = Number % 100000;
			Play(Quotient * 10000 + Remainder, Count + 1);
		}
		else if (Number >= 1000000 && Number < 10000000)
		{
			Quotient = Number / 1000000;
			Remainder = Number % 1000000;
			Play(Quotient * 100000 + Remainder, Count + 1);
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("s_input6959.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int _Number = 0;
		IsTheEnd = false;
		scanf("%d", &_Number);
		printf("#%d ", test_case);
		Play(_Number, 1);
	}
	return 0;
}