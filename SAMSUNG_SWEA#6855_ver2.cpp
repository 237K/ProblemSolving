//
//	OS Windows
//	2019.02.14
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6855] <신도시 전기 연결하기> (D4)
//	
//	K(발전소 개수)개 씩 조합해서(DFS) 완전탐색해보겠음

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
	int *Distance;						//발전소에서 각 집 까지의 거리를 계산해서 저장해두기 위한 배열
	int *Plant;							//DFS로 발전소를 설치할 모든 경우의 수를 순회할 때 발전소 위치를 저장해두기 위한 배열
	bool *Check;						//DFS사용할 때 사용하기 위한 bool 배열
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
				Distance[j] = 0;								//발전소와 동일한 곳에 위치한 집까지의 거리는 0
			}
			else
			{
				if (Distance[j] > abs(H[Plant[i]] - H[j]))		//이전 발전소에서부터의 거리가 다음 발전소부터의 거리보다 길면
				{
					Distance[j] = abs(H[Plant[i]] - H[j]);		//짧은 거리로 갱신
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
	vector<int> Home;					//각 집까지의 거리 인풋값 저장하기 위한 벡터
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
			printf("#%d 입력값이 범위를 초과했습니다. N:%d, K:%d\n", tc, expn.first, expn.second);
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