//
//  OS Windows
//  2019.02.11
//
//  [Algorithm Problem Solving]
//
//  <ȭ�� ���� 2>
//
//	1. ������ ���´� 0 �ʿ�, 1 �ٸ�����Ʈ, 2 ȭ�� ���� ������
//	2. ȭ���� �����ϸ� ����� ������� �귯���� �ʿ��� �ı��س���
//	3. ����� �ٸ�����Ʈ�� ȭ���� ������ ������ �� ����
//	4. (+) ��ǲ������ �־����� ���� ��ŭ�� �ٸ�����Ʈ�� �߰������� �ʿ��� ���� �� ����
//	5. �ʿ� �ı��� �ּ�ȭ �Ǵ� ����� �ı����� ���� �ʿ� ������ ���
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
	vector<PII> Volcano;	//�Է¹��� �� ȭ���� ��ǥ�� �����ص�
	queue<PII> Lava;		//����� �귯���� ������ BFS�� �����ϱ� ����
	vector<PII> Grass;		//�Է¹��� �� �ʿ��� ��ǥ�� �����ص�
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
		//����
		if (_Loc.first - 1 >= 0 && Map[_Loc.first - 1][_Loc.second] == 0)
		{
			Lava.push(PII(_Loc.first - 1, _Loc.second));
			Map[_Loc.first - 1][_Loc.second] = 3;
		}
		//����
		if (_Loc.second + 1 < Size && Map[_Loc.first][_Loc.second + 1] == 0)
		{
			Lava.push(PII(_Loc.first, _Loc.second + 1));
			Map[_Loc.first][_Loc.second + 1] = 3;
		}
		//����
		if (_Loc.first + 1 < Size && Map[_Loc.first + 1][_Loc.second] == 0)
		{
			Lava.push(PII(_Loc.first + 1, _Loc.second));
			Map[_Loc.first + 1][_Loc.second] = 3;
		}
		//����
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
		cout << "������ ã�� �� �����ϴ�." << endl;

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