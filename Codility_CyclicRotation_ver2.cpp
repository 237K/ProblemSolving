//
//	OS Windows
//	2019.09.16
//
//	[Algorithm Problem Solving]
//
//	Codility	<Arrays>		Cyclic Rotation
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int>& A, int K)
{
	register int i, idx, sz;
	vector<int> B;
	sz = A.size();
	B.resize(sz);
	for (i = 0; i < sz; ++i)
	{
		idx = (i + K) % sz;
		B[idx] = A[i];
	}
	return B;
}

int main(int argc, char** argv)
{
	freopen("c_input22.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}