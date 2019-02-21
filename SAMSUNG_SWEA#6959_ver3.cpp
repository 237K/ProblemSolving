//
//	OS Windows
//	2019.02.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6959] <�̻��� ������ ��������> (D4)
//	
//	*�׳� �����ϰ� string�� cin���� �޾ƿ� ������ 
//	 1) �տ������� �� ���� ���ڷ� �ٲ㼭 ���ϰ�, 
//	 2) string���� �տ� �� �� �߶󳻰� 
//	 3) 1������ ���Ѱ� �ٿ��ְ�,
//	 4) �ڿ��� �ٿ��ִ°�
//	 5) ���̰� 1�� �� ���� �ݺ���
//	 *Flag�� ���� ���ڸ� ����ϴµ� ����Ŭ�� �� �� �� ������(���濡�� ���ڸ� �ѱ� �� ����) ���ڰ� �ٲ�
//	  -1�� �����ؼ� -1�̸� B�� �¸�, 1�̸� A�� �¸�
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <sstream>						//stringstream
#include <iostream>
using namespace std;

static string ItoS(int n);				//���ڸ� ���ڷ� ��ȯ�ؼ� ���ڿ��� �����ϱ� ���� �Լ�

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string Input;
	int Length;
	int Flag;
	freopen("s_input6959.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Input.clear();
		Length = 0;
		Flag = -1;

		cin >> Input;

		Length = Input.length();
		while (1)
		{
			int Sum = 0;
			int Idx = 0;
			if (Length == 1)
				break;
			int a = Input[Idx] - '0';
			int b = Input[Idx + 1] - '0';
			Sum = a + b;
			Input = Input.substr(0, Idx) + ItoS(Sum) + Input.substr(Idx + 2, Length - 1);
			Length = Input.length();
			Idx += 1;
			Flag *= -1;
		}
		if (Flag == 1)
			printf("#%d A\n", test_case);
		else if (Flag == -1)
			printf("#%d B\n", test_case);

	}
	return 0;
}

string ItoS(int n)
{
	stringstream s;
	s << n;
	return s.str();
}