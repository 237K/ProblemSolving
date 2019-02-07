//
//	OS Windows
//	2019.02.07
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14888	연산자 끼워넣기
//	

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const static int INF = 214700000;

class Calculator
{
private:
	int Size;
	vector<int> Number;
	vector<char> Operator;
	vector<int> Result;
	int InputNumber;
	int Plus, Minus, Mul, Div;
public:
	Calculator(int _Size) : Size(_Size), InputNumber(0), Plus(0), Minus(0), Mul(0), Div(0)
	{
		Number.clear();
		Operator.clear();
		Number.resize(_Size+1, 0);
		Operator.resize(_Size, ' ');
		Result.clear();
	}
	~Calculator() {}
	void Setting(ifstream& _fin)
	{
		for (int init = 1; init <= Size; ++init)
		{
			_fin >> InputNumber;
			Number[init] = InputNumber;
		}
		_fin >> Plus >> Minus >> Mul >> Div;
		for (int init = 1; init < Size; ++init)
		{
			while (!(Plus == 0))
			{
				Operator.push_back('+');
				Plus--;
			}
			while (!(Minus == 0))
			{
				Operator.push_back('-');
				Minus--;
			}
			while (!(Mul == 0))
			{
				Operator.push_back('X');
				Mul--;
			}
			while (!(Div == 0))
			{
				Operator.push_back('/');
				Div--;
			}
		}

		Print();

	}
	void Print() const
	{
		cout << "vector Number   : ";
		for (auto i = 1; i < Number.size(); ++i)
		{
			cout << Number[i] << ' ';
		}
		cout << endl << "vector Operator : ";
		for (auto i = 1; i < Operator.size(); ++i)
		{
			cout << Operator[i] << ' ';
		}
		cout << endl << endl;
	}
};

int main(void)
{
	Calculator *Cal[100];
	int testcase = 0;
	int _Size = 0;
	ifstream fin("testcase_Operator1.txt");
	ofstream fout("Answer_Operator1_237.txt");

	fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		fin >> _Size;
		Cal[tc] = new Calculator(_Size);
		cout << "#" << tc << endl;
		Cal[tc]->Setting(fin);
	}

	fin.close();
	fout.close();
	return 0;
}