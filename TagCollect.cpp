//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	<딱지 수집>
//	
//	1. 영미는 1일부터 N일까지 매일 아침 A개의 딱지를 구매해서 오후에 동생에게 딱지를 나눠줌
//	2. 하루에 P개 이하의 딱지를 줄 수 있음
//	3. 딱지를 나눠주고 남은 딱지가 있으면 다음 날 구매한 딱지와 합함
//	4. 동생은 최종적으로 K개의 딱지를 갖고 싶어 함. 영미도 얼른 동생이 원하는 개수의 딱지를 주고싶음
//	5. 동생이 원하는 개수의 딱지를 갖기위해 필요한 최소 일수 출력
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
const static int MAX = 100;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, K, P;
	int Number[MAX] = { 0, };
	int Answer;
	freopen("testcase_TagCollect.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Answer = 0;
		scanf("%d %d %d", &N, &K, &P);
		for (int day = 1; day <= N; ++day)
		{
			scanf("%d", &Number[day]);
		}
		for (int i = 1; i <= N+1; ++i)
		{
			if (i == N+1)
			{
				printf("#%d -1\n", test_case);
				break;
			}
			else
			{
				if (Number[i] > P)
				{
					Number[i + 1] = Number[i + 1] + Number[i] - P;
					Number[i] = P;
				}
				Answer += Number[i];
				if (Answer >= K)
				{
					printf("#%d %d\n", test_case, i);
					break;
				}
			}
		}
	}
	return 0;
}