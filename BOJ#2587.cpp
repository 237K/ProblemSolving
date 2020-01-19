//
//	OS Windows
//	2020.01.06
//
//	[Algorithm Problem Solving]
//
//	[구현]	<BOJ #2587>	대표값2
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const static int SZ = 5;
int main(int argc, char** argv)
{
	freopen("input2587.txt", "r", stdin);
	vector<int> v(SZ);
	int sum = 0, avg, i;
	for (i = 0; i < SZ; ++i)
	{
		scanf("%d", &v[i]);
		sum += v[i];
	}
	avg = sum / 5;
	sort(v.begin(), v.end());
	printf("%d\n%d", avg, v[2]);
	return 0;
}