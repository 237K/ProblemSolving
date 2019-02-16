//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	<���� ����>
//	
//	1. ���̴� 1�Ϻ��� N�ϱ��� ���� ��ħ A���� ������ �����ؼ� ���Ŀ� �������� ������ ������
//	2. �Ϸ翡 P�� ������ ������ �� �� ����
//	3. ������ �����ְ� ���� ������ ������ ���� �� ������ ������ ����
//	4. ������ ���������� K���� ������ ���� �;� ��. ���̵� �� ������ ���ϴ� ������ ������ �ְ����
//	5. ������ ���ϴ� ������ ������ �������� �ʿ��� �ּ� �ϼ� ���
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
const static int MAX = 100;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, K, P;
	int Number[MAX] = { 0, };
	int Answer;
	freopen("testcase_TagCollect.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Answer = 0;
		scanf("%d %d %d", &N, &K, &P);
		for (int day = 1; day <= N; ++day)
		{
			scanf("%d", &Number[day]);
		}
		for (int i = 1; i <= N+1; ++i)
		{
			if (i == N+1)
			{
				printf("#%d -1\n", test_case);
				break;
			}
			else
			{
				if (Number[i] > P)
				{
					Number[i + 1] = Number[i + 1] + Number[i] - P;
					Number[i] = P;
				}
				Answer += Number[i];
				if (Answer >= K)
				{
					printf("#%d %d\n", test_case, i);
					break;
				}
			}
		}
	}
	return 0;
}