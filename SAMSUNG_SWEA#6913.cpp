//
//	OS Windows
//	2019.02.16
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6913] <동철이의 프로그래밍 대회> (D3)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
const static int MAX = 22;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, M;			
	int Solve[MAX] = { 0, };						//Solve[i] : i번째 사람이 문제를 맞힌 개수
	int Counter_Solve;								//문제 맞힌 개수를 카운터해서 Solve에 넣기 위함
	int Answer_NumOfPerson, Answer_NumOfSolve;
	//freopen("s_input6913.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Answer_NumOfPerson = 0; Answer_NumOfSolve = 0;
		scanf("%d %d", &N, &M);
		for (int person = 1; person <= N; ++person)
		{
			Counter_Solve = 0;
			for (int problem = 1; problem <= M; ++problem)
			{
				int Recent = 0;
				scanf("%d", &Recent);
				if (Recent == 1)
				{
					Counter_Solve++;
				}
			}
			Solve[person] = Counter_Solve;
			if (Solve[person] >= Answer_NumOfSolve)
				Answer_NumOfSolve = Solve[person];
		}
		for (int p = 1; p <= N; ++p)
		{
			if (Solve[p] == Answer_NumOfSolve)
				Answer_NumOfPerson++;
		}
		printf("#%d %d %d\n", test_case, Answer_NumOfPerson, Answer_NumOfSolve);
	}
	return 0;
}