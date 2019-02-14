//
//	OS Windows
//	2019.02.14
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6855] <신도시 전기 연결하기> (D4)
//	
//	K(발전소 개수)개 씩 조합해서(DFS) 완전탐색해보겠음

#include <iostream>
#include <fstream>
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
	vector<int> Home;					//각 집까지의 거리 인풋값 저장하기 위한 벡터
	int *Distance;						//발전소에서 각 집 까지의 거리를 계산해서 저장해두기 위한 배열
	int *Plant;							//DFS로 발전소를 설치할 모든 경우의 수를 순회할 때 발전소 위치를 저장해두기 위한 배열
	bool *Check;						//DFS사용할 때 사용하기 위한 bool 배열
	int Wire;						
	int Answer;
public:
	explicit Planning(int N, int K);
	~Planning();
	void Input(ifstream& _fin);
	void DFS(int count);
	void Calculation();
	void InitDistance();
	void PrintAnswer() const;
};

Planning::Planning(int N, int K) : NumOfHouse(N), NumOfPlant(K), Wire(INF), Answer(INF)
{
	Home.clear();
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

void Planning::Input(ifstream& _fin)
{
	int Recent = 0;
	for (int init = 0; init < NumOfHouse; ++init)
	{
		_fin >> Recent;
		Home.push_back(Recent);
	}
}

void Planning::DFS(int count)
{
		if (count == NumOfPlant)
		{
			Calculation();
			if (Answer > Wire)
			{
				Answer = Wire;
			}
			return;
		}
		else
		{
			for (vector<int>::size_type i = 0; i < Home.size(); ++i)
			{
				if (Check[i] == false)
				{
					Plant[count] = i;
					Check[i] = true;
					DFS(count + 1);
					Check[i] = false;
				}
			}
		}
}
void Planning::Calculation()
{
	int Sum = 0;
	for (int i = 0; i < NumOfPlant; ++i)
	{
		for (vector<int>::size_type j = 0; j < Home.size(); ++j)
		{
			if (Plant[i] == j)
			{
				Distance[j] = 0;				//발전소와 동일한 곳에 위치한 집까지의 거리는 0
			}
			else
			{
				if (Distance[j] > abs(Home[Plant[i]] - Home[j]))		//이전 발전소에서부터의 거리가 다음 발전소부터의 거리보다 길면
				{
					Distance[j] = abs(Home[Plant[i]] - Home[j]);		//짧은 거리로 갱신
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
void Planning::PrintAnswer() const
{
	cout << Answer << endl;
}

int main(void)
{
	Planning *Plan[51];
	int testcase = 0;
	int N = 0 , K = 0;
	ifstream fin("s_input.txt");
	ofstream fout("s_output.txt");

	if (!fin.is_open())
	{
		fout << "파일을 찾을 수 없습니다." << endl;
	}

	fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		try
		{
			fin >> N >> K;
			if (N > MAX || K > MAX)
				throw PII(N, K);
			Plan[tc] = new Planning(N, K);
		}
		catch (PII expn)
		{
			fout << "(예외발생. 입력받은 N혹은K 값이 범위를 초과했습니다.) N : " << expn.first << ", K : " << expn.second << endl << endl;
		}
		Plan[tc]->Input(fin);
		Plan[tc]->DFS(0);
		cout << "#" << tc << " ";
		Plan[tc]->PrintAnswer();
	}

	fin.close();
	fout.close();

	for (int del = 1; del <= testcase; ++del)
	{
		delete Plan[del];
	}
	return 0;
}