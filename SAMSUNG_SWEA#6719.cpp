//
//    OS Mac
//    2019.03.24
//
//    [Algorithm Problem Solving]
//
//    SAMSUNG SW Expert Academy [#6719] <성수의 프로그래밍 강좌 시청> (D4)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

static int N, K;
static vector<double> Class;
static double result;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("s_input6719.txt", "r", stdin);
    int T;
    int test_case;
    
    cin>>T;
    for(test_case = 1 ; test_case <= T ; ++test_case)
    {
        result = 0.0;
        Class.clear();
        cin>>N>>K;
        for(int i = 0 ; i < N ; ++i)
        {
            double temp = 0.0;
            cin>>temp;
            Class.push_back(temp);
        }
        sort(Class.begin(), Class.end(), greater<double>());
        
        for(int k = K-1 ; k >= 0 ; --k)
        {
            result = (result + Class[k]) / 2;
        }
        cout<<"#"<<test_case<<' '<<result<<'\n';
    }
    return 0;
}
