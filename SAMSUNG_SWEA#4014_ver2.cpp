//
//	OS Windows
//	2019.05.08
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#4014] <Ȱ�ַ� �Ǽ�> (����)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const static int SIZE = 20;
static int map[SIZE][SIZE];
static int N, X;
inline int simulation()
{
	int result = 0;
	register int r, c, i;
	//	���� Ȱ�ַ� �˻�
	for (r = 0; r < N; ++r)
	{
		int len = 1;
		int equal_h = 1;
		int flag = 1;
		for (c = 1; c < N; ++c)
		{
			int diff = map[r][c] - map[r][c - 1];
			if (diff > 1 || diff < -1) break;
			if (!diff)
			{
				equal_h++;
				len++;
			}
			//	�����ʿ� �ִ� ������ ���� ���
			if (diff == 1)
			{
				//	���ʿ� ���̰� ���� ���� ������ X���� �����̸� ���� ��ġ�� �� ����
				if (equal_h >= X)
				{
					equal_h = 1;
					len++;
					continue;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			//	�����ʿ� �ִ� ������ ���� ���
			else if (diff == -1)
			{
				equal_h = 1;
				for (i = c + 1; i < N; ++i)
				{
					if (map[r][i] != map[r][i - 1])
						break;
					else
					{
						if ((++equal_h) >= X)
							break;
					}
				}
				if (equal_h >= X)
				{
					equal_h = 0;
					c += X - 1;
					len += X;
				}
				else
					flag = 0;
			}
			if (!flag) break;
		}
		if (flag && (len == N))
		{
			result++;
		}
	}
	//	���� Ȱ�ַ� �˻�
	for (c = 0; c < N; ++c)
	{
		int len = 1;
		int equal_h = 1;
		int flag = 1;
		for (r = 1; r < N; ++r)
		{
			int diff = map[r][c] - map[r-1][c];
			if (diff > 1 || diff < -1) break;
			if (!diff)
			{
				len++;
				equal_h++;
			}
			if (diff == 1)
			{
				if (equal_h >= X)
				{
					equal_h = 1;
					len++;
					continue;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			else if (diff == -1)
			{
				equal_h = 1;
				for (i = r + 1; i < N; ++i)
				{
					if (map[i][c] != map[i - 1][c])
						break;
					else
					{
						if ((++equal_h) >= X)
							break;
					}
				}
				if (equal_h >= X)
				{
					equal_h = 0;
					r += X - 1;
					len += X;
				}
				else
					flag = 0;
			}
			if (!flag) break;
		}
		if (flag && (len == N))
		{
			result++;
		}
	}
	return result;
}
int main(int argc, char** argv)
{
	freopen("s_input4014.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	register int test_case, r, c;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> X;
		for (r = 0; r < N; ++r)
		{
			for (c = 0; c < N; ++c)
			{
				cin >> map[r][c];
			}
		}
		cout << "#" << test_case << ' ' << simulation() << '\n';
	}
	return 0;
}