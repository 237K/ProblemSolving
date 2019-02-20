//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6900] <주혁이의 복권 당첨> (D3)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int StoI(char ch)			//stdlib 헤더의 atoi, string 헤더의 stoi 쓰니 채점서버에서 에러 발생하는 것 같아서 직접 구현
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

int main(int argc, char**argv)
{
	int test_case;
	int T;
	int N, M;
	int MyLottery[8];		//본 코드에선 배열로 안받아와도 무방하지만 확인차 저장해둠
	char **Lottery;			//당첨정보 읽어와서 저장함
	int *Reward;			//당첨금 읽어와서 저장함
	bool *Flag;				//당첨정보랑 일치하는지 여부 저장
	int Answer;				//총 수령액 저장

	freopen("s_input6900.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0; M = 0; Answer = 0;
		scanf("%d %d", &N, &M);
		Lottery = new char*[N];
		Reward = new int[N];
		Flag = new bool[N];
		for (int in = 0; in < N; ++in)
		{
			Lottery[in] = new char[9];
			Flag[in] = true;
			scanf("%8s %d", Lottery[in], &Reward[in]);				//당첨정보랑 당첨금 읽어와서 Lottery[N][9], Reward[N]에 저장해둠
		}
		for (int i = 0; i < M; ++i)									//이제 내가 산 복권정보를 읽어올건데
		{
			for (int my = 0; my < 8; ++my)						
			{				
				scanf("%1d", &MyLottery[my]);						//한 글자씩 읽어오면서
				for (int search = 0; search < N; ++search)			//당첨정보 0~N 까지랑 비교해보고
				{
					if (Lottery[search][my] == '*')					//*이면 다음글자로 넘어가고
						continue;

					else if (StoI(Lottery[search][my]) != MyLottery[my])	//*이 아닌데 숫자가 다르면 
					{
						Flag[search] = false;								//이건 당첨 안된거라고 표시하고 넘어감
						continue;
					}
				}
			}
			for (int ans = 0; ans < N; ++ans)
			{
				if (Flag[ans])
					Answer += Reward[ans];
				Flag[ans] = true;
			}
		}
		
		printf("#%d %d\n", test_case, Answer);

		for (int i = 0; i < N; ++i)
		{
			delete Lottery[i];
		}
		delete[] Lottery;
		delete[] Reward;
		delete[] Flag;
	}
	return 0;
}