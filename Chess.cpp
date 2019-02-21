//
//	OS Windows
//	2019.02.10
//
//	[Algorithm Problem Solving]
//
//	<새로운 체스 게임>
//
//	1. 3종류의 퀸(A, B, C)이 있음. 퀸은 가로, 세로, 대각선으로 이동할 수 있음
//	2. A형 퀸은 1칸, B형 퀸은 2칸, C형 퀸은 3칸씩 이동할 수 있음
//	3. 0 0 1 5 5 6, 2 4 5 2, 3 2 5 5  와 같은 형태로 각 퀸의 좌표가 주어짐
//	4. 퀸이 이동할 수 없는 위치의 개수를 출력
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
typedef pair<int, int> PII;

class Chess
{
private:
	int Size;
	int** Board;
	int Answer;
public:
	explicit Chess(int _Size);
	~Chess();
	void Print() const;
	void SetA(queue<int> q);
	void SetB(queue<int> q);
	void SetC(queue<int> q);
	void Search();
};

Chess::Chess(int _Size) : Size(_Size), Answer(0)
{
	Board = new int*[_Size];
	for (int r = 0; r < _Size; ++r)
	{
		Board[r] = new int[_Size];
		for (int c = 0; c < _Size; ++c)
		{
			Board[r][c] = 0;
		}
	}
}

Chess::~Chess()
{
	for (int del = 0; del < Size; ++del)
	{
		delete[] Board[del];
	}
	delete[] Board;
}

void Chess::Print() const
{
	for (int r = 0; r < Size; ++r)
	{
		for (int c = 0; c < Size; ++c)
		{
			cout << Board[r][c] << ' ';
		}
		cout << endl << endl;
	}
}

void Chess::SetA(queue<int> q)
{
	while (!q.empty())
	{
		int tempR = q.front();
		q.pop();
		int tempC = q.front();
		q.pop();
		Board[tempR][tempC] = 1;
		if(tempR-1 >= 0 && tempC-1 >= 0)
			Board[tempR-1][tempC-1] = 1;
		if (tempR - 1 >= 0)
			Board[tempR - 1][tempC] = 1;
		if (tempC - 1 >= 0)
			Board[tempR][tempC - 1] = 1;
		if (tempR + 1 < Size && tempC + 1 < Size)
			Board[tempR + 1][tempC + 1] = 1;
		if (tempR + 1 < Size)
			Board[tempR + 1][tempC] = 1;
		if (tempC + 1 < Size)
			Board[tempR][tempC + 1] = 1;
		if (tempR + 1 < Size && tempC - 1 >= 0)
			Board[tempR + 1][tempC - 1] = 1;
		if (tempR - 1 >= 0 && tempC + 1 < Size)
			Board[tempR - 1][tempC + 1] = 1;
	}

}

void Chess::SetB(queue<int> q)
{
	while (!q.empty())
	{
		int tempR = q.front();
		q.pop();
		int tempC = q.front();
		q.pop();
		Board[tempR][tempC] = 2;
		if (tempR - 1 >= 0 && tempC - 1 >= 0)
			Board[tempR - 1][tempC - 1] = 2;
		if (tempR - 1 >= 0)
			Board[tempR - 1][tempC] = 2;
		if (tempC - 1 >= 0)
			Board[tempR][tempC - 1] = 2;
		if (tempR + 1 < Size && tempC + 1 < Size)
			Board[tempR + 1][tempC + 1] = 2;
		if (tempR + 1 < Size)
			Board[tempR + 1][tempC] = 2;
		if (tempC + 1 < Size)
			Board[tempR][tempC + 1] = 2;
		if (tempR + 1 < Size && tempC - 1 >= 0)
			Board[tempR + 1][tempC - 1] = 2;
		if (tempR - 1 >= 0 && tempC + 1 < Size)
			Board[tempR - 1][tempC + 1] = 2;

		if (tempR - 2 >= 0 && tempC - 2 >= 0)
			Board[tempR - 2][tempC - 2] = 2;
		if (tempR - 2 >= 0)
			Board[tempR - 2][tempC] = 2;
		if (tempC - 2 >= 0)
			Board[tempR][tempC - 2] = 2;
		if (tempR + 2 < Size && tempC + 2 < Size)
			Board[tempR + 2][tempC + 2] = 2;
		if (tempR + 2 < Size)
			Board[tempR + 2][tempC] = 2;
		if (tempC + 2 < Size)
			Board[tempR][tempC + 2] = 2;
		if (tempR + 2 < Size && tempC - 2 >= 0)
			Board[tempR + 2][tempC - 2] = 2;
		if (tempR - 2 >= 0 && tempC + 2 < Size)
			Board[tempR - 2][tempC + 2] = 2;
	}
}

void Chess::SetC(queue<int> q)
{
	while (!q.empty())
	{
		int tempR = q.front();
		q.pop();
		int tempC = q.front();
		q.pop();
		Board[tempR][tempC] = 3;
		if (tempR - 1 >= 0 && tempC - 1 >= 0)
			Board[tempR - 1][tempC - 1] = 3;
		if (tempR - 1 >= 0)
			Board[tempR - 1][tempC] = 3;
		if (tempC - 1 >= 0)
			Board[tempR][tempC - 1] = 3;
		if (tempR + 1 < Size && tempC + 1 < Size)
			Board[tempR + 1][tempC + 1] = 3;
		if (tempR + 1 < Size)
			Board[tempR + 1][tempC] = 3;
		if (tempC + 1 < Size)
			Board[tempR][tempC + 1] = 3;
		if (tempR + 1 < Size && tempC - 1 >= 0)
			Board[tempR + 1][tempC - 1] = 3;
		if (tempR - 1 >= 0 && tempC + 1 < Size)
			Board[tempR - 1][tempC + 1] = 3;

		if (tempR - 2 >= 0 && tempC - 2 >= 0)
			Board[tempR - 2][tempC - 2] = 3;
		if (tempR - 2 >= 0)
			Board[tempR - 2][tempC] = 3;
		if (tempC - 2 >= 0)
			Board[tempR][tempC - 2] = 3;
		if (tempR + 2 < Size && tempC + 2 < Size)
			Board[tempR + 2][tempC + 2] = 3;
		if (tempR + 2 < Size)
			Board[tempR + 2][tempC] = 3;
		if (tempC + 2 < Size)
			Board[tempR][tempC + 2] = 2;
		if (tempR + 2 < Size && tempC - 2 >= 0)
			Board[tempR + 2][tempC - 2] = 3;
		if (tempR - 2 >= 0 && tempC + 2 < Size)
			Board[tempR - 2][tempC + 2] = 3;

		if (tempR - 3 >= 0 && tempC - 3 >= 0)
			Board[tempR - 3][tempC - 3] = 3;
		if (tempR - 3 >= 0)
			Board[tempR - 3][tempC] = 3;
		if (tempC - 3 >= 0)
			Board[tempR][tempC - 3] = 3;
		if (tempR + 3 < Size && tempC + 3 < Size)
			Board[tempR + 3][tempC + 3] = 3;
		if (tempR + 3 < Size)
			Board[tempR + 3][tempC] = 3;
		if (tempC + 3 < Size)
			Board[tempR][tempC + 3] = 3;
		if (tempR + 3 < Size && tempC - 3 >= 0)
			Board[tempR + 3][tempC - 3] = 3;
		if (tempR - 3 >= 0 && tempC + 3 < Size)
			Board[tempR - 3][tempC + 3] = 3;
	}
}

void Chess::Search()
{
	for (int r = 0; r < Size; ++r)
	{
		for (int c = 0; c < Size; ++c)
		{
			if (Board[r][c] == 0)
				Answer++;
		}
	}
	printf("%d\n", Answer);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	char Input[2];
	Chess *Game[10];
	queue<int> Q;
	freopen("testcase_Chess.txt", "r", stdin);
	scanf("%d\n", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d\n", &N);
		Game[test_case] = new Chess(N);
		int cnt = 0;
		while (!Q.empty()) { Q.pop(); }
		while(1)
		{
			if (cnt == 3)
				break;
			else
			{
				*Input = { NULL, };
				scanf("%c", Input);
				if (Input[0] == ',' || Input[0] == '\n' || Input[0] == '\0')
				{
					cnt++;
					if (cnt == 1)
					{
						Game[test_case]->SetA(Q);
					}
					else if (cnt == 2)
					{
						Game[test_case]->SetB(Q);
					}
					else
					{
						Game[test_case]->SetC(Q);
					}
					while (!Q.empty()) { Q.pop(); }
					continue;
				}
				else if (Input[0] == ' ')
					continue;
				else
				{
					int temp = Input[0] - '0';
					Q.push(temp);
				}
			}
		}
		printf("#%d ", test_case);
		Game[test_case]->Search();
		Game[test_case]->Print();
	}
	for (int d = 1; d <= T; ++d)
	{
		delete Game[d];
	}
	return 0;
}