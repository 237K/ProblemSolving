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
using namespace std;

enum Structure{ grassland = 0, gate = 1, vol = 2 };
typedef pair<int, int> PII;

class Volcano
{
private:
	int **Map;
	int size;
	vector<PII> VolcanoLocate;
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
		VolcanoLocate.clear();
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
					VolcanoLocate.push_back(PII(r, c));
				}
			}
		}
	}
	void Explosion()
	{
		PII Loc;
		PII LocCopy;
		for (vector<PII>::size_type i = 1; i <= VolcanoLocate.size(); ++i)
		{
			if (!VolcanoLocate.empty())
			{
				Loc = VolcanoLocate.back();
				VolcanoLocate.pop_back();
				LocCopy = Loc;
			}
			//North
			while (1)
			{
				if (LocCopy.first - 1 >= 0 && Map[LocCopy.first - 1][LocCopy.second] == 0)
				{
					Map[LocCopy.first - 1][LocCopy.second] = 1;
					LocCopy.first -= 1;
				}
				else
				{
					LocCopy = Loc;
					break;
				}
			}
			//East
			while (1)
			{
				if (LocCopy.second + 1 < size && Map[LocCopy.first][LocCopy.second + 1] == 0)
				{
					Map[LocCopy.first][LocCopy.second + 1] = 1;
					LocCopy.second += 1;
				}
				else
				{
					LocCopy = Loc;
					break;
				}
			}
			//South
			while (1)
			{
				if (LocCopy.first + 1 < size && Map[LocCopy.first + 1][LocCopy.second] == 0)
				{
					Map[LocCopy.first + 1][LocCopy.second] = 1;
					LocCopy.first += 1;
				}
				else
				{
					LocCopy = Loc;
					break;
				}
			}
			//West
			while (1)
			{
				if (LocCopy.second - 1 >= 0 && Map[LocCopy.first][LocCopy.second - 1] == 0)
				{
					Map[LocCopy.first][LocCopy.second - 1] = 1;
					LocCopy.second -= 1;
				}
				else
				{
					LocCopy = Loc;
					break;
				}
			}
		}
		PrintMap();
		CheckMap();
		cout << endl;
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
			volcano[tc]->Explosion();
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
