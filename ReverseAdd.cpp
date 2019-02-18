//
//	OS Windows
//	2019.02.18
//
//	[Algorithm Problem Solving]
//
//	<������ ���ϱ�>
//	
//	1. 10,000,000 ������ ����� �־���
//	2. ���� ����� ����
//	3. ������ �� �縰������� Ȯ���Ͽ� yes or no ���
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int arr[10];
int ReverseN;

void Reverse(int n)
{
	int Cur = n;
	while (1)
	{
		int Quotient = Cur / 10;
		int Remainder = Cur % 10;
		ReverseN += Remainder;
		Cur = Cur / 10;
		if (Cur == 0)
			break;
		else
			ReverseN *= 10;
	}
	cout << "Number : " << n << ", Reverse : " << ReverseN << endl;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	freopen("testcase_ReverseAdd.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		*arr = { 0, };
		ReverseN = 0;
		scanf("%d", &N);
		cout << "#" << test_case << endl;
		Reverse(N);
	}
	return 0;
}