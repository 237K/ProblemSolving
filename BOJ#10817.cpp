//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10817 ¼¼ ¼ö
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int A, B, C;
	vector<int> v(3);
	scanf("%d %d %d", &A, &B, &C);
	v[0] = A; v[1] = B; v[2] = C;
	sort(v.begin(), v.end());
	printf("%d", v[1]);
	return 0;
}