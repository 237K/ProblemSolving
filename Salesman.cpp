//
//  Salesman.cpp
//  ProblemSolving
//
//  OS macOS
//  Created by 형성모 on 02/04/2019.
//
//  [Algorithm Problem Solving]
//
//  <외판원 순회>
//  1. 출발지를 제외한 모든 도시를 한 번씩만 방문한 후 처음 출발지로 돌아오려고 함
//  2. 도시 사이에 길이 있는 경우에만 이동 가능
//  3. 도시들 사이의 길을 지날 때 통행료가 있음
//  4. 최소비용
//
//  다익스트라 사용
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

class Graph
{
private:
    vector<PII> *DG;
    vector<bool> Check;
    vector<int> Cost;
    priority_queue<PII, vector<PII>> PQ;
    int NumOfCity;
    int InputCost;
public:
    Graph(int _Cities) : NumOfCity(_Cities)
    {
        DG = new vector<PII> [_Cities+1];
        for(int init = 0 ; init <= _Cities ; ++init)
        {
            DG[init].clear();
        }
        Check.clear();
        Cost.clear();
    }
    ~Graph()
    {
        delete[] DG;
    }
    void MakeGraph(ifstream& _in)
    {
        for(int r = 1 ; r <= NumOfCity ; ++r)
        {
            for(int c = 1; c <= NumOfCity ; ++c)
            {
                _in>>InputCost;
                DG[r].push_back(PII(c, InputCost));
            }
        }
    }
    void Dijkstra(int _Start)
    {
        
    }
};

class GraphGenerator
{
private:
    Graph *graph[10];
    const int Testcase;
    int Cities;
    int StartCity;
public:
    GraphGenerator(const int _testcase) : Testcase(_testcase) {}
    void Generate(ifstream& _in)
    {
        for(int tc = 1 ; tc <= Testcase ; ++tc)
        {
            _in>>Cities>>Cities>>StartCity;
            graph[tc] = new Graph(Cities);
            graph[tc]->MakeGraph(_in);
            graph[tc]->Dijkstra(StartCity);
        }
    }
                            
};

int main(void)
{
    int testcase = 0;
    ifstream in("testcase_Salesman.txt");
    if(!in.is_open())
        cout<<"파일을 찾을 수 없습니다."<<endl<<endl;
    
    in>>testcase;
    GraphGenerator(testcase);
    
}
