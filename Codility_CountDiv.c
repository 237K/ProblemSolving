//
//	OS Windows
//	2019.06.11
//
//	[Algorithm Problem Solving]
//
//	Codility	<Count Div>
//

int solution(int A, int B, int K) {
	if (!A) return B / K + 1;
	else return B / K - (A - 1) / K;
}