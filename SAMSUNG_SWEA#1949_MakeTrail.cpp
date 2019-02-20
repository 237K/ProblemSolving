//
//	OS Windows
//	2019.02.20
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1949] <���� ����> (���� SW �����׽�Ʈ)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> PII;
const static int MAX = 8;

//ó���� class�� ������ٰ� ä������ ����� �ȵǼ�.. ��Ÿ���Ե� ������ �� �ۿ� Ƣ����ֽ��ϴ�..
int Map[MAX][MAX];					//�������� ����
bool Check[MAX][MAX];				//��ǥ �湮 ���� Ȯ��
int N, K;
stack<PII> Start;					//���� ���� ���츮 ��ǥ �����ص� stack
int Top;							//���� ���� ���츮 ���� ����
int Count;							//���� ���� ����
bool CanDig;						//���縦 �ߴ��� ���ߴ��� Ȯ���ϱ� ����
int Answer;

void Make(PII L)					//DFS
{
	Check[L.first][L.second] = true;								//��ǥ �湮 üũ
	if (L.first - 1 >= 0 && Check[L.first - 1][L.second] == false)	//���� ����� �ʰ�, �湮������ ���� ���
	{
		if (Map[L.first - 1][L.second] < Map[L.first][L.second])	//���� ������ ���ݺ��� ������ ������
		{
			Count++;												//���� ��ġ�ϰ�
			Make(PII(L.first - 1, L.second));						//���� ��ǥ�� ���ȣ��
			Answer = max(Answer, Count);							//�� ��η� ���� �� ���α��̰� ���ݺ��� ��� ����
			Count--;												//�ٸ� ��� Ž���� ���� �ʱ�ȭ
		}
		else
		{																				//���� ����� �ʰ� �湮������ ���µ�, ���� ������ ���ݺ��� ���ų� ���ݰ� ������
			int dig1 = abs(Map[L.first][L.second] - Map[L.first - 1][L.second]) + 1;	//�󸶳� �ľߵ��� ������ �̾ƺ���(���ݺ��� 1�� ���� ��쿡 �� ���� �������� �� �� ���� Ȯ���� ����)
			if (CanDig == true && dig1 <= K)											//���縦 �� ���� ����, ���� ���� ���̸�
			{
				Map[L.first - 1][L.second] -= dig1;										//�����ϰ�
				CanDig = false;															//���� �� �� ������, ���� ����
				Count++;																//���� ��ġ
				Make(PII(L.first - 1, L.second));										//���� ��ǥ�� ���ȣ��
				Answer = max(Answer, Count);											//����� ���� �� �ִ� ���̰� ������ ����
				CanDig = true;															//�ٸ� ��� Ž���� ���� �ʱ�ȭ
				Map[L.first - 1][L.second] += dig1;
				Count--;
			}
		}
	}
	if (L.first + 1 < N && Check[L.first + 1][L.second] == false)
	{
		if (Map[L.first + 1][L.second] < Map[L.first][L.second])
		{
			Count++;
			Make(PII(L.first + 1, L.second));
			Answer = max(Answer, Count);
			Count--;
		}
		else
		{
			int dig2 = abs(Map[L.first][L.second] - Map[L.first + 1][L.second]) + 1;
			if (CanDig == true && dig2 <= K)
			{
				Map[L.first + 1][L.second] -= dig2;
				CanDig = false;
				Count++;
				Make(PII(L.first + 1, L.second));
				Answer = max(Answer, Count);
				CanDig = true;
				Map[L.first + 1][L.second] += dig2;
				Count--;
			}
		}
	}
	if (L.second - 1 >= 0 && Check[L.first][L.second - 1] == false)
	{
		if (Map[L.first][L.second - 1] < Map[L.first][L.second])
		{
			Count++;
			Make(PII(L.first, L.second - 1));
			Answer = max(Answer, Count);
			Count--;
		}
		else
		{
			int dig3 = abs(Map[L.first][L.second] - Map[L.first][L.second - 1]) + 1;
			if (CanDig == true && dig3 <= K)
			{
				Map[L.first][L.second - 1] -= dig3;
				CanDig = false;
				Count++;
				Make(PII(L.first, L.second - 1));
				Answer = max(Answer, Count);
				CanDig = true;
				Map[L.first][L.second - 1] += dig3;
				Count--;
			}
		}
	}
	if (L.second + 1 < N && Check[L.first][L.second + 1] == false)
	{
		if (Map[L.first][L.second + 1] < Map[L.first][L.second])
		{
			Count++;
			Make(PII(L.first, L.second + 1));
			Answer = max(Answer, Count);
			Count--;
		}
		else
		{
			int dig4 = abs(Map[L.first][L.second] - Map[L.first][L.second + 1]) + 1;
			if (CanDig == true && dig4 <= K)
			{
				Map[L.first][L.second + 1] -= dig4;
				CanDig = false;
				Count++;
				Make(PII(L.first, L.second + 1));
				Answer = max(Answer, Count);
				CanDig = true;
				Map[L.first][L.second + 1] += dig4;
				Count--;
			}
		}
	}
	Check[L.first][L.second] = false;
}

void PushStack()								//���� ���� ���츮 ã�Ƽ� ���ÿ� �ִ� �Լ�
{
	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
		{
			if (Map[r][c] == Top)
				Start.push(PII(r, c));
		}
	}
}

void InitMap()									//�迭�̶� ����, ���� ���� �ʱ�ȭ �Լ�
{
	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
		{
			Map[r][c] = 0;
			Check[r][c] = false;
		}
	}
	while (!Start.empty()) { Start.pop(); }
	Answer = 0;
	Top = 0;
	N = 0;
	K = 0;
	CanDig = true;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		InitMap();
		scanf("%d %d", &N, &K);
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				scanf("%d", &Map[r][c]);
				if (Top < Map[r][c])
					Top = Map[r][c];
			}
		}
		PushStack();
		while (!Start.empty())
		{
			PII Cur = Start.top();
			Start.pop();
			Count = 1;
			Make(Cur);
		}
		printf("#%d %d\n", test_case, Answer);
	}
	return 0;
}