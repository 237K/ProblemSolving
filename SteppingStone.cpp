//
//	OS Windows
//	2019.02.16
//
//	[Algorithm Problem Solving]
//
//	<징검다리 건너기>
//	
//	1. N개의 징검돌이 주어짐. 각 징검돌에는 점수가 있음
//	2. i번째 징검돌을 밟았다면 i+1, i+2번째 징검돌로 갈 수 있음. 하지만 연속된 세 개의 징검돌을 밟을 순 없음. 다만 첫 번째 징검돌에서 2번째, 3번째로는 이동할 수 있음
//	3. 마지막 N번째 징검돌은 꼭 밟아야 함.
//	4. 최대점수 출력

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const static int MAX = 10000;
int N;
int Score[MAX] = { 0, };
bool Check[MAX] = { false, };
int Answer;
stack<int> Stack;

void DFS(int _N)
{
	Stack.push(2);
	Stack.push(3);
	Check[1] = true;
	while (!Stack.empty())
	{
		int CurStone = Stack.top();
		Stack.pop();
		for (int i = 3; i <= N; ++i)
		{
			if (Check[i + 1] == false)
			{
				Check[i + 1] = true;
				Stack.push(i + 1);
			}
			if (Check[i + 2] == false)
			{
				Check[i + 2] = true;
				Stack.push(i + 2);
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("testcase_SteppingStone.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &Score[i]);
		}
	}
	return 0;
}