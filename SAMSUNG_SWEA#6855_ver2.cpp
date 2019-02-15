//
//	OS Windows
//	2019.02.14
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6855] <신도시 전기 연결하기> (D4)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, K;
	int Answer;
	vector<int> House;
	vector<int> Distance;
	//freopen("s_input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Answer = 0;
		House.clear();
		Distance.clear();
		scanf("%d %d", &N, &K);
		House.resize(N + 1, 0);
		Distance.resize(N + 1, 0);
		for (int i = 0; i < N; ++i)
		{
			int Recent = 0;
			scanf("%d", &Recent);
			House[i] = Recent;
			if (i == 0)
				Distance[i] = 0;
			else
				Distance[i] = House[i] - House[i - 1];
		}
		if (N == K || N <= K)
		{
			printf("#%d %d\n", test_case, Answer);
			continue;
		}
		else
		{
			sort(Distance.begin(), Distance.end(), greater<int>());
			Answer = House[N - 1] - House[0];
			for (int del = 0; del < K - 1; ++del)
				Answer -= Distance[del];
			printf("#%d %d\n", test_case, Answer);
		}
	}
	return 0;
}