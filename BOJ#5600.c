//
//	OS Windows
//	2019.08.05
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5600	ǰ���˻�
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
	//	��ǰ ���δ� 2(�� �� ����)�� �ʱ�ȭ
	for (i = 1; i <= T; ++i) QC[i] = 2;
	for (i = 0; i < N; ++i)
		for (j = 0; j < 4; ++j)
			scanf("%d", &QA[i][j]);
	//	1. �˻����� 1�� �� ã�Ƽ� ��ǰ 3�� �� ����ó��
	for (i = 0; i < N; ++i)
	{
		if (QA[i][3])
		{
			for (j = 0; j < 3; ++j)
				QC[QA[i][j]] = 1;
		}
	}
	//	2. �˻����� 0�� �� ã�Ƽ� ��ǰ 3�� �� 2���� �����̸� ������ �ϳ� ����ó��
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
	//	���
	for (i = 1; i <= T; ++i) printf("%d\n", QC[i]);
	return 0;
}