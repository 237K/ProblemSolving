//
//	OS Windows
//	2019.09.22
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Time Complexity>	Perm Missing Element
//
//	ver.2
//

#include <memory.h>
int check[100002];
int solution(vector<int>& A) {
	(void)memset(check, 0, sizeof(check));
	register int sz, i, ret = 0;
	sz = A.size();
	if (!sz) return 1;
	for (i = 0; i < sz; ++i) check[A[i]] = 1;
	for (i = 1; i <= sz; ++i) if (!check[i]) ret = i;
	if (!ret) ret = sz + 1;
	return ret;
}