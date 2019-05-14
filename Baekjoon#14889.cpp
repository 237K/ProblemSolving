//
//	OS Windows
//	2019.02.24
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14889	스타트와 링크
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const static int MAX = 20;
const static int INF = 2147000000;

static int Chart[MAX][MAX];
static bool Check[MAX];
static int N;
static int StartMember[MAX/2];
static int LinkMember[MAX/2];
static int Difference;

inline void ClearChart()
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

inline void Pick(int cnt)
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
				LinkMember[idx] = i;			//	Start팀 멤버가 아닌사람을 Link팀으로
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

		int tempScore = abs(StartScore - LinkScore);
		Difference = min(Difference, tempScore);

		for (int init = 0; init < idx; ++init)
		{
			Check[LinkMember[init]] = false;	//	*Link팀 멤버로 넣었던 사람들 체크 해제
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
				StartMember[cnt] = i;			//	Start팀 구성을 조합함
				Pick(cnt + 1);
				Check[i] = false;
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	freopen("testcase_Baekjoon#14889.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ClearChart();
		Difference = INF;
		cin >> N;
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				cin>>Chart[r][c];
			}
		}
		Pick(0);
		cout << "#" << test_case << ' ' << Difference << '\n';
	}
	return 0;
}