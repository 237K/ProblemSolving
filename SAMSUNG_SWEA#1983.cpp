//
//	OS Windows
//	2019.07.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1983] (D2) 조교의 성적 매기기
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const static int GRADE = 10;
const static int MAX = 101;

static string grade[GRADE] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
static double score[MAX];
static int T, N, K, mid, fnl, hw;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, i, ret;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		ret = 0;
		cin >> N >> K;
		for (i = 0; i < N; ++i)
		{
			cin >> mid >> fnl >> hw;
			score[i] = mid * 0.35 + fnl * 0.45 + hw * 0.2;
		}
		for (i = 0; i < N; ++i)
		{
			if (score[i] > score[K - 1]) ret++;
		}
		cout << "#" << tc << ' ' << grade[ret / (N / 10)] << '\n';
	}
	return 0;
}