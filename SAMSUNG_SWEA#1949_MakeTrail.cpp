//
//	OS Windows
//	2019.02.20
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1949] <등산로 조성> (모의 SW 역량테스트)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> PII;
const static int MAX = 8;

//처음에 class로 만들었다가 채점서버 통과가 안되서.. 안타깝게도 변수가 다 밖에 튀어나와있습니다..
int Map[MAX][MAX];					//지형정보 저장
bool Check[MAX][MAX];				//좌표 방문 여부 확인
int N, K;
stack<PII> Start;					//제일 높은 봉우리 좌표 저장해둘 stack
int Top;							//제일 높은 봉우리 높이 저장
int Count;							//등산로 길이 저장
bool CanDig;						//공사를 했는지 안했는지 확인하기 위함
int Answer;

void Make(PII L)					//DFS
{
	Check[L.first][L.second] = true;								//좌표 방문 체크
	if (L.first - 1 >= 0 && Check[L.first - 1][L.second] == false)	//맵을 벗어나지 않고, 방문한적이 없는 경우
	{
		if (Map[L.first - 1][L.second] < Map[L.first][L.second])	//다음 지형이 지금보다 지형이 낮으면
		{
			Count++;												//등산로 설치하고
			Make(PII(L.first - 1, L.second));						//다음 좌표로 재귀호출
			Answer = max(Answer, Count);							//이 경로로 갔을 때 등산로길이가 지금보다 길면 갱신
			Count--;												//다른 경로 탐색을 위해 초기화
		}
		else
		{																				//맵을 벗어나지 않고 방문한적은 없는데, 다음 지형이 지금보다 높거나 지금과 같으면
			int dig1 = abs(Map[L.first][L.second] - Map[L.first - 1][L.second]) + 1;	//얼마나 파야될지 견적을 뽑아보고(지금보다 1만 낮은 경우에 그 다음 지형으로 갈 수 있을 확률이 높음)
			if (CanDig == true && dig1 <= K)											//공사를 한 적이 없고, 공사 가능 깊이면
			{
				Map[L.first - 1][L.second] -= dig1;										//공사하고
				CanDig = false;															//공사 한 번 했으니, 이제 못함
				Count++;																//등산로 설치
				Make(PII(L.first - 1, L.second));										//다음 좌표로 재귀호출
				Answer = max(Answer, Count);											//여기로 갔을 때 최대 길이가 있으면 갱신
				CanDig = true;															//다른 경로 탐색을 위해 초기화
				Map[L.first - 1][L.second] += dig1;
				Count--;
			}
		}
	}
	if (L.first + 1 < N && Check[L.first + 1][L.second] == false)
	{
		if (Map[L.first + 1][L.second] < Map[L.first][L.second])
		{
			Count++;
			Make(PII(L.first + 1, L.second));
			Answer = max(Answer, Count);
			Count--;
		}
		else
		{
			int dig2 = abs(Map[L.first][L.second] - Map[L.first + 1][L.second]) + 1;
			if (CanDig == true && dig2 <= K)
			{
				Map[L.first + 1][L.second] -= dig2;
				CanDig = false;
				Count++;
				Make(PII(L.first + 1, L.second));
				Answer = max(Answer, Count);
				CanDig = true;
				Map[L.first + 1][L.second] += dig2;
				Count--;
			}
		}
	}
	if (L.second - 1 >= 0 && Check[L.first][L.second - 1] == false)
	{
		if (Map[L.first][L.second - 1] < Map[L.first][L.second])
		{
			Count++;
			Make(PII(L.first, L.second - 1));
			Answer = max(Answer, Count);
			Count--;
		}
		else
		{
			int dig3 = abs(Map[L.first][L.second] - Map[L.first][L.second - 1]) + 1;
			if (CanDig == true && dig3 <= K)
			{
				Map[L.first][L.second - 1] -= dig3;
				CanDig = false;
				Count++;
				Make(PII(L.first, L.second - 1));
				Answer = max(Answer, Count);
				CanDig = true;
				Map[L.first][L.second - 1] += dig3;
				Count--;
			}
		}
	}
	if (L.second + 1 < N && Check[L.first][L.second + 1] == false)
	{
		if (Map[L.first][L.second + 1] < Map[L.first][L.second])
		{
			Count++;
			Make(PII(L.first, L.second + 1));
			Answer = max(Answer, Count);
			Count--;
		}
		else
		{
			int dig4 = abs(Map[L.first][L.second] - Map[L.first][L.second + 1]) + 1;
			if (CanDig == true && dig4 <= K)
			{
				Map[L.first][L.second + 1] -= dig4;
				CanDig = false;
				Count++;
				Make(PII(L.first, L.second + 1));
				Answer = max(Answer, Count);
				CanDig = true;
				Map[L.first][L.second + 1] += dig4;
				Count--;
			}
		}
	}
	Check[L.first][L.second] = false;
}

void PushStack()								//가장 높은 봉우리 찾아서 스택에 넣는 함수
{
	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
		{
			if (Map[r][c] == Top)
				Start.push(PII(r, c));
		}
	}
}

void InitMap()									//배열이랑 스택, 각종 변수 초기화 함수
{
	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
		{
			Map[r][c] = 0;
			Check[r][c] = false;
		}
	}
	while (!Start.empty()) { Start.pop(); }
	Answer = 0;
	Top = 0;
	N = 0;
	K = 0;
	CanDig = true;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		InitMap();
		scanf("%d %d", &N, &K);
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				scanf("%d", &Map[r][c]);
				if (Top < Map[r][c])
					Top = Map[r][c];
			}
		}
		PushStack();
		while (!Start.empty())
		{
			PII Cur = Start.top();
			Start.pop();
			Count = 1;
			Make(Cur);
		}
		printf("#%d %d\n", test_case, Answer);
	}
	return 0;
}