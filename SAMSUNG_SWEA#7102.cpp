//
//	OS Windows
//	2019.03.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7102] <준홍이의 카드놀이> (D3)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

void CardPlay(int _n, int _m);

int main(int argc, char** argv)
{
	int T;
	int test_case;
	int N, M;
	freopen("s_input7102.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0; M = 0;
		scanf("%d %d", &N, &M);
		printf("#%d ", test_case);
		if (N >= M)					//CardPlay 함수 간소화를 위해 N 개수를 행 개수로 두기 위함
			CardPlay(N, M);	
		else
			CardPlay(M, N);
	}
	return 0;
}
void CardPlay(int _n, int _m)
{
	int Gap = _n - _m + 1;			//정답 개수는 N, M 차이보다 1개 많을 수 밖에 없음 (N이 6개, M이 4개면 정답은 3개)
	for (int i = 1; i <= Gap; ++i)
	{
		printf("%d ", i + _m);
	}
	printf("\n");
}