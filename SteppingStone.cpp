//
//	OS Windows
//	2019.02.16
//
//	[Algorithm Problem Solving]
//
//	<¡�˴ٸ� �ǳʱ�>
//	
//	1. N���� ¡�˵��� �־���. �� ¡�˵����� ������ ����
//	2. i��° ¡�˵��� ��Ҵٸ� i+1, i+2��° ¡�˵��� �� �� ����. ������ ���ӵ� �� ���� ¡�˵��� ���� �� ����. �ٸ� ù ��° ¡�˵����� 2��°, 3��°�δ� �̵��� �� ����
//	3. ������ N��° ¡�˵��� �� ��ƾ� ��.
//	4. �ִ����� ���

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