//
//    OS Windows
//    2019.03.21
//
//    [Algorithm Problem Solving]
//
//    <단색이 좋아>
//
//    1. 빨간색, 초록색, 파란색 공들이 섞여 있음
//    2. 한 턴에 제일 앞의 공 혹은 제일 뒤의 공 하나를 제거할 수 있음
//    3. 한 색깔의 공만 남기기 위해서는 최소 몇 번의 턴이 필요한지 출력
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

inline int Check(const string& in)
{
    int MAX = 0;
    int count = 1;
    int length;
    length = in.length();
    for (int i = 1; i < length; ++i)
    {
        if (in[i] == in[i - 1])
        {
            count++;
        }
        else
        {
            MAX = max(MAX, count);
            count = 1;
        }
    }
    MAX = max(MAX, count);
    return length - MAX;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("testcase_UniqueColor.txt", "r", stdin);
    int T;
    int test_case;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string str;
        cin >> str;
        cout << "#" << test_case << ' ' << Check(str) << '\n';
    }
    return 0;
}
