//
//	OS Windows
//	2019.02.14
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6855] <�ŵ��� ���� �����ϱ�> (D4)
//	
//	K(������ ����)�� �� �����ؼ�(DFS) ����Ž���غ�����

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const static int MAX = 100000;
const static int INF = 2147000000;
typedef pair<int, int> PII;

class Planning
{
private:
	int NumOfHouse;
	int NumOfPlant;
	int *Distance;						//�����ҿ��� �� �� ������ �Ÿ��� ����ؼ� �����صα� ���� �迭
	int *Plant;							//DFS�� �����Ҹ� ��ġ�� ��� ����� ���� ��ȸ�� �� ������ ��ġ�� �����صα� ���� �迭
	bool *Check;						//DFS����� �� ����ϱ� ���� bool �迭
	int Wire;
	int Answer;
public:
	explicit Planning(int N, int K);
	~Planning();
	void DFS(const vector<int>& H, int count);
	void Calculation(const vector<int>& H);
	void InitDistance();
	int PrintAnswer() const;
};

Planning::Planning(int N, int K) : NumOfHouse(N), NumOfPlant(K), Wire(INF), Answer(INF)
{
	Distance = new int[N];
	Plant = new int[N];
	Check = new bool[N];
	for (int init = 0; init < N; ++init)
	{
		Distance[init] = INF;
		Plant[init] = 0;
		Check[init] = false;
	}
}
Planning::~Planning()
{
	delete[] Distance;
	delete[] Plant;
	delete[] Check;
}

void Planning::DFS(const vector<int>& H, int count)
{
	if (count == NumOfPlant)
	{
		Calculation(H);
		if (Answer > Wire)
		{
			Answer = Wire;
		}
		return;
	}
	else
	{
		for (int i = 0; i < NumOfHouse; ++i)
		{
			if (Check[i] == false)
			{
				Plant[count] = i;
				Check[i] = true;
				DFS(H, count + 1);
				Check[i] = false;
			}
		}
	}
}
void Planning::Calculation(const vector<int>& H)
{
	int Sum = 0;
	for (int i = 0; i < NumOfPlant; ++i)
	{
		for (int j = 0; j < NumOfHouse; ++j)
		{
			if (Plant[i] == j)
			{
				Distance[j] = 0;								//�����ҿ� ������ ���� ��ġ�� �������� �Ÿ��� 0
			}
			else
			{
				if (Distance[j] > abs(H[Plant[i]] - H[j]))		//���� �����ҿ��������� �Ÿ��� ���� �����Һ����� �Ÿ����� ���
				{
					Distance[j] = abs(H[Plant[i]] - H[j]);		//ª�� �Ÿ��� ����
				}
			}
		}
	}

	for (int i = 0; i < NumOfHouse; ++i)
	{
		Sum += Distance[i];
	}
	if (Wire > Sum)
		Wire = Sum;

	InitDistance();
}
void Planning::InitDistance()
{
	for (int i = 0; i < NumOfHouse; ++i)
	{
		Distance[i] = INF;
	}
}
int Planning::PrintAnswer() const
{
	return Answer;
}

int main(int argc, char** argv)
{
	Planning *Plan[51];
	int test_case = 0;
	int N = 0, K = 0;
	vector<int> Home;					//�� �������� �Ÿ� ��ǲ�� �����ϱ� ���� ����
	//freopen("s_input.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; ++tc)
	{
		Home.clear();
		try
		{
			scanf("%d %d", &N, &K);
			if (N > MAX || K > MAX)
				throw PII(N, K);
			for (int in = 0; in < N; ++in)
			{
				int recent = 0;
				scanf("%d", &recent);
				Home.push_back(recent);
			}
		}
		catch (PII expn)
		{
			printf("#%d �Է°��� ������ �ʰ��߽��ϴ�. N:%d, K:%d\n", tc, expn.first, expn.second);
		}
		Plan[tc] = new Planning(N, K);
		if (N == K || N < K)
		{
			printf("#%d 0\n", tc);
			continue;
		}
		else
		{
			Plan[tc]->DFS(Home, 0);
			int Result = Plan[tc]->PrintAnswer();
			printf("#%d %d\n", tc, Result);
		}
	}

	for (int del = 1; del <= test_case; ++del)
	{
		delete Plan[del];
	}
	return 0;
}