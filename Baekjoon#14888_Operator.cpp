//
//	OS Windows
//	2019.02.07
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14888	������ �����ֱ�
//	

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const static int INF = 214700000;

class Calculator
{
private:
	int Size;
	vector<int> Number;						//���� ������ ����
	vector<char> Operator;					//������ ������ ����
	queue<char> Q;							//�����ڸ� ���(�����ؼ�) �־�� ť
	int Result;
	int InputNumber;
	int Plus, Minus, Mul, Div;
	int Min, Max;
public:
	Calculator(int _Size) : Size(_Size), InputNumber(0), Plus(0), Minus(0), Mul(0), Div(0), Min(INF), Max(-INF), Result(0)
	{
		Number.clear();
		Operator.clear();
		Number.resize(_Size+1, 0);
		Operator.resize(_Size, 'n');
	}
	~Calculator() {}
	void Setting(ifstream& _fin)					//��ǲ�� �о���� �Լ�
	{
		for (int init = 1; init <= Size; ++init)
		{
			_fin >> InputNumber;
			Number[init] = InputNumber;
		}
		_fin >> Plus >> Minus >> Mul >> Div;
													//�־��� �����ڸ� ������ ���Ϳ� ����
		int init = 1;
			while (!(Plus == 0))
			{
				Operator[init] = '+';
				Plus--;
				init++;
			}
			while (!(Minus == 0))
			{
				Operator[init] = '-';
				Minus--;
				init++;
			}
			while (!(Mul == 0))
			{
				Operator[init] = '*';
				Mul--;
				init++;
			}
			while (!(Div == 0))
			{
				Operator[init] = '/';
				Div--;
				init++;
			}
		Print();
	}
	void Print() const
	{
		cout << "vector Number   : ";
		for (vector<int>::size_type i = 1; i < Number.size(); ++i)
		{
			cout << Number[i] << ' ';
		}
		cout << endl << "vector Operator : ";
		for (vector<int>::size_type i = 1; i < Operator.size(); ++i)
		{
			cout << Operator[i] << ' ';
		}
		cout << endl << endl;
	}
	void Execution()
	{								//���� 2��, ������ 1���� ��쿡 ���� ������ �����Ƿ� while ���� ���� ����. �ּ� 1���� �����ϵ��� do while ���
		do
		{
			int Recent = 0;
			Result = Number[1];		//ù��° ���ڸ� ���ڷ� �����ϰ�, �� ���ڸ� ������ ���� ���ڷ� �ݺ� ����� ����

				for (vector<int>::size_type i = 1; i < Operator.size(); ++i)		//2. ������ ���Ϳ� ����ִ� ������� ť�� Ǫ��
				{
					if (Operator[i] != '\0')
					{
						Q.push(Operator[i]);
					}
				}
			
			for (vector<int>::size_type n = 2; n < Number.size(); ++n)
			{
				if (!Q.empty())
				{
					char O = Q.front();
					cout << O << ' ';
					Q.pop();
					Recent = Operating(Result, Number[n], O);						//3. Result�� ���ں����� ���� ���ڸ� ť���� ���� �����ڷ� ������
					Result = Recent;
					Max = max(Max, Result);											//4. �ִ밪/�ּҰ� ��
					Min = min(Min, Result);
				}
				cout << endl;
			}

		}
		while (next_permutation(Operator.begin(), Operator.end()));			//1. algorithm ����� next_permutation �Լ��� ������ ���͸� ���� ������ ���� ( + * -> * + )

		cout << "Max : " << Max << endl;
		cout << "Min : " << Min << endl << endl;
	}
	int Operating(int _Num1, int _Num2, char _Operator)
	{
		switch (_Operator)
		{
		case '+':
			return _Num1 + _Num2;
			break;
		case '-':
			return _Num1 - _Num2;
			break;
		case '*':
			return _Num1 * _Num2;
			break;
		case '/':
			if (_Num1 < 0 && _Num2 > 0)
				return -((-(_Num1)) / _Num2);
			else if (_Num2 == 0)
			{
				cout << "Divided by 0" << endl;
				return INF;
			}
			else
			{
				return _Num1 / _Num2;
				break;
			}
		}
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
		cout << "#" << tc << endl;
		Cal[tc]->Execution();
	}

	fin.close();
	fout.close();
	return 0;
}