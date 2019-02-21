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
//
//	(*�ֿ� �帧��)
//	1. 1000�� ������ ���� �� �� ������ �о�ͼ� char�迭�� ������ (getline ����ϴ� ä���������� �ڲ� ������ ������ ���� �ϳ��� ���о�ͼ� scanf �����)
//	2. ���ڰ� ����� Ȯ��
//	3. char�迭�� ����� ���ڸ� �ϳ��� int������ ��ȯ�ؼ� �����Ͽ� Sum�� ������
//	4. Sum�� ����Լ�(DFS �Լ�)�� �����ǵ�, ���� ������ ¦�����̸� cnt�� 0���� �ؼ� ������, Ȧ�����̸� 1�� �ؼ� ����
//	5. Sum�� 10���� ���� ��ŭ cnt�� ����
//	6. Sum�� �� �ڸ��� ����(Accumulate �Լ�)
//	7. Sum�� �� �ڸ��� ���Ѱ� 10���� ������ cnt�� ���� ���� ���
//	8. 10�̻��̸� �ٽ� DFS�� ����
//	9. 10���� ���� ��ŭ cnt�� ���ϰ�.. �ٽ� �� �ڸ��� ���ؼ� 10���� ������ ����ϰ� 10�̻��̸� �ݺ�...
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
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
	int Acc = 0;
	cnt += Num / 10;
	Acc = Accumulate(Num);
	if (Acc < 10)
	{
		if (cnt % 2 == 0)
			printf("A\n");
		else
			printf("B\n");
		return;
	}
	else if (Acc >= 10)
	{
		DFS(Acc, cnt);
	}
}

int StoI(char ch)
{
	switch (ch)
	{
	case 48:
		return 0;
		break;
	case 49:
		return 1;
		break;
	case 50:
		return 2;
		break;
	case 51:
		return 3;
		break;
	case 52:
		return 4;
		break;
	case 53:
		return 5;
		break;
	case 54:
		return 6;
		break;
	case 55:
		return 7;
		break;
	case 56:
		return 8;
		break;
	case 57:
		return 9;
		break;
	default:
		return -1;
		break;
	}
}

int main(int argc, char** argv)
{
	int Sum;
	int Length;
	int test_case;
	int T;
	char Input[1001];
	freopen("s_input6959.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int init = 0; init < 1001; ++init)
			Input[init] = NULL;
		Length = 0;
		Sum = 0;
		scanf("%1000s", &Input);
		while (Input[Length] != NULL)
		{
			Sum += StoI(Input[Length]);
			Length++;
		}
		printf("#%d ", test_case);
		if (Length == 1)
			printf("B\n");
		else if (Length % 2 == 0)					//�־��� ���� ������ ¦���̸�
		{
			DFS(Sum, 0);
		}
		else
		{											//�־��� ���� ������ Ȧ���̸�
			DFS(Sum, 1);
		}

	}
	return 0;
}