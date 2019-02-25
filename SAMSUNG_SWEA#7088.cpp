//
//	OS Windows
//	2019.02.25
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7088] <은기의 송아지 세기> (D4)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
const static int MAX = 100001;
const static int Category = 4;

int main(int argc, char** argv)
{
	int **Cow;
	int test_case;
	int T;
	freopen("s_input7088.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, Q;
		N = 0;
		Q = 0;
		scanf("%d %d", &N, &Q);

		Cow = new int*[N+1];
		for (int init = 0; init <= N; ++init)
		{
			Cow[init] = new int[Category];
			for (int initc = 0; initc < Category; ++initc)
			{
				Cow[init][initc] = 0;
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			int tempCategory;
			scanf("%d", &tempCategory);
			for (int t = 1; t <= 3; ++t)
			{
				if (t == tempCategory)
				{
					Cow[i][t] = Cow[i - 1][t] + 1;
				}
				else
					Cow[i][t] = Cow[i - 1][t];
			}
		}

		printf("#%d\n", test_case);
		for (int q = 0; q < Q; ++q)
		{
			int ONE, TWO, THREE;
			int Lower, Upper;
			ONE = 0;
			TWO = 0;
			THREE = 0;
			Lower = 0;
			Upper = 0;
			scanf("%d %d", &Lower, &Upper);

			ONE = Cow[Upper][1] - Cow[Lower-1][1];
			TWO = Cow[Upper][2] - Cow[Lower-1][2];
			THREE = Cow[Upper][3] - Cow[Lower-1][3];

			printf("%d %d %d\n", ONE, TWO, THREE);
		}
		for (int del = 0; del <= N; ++del)
		{
			delete[] Cow[del];
		}
		delete[] Cow;
	}
	return 0;
}