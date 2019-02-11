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

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <time.h>
using namespace std;

const static int MAX_ROOM = 50000;
const static int MAX_PORTAL = 25000;
const static int PARTITION = 40000;		//탈출구가 49727번 방에 있다거나 하는 경우에 실행시간이 6초 넘게 걸려서 실행시간 줄일 수 있도록 퀵소트처럼 구현해봄
const static int INF = 2147000000;
const static int COST = 1;				//다음 방으로 이동하는 비용. i*2 방으로 가든 i+1로 가든 i-1로 가든 한 번 이동하는데는 1이 소모

typedef pair<int, int> PII;

class Graph
{
private:
	vector<int> *G;
	int *Distance;
	bool *Check;
	queue<int> Q;
	int Start, End;
public:
	Graph(int _Start, int _End) : Start(_Start), End(_End)
	{
		G = new vector<int>[MAX_ROOM + 1];
		Distance = new int[MAX_ROOM + 1];
		Check = new bool[MAX_ROOM + 1];
		for (int init = 1; init <= MAX_ROOM; ++init)
		{
			G[init].clear();
			Distance[init] = INF;
			Check[init] = false;
		}
	}
	~Graph()
	{
		delete[] G;
		delete[] Distance;
		delete[] Check;
	}
	void Push(int _Node)
	{
		if (_Node == 1)
		{
			G[_Node].push_back(2);
		}
		else if(_Node <= MAX_PORTAL)
		{
			G[_Node].push_back(_Node - 1);
			G[_Node].push_back(_Node + 1);
			G[_Node].push_back(_Node * 2);
		}
		else if (_Node > MAX_PORTAL)
		{
			G[_Node].push_back(_Node - 1);
			G[_Node].push_back(_Node + 1);
		}
	}
	void BFS()
	{
		int Result = 0;		//탈출구가 40000보다 크고, 짝수도 아닐 경우에 사용하기 위한 변수
		Distance[Start] = 0;
		Q.push(Start);
		Check[Start] = true;
		if (End < PARTITION)
		{
			while (!Q.empty())
			{
				int CurrentNode = Q.front();
				cout << CurrentNode << ' ';
				if (CurrentNode == End)
					break;
				else
				{
					Push(CurrentNode);
					Q.pop();
					for (vector<int>::size_type i = 0; i < G[CurrentNode].size(); ++i)
					{
						int NextNode = G[CurrentNode][i];
						if (Check[NextNode] == false)
						{
							Q.push(NextNode);
							Check[NextNode] = true;
							if (Distance[CurrentNode] != INF && Distance[NextNode] > Distance[CurrentNode] + COST)
							{
								Distance[NextNode] = Distance[CurrentNode] + COST;
							}
						}
					}
				}
			}
			cout << endl << "최단경로에서 발생하는 비용 : " << Distance[End] << endl << endl;
		}
		else if (End >= PARTITION)
		{
			if (End % 2 == 0)
			{
				End = End / 2;

				while (!Q.empty())
				{
					int CurrentNode = Q.front();
					cout << CurrentNode << ' ';
					if (CurrentNode == End)
					{
						Distance[End] += 1;
						break;
					}
					else
					{
						Push(CurrentNode);
						Q.pop();
						for (vector<int>::size_type i = 0; i < G[CurrentNode].size(); ++i)
						{
							int NextNode = G[CurrentNode][i];
							if (Check[NextNode] == false)
							{
								Q.push(NextNode);
								Check[NextNode] = true;
								if (Distance[CurrentNode] != INF && Distance[NextNode] > Distance[CurrentNode] + COST)
								{
									Distance[NextNode] = Distance[CurrentNode] + COST;
								}
							}
						}
					}
				}
				cout << endl << "최단경로에서 발생하는 비용 : " << Distance[End] << endl << endl;
			}

			else if(End % 2 != 0)
			{
				int End1 = (End + 1) / 2;
				int End2 = (End - 1) / 2;
				while (!Q.empty())
				{
					int CurrentNode = Q.front();
					cout << CurrentNode << ' ';
					if (CurrentNode == End1 || CurrentNode == End2)
					{
						Result = min(Distance[End1], Distance[End2]);
						Result += 2;
						break;
					}

					else
					{
						Push(CurrentNode);
						Q.pop();
						for (vector<int>::size_type i = 0; i < G[CurrentNode].size(); ++i)
						{
							int NextNode = G[CurrentNode][i];
							if (Check[NextNode] == false)
							{
								Q.push(NextNode);
								Check[NextNode] = true;
								if (Distance[CurrentNode] != INF && Distance[NextNode] > Distance[CurrentNode] + COST)
								{
									Distance[NextNode] = Distance[CurrentNode] + COST;
								}
							}
						}
					}
				}
			}
			cout << endl << "최단경로에서 발생하는 비용 : " << Result << endl << endl;
		}
	}
};

int main(void)
{
	Graph *graph[101];
	int testcase = 0;
	int _Start = 0, _End = 0;
	clock_t timer_s, timer_e;
	double timer;

	timer_s = clock();
	ifstream fin("testcase_RoomEscape2.txt");

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
	cout << "Execution Time : " << timer <<"ms"<< endl << endl;
	return 0;
}