//
//    OS Mac
//    2019.03.21
//
//    [Algorithm Problem Solving]
//
//    <탱크 게임>
//
//    1. 아군탱크 : T, 적군탱크 : E, 벽 : B 로 표시함
//    2. 아군탱크는 직선상의 적탱크를 공격할 수 있음
//    3. 중간에 벽이나 다른 탱크가 있으면 공격할 수 없음
//    4. 아군의 탱크가 공격한 적탱크 개수를 출력
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> coor;
const static int MAP_SIZE = 7;

static char Map[MAP_SIZE][MAP_SIZE];
static int N;
static queue<coor> Q;

inline int Play()
{
    int result = 0;
    while (!Q.empty())
    {
        coor cur = Q.front();
        cout << "Tank (" << cur.first << ", " << cur.second << ")" << endl;
        Q.pop();
        {
            for (int i = 0; i < N; ++i)
            {
                if (Map[i][cur.second] == 'E')
                {
                    bool Wall = false;
                    if (i < cur.first)
                    {
                        for (int p = i + 1; p < cur.first; ++p)
                        {
                            if (Map[p][cur.second] == 'B' || Map[p][cur.second] == 'E')
                            {
                                Wall = true;
                                break;
                            }
                        }
                        if (!Wall)
                        {
                            Map[i][cur.second] = '0';
                            cout << "(" << i << ", " << cur.second << ") Bomb!" << endl;
                            result++;
                        }
                    }
                    else
                    {
                        for (int p = cur.first + 1; p < i; ++p)
                        {
                            if (Map[p][cur.second] == 'B' || Map[p][cur.second] == 'E')
                            {
                                Wall = true;
                                break;
                            }
                        }
                        if (!Wall)
                        {
                            Map[i][cur.second] = '0';
                            cout << "(" << i << ", " << cur.second << ") Bomb!" << endl;
                            result++;
                        }
                    }
                }
            }
            for (int i = 0; i < N; ++i)
            {
                if (Map[cur.first][i] == 'E')
                {
                    bool Wall = false;
                    if (i < cur.second)
                    {
                        for (int p = i + 1; p < cur.second; ++p)
                        {
                            if (Map[cur.first][p] == 'B' || Map[cur.first][p] == 'E')
                            {
                                Wall = true;
                                break;
                            }
                        }
                        if (!Wall)
                        {
                            Map[cur.first][i] = '0';
                            cout << "(" << cur.first << ", " << i << ") Bomb!" << endl;
                            result++;
                        }
                    }
                    else
                    {
                        for (int p = cur.second + 1; p < i; ++p)
                        {
                            if (Map[cur.first][p] == 'B' || Map[cur.first][p] == 'E')
                            {
                                Wall = true;
                                break;
                            }
                        }
                        if (!Wall)
                        {
                            Map[cur.first][i] = '0';
                            cout << "(" << cur.first << ", " << i << ") Bomb!" << endl;
                            result++;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("testcase_TankGame.txt", "r", stdin);
    int T;
    int test_case;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                cin >> Map[r][c];
                if (Map[r][c] == 'T')
                    Q.push(coor(r, c));
            }
        }
        cout << "#" << test_case << " " << Play() << endl << endl;
    }
    return 0;
}
