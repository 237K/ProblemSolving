//
//	OS Windows
//	2019.02.18
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6959] <이상한 나라의 덧셈게임> (D4)
//	
//	(나의 풀이 방법)
//	1. 1자리 수이면 무조건 B가 승리
//	2. 주어진 수의 개수가 짝수개 일 때 각 자리 숫자들의 합이 10미만이면 A가 승리, 10이상이면 B가 승리, 19이상이면 A가 승리, 28이상이면 다시 B가 승리......
//	3. 주어진 수의 개수가 홀수개 일 때 각 자리 숫자들의 합이 10미만이면 B가 승리, 10이상이면 A가 승리, 19이상이면 B가 승리, 28이상이면 다시 A가 승리......
//	Answer) 5678을 예로 들면,
//			1) 주어진 수의 개수에 따라 디폴트(합이 10보다 작을 때 == Count가 0일 때) 승자를 정함 (5678은 숫자가 짝수개 이므로 디폴트 승자는 A)
//			2) 각 자리 숫자들을 합함 (합 : 26)
//			3) 합을 10으로 나눈 몫 만큼 승자가 바뀜 (몫 : 2, A -> B -> A이므로 A)
//			4) 합을 10으로 나눈 몫이랑 나머지를 더함 (합 : 8)
//			5) 합을 10으로 나눈 몫 만큼 승자가 바뀜 (몫 : 0, 그대로 A)
//			6) 합을 10으로 나눈 몫과 나머지의 합이 10보다 크면 10보다 작을 때 까지 반복함
//
//	*그러므로 이 방법에선 몇 자리 수인지 확인하는 것이 우선
//	1) while문으로 몫이 0이 될 때까지 10으로 나누면서 Count++ 해서 확인할 수 도 있고,
//	2) string으로 받아와서 length 쓸 수도 있음
//	string으로 받아오는 방법으로 진행해봄
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int Accumulate(int Num)									//각 자리 숫자를 모두 합하는 함수
{
	int Temp = 0;
	int Quotient = 0, Remainder = 0;
	while (1)
	{
		Quotient = Num / 10;
		Remainder = Num % 10;
		Temp += Remainder;
		Num /= 10;
		if (Num == 0)
			break;
	}
	return Temp;
}

void DFS(int Num, int cnt)
{	
	int Quotient = 0, Remainder = 0;
	cnt += Num / 10;
	Quotient = Num / 10;
	Remainder = Num % 10;
	if (Quotient + Remainder < 10)
	{
		if (cnt % 2 == 0)
			printf("A\n");
		else
			printf("B\n");
		return;
		
	}
	else if (Quotient + Remainder >= 10)
	{
		DFS(Accumulate(Quotient + Remainder), cnt);
	}
}

int main(int argc, char** argv)
{
	string Input;
	int Number;
	int Sum;
	int Length;
	int test_case;
	int T;
	freopen("s_input6959.txt", "r", stdin);
	scanf("%d\n", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Input = { NULL, };											//string 배열 초기화
		Number = 0; Length = 0;	Sum = 0;							//변수 초기화
		getline(cin, Input);										//한 줄 string으로 읽어옴 (string.length로 몇자리 수인지 확인하기 위함)
		Number = stoi(Input);										//string을 숫자로 바꿔서 저장하고
		Length = Input.length();									//몇 자리 수인지 저장하고
		printf("#%d ", test_case);
		if (Length == 1)
			printf("B\n");
		else if (Length % 2 == 0)					//주어진 수의 개수가 짝수이면
		{
			Sum = Accumulate(Number);				//숫자를 모두 합하고
			DFS(Sum, 0);
		}
		else
		{											//주어진 수의 개수가 홀수이면
			Sum = Accumulate(Number);
			DFS(Sum, 1);
		}
	}
	return 0;
}