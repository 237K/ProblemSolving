//
//	OS Windows
//	2019.03.20
//
//	[Algorithm Problem Solving]
//
//	<���������� ����Ÿ�>
//
//	1. ���������ʹ� �� ������ �� ����� �̿��� �� ����
//	2. �̿��ڰ� �� ��ġ���� ����ư�� ������ ���������Ͱ� �����ϰ� �������� �Է��ϸ� �̵���
//	3. ���������Ͱ� �� ���� �̵��ϴµ� 1�� �ɸ�
//	4. �̿��� ���� �� �̿����� �����, �������� �Է¹޾Ƽ�
//	5. ���������Ͱ� ������ �Ÿ��� �����Ͽ� ���
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
using namespace std;

const static int MAX = 10;

int main(int argc, char**argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("testcase_Elevator.txt", "r", stdin);
	int T;
	int test_case;
	int N;
	int Elevator[MAX];
	int Result;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(&Elevator[0], 0, sizeof(Elevator));
		N = 0;
		Result = 0;

		cin >> N;
		for (int n = 0; n < N * 2; ++n)
		{
			cin >> Elevator[n];
			if (n > 0)
			{
				Result += abs(Elevator[n] - Elevator[n - 1]);
			}
		}
		cout << "#" << test_case << ' ' << Result << '\n';
	}
	return 0;
}