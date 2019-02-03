//
//  RoomEscape.cpp
//  ProblemSolving
//
//  OS macOS
//  Created by 형성모 on 02/02/2019.
//
//  [Algorithm Problem Solving]
//
//  <방 탈출>
//  1. i번째 방의 포탈은 Ai번째 방으로 이동하며, 이때 Ai 의 값은 i < Ai <= N
//  2. 포탈은 단방향 이동만 가능
//  3. 포탈을 통과하면 +1점, 출구에 도착해야만 점수 인정
//  4. 얻을 수 있는 최대 점수 출력
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Graph
{
private:
    vector<int>* Room;
    stack<int> Stack;
    vector<int> *IsThereExit;
    bool* Check;
    const int NumOfRoom;
    const int Exit;
    int InputRoom;
    int Score;
public:
    explicit Graph(const int _NumOfRoom, const int _Exit) : NumOfRoom(_NumOfRoom), Exit(_Exit), Score(0)
    {
        Room = new vector<int> [_NumOfRoom+1];
        Check = new bool [_NumOfRoom+1];
        IsThereExit = new vector<int> [_NumOfRoom+1];
        for(int init = 0 ; init <= _NumOfRoom ; ++init)
        {
            Room[init].clear();
            Check[init] = false;
            IsThereExit[init].clear();
        }
    }
    ~Graph()
    {
        delete[] Room;
        delete[] Check;
        delete[] IsThereExit;
    }
    void MakeGraph(ifstream& _in)
    {
        for(int i = 1 ; i <= NumOfRoom ; ++i)
        {
            _in>>InputRoom;
            Room[i].push_back(InputRoom);
            sort(Room[i].begin(), Room[i].end());
        }
    }
    void DFS()
    {
        for(int dfs = 1 ; dfs <= Exit ; ++dfs)
        {
            int ThisScore = 0;
            Stack.push(dfs);
            IsThereExit[dfs].push_back(dfs);
            Check[dfs] = true;
            cout<<"Escape Route : "<<dfs<<' ';
            while(!Stack.empty())
            {
                int CurrentNode = Room[dfs].front();
                if(CurrentNode == Exit)
                    break;
                ThisScore++;
                Stack.push(CurrentNode);
                IsThereExit[dfs].push_back(CurrentNode);
                Check[CurrentNode] = true;
                Stack.pop();
                cout<<CurrentNode<<' ';
                for(vector<int>::size_type v = 0 ; v < Room[CurrentNode].size() ; ++v)
                {
                    int NextNode = Room[CurrentNode][v];
                    if(!Check[NextNode])
                    {
                        Check[NextNode] = true;
                        Stack.push(NextNode);
                        Stack.push(CurrentNode);
                    }
                }
            }
            if(find(IsThereExit[dfs].begin(), IsThereExit[dfs].end(), Exit) != IsThereExit[dfs].end())
                ThisScore = -1;
            cout<<endl<<"Score : "<<ThisScore<<endl<<endl;
            if(ThisScore > Score)
                Score = ThisScore;
        }
        cout<<"*Final Score : "<<Score<<endl<<endl;
    }
};

int main(void)
{
    Graph *graph[100];
    int testcase = 0;
    int _NumOfRoom = 0, _Exit = 0;
    
    ifstream in("testcase_RoomEscape.txt");
    if(!in.is_open())
        cout<<"파일을 찾을 수 없습니다."<<endl<<endl;
    
    for(int tc = 1 ; tc <= testcase ; ++tc)
    {
        in>>_NumOfRoom>>_Exit;
        graph[tc] = new Graph(_NumOfRoom, _Exit);
        graph[tc]->MakeGraph(in);
        cout<<"#"<<tc<<endl;
        graph[tc]->DFS();
    }
    
    in.close();
    for(int del = 0 ; del < testcase ; ++del)
    {
        delete graph[del];
        
    }
    return 0;
}
