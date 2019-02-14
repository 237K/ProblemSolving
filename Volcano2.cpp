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

//	�ʿ��� �ٸ�����Ʈ�� ��ġ�ϴ� ���(�� DFS�� ������)�ȿ��� BFS(����� �ʿ� �ı��س���)�� ������ ������� ������
//	{DFS(BFS)} ����
//
//	(*Core Function)
//	1. Graph::void Simulation(int) -> DFS(Recursion), �ٸ�����Ʈ�� ��ġ�ϴ� ��� ����� ���� ��ȸ
//	2. Graph::void Eruption() -> BFS(queue), ����� �귯���鼭 �ʿ� �ı�
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
	bool **Check;			//DFS���� �� ����ϱ� ����
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
		Grass.clear();
		while (!Lava.empty()) { Lava.pop(); }
	}
	~Graph()
	{
		for (int del = 0; del < Size; ++del)
		{
			delete[] Map[del];
			delete[] Check[del];
		}
		delete[] Map;
		delete[] Check;
	}
	void Setting(ifstream& _fin)					//�ʱ� �� ���� ��ǲ�� �о���� �Լ�
	{
		for (int r = 0; r < Size; r++)
		{
			for (int c = 0; c < Size; c++)
			{
				_fin >> Map[r][c];
				if (Map[r][c] == 0)					//�ʱ� ������ ���°� 0�̸�
				{
					Grass.push_back(PII(r, c));		//�ش� ��ǥ�� Grass ���Ϳ� ����
				}
				if (Map[r][c] == 2)					//�ʱ� ������ ���°� 2�̸�
				{
					Volcano.push_back(PII(r, c));	//�ش� ��ǥ�� Volcano ���Ϳ� ����
				}
			}
		}
	}
	void Simulation(int depth)						//(*Core Function) �ʿ��� �ٸ�����Ʈ�� ��ġ�ϴ� ��� ����� ���� ��ȸ
	{												
		if (depth == NumOfGate + 1)					//Ż�� ����
		{											//��ǲ������ �־��� �ٸ�����Ʈ����ŭ ��ġ�ϸ�
			int ThisTime = 0;
			Eruption();								//ȭ������
			//PrintMap();							//(����� �ùķ��̼� �ǰ� �ִ��� Ȯ���ϱ� ����)
			ThisTime = CountArea();					//�ı����� ���� �ʿ��� ���������� ������ ����
			if (Unaffected < ThisTime)
				Unaffected = ThisTime;				
			ClearMap();								//���� �ʱⰪ���� �ʱ�ȭ
			return;
		}
		else
		{																					//Ž�� ����
			for (vector<int>::size_type i = 0; i < Grass.size(); ++i)
			{
				PII CurGrass = Grass[i];
				if (Check[CurGrass.first][CurGrass.second] == false)
				{
					//cout << "(" << CurGrass.first << ", " << CurGrass.second << ") ";		//��� ����� ���� Ž���ϴ��� Ȯ���ϱ� ����
					Check[CurGrass.first][CurGrass.second] = true;
					Map[CurGrass.first][CurGrass.second] = 1;
					Simulation(depth + 1);
					Check[CurGrass.first][CurGrass.second] = false;
					Map[CurGrass.first][CurGrass.second] = 0;
					//cout << endl;
				}
			}
		}
	}
	void Eruption()														//(*Core Function) ����� �귯���鼭 �ʿ��� �ı��ϴ� �Լ�
	{
		for (vector<PII>::size_type i = 0; i < Volcano.size(); i++)		//ȭ���� ��ǥ�� �����ص� ���Ϳ��� ��ǥ�� �ϳ��� ������
		{
			Lava.push(Volcano[i]);										//ť�� Ǫ��
		}
		while (!Lava.empty())
		{
			PII CurLoc = Lava.front();									//�ӽú����� ȭ����ǥ�� �ְ�
			Lava.pop();													//ť���� ���ϰ�
			Destroy(CurLoc);											//Destroy�Լ� ȣ��
		}
	}
	void Destroy(PII _Loc)														//(*Core Function)
	{
		//����
		if (_Loc.first - 1 >= 0 && Map[_Loc.first - 1][_Loc.second] == 0)		//��ǥ�� ���� ����� �ʰ�, �ʿ��̸�
		{
			Lava.push(PII(_Loc.first - 1, _Loc.second));						//�ش� ��ǥ�� ť�� Ǫ���ϰ�
			Map[_Loc.first - 1][_Loc.second] = 3;								//�ı��Ǿ��ٴ� ���� ǥ����
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
	int CountArea()								//�ı����� ���� �ʿ� ������ ��ȯ�ϴ� �Լ�
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
	void PrintAnswer() const
	{
		cout << "Unaffected Area : " << Unaffected << endl << endl;
	}
	void ClearMap()
	{
		for (int r = 0; r < Size; ++r)
		{
			for (int c = 0; c < Size; ++c)
			{
				if (Map[r][c] == 3)
					Map[r][c] = 0;
			}
		}
	}
	void PrintMap() const						//(����� �ùķ��̼� �ǰ� �ִ��� Ȯ���ϱ� ����)
	{
		for (int r = 0; r < Size; ++r)
		{
			for (int c = 0; c < Size; ++c)
			{
				cout << Map[r][c] << ' ';
			}
			cout << endl << endl;
		}
		cout << endl;
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
		graph[tc]->PrintAnswer();
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