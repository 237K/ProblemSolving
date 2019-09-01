//
//	OS Windows
//	2019.08.28
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #5212	지구 온난화
//

#include <stdio.h>
#define DIR 4
int dir[DIR][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char map[11][11];
int R, C;
int row[100], col[100];
void simul()
{
	register int r, c, d, nr, nc, cnt, num_sink = 0, i, start_r, start_c, end_r, end_c;

	//	물에 잠기게 될 운명인 섬을 찾아서 위치 저장
	for (r = 0; r < R; ++r)
	{
		for (c = 0; c < C; ++c)
		{
			if (map[r][c] == 'X')
			{
				cnt = 0;
				for (d = 0; d < DIR; ++d)
				{
					nr = r + dir[d][0];
					nc = c + dir[d][1];
					if (nr < 0 || nc < 0 || nr >= R || nc >= C)
					{
						cnt++;
						continue;
					}
					if (map[nr][nc] == '.') cnt++;
				}
				if (cnt > 2)
				{
					row[num_sink] = r;
					col[num_sink++] = c;
				}
			}
		}
	}
	//	물에 잠기게 된 섬 표시
	for (i = 0; i < num_sink; ++i) map[row[i]][col[i]] = '.';

	//	맵 축소
	start_r = start_c = 0; end_r = R - 1; end_c = C - 1;
	for (r = 0; r < R; ++r)
	{
		cnt = 0;
		for (c = 0; c < C; ++c)
		{
			if (map[r][c] == '.') cnt++;
			else break;
		}
		if (cnt == C) start_r++;
		else break;
	}
	for (r = R - 1; r >= start_r; --r)
	{
		cnt = 0;
		for (c = 0; c < C; ++c)
		{
			if (map[r][c] == '.') cnt++;
			else break;
		}
		if (cnt == C) end_r--;
		else break;
	}
	for (c = 0; c < C; ++c)
	{
		cnt = 0;
		for (r = 0; r < R; ++r)
		{
			if (map[r][c] == '.') cnt++;
			else break;
		}
		if (cnt == R) start_c++;
		else break;
	}
	for (c = C - 1; c >= start_c; --c)
	{
		cnt = 0;
		for (r = 0; r < R; ++r)
		{
			if (map[r][c] == '.') cnt++;
			else break;
		}
		if (cnt == R) end_c--;
		else break;
	}
	
	//	출력
	for (r = start_r; r <= end_r; ++r)
	{
		for (c = start_c; c <= end_c; ++c)
		{
			printf("%c", map[r][c]);
		}
		printf("\n");
	}
}
int main(void)
{
	freopen("input5212.txt", "r", stdin);
	register int r;
	scanf("%d %d", &R, &C);
	for (r = 0; r < R; ++r) scanf("%s", &map[r]);
	simul();
	return 0;
}