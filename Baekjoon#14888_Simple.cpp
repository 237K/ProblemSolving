//
//	OS Windows
//	2019.02.07
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14888	연산자 끼워넣기
//	
//	Simple version
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const static int INF = 2137000000;

class Calculator
{
private:
	int Size;
	int *Number;
	int Operator[4];
	int Plus, Minus, Mul, Div;
	int Result;
	int Max, Min;
public:
	Calculator(int _Size) : Size(_Size), Plus(0), Minus(0), Mul(0), Div(0), Result(0), Max(-INF), Min(INF)
	{
		Number = new int[_Size];
		for (int init = 0; init < _Size; ++init)
		{
			Number[init] = 0;
		}
		for (int init = 0; init < 4; ++init)
		{
			Operator[init] = 0;
		}
	}
	void Setting(ifstream& _fin)
	{
		for (int init = 0; init < Size; ++init)
		{
			_fin >> Number[init];
		}
		for (int init = 0; init < 4; ++init)
		{
			_fin >> Operator[init];
		}
	}

	void Execution()
	{
		Operating(1, Number[0]);
	}

	void Operating(int index, int _Result)
	{
		if (index == Size)
		{
			Max = max(Max, _Result);
			Min = min(Min, _Result);
			return;
		}
		if (Operator[0] > 0)
		{
			Operator[0]--;
			Operating(index+1, _Result + Number[index]);
			Operator[0]++;
		}
		if (Operator[1] > 0)
		{
			Operator[1]--;
			Operating(index+1, _Result - Number[index]);
			Operator[1]++;
		}
		if (Operator[2] > 0)
		{
			Operator[2]--;
			Operating(index+1, _Result * Number[index]);
			Operator[2]++;
		}
		if (Operator[3] > 0)
		{
			Operator[3]--;
			Operating(index+1, _Result / Number[index]);
			Operator[3]++;
		}
	}
	void PrintResult() const
	{
		cout << "Max : " << Max << endl;
		cout << "Min : " << Min << endl << endl;
	}
	~Calculator()
	{
		delete[] Number;
	}
};

int main(void)
{
	Calculator *Cal[100];
	int testcase = 0;
	ifstream fin("testcase_Operator1.txt");
	ofstream fout("testcase_Operator1_237_Simple.txt");

	fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		int _Size = 0;
		fin >> _Size;
		Cal[tc] = new Calculator(_Size);
		Cal[tc]->Setting(fin);
		cout << "#" << tc << endl;
		Cal[tc]->Execution();
		Cal[tc]->PrintResult();
	}

	fin.close();
	fout.close();
	return 0;
}