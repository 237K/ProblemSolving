//
//	OS Windows
//	2019.06.13
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Sorting>	(Distinct)
//

int solution(vector<int>& A) {
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	return A.size();
}