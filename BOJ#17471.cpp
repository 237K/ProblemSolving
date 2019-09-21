//
//	OS Windows
//	2019.09.20
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #17471 게리맨더링
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <memory.h>
using namespace std;
const static int MAX = 11;
static int N, M, in, num_A, num_B, cnt_A, cnt_B;
static int people[MAX], A[MAX], B[MAX], check[MAX];
static vector<int> graph[MAX];
inline void print()
{
	register int i;
	cout << "1번 선거구 : ";
	for (i = 0; i < num_A; ++i) cout << A[i] << ' ';
	cout << " / 인구합 : " << cnt_A << "\n";
	cout << "2번 선거구 : ";
	for (i = 0; i < num_B; ++i) cout << B[i] << ' ';
	cout << " / 인구합 : " << cnt_B << "\n";
	cout << "==================================\n\n";
}
inline void cal_people()
{
	register int i;
	cnt_A = cnt_B = 0;
	for (i = 0; i < num_A; ++i) cnt_A += people[A[i]];
	for (i = 0; i < num_B; ++i) cnt_B += people[B[i]];
}
inline int check_connect()
{
	register int i, j, k, cur, sz, nxt, l, flag, end_flag = 0;
	stack<int> st;
	//	첫 번째 선거구 검사
	//	구역이 1개면 검사할 필요 없음
	if (num_A > 1)
	{
		//	i번째 노드에서 j번째 노드까지 갈 수 있고, 그 과정에 있는 중간노드가 같은 선거구에 포함되있으면 OK
		for (i = 0; i < num_A - 1; ++i)
		{
			for (j = i + 1; j < num_A; ++j)
			{
				end_flag = 0;
				(void)memset(check, 0, sizeof(check));
				while (!st.empty()) { st.pop(); }
				st.push(A[i]);
				check[A[i]] = 1;
				while (!st.empty())
				{
					cur = st.top();
					st.pop();
					if (cur == A[j])
					{
						end_flag = 1;
						break;
					}
					sz = graph[cur].size();
					for (l = 0 ; l < sz ; ++l)
					{
						nxt = graph[cur][l];
						if (check[nxt]) continue;
						flag = 0;
						for (k = 0; k < num_A; ++k)
						{
							if (A[k] == nxt)
							{
								flag = 1;
								break;
							}
						}
						if (!flag) continue;
						check[nxt] = 1;
						st.push(nxt);
					}
				}
				if (!end_flag) return 0;
			}
		}
	}
	//	두 번째 선거구 검사
	if (num_B > 1)
	{
		//	i번째 노드에서 j번째 노드까지 갈 수 있고, 그 과정에 있는 중간노드가 같은 선거구에 포함되있으면 OK
		for (i = 0; i < num_B - 1; ++i)
		{
			for (j = i + 1; j < num_B; ++j)
			{
				end_flag = 0;
				(void)memset(check, 0, sizeof(check));
				while (!st.empty()) { st.pop(); }
				st.push(B[i]);
				check[B[i]] = 1;
				while (!st.empty())
				{
					cur = st.top();
					st.pop();
					if (cur == B[j])
					{
						end_flag = 1;
						break;
					}
					sz = graph[cur].size();
					for (l = 0 ; l < sz ; ++l)
					{
						nxt = graph[cur][l];
						if (check[nxt]) continue;
						flag = 0;
						for (k = 0; k < num_B; ++k)
						{
							if (B[k] == nxt)
							{
								flag = 1;
								break;
							}
						}
						if (!flag) continue;
						check[nxt] = 1;
						st.push(nxt);
					}
				}
				if (!end_flag) return 0;
			}
		}
	}
	return 1;
}
inline int simul()
{
	register int mask, flag, cnt, ret = 2147000000;

	//	비트마스크로 두 선거구를 나눔
	for (mask = 0; (mask < (1 << N)); ++mask)
	{
		num_A = num_B = 0;
		for (flag = 0; flag < N; ++flag)
		{
			if (mask & (1 << flag)) B[num_B++] = flag;
			else A[num_A++] = flag;
		}
		//	한 쪽에만 쏠려있으면 넘어가고
		if (!num_A || !num_B) continue;
		//	각 구역이 다 연결되어 있는지 검사
		if (!check_connect()) continue;
		//	각 구역의 인구수 계산
		cal_people();
		cnt = cnt_A - cnt_B;
		//print();
		if (cnt < 0) cnt *= -1;
		//	최소값 확인
		if (ret > cnt) ret = cnt;
	}
	if (ret == 2147000000) ret = -1;
	return ret;
}
int main(int argc, char** argv)
{
	freopen("input17471.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int init, p, i, j;
	(void)memset(graph, 0, sizeof(graph));
	cin >> N;
	for (init = 0; init < N; ++init) graph[init].clear();
	for (p = 0; p < N; ++p) cin >> people[p];
	for (i = 0; i < N; ++i)
	{
		cin >> M;
		graph[i].resize(M);
		for (j = 0; j < M; ++j)
		{
			cin >> in;
			graph[i][j] = in - 1;
		}
	}
	cout << simul();
	return 0;
}