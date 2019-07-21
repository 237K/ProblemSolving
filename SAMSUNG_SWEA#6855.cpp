//
//	OS Windows
//	2019.02.14
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6855] <�ŵ��� ���� �����ϱ�> (D4)
//	
//	K(������ ����)�� �� �����ؼ�(DFS) ����Ž���غ�����

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
	vector<int> Home;					//�� �������� �Ÿ� ��ǲ�� �����ϱ� ���� ����
	int *Distance;						//�����ҿ��� �� �� ������ �Ÿ��� ����ؼ� �����صα� ���� �迭
	int *Plant;							//DFS�� �����Ҹ� ��ġ�� ��� ����� ���� ��ȸ�� �� ������ ��ġ�� �����صα� ���� �迭
	bool *Check;						//DFS����� �� ����ϱ� ���� bool �迭
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
				Distance[j] = 0;				//�����ҿ� ������ ���� ��ġ�� �������� �Ÿ��� 0
			}
			else
			{
				if (Distance[j] > abs(Home[Plant[i]] - Home[j]))		//���� �����ҿ��������� �Ÿ��� ���� �����Һ����� �Ÿ����� ���
				{
					Distance[j] = abs(Home[Plant[i]] - Home[j]);		//ª�� �Ÿ��� ����
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
		fout << "������ ã�� �� �����ϴ�." << endl;
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
			fout << "(���ܹ߻�. �Է¹��� NȤ��K ���� ������ �ʰ��߽��ϴ�.) N : " << expn.first << ", K : " << expn.second << endl << endl;
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