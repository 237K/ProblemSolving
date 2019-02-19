//
//	OS Windows
//	2019.02.18
//
//	[Algorithm Problem Solving]
//
//	<뒤집어 더하기>
//	
//	1. 10,000,000 이하의 양수가 주어짐
//	2. 수를 뒤집어서 더함
//	3. 더했을 때 펠린드롬인지 확인하여 yes or no 출력
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int arr[10];
int ReverseN;
int Count;

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

void MakeArray(int n)
{
	int tmp = n;
	int idx = 0;
	while (tmp != 0)
	{
		int Quotient = tmp / 10;
		int Remainder = tmp % 10;
		arr[idx] = Remainder;
		idx++;
		Count++;
		tmp /= 10;
	}

	for (int i = 0; i < Count; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

bool Palindrome(int a[])
{
	int Start = 0;
	int End = Count-1;
	bool Flag = true;
	while (Start <= End)
	{
		if (arr[Start] != arr[End])
		{
			Flag = false;
			break;
		}
		else
		{
			Start++;
			End--;
		}
	}
	return Flag;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int Sum;
	freopen("testcase_ReverseAdd.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		*arr = { 0, };
		ReverseN = 0;	Sum = 0;	Count = 0;
		scanf("%d", &N);
		cout << "#" << test_case << endl;
		Reverse(N);
		Sum = N + ReverseN;
		MakeArray(Sum);
		if (Palindrome(arr))
			printf("Yes\n");
		else
			printf("No\n");
		printf("\n");
	}
	return 0;
}