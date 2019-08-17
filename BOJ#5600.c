//
//	OS Windows
//	2019.08.05
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5600	품질검사
//	

#include <stdio.h>
int N, T, A, B, C;
int QA[1001][4];
int QC[303];
int main(void)
{
	freopen("input5600.txt", "r", stdin);
	register int i, j, flag, cnt;
	scanf("%d %d %d", &A, &B, &C);
	scanf("%d", &N);
	T = A + B + C;
	//	부품 전부다 2(알 수 없음)로 초기화
	for (i = 1; i <= T; ++i) QC[i] = 2;
	for (i = 0; i < N; ++i)
		for (j = 0; j < 4; ++j)
			scanf("%d", &QA[i][j]);
	//	1. 검사결과가 1인 거 찾아서 부품 3개 다 정상처리
	for (i = 0; i < N; ++i)
	{
		if (QA[i][3])
		{
			for (j = 0; j < 3; ++j)
				QC[QA[i][j]] = 1;
		}
	}
	//	2. 검사결과가 0인 거 찾아서 부품 3개 중 2개가 정상이면 나머지 하나 고장처리
	for (i = 0; i < N; ++i)
	{
		flag = cnt = 0;
		if (!QA[i][3])
		{
			for (j = 0; j < 3; ++j)
			{
				if (QC[QA[i][j]] == 2)
				{
					if (!flag) flag = QA[i][j];
					else break;
				}
				else if (QC[QA[i][j]] == 1) cnt++;
				else break;
			}
			if (cnt == 2) QC[flag] = 0;
		}
	}
	//	출력
	for (i = 1; i <= T; ++i) printf("%d\n", QC[i]);
	return 0;
}