//
//  OS MAC
//  SAMSUNG_SWEA#5549.cpp
//  ProblemSolving
//
//  [SAMSUNG SWEA] #5549 (D3) 
//
//  Created by 237 on 22/05/2019.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
    freopen("s_input5549.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, tc;
    string str;
    cin>>T;
    for(tc = 1 ; tc <= T ; ++tc)
    {
        cin>>str;
        cout<<"#"<<tc<<' ';
        if((str.back() - '0') % 2) cout<<"Odd\n";
        else cout<<"Even\n";
    }
    return 0;
}
