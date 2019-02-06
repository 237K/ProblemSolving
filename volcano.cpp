//
//  OS Windows
//  Created by 형성모 on 02/06/2019.
//
//  [Algorithm Problem Solving]
//
//  <화산 폭발>
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

enum Structure{ grassland = 0, gate = 1, vol = 2 };
typedef pair<int, int> PII;

class Volcano
{
private:
	int **Map;
	int size;
	queue<PII> VolcanoLocate;
public:
	Volcano(int _size) : size(_size)
	{
		Map = new int*[_size];
		for (int r = 0; r < _size; ++r)
		{
			Map[r] = new int[_size];
			for (int c = 0; c < _size; ++c)
			{
				Map[r][c] = 0;
			}
		}
	}
	~Volcano()
	{
		for (int del = 0; del < size; ++del)
		{
			delete[] Map[del];
		}
		delete[] Map;
	}
	void MakeMap(ifstream& _fin)
	{
		for (int r = 0; r < size; ++r)
		{
			for (int c = 0; c < size; ++c)
			{
				_fin >>	Map[r][c];
				if (Map[r][c] == 2)
				{
					VolcanoLocate.push(PII(r, c));
				}
			}
		}
	}
	void Execution()
	{
		PII RecentLoc;
		while(!VolcanoLocate.empty())
		{
			RecentLoc = VolcanoLocate.front();
			VolcanoLocate.pop();
			Explosion(RecentLoc);
		}
		PrintMap();
		CheckMap();
		cout << endl;
	}
	void Explosion(PII _RecentLoc)
	{

			if (_RecentLoc.first - 1 >= 0 && Map[_RecentLoc.first - 1][_RecentLoc.second] == 0)
			{
				Map[_RecentLoc.first - 1][_RecentLoc.second] = 1;
				VolcanoLocate.push(PII(_RecentLoc.first - 1, _RecentLoc.second));
			}
			if (_RecentLoc.second + 1 < size && Map[_RecentLoc.first][_RecentLoc.second + 1] == 0)
			{
				Map[_RecentLoc.first][_RecentLoc.second + 1] = 1;
				VolcanoLocate.push(PII(_RecentLoc.first, _RecentLoc.second + 1));
			}
			if (_RecentLoc.first + 1 < size && Map[_RecentLoc.first + 1][_RecentLoc.second] == 0)
			{
				Map[_RecentLoc.first + 1][_RecentLoc.second] = 1;
				VolcanoLocate.push(PII(_RecentLoc.first + 1, _RecentLoc.second));
			}
			if (_RecentLoc.second - 1 >= 0 && Map[_RecentLoc.first][_RecentLoc.second - 1] == 0)
			{
				Map[_RecentLoc.first][_RecentLoc.second - 1] = 1;
				VolcanoLocate.push(PII(_RecentLoc.first, _RecentLoc.second - 1));
			}
	}
	void CheckMap()
	{
		int Unaffected = 0;
		for (int r = 0; r < size; ++r)
		{
			for (int c = 0; c < size; ++c)
			{
				if (Map[r][c] == 0)
				{
					Unaffected += 1;
				}
			}
		}
		cout << "Unaffected Area : " << Unaffected << endl << endl;
	}
	void PrintMap() const
	{
		for (int r = 0; r < size; ++r)
		{
			for (int c = 0; c < size; ++c)
			{
				cout << Map[r][c] << ' ';
			}
			cout << endl << endl;
		}
	}
};

class Simulator
{
private:
	Volcano *volcano[100];
	int testcase;
	int MapSize;
public:
	Simulator(int _testcase) : testcase(_testcase), MapSize(0) {}
	~Simulator()
	{
		for (int del = 1; del <= testcase; ++del)
		{
			delete volcano[del];
		}
	}
	void Simul(ifstream& _fin)
	{
		for (int tc = 1; tc <= testcase; ++tc)
		{
			_fin >> MapSize;
			volcano[tc] = new Volcano(MapSize);
			volcano[tc]->MakeMap(_fin);
			cout << "#" << tc << endl;
			volcano[tc]->Execution();
		}
	}
};

int main(void)
{
	int testcase = 0;

	ifstream fin("testcase_Volcano.txt");
	if (!fin.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	fin >> testcase;
	Simulator simulator(testcase);
	simulator.Simul(fin);

	fin.close();
	return 0;
}
