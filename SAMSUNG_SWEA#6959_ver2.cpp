//
//	OS Windows
//	2019.02.18
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6959] <�̻��� ������ ��������> (D4)
//	
//	(���� Ǯ�� ���)
//	1. 1�ڸ� ���̸� ������ B�� �¸�
//	2. �־��� ���� ������ ¦���� �� �� �� �ڸ� ���ڵ��� ���� 10�̸��̸� A�� �¸�, 10�̻��̸� B�� �¸�, 19�̻��̸� A�� �¸�, 28�̻��̸� �ٽ� B�� �¸�......
//	3. �־��� ���� ������ Ȧ���� �� �� �� �ڸ� ���ڵ��� ���� 10�̸��̸� B�� �¸�, 10�̻��̸� A�� �¸�, 19�̻��̸� B�� �¸�, 28�̻��̸� �ٽ� A�� �¸�......
//	Answer) 5678�� ���� ���,
//			1) �־��� ���� ������ ���� ����Ʈ(���� 10���� ���� �� == Count�� 0�� ��) ���ڸ� ���� (5678�� ���ڰ� ¦���� �̹Ƿ� ����Ʈ ���ڴ� A)
//			2) �� �ڸ� ���ڵ��� ���� (�� : 26)
//			3) ���� 10���� ���� �� ��ŭ ���ڰ� �ٲ� (�� : 2, A -> B -> A�̹Ƿ� A)
//			4) ���� 10���� ���� ���̶� �������� ���� (�� : 8)
//			5) ���� 10���� ���� �� ��ŭ ���ڰ� �ٲ� (�� : 0, �״�� A)
//			6) ���� 10���� ���� ��� �������� ���� 10���� ũ�� 10���� ���� �� ���� �ݺ���
//
//	*�׷��Ƿ� �� ������� �� �ڸ� ������ Ȯ���ϴ� ���� �켱
//	1) while������ ���� 0�� �� ������ 10���� �����鼭 Count++ �ؼ� Ȯ���� �� �� �ְ�,
//	2) string���� �޾ƿͼ� length �� ���� ����
//	string���� �޾ƿ��� ������� �����غ�
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int Accumulate(int Num)									//�� �ڸ� ���ڸ� ��� ���ϴ� �Լ�
{
	int Temp = 0;
	int Quotient = 0, Remainder = 0;
	while (1)
	{
		Quotient = Num / 10;
		Remainder = Num % 10;
		Temp += Remainder;
		Num /= 10;
		if (Num == 0)
			break;
	}
	return Temp;
}

void DFS(int Num, int cnt)
{	
	int Quotient = 0, Remainder = 0;
	cnt += Num / 10;
	Quotient = Num / 10;
	Remainder = Num % 10;
	if (Quotient + Remainder < 10)
	{
		if (cnt % 2 == 0)
			printf("A\n");
		else
			printf("B\n");
		return;
		
	}
	else if (Quotient + Remainder >= 10)
	{
		DFS(Accumulate(Quotient + Remainder), cnt);
	}
}

int main(int argc, char** argv)
{
	string Input;
	int Number;
	int Sum;
	int Length;
	int test_case;
	int T;
	freopen("s_input6959.txt", "r", stdin);
	scanf("%d\n", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Input = { NULL, };											//string �迭 �ʱ�ȭ
		Number = 0; Length = 0;	Sum = 0;							//���� �ʱ�ȭ
		getline(cin, Input);										//�� �� string���� �о�� (string.length�� ���ڸ� ������ Ȯ���ϱ� ����)
		Number = stoi(Input);										//string�� ���ڷ� �ٲ㼭 �����ϰ�
		Length = Input.length();									//�� �ڸ� ������ �����ϰ�
		printf("#%d ", test_case);
		if (Length == 1)
			printf("B\n");
		else if (Length % 2 == 0)					//�־��� ���� ������ ¦���̸�
		{
			Sum = Accumulate(Number);				//���ڸ� ��� ���ϰ�
			DFS(Sum, 0);
		}
		else
		{											//�־��� ���� ������ Ȧ���̸�
			Sum = Accumulate(Number);
			DFS(Sum, 1);
		}
	}
	return 0;
}