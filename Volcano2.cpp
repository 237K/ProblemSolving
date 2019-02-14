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

//	초원에 바리게이트를 설치하는 경우(는 DFS로 조합함)안에서 BFS(용암이 초원 파괴해나감)를 돌리는 방식으로 구현함
//	{DFS(BFS)} 형태
//
//	(*Core Function)
//	1. Graph::void Simulation(int) -> DFS(Recursion), 바리게이트를 설치하는 모든 경우의 수를 순회
//	2. Graph::void Eruption() -> BFS(queue), 용암이 흘러가면서 초원 파괴
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
	bool **Check;			//DFS돌릴 때 사용하기 위함
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
	void Setting(ifstream& _fin)					//초기 맵 상태 인풋값 읽어오는 함수
	{
		for (int r = 0; r < Size; r++)
		{
			for (int c = 0; c < Size; c++)
			{
				_fin >> Map[r][c];
				if (Map[r][c] == 0)					//초기 격자의 상태가 0이면
				{
					Grass.push_back(PII(r, c));		//해당 좌표를 Grass 벡터에 넣음
				}
				if (Map[r][c] == 2)					//초기 격자의 상태가 2이면
				{
					Volcano.push_back(PII(r, c));	//해당 좌표를 Volcano 벡터에 넣음
				}
			}
		}
	}
	void Simulation(int depth)						//(*Core Function) 초원에 바리케이트를 설치하는 모든 경우의 수를 순회
	{												
		if (depth == NumOfGate + 1)					//탈출 조건
		{											//인풋값으로 주어진 바리게이트수만큼 설치하면
			int ThisTime = 0;
			Eruption();								//화산폭발
			//PrintMap();							//(제대로 시뮬레이션 되고 있는지 확인하기 위함)
			ThisTime = CountArea();					//파괴되지 않은 초원이 기존값보다 많으면 갱신
			if (Unaffected < ThisTime)
				Unaffected = ThisTime;				
			ClearMap();								//맵을 초기값으로 초기화
			return;
		}
		else
		{																					//탐색 조건
			for (vector<int>::size_type i = 0; i < Grass.size(); ++i)
			{
				PII CurGrass = Grass[i];
				if (Check[CurGrass.first][CurGrass.second] == false)
				{
					//cout << "(" << CurGrass.first << ", " << CurGrass.second << ") ";		//모든 경우의 수를 탐색하는지 확인하기 위함
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
	void Eruption()														//(*Core Function) 용암이 흘러가면서 초원을 파괴하는 함수
	{
		for (vector<PII>::size_type i = 0; i < Volcano.size(); i++)		//화산의 좌표를 저장해둔 벡터에서 좌표를 하나씩 꺼내서
		{
			Lava.push(Volcano[i]);										//큐에 푸쉬
		}
		while (!Lava.empty())
		{
			PII CurLoc = Lava.front();									//임시변수에 화산좌표를 넣고
			Lava.pop();													//큐에서 팝하고
			Destroy(CurLoc);											//Destroy함수 호출
		}
	}
	void Destroy(PII _Loc)														//(*Core Function)
	{
		//북쪽
		if (_Loc.first - 1 >= 0 && Map[_Loc.first - 1][_Loc.second] == 0)		//좌표가 맵을 벗어나지 않고, 초원이면
		{
			Lava.push(PII(_Loc.first - 1, _Loc.second));						//해당 좌표를 큐에 푸쉬하고
			Map[_Loc.first - 1][_Loc.second] = 3;								//파괴되었다는 것을 표시함
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
	int CountArea()								//파괴되지 않은 초원 개수를 반환하는 함수
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
	void PrintMap() const						//(제대로 시뮬레이션 되고 있는지 확인하기 위함)
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
		cout << "파일을 찾을 수 없습니다." << endl;

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