//
//	OS Windows
//	2019.02.07
//
//	[Algorithm Problem Solving]
//
//	<�̷� ã��>
//	1. ���α��̿� ���α���, ������ǥ�� Ż�ⱸ��ǥ, ��ǥ�� �̵��� �� �ִ���(0) �̵��� �� ������(1) �־���	
//	2. Ż�ⱸ���� ���� �ִܰ�� ���. ��ΰ� ������ -1
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

class Maze
{
private:
	int **Map;
	int Row, Column;
	PII Start;
	PII Exit;
	vector<int> Distance;
	queue<PII> Q;
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
		Q.push(Start);
		while (!Q.empty())
		{
			PII CurLocate = Q.front();
			Q.pop();
			Search(CurLocate);
		}
		if (IsThereAnswer)
		{
			cout << "Answer : " << Answer << endl << endl;
		}
		else
			cout << "Answer : -1" << endl << endl;
	}
	void Search(PII Loc)
	{
		int NotCounter = 0;
		if (Loc.first - 1 >= 1 && Map[Loc.first - 1][Loc.second] == 0)
		{
			Q.push(PII(Loc.first - 1, Loc.second));
			if (IsExit(PII(Loc.first - 1, Loc.second)))
			{
				Answer++;
				IsThereAnswer = true;
				while (!Q.empty())
				{
					Q.pop();
				}
				break;
			}
		}
		else
			NotCounter++;
		if (Loc.second + 1 <= Column && Map[Loc.first][Loc.second + 1] == 0)
		{
			Q.push(PII(Loc.first, Loc.second + 1));
			if (IsExit(PII(Loc.first - 1, Loc.second)))
			{
				Answer++;
				IsThereAnswer = true;
				while (!Q.empty())
				{
					Q.pop();
				}
				break;
			}
		}
		else
			NotCounter++;
		if (Loc.first + 1 <= Row && Map[Loc.first + 1][Loc.second] == 0)
		{
			Q.push(PII(Loc.first + 1, Loc.second));
			if (IsExit(PII(Loc.first - 1, Loc.second)))
			{
				Answer++;
				IsThereAnswer = true;
				while (!Q.empty())
				{
					Q.pop();
				}
				break;
			}
		}
		else
			NotCounter++;
		if (Loc.second - 1 >= 1 && Map[Loc.first][Loc.second - 1] == 0)
		{
			Q.push(PII(Loc.first, Loc.second - 1));
			if (IsExit(PII(Loc.first - 1, Loc.second)))
			{
				Answer++;
				IsThereAnswer = true;
				while (!Q.empty())
				{
					Q.pop();
				}
				break;
			}
		}
		else
			NotCounter++;
		if (NotCounter != 4)
		{
			Answer++;
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
	}

	for (int del = 1; del <= testcase; del++)
	{
		delete maze[del];
	}
	fout.close();
	fin.close();
	return 0;
}