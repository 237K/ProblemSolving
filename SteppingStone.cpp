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
#include <algorithm>
using namespace std;
const static int MAX = 10001;
int N;
int Score[MAX] = { 0, };
int Stone[MAX][2] = { 0, };

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int Answer;
	freopen("testcase_SteppingStone.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Answer = -1;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{											
			scanf("%d", &Score[i]);					
			if (i == 1)
			{
				Stone[i][1] = Score[i];						//Stone[i][1]�� i-1��° ������ �� ĭ �ǳ� i��° ¡�˵��� �� ��츦 �ǹ��մϴ�.
				Stone[i][2] = Score[i];						//Stone[i][2]�� i-2��° ������ �� ĭ �ǳ� i��° ¡�˵��� �� ��츦 �ǹ��մϴ�.
			}
			else
			{
				Stone[i][1] = Stone[i - 1][2] + Score[i];							//�� ĭ�� �������� �̵��� �� �����Ƿ�, i-1��° ������ �� ĭ �ǳ� i���� �� ��� i-1�� ������ 2ĭ �ǳ� �Ծ�߸� �մϴ�. 
				Stone[i][2] = max(Stone[i - 2][1], Stone[i - 2][2]) + Score[i];		//i-2��° ������ i�� ���� �� ��쿡�� i-2�� ���� �� ĭ �ǳ� �Ծ��� ���� �ְ�, �� ĭ �ǳ� ���� ���� �ֽ��ϴ�.
			}																		//�� �߿� �ִ밪�� ������ �����ݴϴ�.
		}
		Answer = max(Stone[N][1], Stone[N][2]);
		printf("#%d %d\n", test_case, Answer);
	}
	return 0;
}