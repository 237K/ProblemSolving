//
//	OS Windows
//	2019.02.16
//
//	[Algorithm Problem Solving]
//
//	<징검다리 건너기>
//	
//	1. N개의 징검돌이 주어짐. 각 징검돌에는 점수가 있음
//	2. i번째 징검돌을 밟았다면 i+1, i+2번째 징검돌로 갈 수 있음. 하지만 연속된 세 개의 징검돌을 밟을 순 없음. 다만 첫 번째 징검돌에서 2번째, 3번째로는 이동할 수 있음
//	3. 마지막 N번째 징검돌은 꼭 밟아야 함.
//	4. 최대점수 출력

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const static int MAX = 10001;
int N;
int Score[MAX] = { 0, };
int Stone[MAX][2] = { 0, };

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int Answer;
	freopen("testcase_SteppingStone.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Answer = -1;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{											
			scanf("%d", &Score[i]);					
			if (i == 1)
			{
				Stone[i][1] = Score[i];						//Stone[i][1]은 i-1번째 돌에서 한 칸 건너 i번째 징검돌에 온 경우를 의미합니다.
				Stone[i][2] = Score[i];						//Stone[i][2]는 i-2번째 돌에서 두 칸 건너 i번째 징검돌에 온 경우를 의미합니다.
			}
			else
			{
				Stone[i][1] = Stone[i - 1][2] + Score[i];							//세 칸을 연속으로 이동할 수 없으므로, i-1번째 돌에서 한 칸 건너 i돌로 온 경우 i-1번 돌에는 2칸 건너 왔어야만 합니다. 
				Stone[i][2] = max(Stone[i - 2][1], Stone[i - 2][2]) + Score[i];		//i-2번째 돌에서 i번 돌로 온 경우에는 i-2번 돌에 한 칸 건너 왔었을 수도 있고, 두 칸 건너 왔을 수도 있습니다.
			}																		//그 중에 최대값을 선택해 더해줍니다.
		}
		Answer = max(Stone[N][1], Stone[N][2]);
		printf("#%d %d\n", test_case, Answer);
	}
	return 0;
}