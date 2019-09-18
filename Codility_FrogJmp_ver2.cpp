//
//	OS Windows
//	2019.09.18
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Time Complexity>	Frog Jmp
//
//	ver.2
//

int solution(int X, int Y, int D) {
	register int ret, rmd;
	if (X >= Y) return 0;
	ret = (Y - X) / D;
	if (!ret) return 1;
	rmd = (Y - X) % D;
	if (rmd) ret++;
	return ret;
}