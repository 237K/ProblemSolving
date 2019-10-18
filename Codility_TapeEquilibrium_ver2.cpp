//
//	OS Windows
//	2019.09.22
//
//	[Algorithm Problem Solving]
//
//	[Codility]	<Time Complexity>	Tape Equilibrium
//
//	ver.2
//

int solution(vector<int>& A) {
	register int i, sz, part2 = 0, part1, diff, min_value;
	sz = A.size();
	part1 = A[0];
	for (i = 1; i < sz; ++i) part2 += A[i];
	min_value = part2 - part1;
	if (min_value < 0) min_value *= -1;
	for (i = 1; i < sz - 1; ++i)
	{
		diff = part2 - part1;
		if (diff < 0) diff *= -1;
		if (min_value > diff) min_value = diff;
		part2 -= A[i];
		part1 += A[i];
	}
	diff = part2 - part1;
	if (diff < 0) diff *= -1;
	if (min_value > diff) min_value = diff;
	return min_value;
}