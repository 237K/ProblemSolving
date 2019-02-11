//
//	OS Windows
//	2019.02.10
//
//	[Algorithm Problem Solving]
//
//	<�� Ż�� ���� 2>
//
//	1. 1 ~ 50,000 ���� ����. 1 ~ 25,000 �濡�� i*2�������� �̵��� �� �ִ� ��Ż�� ������ Ȥ�� ���������� �̵��� �� �ִ� ��ΰ� ����
//	2. 25,000 ~ 50,000 �濡�� ������ Ȥ�� ���������� �̵��� �� �ִ� ��θ� ����
//	3. �� �׽�Ʈ���̽����� ����ϴ� ��� �ⱸ ���� �־�����, �ⱸ������ �̵��ϱ� ���� �������ϴ� �ּ� �� ������ ���
//
//	ver2. �ڵ带 ����ȭ�� ��
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
		cout << endl<< "Ż�ⱸ�� ���� �ִܰ�ο��� �ҿ�Ǵ� ��� : " << Answer << endl << endl;
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
		cout << "������ ã�� �� �����ϴ�." << endl;

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