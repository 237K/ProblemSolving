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
const static int DIRECT = 4;

static char Map[MAP_SIZE][MAP_SIZE];
static int N;
static int Dir[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
static queue<coor> Q;

inline int Play()
{
    int result = 0;
    while (!Q.empty())
    {
        coor cur = Q.front();
        Q.pop();
        
        cout << "Tank (" << cur.first << ", " << cur.second << ")" << endl;
        
        for (int d = 0; d < DIRECT; ++d)
        {
            for (int s = 1; s < N; ++s)
            {
                bool Wall = false;
                int x = cur.first + (s * Dir[d][0]);
                int y = cur.second + (s * Dir[d][1]);
                
                if (x < 0 || y < 0 || x >= N || y >= N)
                    continue;
                else
                {
                    if (Map[x][y] == 'B')
                    {
                        Wall = true;
                        break;
                    }
                    if (Map[x][y] == 'E' && !Wall)
                    {
                        Map[x][y] = 'B';
                        result++;
                        cout << "Bomb! (" << x << ", " << y << ")" << endl;
                        break;
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
