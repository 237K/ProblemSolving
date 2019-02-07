//
//	OS Windows
//	2019.02.07
//
//	[Algorithm Problem Solving]
//
//	<미로 찾기>
//	1. 세로길이와 가로길이, 시작좌표와 탈출구좌표, 좌표로 이동할 수 있는지(0) 이동할 수 없는지(1) 주어짐	
//	2. 탈출구까지 가는 최단경로 출력. 경로가 없으면 -1
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const static int INF = 21370000;

class Maze
{
private:
	int **Map;
	int Row, Column;
	PII Start;
	PII Exit;
	queue<pair<PII, int>> Q;
	int Answer;
	bool IsThereAnswer;
public:
	Maze(int _Row = 0, int _Column = 0) : Row(_Row), Column(_Column), Start(PII(0, 0)), Exit(PII(0, 0)), Answer(0), IsThereAnswer(false)
	{
		Map = new int*[_Row + 1];
		for (int r = 1; r <= _Row; ++r)
		{
			Map[r] = new int[_Column + 1];
			for (int c = 1; c <= _Column; ++c)
			{
				Map[r][c] = 0;
			}
		}
		while (!Q.empty())
		{
			Q.pop();
		}
	}
	~Maze()
	{
		for (int del = 1; del <= Row; ++del)
		{
			delete[] Map[del];
		}
		delete[] Map;
	}
	void MakeMap(ifstream& _fin)
	{
		_fin >> Start.first >> Start.second >> Exit.first >> Exit.second;
		for (int r = 1; r <= Row; ++r)
		{
			for (int c = 1; c <= Column; ++c)
			{
				int Recent = 0;
				_fin >> Recent;
				Map[r][c] = Recent;
			}
		}
	}
	void Escape()
	{
		Q.push(pair<PII, int>(Start, 0));
		Map[Start.first][Start.second] = 1;
		while (!Q.empty())
		{
			PII CurLocate = Q.front().first;
			int Distance = Q.front().second;
			Q.pop();
			if (IsExit(CurLocate))
			{
				Answer = Distance;
				IsThereAnswer = true;
				break;
			}
			Search(CurLocate, Distance);
		}
		if (IsThereAnswer)
		{
			cout << "Answer : " << Answer << endl << endl;
		}
		else
			cout << "Answer : -1" << endl << endl;
	}
	void Search(PII Loc, int Dis)
	{
		int RecentDis = Dis;
		if (Loc.first - 1 >= 1)
		{
			if (Map[Loc.first - 1][Loc.second] == 0)
			{
				Dis++;
				Q.push(pair<PII, int>(PII(Loc.first - 1, Loc.second), Dis));
				Map[Loc.first - 1][Loc.second] = 1;
				Dis = RecentDis;
			}
		}

		if (Loc.second + 1 <= Column)
		{
			if (Map[Loc.first][Loc.second + 1] == 0)
			{
				Dis++;
				Q.push(pair<PII, int>(PII(Loc.first, Loc.second + 1), Dis));
				Map[Loc.first][Loc.second + 1] = 1;
				Dis = RecentDis;
			}
		}

		if (Loc.first + 1 <= Row)
		{
			if (Map[Loc.first + 1][Loc.second] == 0)
			{
				Dis++;
				Q.push(pair<PII, int>(PII(Loc.first + 1, Loc.second), Dis));
				Map[Loc.first + 1][Loc.second] = 1;
				Dis = RecentDis;
			}
		}

		if (Loc.second - 1 >= 1)
		{
			if (Map[Loc.first][Loc.second - 1] == 0)
			{
				Dis++;
				Q.push(pair<PII, int>(PII(Loc.first, Loc.second - 1), Dis));
				Map[Loc.first][Loc.second - 1] = 1;
				Dis = RecentDis;
			}
		}
	}
	bool IsExit(PII Loc)
	{
		if (Loc == Exit)
			return true;
		else
			return false;
	}
};

int main(void)
{
	Maze *maze[100];
	int testcase = 0;
	int _Row = 0, _Column = 0;
	ifstream fin("testcase_Maze.txt");
	ofstream fout("Answer_237.txt");

	fin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		fin >> _Row >> _Column;
		maze[tc] = new Maze(_Row, _Column);
		maze[tc]->MakeMap(fin);
		cout << "#" << tc << endl;
		maze[tc]->Escape();
	}

	for (int del = 1; del <= testcase; del++)
	{
		delete maze[del];
	}
	fout.close();
	fin.close();
	return 0;
}