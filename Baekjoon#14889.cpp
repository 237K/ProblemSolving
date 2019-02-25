//
//	OS Windows
//	2019.02.24
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14889	스타트와 링크
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const static int MAX = 20;
const static int INF = 2147000000;

int Chart[MAX][MAX];
bool Check[MAX];
int N;
int StartMember[MAX/2];
int LinkMember[MAX/2];
int Difference;

void ClearChart()
{
	for (int r = 0; r < MAX; ++r)
	{
		Check[r] = false;
		StartMember[r] = -1;
		LinkMember[r] = -1;
		for (int c = 0; c < MAX; ++c)
		{
			Chart[r][c] = 0;
		}
	}
}

void Pick(int cnt)
{
	if (cnt == N/2)
	{
		int idx = 0;
		int StartScore = 0;
		int LinkScore = 0;
		for (int i = 0; i < N; ++i)				
		{
			if (Check[i] == false)
			{
				Check[i] = true;
				LinkMember[idx] = i;			//Start팀 멤버가 아닌사람을 Link팀으로
				idx++;
				continue;
			}
		}

		for (int r = 0; r < N / 2; ++r)
		{
			for (int c = 0; c < N / 2; ++c)
			{
				if (r != c)
				{
					StartScore += Chart[StartMember[r]][StartMember[c]];
					LinkScore += Chart[LinkMember[r]][LinkMember[c]];
				}
			}
		}

		cout << "Start team : ";
		for (int r = 0; r < N / 2; ++r)
		{
			cout << StartMember[r] << ' ';
		}
		cout << endl;
		cout << "Start team Score : " << StartScore << endl;
		cout << "Link team : ";
		for (int r = 0; r < N / 2; ++r)
		{
			cout << LinkMember[r] << ' ';
		}
		cout << endl;
		cout << "Link team Score : " << LinkScore << endl << endl;

		int tempScore = abs(StartScore - LinkScore);
		if (Difference > tempScore)
			Difference = tempScore;

		for (int init = 0; init < idx; ++init)
		{
			Check[LinkMember[init]] = false;	//Link팀 멤버로 넣었던 사람들 체크 해제
		}
		return;
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			if (Check[i] == false)
			{
				Check[i] = true;
				StartMember[cnt] = i;			//DFS로 Start팀 구성을 조합함
				Pick(cnt + 1);
				Check[i] = false;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int T;
	int test_case;
	freopen("testcase_Baekjoon#14889.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ClearChart();
		Difference = INF;
		scanf("%d", &N);
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				scanf("%d", &Chart[r][c]);
			}
		}
		Pick(0);
		printf("#%d %d\n\n", test_case, Difference);
	}
	return 0;
}