//
//  OS MAC
//  SAMSUNG_SWEA#5789.cpp
//  ProblemSolving
//
//  [SAMSUNG SWEA] #5948 (D3) 새샘이의 7-3-5 게임
//
//  Created by 237 on 24/05/2019.

#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
static int arr[7];
static int comb[3];
static vector<int> v;
static void recur(int cnt, int idx)
{
    if(cnt == 3)
    {
        int sum = 0;
        for(int s = 0 ; s < 3 ; ++s)
            sum += comb[s];
        v.push_back(sum);
        return;
    }
    else
    {
        for(int i = idx ; i < 7 ; ++i)
        {
            comb[cnt] = arr[i];
            recur(cnt+1, i+1);
        }
    }
}
int main(int argc, char** argv)
{
    freopen("s_input5948.txt", "r", stdin);
    int T, tc, n, input;
    cin>>T;
    for(tc = 1 ; tc <= T ; ++tc)
    {
        v.clear();
        for(n = 0 ; n < 7 ; ++n)
            cin>>arr[n];
        recur(0, 0);
        sort(v.begin(), v.end(), greater<int>());
        unique(v.begin(), v.end());
        cout<<"#"<<tc<<' '<<v[4]<<'\n';
    }
    return 0;
}
