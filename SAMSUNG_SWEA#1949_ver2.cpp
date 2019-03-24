//
//    OS Mac
//    2019.03.23
//
//    [Algorithm Problem Solving]
//
//    SAMSUNG SW Expert Academy [#1949] <등산로 조성> (모의)
//    ver2. 코드 간소화 및 실행시간 감소를 위해 최적화하여 다시 풀어봄
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef pair<int, int> coor;
const static int MAP_SIZE = 8;
const static int DIRECT = 4;

static int map[MAP_SIZE][MAP_SIZE];
static int check[MAP_SIZE][MAP_SIZE];
static queue<coor> Top;
static int N, K;
static int dir[DIRECT][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };    //µø≥≤º≠∫œ
static int result;

void FindTop(int top)
{
    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            if (map[r][c] == top)
                Top.push(coor(r, c));
        }
    }
}

void Make_Trail(int curx, int cury, int length)
{
    for (int d = 0; d < DIRECT; ++d)
    {
        int nextx = curx + dir[d][0];
        int nexty = cury + dir[d][1];
        
        if (nextx < 0 || nexty < 0 || nextx >= N || nexty >= N || check[nextx][nexty])
        {
            continue;
        }
        else
        {
            if (map[nextx][nexty] < map[curx][cury])
            {
                
                check[nextx][nexty] = 1;
                Make_Trail(nextx, nexty, length + 1);
                result = max(result, length+1);
                check[nextx][nexty] = 0;
            }
            
            else if (map[nextx][nexty] >= map[curx][cury])
            {
                if(K >= map[nextx][nexty] - map[curx][cury] + 1)
                {
                    int temp = map[nextx][nexty];
                    int tempK = K;
                    map[nextx][nexty] = map[curx][cury] - 1;
                    check[nextx][nexty] = 1;
                    K = 0;
                    Make_Trail(nextx, nexty, length + 1);
                    result = max(result, length+1);
                    map[nextx][nexty] = temp;
                    check[nextx][nexty] = 0;
                    K = tempK;
                }
                else
                    continue;
            }
        }
    }
}

void Simulation()
{
    result = -1;
    while (!Top.empty())
    {
        int x = Top.front().first;
        int y = Top.front().second;
        Top.pop();
        check[x][y] = 1;
        Make_Trail(x, y, 1);
        check[x][y] = 0;
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T;
    freopen("s_input1949.txt", "r", stdin);
    
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        (void)memset(&map[0][0], 0, sizeof(map));
        (void)memset(&check[0][0], 0, sizeof(check));
        
        cin >> N >> K;
        
        int top_height = 0;
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                cin >> map[r][c];
                top_height = max(top_height, map[r][c]);
            }
        }
        FindTop(top_height);
        Simulation();
        
        cout << "#" << test_case << ' ' << result << '\n';
    }
    return 0;
}
