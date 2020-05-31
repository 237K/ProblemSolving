//
//	OS Windows
//	2020.05.31
//
//	[Algorithm Problem Solving]
//
//	[시뮬레이션] <BOJ #17471> 게리맨더링
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
const static int SZ = 11;
const static int EX = 2147000000;
static int city_people[SZ], city_connect_num[SZ], city_connect[SZ][SZ], cluster[2], num_cluster[2], N, check[SZ];
inline void print()
{
	register int i, j;
	for (i = 0; i < 2; ++i)
	{
		cout << i + 1 << "번 클러스터 도시 : ";
		for (j = 0; j < num_cluster[i]; ++j)
		{
			cout << cluster[j] << " (*"<<city_people[cluster[j]]<<"명) ";
		}
		cout << "\n\n";
	}
}
inline int cal()
{
	int sum[2];
	register int i, j, diff;
	for (i = 0; i < 2; ++i)
	{
		sum[i] = 0;
		for (j = 0; j < num_cluster[i]; ++j)
		{
			sum[i] += city_people[cluster[j]];
		}
	}
	diff = sum[1] - sum[0];
	if (diff < 0) diff *= -1;
	return diff;
}
inline int check_connect()
{
	register int i, j, k, l, m, start, end, cur, nxt, rflag = 1, rrflag, cflag;
	queue<int> Q;
	for (i = 0; i < 2; ++i)
	{
		while (!Q.empty()) { Q.pop(); }
		(void)memset(check, 0, sizeof(check));
		for (j = 0; j < num_cluster[i] - 1; ++j)
		{
			for (k = j + 1; k < num_cluster[i]; ++k)
			{
				rrflag = 0;
				start = cluster[j];
				end = cluster[k];
				Q.push(start);
				check[start] = 1;
				while (!Q.empty())
				{
					cur = Q.front();
					Q.pop();
					for (l = 1; l <= city_connect_num[cur]; ++l)
					{
						nxt = city_connect[cur][l];
						if (nxt == end)
						{
							rrflag = 1;
							break;
						}
						cflag = 0;
						for (m = 0; m < num_cluster[i]; ++m)
						{
							if (nxt == cluster[m])
							{
								cflag = 1;
								break;
							}
						}
						if (cflag)
						{
							Q.push(nxt);
							check[nxt] = 1;
						}
					}
					if (rrflag) break;
				}
			}
		}
		if (!rrflag)
		{
			rflag = 0;
			break;
		}
	}
	return rflag;
}
inline int simul()
{
	register int mask, flag, cur, ret, i, eflag;
	ret = EX;
	for (mask = 0; mask < (1 << N); ++mask)
	{
		for (i = 0; i < 2; ++i)
			num_cluster[i] = 0;
		for (flag = 0; flag < N; ++flag)
		{
			if (mask & (1 << flag))
				cluster[num_cluster[1]++] = flag + 1;
			else
				cluster[num_cluster[0]++] = flag + 1;
		}
		eflag = 1;
		for (i = 0; i < 2; ++i)
		{
			if (!num_cluster[i])
			{
				eflag = 0;
				break;
			}
		}
		if (!eflag) continue;
		if (!check_connect()) continue;
		//print();
		cur = cal();
		if (ret > cur) ret = cur;
	}
	if (ret == EX) ret = -1;
	return ret;
}
int main(int argc, char** argv)
{
	freopen("binput17471.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int n, c;
	cin >> N;
	for (n = 1; n <= N; ++n)
		cin >> city_people[n];
	for (n = 1; n <= N; ++n)
	{
		cin >> city_connect_num[n];
		for (c = 0; c < city_connect_num[n]; ++c)
		{
			cin >> city_connect[n][c];
		}
	}
	cout << simul();
	return 0;
}