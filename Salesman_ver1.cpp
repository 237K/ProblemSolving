//
//  Salesman_ver1.cpp
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
//  DFS 사용
//  스택, 벡터 사용하지 않고 구현

#include <iostream>
#include <fstream>
using namespace std;

int testcase = 0;
int Cities = 0;
int Start = 0;
int Cost = 0;
int **Graph;
bool *Check;

void DFS(int index, int cost, int count)
{
    if(count == Cities)
    {
        cout<<index<<endl;
        if(Graph[index][Start] != 0)
        {
            if(Cost == -1 || Cost > cost + Graph[index][Start])
            {
                Cost = cost + Graph[index][Start];
                cout<<"*Cost : "<<Cost<<endl<<endl;
            }
        }
    }
    else
    {
        for(int i = 1 ; i <= Cities ; ++i)
        {
            if(Check[i] == false && Graph[index][i] != 0)
            {
                cout<<index<<' '<<i<<' ';
                if(Cost == -1 || Cost > cost + Graph[index][i])
                {
                    Check[i] = true;
                    DFS(i, Graph[index][i], count+1);
                    Check[i] = false;
                }
            }
        }
    }
}

int main(void)
{
    cout<<"Test Case : "; cin>>testcase;
    cout<<endl;
    for(int tc = 1 ; tc <= testcase ; ++tc)
    {
        cout<<"Number of cities, Start City : "; cin>>Cities>>Start;
        
        Graph = new int* [Cities+1];
        Check = new bool [Cities+1];
        for(int init = 1 ; init <=Cities ; ++init)
        {
            Graph[init] = new int [Cities+1];
            Check[init] = false;
            for(int initc = 1 ; initc <=Cities ; ++initc)
            {
                Graph[init][initc] = 0;
            }
        }
        for(int r = 1 ; r <= Cities ; ++r)
        {
            for(int c = 1; c <= Cities ; ++c)
            {
                int RecentCost = 0;
                cout<<"Cost : "; cin>>RecentCost;
                Graph[r][c] = RecentCost;
            }
        }
        Cost = -1;
        Check[Start] = true;
        cout<<"#"<<tc<<endl<<"Route : ";
        DFS(Start, 0, 1);
        cout<<endl<<endl;
    }
    
    return 0;
}
