//
//	OS Windows
//	2019.03.26
//
//	[Algorithm Problem Solving]
//
//	<¡�˴ٸ�>
//
//	1. ¡�˴ٸ��� �ǳʾ� �ϴµ� ¡�˴ٸ��� �ǳ� �� ���� ¡�˴ٸ��� ���� �ִ� ���ڸ�ŭ�� �ݾ��� �����ؾ� ��
//	2. �ִ� �������� 3���� 3ĭ ���� ¡�˴ٸ����� �� �� ����
//	2. �ּҺ������ ¡�˴ٸ��� �ǳ� �� �����ؾ� �ϴ� ��� ���
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
using namespace std;

const static int MAX = 10000;

static int N;
static int stepping_stone[MAX];
static int min_cost;

void DFS(int idx, int cost)
{
	if (idx >= N)
	{
		min_cost = min(min_cost, cost);
		return;
	}
	else
	{
		DFS(idx + 1, cost + stepping_stone[idx + 1]);
		DFS(idx + 2, cost + stepping_stone[idx + 2]);
		DFS(idx + 3, cost + stepping_stone[idx + 3]);
	}
}

void Simulation()
{
	for (int i = 0; i < 3; ++i)
	{
		DFS(i, stepping_stone[i]);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("testcase_SteppingStone2.txt", "r", stdin);
	int T;
	int test_case;
	double timer;
	clock_t time_s, time_e;
	time_s = clock();
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(stepping_stone, 0, sizeof(stepping_stone));
		min_cost = 2147000000;
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> stepping_stone[i];
		Simulation();
		cout << "#" << test_case << ' ' << min_cost << '\n';
	}
	time_e = clock();
	timer = (double)(time_e - time_s);
	cout << "execution time : " << timer << "ms\n\n";
	return 0;
}