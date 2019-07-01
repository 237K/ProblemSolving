//
//	OS Windows
//	2019.07.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1984] (D2) 중간 평균값 구하기
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const static int SZ = 10;
static vector<int> v(SZ);
int main(int argc, char** argv)
{
	int T, N;
	register int tc, i;
	double tmp;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		tmp = 0;
		for (i = 0; i < SZ; ++i)
		{
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		for (i = 1; i < 9; ++i)
		{
			tmp += (double)v[i];
		}
		tmp /= (double)8;
		printf("#%d %d\n", tc, (int)(round(tmp)));
	}
	return 0;
}