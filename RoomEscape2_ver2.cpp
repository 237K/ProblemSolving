//
//	OS Windows
//	2019.02.10
//
//	[Algorithm Problem Solving]
//
//	<방 탈출 게임 2>
//
//	1. 1 ~ 50,000 방이 있음. 1 ~ 25,000 방에는 i*2번방으로 이동할 수 있는 포탈과 이전방 혹은 다음방으로 이동할 수 있는 통로가 있음
//	2. 25,000 ~ 50,000 방에는 이전방 혹은 다음방으로 이동할 수 있는 통로만 있음
//	3. 각 테스트케이스마다 출발하는 방과 출구 방이 주어지고, 출구방으로 이동하기 위해 지나야하는 최소 방 개수를 출력
//
//	ver2. 코드를 간소화해 봄
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <time.h>
using namespace std;

typedef pair<int, int> PII;
const static int MAX_ROOM = 50000;
const static int MAX_PORTAL = 25000;
const static int INF = 2137000000;

class Graph
{
private:
	int Start, End, Answer;
	bool *Check;
	queue<PII> Q;
public:
	Graph(int _Start = 0, int _End = 0) : Start(_Start), End(_End), Answer(INF)
	{
		Check = new bool[MAX_ROOM + 1];
		for (int init = 1; init <= MAX_ROOM; ++init)
		{
			Check[init] = false;
		}
		while (!Q.empty())
		{
			Q.pop();
		}
	}
	~Graph() { delete[] Check; }

	void BFS()
	{
		Check[Start] = true;
		QPush(Start, 0);
		
		while (!Q.empty())
		{
			int CurrentNode = Q.front().first;
			int CurrentNode_Cost = Q.front().second;
			cout << CurrentNode << ' ';
			Q.pop();
			if (CurrentNode == End)
			{
				Answer = min(Answer, CurrentNode_Cost);
				break;
			}

				QPush(CurrentNode, CurrentNode_Cost);

		}
		cout << endl<< "탈출구로 가는 최단경로에서 소요되는 비용 : " << Answer << endl << endl;
	}
	void QPush(int _CurrentNode, int _CurrentNode_Cost)
	{
		if (Check[_CurrentNode + 1] == false)
		{
			Q.push(PII(_CurrentNode + 1, _CurrentNode_Cost + 1));
			Check[_CurrentNode + 1] = true;
		}
		if (_CurrentNode > 1 && Check[_CurrentNode-1] == false)
		{
			Q.push(PII(_CurrentNode - 1, _CurrentNode_Cost + 1));
			Check[_CurrentNode - 1] = true;
		}
		if (_CurrentNode <= MAX_PORTAL && Check[_CurrentNode*2] == false)
		{
			Q.push(PII(_CurrentNode * 2, _CurrentNode_Cost + 1));
			Check[_CurrentNode * 2] = true;
		}
	}
};

int main(void)
{
	Graph *graph[101];
	int testcase = 0;
	int _Start, _End;
	clock_t timer_s, timer_e;
	double timer;

	timer_s = clock();

	ifstream fin("testcase_RoomEscape2.txt");
	if (!fin.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		fin >> _Start >> _End;
		graph[tc] = new Graph(_Start, _End);
		cout << "#" << tc << endl;
		graph[tc]->BFS();
	}

	fin.close();
	for (int del = 1; del <= testcase; ++del)
	{
		delete graph[del];
	}
	timer_e = clock();
	timer = (double)(timer_e - timer_s);
	cout << "Execution Time : " << timer << "ms" << endl<<endl;
	return 0;
}