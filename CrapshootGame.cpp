//
//	OS Windows
//	2019.03.18
//
//	[Algorithm Problem Solving]
//
//	<동서남북 복불복>
//
//	1. 맵의 각 원소는 영대문자 1개와 숫자로 입력받음 (예 : N2, S3, W1, E4)
//	2. 시작 좌표와 이동 횟수를 입력받음
//	3. 도착한 좌표가 맵을 벗어나지 않으면 해당 좌표 원소의 숫자 X 1000을 출력, 맵을 벗어날 경우 10000 출력
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

typedef pair<char, int> CI;
const static int MAX = 11;

static CI Map[MAX][MAX];
static int N;
static int Result;

void Play(int r, int c, int cnt, int playcnt)
{
	cout << "(" << r << ", " << c << ") " << Map[r][c].first << " " << Map[r][c].second << " count : " << playcnt << endl;
	if (playcnt >= cnt)
	{
		Result = Map[r][c].second;
		if (Result != 10000)
			Result = Result * 1000;
		return;
	}
	else
	{
		switch (Map[r][c].first)
		{
		case 'N':
			if (r - Map[r][c].second < 1)
				Result = 10000;
			else
				Play(r - Map[r][c].second, c, cnt, playcnt + 1);
			break;
		case 'E':
			if (c + Map[r][c].second > N)
				Result = 10000;
			else
				Play(r, c + Map[r][c].second, cnt, playcnt + 1);
			break;
		case 'S':
			if (r + Map[r][c].second > N)
				Result = 10000;
			else
				Play(r + Map[r][c].second, c, cnt, playcnt + 1);
			break;
		case 'W':
			if (c - Map[r][c].second < 1)
				Result = 10000;
			else
				Play(r, c - Map[r][c].second, cnt, playcnt + 1);
			break;
		}
	}
}

int main(int argc, char** argv)
{
	int T;
	int test_case;
	freopen("testcase_CrapshootGame.txt", "r", stdin);
	scanf("%d", &T);
	scanf("%d", &N);

	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			scanf("%1s%1d", &Map[r][c].first, &Map[r][c].second);
		}
		cout << endl << endl;
	}

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int row = 0, col = 0, count = 0; Result = 0;
		scanf("%d %d %d", &row, &col, &count);
		Play(row, col, count, 1);
		printf("#%d %d\n", test_case, Result);
	}

	return 0;
}