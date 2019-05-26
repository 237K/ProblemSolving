//
//  OS MAC
//  SAMSUNG_SWEA#5789.cpp
//  ProblemSolving
//
//  [SAMSUNG SWEA] #5515 (D3)
//
//  Created by 237 on 24/05/2019.

#include <stdio.h>
int table[12] = { 4, 0, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3 };
int main(void)
{
    freopen("s_input5515.txt", "r", stdin);
    int T, tc, m, d;
    scanf("%d", &T);
    for(tc = 1 ; tc <= T ; ++tc)
    {
        scanf("%d %d", &m, &d);
        printf("#%d %d\n", tc, (table[m-1] + ((d-1) % 7)) % 7);
    }
    return 0;
}
