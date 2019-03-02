//
//	OS Windows
//	2019.03.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7102] <��ȫ���� ī�����> (D3)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

void CardPlay(int _n, int _m);

int main(int argc, char** argv)
{
	int T;
	int test_case;
	int N, M;
	freopen("s_input7102.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0; M = 0;
		scanf("%d %d", &N, &M);
		printf("#%d ", test_case);
		if (N >= M)					//CardPlay �Լ� ����ȭ�� ���� N ������ �� ������ �α� ����
			CardPlay(N, M);	
		else
			CardPlay(M, N);
	}
	return 0;
}
void CardPlay(int _n, int _m)
{
	int Gap = _n - _m + 1;			//���� ������ N, M ���̺��� 1�� ���� �� �ۿ� ���� (N�� 6��, M�� 4���� ������ 3��)
	for (int i = 1; i <= Gap; ++i)
	{
		printf("%d ", i + _m);
	}
	printf("\n");
}