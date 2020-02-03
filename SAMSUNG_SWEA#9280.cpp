//
//	OS Windows
//	2020.01.28
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#9280> (D3) �����̳� ����Ÿ��
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
#define MAX_PARKING 101
#define MAX_CAR 2001
static int parkingfee[MAX_PARKING], parkinglot[MAX_PARKING], car[MAX_CAR], N, M, T;
static queue<int> Q;
int main(int argc, char** argv)
{
	freopen("s_input9280.txt", "r", stdin);
	int tc, n, m, i, j, k, l, cur_park, cur, ret, cnt;
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		ret = cnt = 0;
		while (!Q.empty()) { Q.pop(); }
		(void)memset(parkinglot, 0, sizeof(parkinglot));
		scanf("%d %d", &N, &M);
		for (n = 0; n < N; ++n)
		{
			scanf("%d", &parkingfee[n]);
		}
		for (m = 1; m <= M; ++m)
		{
			scanf("%d", &car[m]);
		}
		for (i = 0; i < 2 * M; ++i)
		{
			scanf("%d", &cur);
			//	������ ����
			if (cur > 0)
			{
				//	�����忡 �� �ڸ��� ������
				if (cnt < N)
				{
					//	��� ������ �� ã�Ƽ� ����
					for (j = 0; j < N; ++j)
					{
						if (!parkinglot[j])
						{
							parkinglot[j] = cur;
							cur_park = j;
							ret += parkingfee[j] * car[cur];
							cnt++;
							break;
						}
					}
				}
				//	�����忡 �� �ڸ� ������ �����ÿ� �߰�
				else
				{
					Q.push(cur);
				}
			}
			//	����
			else
			{
				cnt--;
				cur *= -1;
				//	������ ���� �� �� �ڸ��� �ִ��� ã�Ƽ�
				for (k = 0; k < N; ++k)
				{
					if (parkinglot[k] == cur)
					{
						parkinglot[k] = 0;
						break;
					}
				}
			}
			//	�� �ڸ��� �ְ� �������� ������ ����
			while (!Q.empty())
			{
				if (cnt >= N)
					break;
				int curp = Q.front();
				Q.pop();
				for (l = 0; l < N; ++l)
				{
					if (!parkinglot[l])
					{
						cnt++;
						parkinglot[l] = curp;
						ret += parkingfee[l] * car[curp];
						break;
					}
				}
			}
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}