//
//	OS Windows
//	2019.06.10
//
//	[Algorithm Problem Solving]
//
//	Codility	<Genomic Range Query>
//

#include <memory.h>
const static int N = 5;
const static int MAX = 100000;
static int dna[MAX][N];
inline void check(int idx, char c)
{
	if (c == 'A') dna[idx][1]++;
	else if (c == 'C') dna[idx][2]++;
	else if (c == 'G') dna[idx][3]++;
	else dna[idx][4]++;
}
vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
	(void)memset(dna, 0, sizeof(dna));
	int M = P.size(), len = S.length();
	vector<int> ret(M, 0);
	register int i, j, k, l;

	check(0, S[0]);

	for (i = 1; i < len; ++i)
	{
		for (j = 1; j < N; ++j)
			dna[i][j] = dna[i - 1][j];

		check(i, S[i]);
	}

	for (k = 0; k < M; ++k)
	{
		for (l = 1; l < N; ++l)
		{
			if (dna[Q[k]][l] > dna[P[k] - 1][l])
			{
				ret[k] = l;
				break;
			}
		}
	}
	return ret;
}