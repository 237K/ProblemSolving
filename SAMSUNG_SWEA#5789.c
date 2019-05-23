//
//  OS MAC
//  SAMSUNG_SWEA#5789.cpp
//  ProblemSolving
//
//  [SAMSUNG SWEA] #5789 (D3)
//
//  Created by 237 on 22/05/2019.

#include <stdio.h>
#include <memory.h>
#define MAX 1001

int arr[MAX];
int T, q, N, Q, L, R;
void print()
{
    for(register int i = 1 ; i <= N ; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(void)
{
    freopen("s_input5789.txt", "r", stdin);
    register int tc, i;
    scanf("%d", &T);
    for(tc = 1 ; tc <= T ; ++tc)
    {
        (void)memset(arr, 0, sizeof(int)*MAX);
        scanf("%d %d", &N, &Q);
        for(q = 1 ; q <= Q ; ++q)
        {
            scanf("%d %d", &L, &R);
            for(i = L ; i <= R ; ++i)
                arr[i] = q;
        }
        printf("#%d ", tc); print();
    }
    return 0;
}
