//
//	OS Windows
//	2019.04.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2806> N-Queen (D3)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
const static int DIRECT = 8;
const static int SIZE = 10;
static int dir[DIRECT][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };
static int map[SIZE][SIZE];
static int check[SIZE];
static int N;
static int result;

//��� ���� �˻���ص� �Ǳ� ������, Ȥ�� ���� 8���� �� �˻��غ�
inline bool possible(int row, int col)
{
	for (register int d = 0; d < DIRECT; ++d)
	{
		for (register int n = 1; n < N; ++n)
		{
			int r = row + (n * dir[d][0]);
			int c = col + (n * dir[d][1]);
			if (r < 0 || c < 0 || r >= N || c >= N)
				continue;
			if (map[r][c])
				return false;
		}
	}
	return true;
}

//DFS�� �����غ�
//�� �࿡�� ���� �ϳ� �ۿ� ���� �� �����Ƿ� N���� ���� �ݵ�� N���� �࿡ �ϳ��� ���ƾߵ�. 
//���� �ϳ� ������ ����� ���� ���ϱ޼������� �پ��Ƿ� N�� Ŀ���� ����ð��� ũ�� �þ�� ���� ��
inline void N_Queen(int count)
{
	//���� N�� ������ ����Ǽ� +1
	//���� N�� ���� ���ϸ� N-1���� ���ư��� �ٸ� �ڸ��� ������ �ȵǸ� N-2���� ���ư��� �ٸ��ڸ��� ������........�ݺ�
	if (count == N)
	{
		result++;
		return;
	}
	else
	{
		for (register int c = 0; c < N; ++c)
		{
			//�� ���� �̹� üũ������ �Ѿ��
			if (check[c])
				continue;
			//�� ���� ������ üũ���� �ʾҰ�, �� �ڸ��� �ٸ� ���� ����, 8�������� ��� ���� ������
			if (!map[count][c] && possible(count, c))
			{
				//���⿡ ���� ���� ���� ������ �Ѿ�� ���� 8�� ��� ���� �� ������ ����Ǽ� +1
				check[c]++;
				map[count][c]++;
				N_Queen(count + 1);
				check[c] = 0;
				map[count][c] = 0;
			}
		}
	}
}

int main(int argc, char** argv)
{
	freopen("s_input2806.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(map, 0, sizeof(map));
		(void)memset(check, 0, sizeof(check));
		result = 0;
		cin >> N;
		N_Queen(0);
		cout << "#" << test_case << ' ' << result << '\n';
	}
	return 0;
}