//
//	OS Windows
//	2019.03.20
//
//	[Algorithm Problem Solving]
//
//	<엘리베이터 운행거리>
//
//	1. 엘리베이터는 한 순간에 한 사람만 이용할 수 있음
//	2. 이용자가 현 위치에서 사용버튼을 누르면 엘리베이터가 도착하고 목적층을 입력하면 이동함
//	3. 엘리베이터가 한 층을 이동하는데 1초 걸림
//	4. 이용자 수와 각 이용자의 출발지, 목적지를 입력받아서
//	5. 엘리베이터가 움직인 거리를 측정하여 출력
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