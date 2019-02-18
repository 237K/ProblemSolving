//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6959] <�̻��� ������ ��������> (D4)
//	
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

bool IsTheEnd;								//����Լ� ��������
void Play(int Number, int Count)
{
	while (!IsTheEnd)
	{
		int Quotient = 0;					//��
		int Remainder = 0;					//������
		if (Number < 10)					//���ڰ� 10���� ������
		{
			IsTheEnd = true;				//�������� ����
			if (Count % 2 == 0)				//Count�� ¦���̸�
				printf("A\n");				//B�� �¸�
			else
				printf("B\n");				//�ƴϸ� A�� �¸�
			break;
		}
		else if (Number >= 10 && Number < 100)				//�� �ڸ� ���̸�
		{
			Quotient = Number / 10;							
			Remainder = Number % 10;
			Play(Quotient + Remainder, Count + 1);			//10���� ���� ��� �������� ���ؼ� �ٽ� ����Լ��� ����
		}
		else if (Number >= 100 && Number < 1000)			//�� �ڸ� ���̸�
		{
			Quotient = Number / 100;
			Remainder = Number % 100;
			Play(Quotient * 10 + Remainder, Count + 1);		//100���� ���� �� 10�� ���� �� �������� ���ؼ� �ٽ� ����Լ��� ����
		}
		else if (Number >= 1000 && Number <10000)			//�� �ڸ� ���̸�
		{
			Quotient = Number / 1000;
			Remainder = Number % 1000;
			Play(Quotient * 100 + Remainder, Count + 1);	//1000���� ���� �� 100�� ���� �� �������� ���ؼ� �ٽ� ����Լ��� ����
		}
		else if (Number >= 10000 && Number < 100000)
		{
			Quotient = Number / 10000;
			Remainder = Number % 10000;
			Play(Quotient * 1000 + Remainder, Count + 1);
		}
		else if (Number >= 100000 && Number < 1000000)
		{
			Quotient = Number / 100000;
			Remainder = Number % 100000;
			Play(Quotient * 10000 + Remainder, Count + 1);
		}
		else if (Number >= 1000000 && Number < 10000000)
		{
			Quotient = Number / 1000000;
			Remainder = Number % 1000000;
			Play(Quotient * 100000 + Remainder, Count + 1);
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("s_input6959.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int _Number = 0;
		IsTheEnd = false;
		scanf("%d", &_Number);
		printf("#%d ", test_case);
		Play(_Number, 1);
	}
	return 0;
}