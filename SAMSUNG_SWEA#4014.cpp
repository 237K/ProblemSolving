//
//	OS Windows
//	2019.04.11
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#4014> (����) Ȱ�ַ� �Ǽ�
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef pair<int, int>  pii;
typedef pair<pii, int> coor_and_len;

const static int SIZE = 21;
const static int DIRECT = 2;

static int dir[DIRECT][2] = { {0, 1}, {1, 0} };
static int map[SIZE][SIZE];
static int N, X;
static queue<coor_and_len> Q;

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	while (!Q.empty()) { Q.pop(); }
}
inline bool search(int idx, int direct)
{
	while (!Q.empty()) { Q.pop(); }
	//	first : ��ǥ, second : Ȱ�ַ� ����
	pii cur_coor = { 0, 0 };
	if (!direct)
	{
		cur_coor = { idx, 0 };
		Q.push({ cur_coor, 1 });
	}
	else
	{
		cur_coor = { 0, idx };
		Q.push({ cur_coor, 1 });
	}

	int possible_length = 0;
	int contin_length = 1;
	while (!Q.empty())
	{
		coor_and_len cur = Q.front();
		Q.pop();
		int cr = cur.first.first;
		int cc = cur.first.second;
		int nr = cr + dir[direct][0];
		int nc = cc + dir[direct][1];

		//cout << "(" << nr << ", " << nc << ") length : " << cur.second << '\n';

		if (nr >= N || nc >= N)
		{
			possible_length = cur.second;
			while (!Q.empty()) { Q.pop(); }
			break;
		}
		int diff = abs(map[cr][cc] - map[nr][nc]);

		if (!diff)
		{
			Q.push({ { nr, nc }, cur.second + 1 });
			contin_length++;
			continue;
		}
		else if (diff == 1)
		{
			//	������ ���� ���
			if (map[cr][cc] < map[nr][nc])
			{
				if (contin_length >= X)
				{
					Q.push({ {nr, nc}, cur.second + 1 });
					contin_length = 1;
					continue;
				}
			}
			//	�������� ���� ���
			else
			{
				int base = map[nr][nc];
				int check_len = 0;
				//	�� �˻� ���� ���
				if (!direct)
				{
					//	nc�� Ȯ���� ������ ����� �ʰ�, ��¥�� nc�� ���̿� �����ؾ� �ϹǷ� nc���� ������
					for (register int idx = nc; idx < N; ++idx)
					{
						if (base == map[nr][idx])
							check_len++;
						else
							break;
					}
					if (check_len >= X)
					{
						Q.push({ { nr, nc + X - 1 }, cur.second + X });
						contin_length = 0;
						continue;
					}
					else
						return false;
				}
				//�� �˻� ���� ���
				else
				{
					for (register int idx = nr; idx < N; ++idx)
					{
						if (base == map[idx][nc])
							check_len++;
						else
							break;
					}
					if (check_len >= X)
					{
						Q.push({ {nr + X - 1, nc}, cur.second + X});
						contin_length = 0;
						continue;
					}
					else
						return false;
				}
			}
		}
		else if (diff > 2)
		{
			possible_length = cur.second;
			return false;
		}

	}
	//cout << "N : "<<N<<" possible len : " << possible_length<<'\n';
	if (possible_length == N)
		return true;
	else
		return false;
}
inline int simulation()
{
	int result = 0;
	for (register int r = 0; r < N; ++r)
	{
		//cout << "\n"<<r<<"�� �˻� ��\n";
		if (search(r, 0))
			result++;
		//cout << '\n';
	}

	for (register int c = 0; c < N; ++c)
	{
		//cout << "\n"<<c<<"�� �˻� ��\n";
		if (search(c, 1))
			result++;
		//cout << '\n';
	}
	return result;
}
int main(int argc, char** argv)
{
	freopen("s_input4014.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> X;
		for (register int r = 0; r < N; ++r)
		{
			for (register int c = 0; c < N; ++c)
			{
				cin >> map[r][c];
			}
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}