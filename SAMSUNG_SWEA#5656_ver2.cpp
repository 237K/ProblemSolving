//
//	OS Windows
//	2019.03.18
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5656] <���� ����> (���� SW �����׽�Ʈ)
//	ver1. �ð��ʰ�	
//	ver2. Pass
//
#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef pair<int, int> coor;

const static int MAX_BALL = 5;
const static int MAX_ROW = 16;
const static int MAX_COL = 13;
const static int DIRECT = 4;
const static int DIR[DIRECT][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

static int Map[MAX_BALL][MAX_ROW][MAX_COL];
static int N, W, H;
static pair<coor, int> Q[MAX_ROW * MAX_COL];	//���� ������ �� ����� ť. ��ǥ�� ������ �ı����� ������ ����
static int Qstart, Qend;						//�׳� Q �ᵵ ����

inline void PrintMap()							//����� �۵��ϴ��� Ȯ���غ��� ����
{
	for (int r = 0; r < H; ++r)
	{
		for (int c = 0; c < W; ++c)
		{
			cout << Map[0][r][c] << ' ';
		}
		cout << "\n\n";
	}
}

inline int Shot(int ball)		//DFS (���)
{
	if (ball > N)				//��� Ż�� ����
		return 0;
	
	else
	{							//���� �κ�
		int result = 0;			//�̶����� �ı��� ���� �� ���� (����Ž���ϰ� ���� ���� �ı��� ����� �ı��� ���� �� ��ȯ)
		int temp;				//�̹��� �� ������ �ı��� ���� �� ����
		int curx, cury;			//���� ������ ��, �� �� ä�� �� ��ǥ �����ϱ� ���� ����

		for (int c = 0; c < W; ++c)
		{
			for (int cpy = 0; cpy < H; ++cpy)
				(void)memcpy(Map[ball][cpy], Map[ball - 1][cpy], sizeof(int)*W);	//������ �� ������ ���� �ı��Ȱ� �ݿ��� �� �����ؿ�
			temp = 0;
			bool check1 = true;					//������ 0�� ��� Ȯ���ϱ� ����
			bool check2 = false;				//���� �ı����� 1���� ū ��� Ȯ���ϱ� ����
			for (int r = 0; r < H; ++r)
			{
				if (Map[ball][r][c])			//0�� �ƴ� ���� ������
				{
					check1 = false;				
					if (Map[ball][r][c] > 1)	//���� �ı����� 1 ���� ũ��
						check2 = true;			//üũ�ص�
					Qstart = 0;
					Qend = 0;
					Q[Qend++] = { {r, c}, Map[ball][r][c] };	//ť�� ����
					Map[ball][r][c] = 0;						//�ش� ���� �ı�
					temp++;										//�ı��� ���� �� + 1
					while (Qstart < Qend)						//ť�� �� �� ���� while(!Q.empty())
					{
						int x = Q[Qstart].first.first;			//Q.pop()
						int y = Q[Qstart].first.second;
						int size = Q[Qstart++].second;

						if (Map[ball][x][y] == 1)
							continue;

						for (int d = 0; d < DIRECT; ++d)		//�������� ������
						{
							for (int s = 1; s < size; ++s)		//�ı��� ��ŭ
							{
								curx = x + (s * DIR[d][0]);		
								cury = y + (s * DIR[d][1]);
								if (curx < 0 || cury < 0 || curx >= H || cury >= W)		
									break;
								if (Map[ball][curx][cury] == 0)
									continue;
								if (Map[ball][curx][cury] > 1)	//�ı����� 1���� ũ��
								{
									Q[Qend++] = { {curx, cury}, Map[ball][curx][cury] };	//ť�� �ְ�
								}
								Map[ball][curx][cury] = 0;		//�ش� ���� �ı�
								temp++;							//�ı��� ���� �� + 1
							}
						}
					}
					break;				
				}
			}
			//�ı��ϰ��� ����ִºκ� ä��
			if (check1)
				continue;
			if (check2)
			{
				for (int dropc = 0; dropc < W; ++dropc)
				{
					int drop = 0;
					for (int dropr = H - 1; dropr >= 0; --dropr)
					{
						if (Map[ball][dropr][dropc] == 0)
							drop++;
						else if (drop)
						{
							curx = dropr + drop;

							int swap_container = Map[ball][dropr][dropc];
							Map[ball][dropr][dropc] = Map[ball][curx][dropc];
							Map[ball][curx][dropc] = swap_container;
						}
					}
				}
			}
			result = max(result, Shot(ball + 1) + temp);
		}
		return result;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("s_input5656.txt", "r", stdin);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> W >> H;
		int Result = 0;
		int Input_Brick = 0;
		for (int r = 0; r < H; ++r)
		{
			for (int c = 0; c < W; ++c)
			{
				cin >> Map[0][r][c];
				if (Map[0][r][c] > 0)
					Input_Brick++;				//���� ����� ����
			}
		}
		
		Result = Input_Brick - Shot(1);			//�Է¹��� ���� �������� ���� ���� �ı����� ���� ���� �� ��
		cout << "#" << test_case << ' ' << Result << '\n';
	}
	return 0;
}

