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
//
//	(*주요 흐름도)
//	1. 1000개 이하의 수를 한 줄 단위로 읽어와서 char배열에 저장함 (getline 사용하니 채점서버에서 자꾸 파일의 마지막 숫자 하나를 안읽어와서 scanf 사용함)
//	2. 숫자가 몇개인지 확인
//	3. char배열에 저장된 숫자를 하나씩 int형으로 변환해서 누적하여 Sum에 저장함
//	4. Sum을 재귀함수(DFS 함수)로 보낼건데, 숫자 개수가 짝수개이면 cnt를 0으로 해서 보내고, 홀수개이면 1로 해서 보냄
//	5. Sum을 10으로 나눈 몫만큼 cnt를 더함
//	6. Sum의 각 자리를 더함(Accumulate 함수)
//	7. Sum의 각 자리를 더한게 10보다 작으면 cnt에 따라 승자 출력
//	8. 10이상이면 다시 DFS로 보냄
//	9. 10으로 나눈 몫만큼 cnt를 더하고.. 다시 각 자리를 더해서 10보다 작으면 출력하고 10이상이면 반복...
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
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
	int Acc = 0;
	cnt += Num / 10;
	Acc = Accumulate(Num);
	if (Acc < 10)
	{
		if (cnt % 2 == 0)
			printf("A\n");
		else
			printf("B\n");
		return;
	}
	else if (Acc >= 10)
	{
		DFS(Acc, cnt);
	}
}

int StoI(char ch)
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
	default:
		return -1;
		break;
	}
}

int main(int argc, char** argv)
{
	int Sum;
	int Length;
	int test_case;
	int T;
	char Input[1001];
	freopen("s_input6959.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int init = 0; init < 1001; ++init)
			Input[init] = NULL;
		Length = 0;
		Sum = 0;
		scanf("%1000s", &Input);
		while (Input[Length] != NULL)
		{
			Sum += StoI(Input[Length]);
			Length++;
		}
		printf("#%d ", test_case);
		if (Length == 1)
			printf("B\n");
		else if (Length % 2 == 0)					//주어진 수의 개수가 짝수이면
		{
			DFS(Sum, 0);
		}
		else
		{											//주어진 수의 개수가 홀수이면
			DFS(Sum, 1);
		}

	}
	return 0;
}