//
//  OS Windows
//  2019.02.11
//
//  [Algorithm Problem Solving]
//
//  <화산 폭발 2>
//
//	1. 격자의 상태는 0 초원, 1 바리게이트, 2 화산 으로 구성됨
//	2. 화산이 폭발하면 용암이 사방으로 흘러나와 초원을 파괴해나감
//	3. 용암이 바리게이트나 화산을 만나면 지나갈 수 없음
//	4. (+) 인풋값으로 주어지는 개수 만큼의 바리게이트를 추가적으로 초원에 세울 수 있음
//	5. 초원 파괴가 최소화 되는 경우의 파괴되지 않은 초원 개수를 출력
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

class Graph
{
private:
	int **Map;
	int Size;
	int NumOfGate;
	vector<PII> Volcano;	//입력받을 때 화산의 좌표를 저장해둠
	queue<PII> Lava;		//용암이 흘러가는 과정을 BFS로 구현하기 위함
	vector<PII> Grass;		//입력받을 때 초원의 좌표를 저장해둠
	bool **Check;			//
	int Unaffected;
public:
	Graph(int _Size, int _Gate) : Size(_Size), NumOfGate(_Gate), Unaffected(0)
	{
		Map = new int*[_Size];
		Check = new bool*[_Size];
		for (int r = 0; r < _Size; ++r)
		{
			Map[r] = new int[_Size];
			Check[r] = new bool[_Size];
			for (int c = 0; c < _Size; ++c)
			{
				Map[r][c] = 0;
				Check[r][c] = false;
			}
		}
		Volcano.clear();
		while (!Lava.empty()) { Lava.pop(); }
	}
	~Graph()
	{
		for (int del = 0; del < Size; ++del)
		{
			delete[] Map[del];
		}
		delete[] Map;
	}
	void Setting(ifstream& _fin)
	{
		for (int r = 0; r < Size; r++)
		{
			for (int c = 0; c < Size; c++)
			{
				_fin >> Map[r][c];
				if (Map[r][c] == 0)
				{
					Grass.push_back(PII(r, c));
				}
				if (Map[r][c] == 2)
				{
					Volcano.push_back(PII(r, c));
				}
			}
		}
	}
	void Simulation(int depth)
	{
		cout << "depth : " << depth << endl;
		if (depth == NumOfGate + 1)
		{
			//int ThisTime = 0;
			//Eruption();
			//ThisTime = CountArea();
			//if (Unaffected > ThisTime)
			//	Unaffected = ThisTime;
			//cout << "Unaffected Area : " << Unaffected << endl << endl;
			return;
		}
		else
		{
			for (vector<int>::size_type i = 0; i < Grass.size(); ++i)
			{
				PII CurGrass = Grass[i];
				cout << "(" << CurGrass.first << ", " << CurGrass.second << ") ";
				if (Check[CurGrass.first][CurGrass.second] == false)
				{
					Check[CurGrass.first][CurGrass.second] = true;
					Map[CurGrass.first][CurGrass.second] = 1;
					Simulation(depth + 1);
					Check[CurGrass.first][CurGrass.second] = false;
					Map[CurGrass.first][CurGrass.second] = 0;
				}
			}
		}
	}
	void Eruption()
	{
		for (vector<PII>::size_type i = 0; i < Volcano.size(); i++)
		{
			Lava.push(Volcano[i]);
		}
		while (!Lava.empty())
		{
			PII CurLoc = Lava.front();
			Lava.pop();
			Destroy(CurLoc);
		}
	}
	void Destroy(PII _Loc)
	{
		//북쪽
		if (_Loc.first - 1 >= 0 && Map[_Loc.first - 1][_Loc.second] == 0)
		{
			Lava.push(PII(_Loc.first - 1, _Loc.second));
			Map[_Loc.first - 1][_Loc.second] = 3;
		}
		//동쪽
		if (_Loc.second + 1 < Size && Map[_Loc.first][_Loc.second + 1] == 0)
		{
			Lava.push(PII(_Loc.first, _Loc.second + 1));
			Map[_Loc.first][_Loc.second + 1] = 3;
		}
		//남쪽
		if (_Loc.first + 1 < Size && Map[_Loc.first + 1][_Loc.second] == 0)
		{
			Lava.push(PII(_Loc.first + 1, _Loc.second));
			Map[_Loc.first + 1][_Loc.second] = 3;
		}
		//서쪽
		if (_Loc.second - 1 >= 0 && Map[_Loc.first][_Loc.second - 1] == 0)
		{
			Lava.push(PII(_Loc.first, _Loc.second - 1));
			Map[_Loc.first][_Loc.second - 1] = 3;
		}
	}
	int CountArea()
	{
		int Recent = 0;
		for (int r = 0; r < Size; ++r)
		{
			for (int c = 0; c < Size; ++c)
			{
				if (Map[r][c] == 0)
					Recent++;
			}
		}
		return Recent;
	}
};

int main(void)
{
	Graph *graph[101];
	int testcase = 0;
	int _Size, _Gate;
	clock_t timer_s, timer_e;
	double timer;

	timer_s = clock();
	ifstream fin("testcase_Volcano2.txt");
	if (!fin.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		fin >> _Size >> _Gate;
		graph[tc] = new Graph(_Size, _Gate);
		graph[tc]->Setting(fin);
		cout << "#" << tc << endl;
		graph[tc]->Simulation(1);
	}

	fin.close();

	for (int del = 1; del <= testcase; ++del)
	{
		delete graph[del];
	}
	timer_e = clock();
	timer = (double)(timer_e - timer_s);
	cout << "Execution Time : " << timer << "ms" << endl << endl;
	return 0;
}