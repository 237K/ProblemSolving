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
//  DFS
//  캡슐화, vector, 우선순위큐 사용
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const static int INF = 21470000;

class Graph
{
private:
    vector<PII> *DG;
    vector<bool> Check;
    vector<int> Cost;
    priority_queue<PII, vector<PII>> PQ;
    int NumOfCity;
    int InputCost;
    int Answer;
public:
    Graph(int _Cities) : NumOfCity(_Cities), InputCost(0), Answer(0)
    {
        DG = new vector<PII> [_Cities+1];
        for(int init = 0 ; init <= _Cities ; ++init)
        {
            DG[init].clear();
            Check.push_back(false);
            Cost.push_back(INF);
        }
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
    void DFS(int _Start)
    {
        Check[_Start] = true;
        Cost[_Start] = 237000;
        for(auto iter = DG[_Start].begin() ; iter < DG[_Start].end() ; ++iter)
        {
            PQ.push(*iter);
        }
        while(!PQ.empty())
        {
            int CurrentNode = PQ.top().first;
            int CurrentNodeWeight = PQ.top().second;
            PQ.pop();
            Check[CurrentNode] = true;
            for(auto iter = DG[CurrentNode].begin() ; iter != DG[CurrentNode].end() ; ++iter)
            {
                int NextNode = iter->first;
                int NextNodeWeight = iter->second;
                
                if(NextNode == NumOfCity)
                {
                    for(auto iter = DG[NextNode].begin() ; iter != DG[NextNode].end() ; ++iter)
                    {
                        if(iter->first == _Start)
                        {
                            if(Answer == -1 || Answer > Cost[NextNode] + iter->second)
                                Answer = Cost[NextNode] + iter->second;
                        }
                        else
                        {
                            Answer = -1;
                            break;
                        }
                    }
                }
                
                if(Check[NextNode] == false)
                {
                    PQ.push(*iter);
                    if(Cost[CurrentNode] != INF && Cost[NextNode] > CurrentNodeWeight + NextNodeWeight)
                    {
                        Cost[CurrentNode] = CurrentNodeWeight + NextNodeWeight;
                    }
                }
            }
            cout<<"Answer : "<<Answer<<endl<<endl;
        }
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
            cout<<"#"<<tc<<endl;
            graph[tc]->DFS(StartCity);
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
    GraphGenerator GG(testcase);
    
    in.close();
    return 0;
}
