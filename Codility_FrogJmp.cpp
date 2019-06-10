//
//	OS Windows
//	2019.05.30
//
//	[Algorithm Problem Solving]
//
//	Codility	<Frog Jmp>
//

int solution(int X, int Y, int D) {
	if (X >= Y) return 0;
	int dist, rmd, ret;
	dist = Y - X;
	rmd = dist % D;
	ret = dist / D;
	if (rmd) ret += 1;
	return ret;
}