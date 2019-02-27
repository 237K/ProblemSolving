//
//	OS Windows
//	2019.02.27
//
//	[Algorithm Problem Solving]
//
//	<�߱��� ID ����>
//
//	1. �߱��� ID�� �� 18���ڷ� �����Ǿ� ����
//	2. ó�� 17���ڴ� ��� �����̸�, ������ ���ڴ� ���� Ȥ�� X
//	3. �� ���� ������� �����ڵ尡 6����, �����ڵ� 8����, �����ڵ� 3����, CheckSum Code 1���ڷ� ������
//	4. �����ڵ�� 000001, 000010, 000100, 001000, 010000, 100000 �� �ϳ�
//	5. �����ڵ�� 8�� �����̸� YYYYMMDD ����, 19000101 ~ 20141231 ������ ��ȿ
//	6. 000�� ��ȿ���� ����. Ȧ���̸� ����, ¦���̸� ����
//	7. �տ������� 17���� ���ڸ� a1, a2, ... , a17�̶�� �ϸ� CheckSum = (a1*pow(2, 17) + a2*pow(2, 16) + ... + a17*(2, 1)) % 11
//	   CheckSum�� ���� 0~10�̸�, 10�� ��� X�� ǥ��
//	8. ��ȿ�� ID�̸� "Male" or "Female", �������� ������ "Invalid" ���
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const static int REGION = 6;
const static int BIRTH = 8;
const static int GENDER = 3;

static string Region;
static int intRegion;
static string Birth;
static int intBirth;
static string Gender;
static int intGender;
static string CheckSum;
static int intCheckSum;

void Verification(const string& in);

int main(int argc, char** argv)
{
	int T;
	int test_case;
	string Input;
	freopen("testcase_ChineseID.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Input.clear();
		Region.clear();		intRegion = 0;
		Birth.clear();		intBirth = 0;
		Gender.clear();		intGender = 0;
		CheckSum.clear();	intCheckSum = 0;
		cin >> Input;
		printf("#%d ", test_case);
		Verification(Input);
		
	}
	return 0;
}

void Verification(const string& in)
{
	Region = in.substr(0, REGION);
	Birth = in.substr(REGION, BIRTH);
	intBirth = stoi(Birth);
	Gender = in.substr(REGION+BIRTH, GENDER);
	intGender = stoi(Gender);
	CheckSum = in[17];

	string Gen;
	//	4. �����ڵ�� 000001, 000010, 000100, 001000, 010000, 100000 �� �ϳ�
	int cnt = 0;
	int idx = 0;
	int sum = 0;

	for (int i = 0; i < REGION; ++i)
	{

		if (Region[i] == '1')
		{
			cnt++;
			idx = i;
		}
	}
	if (cnt != 1)
	{
		cout << "Invalid" << endl;
		return;
	}
	else
	{			//�����ڵ尡 ��ȿ�ϸ�,
		sum += (int)pow(2, 17 - idx);
	}
	
	//	5. �����ڵ�� 8�� �����̸� YYYYMMDD ����, 19000101 ~ 20141231 ������ ��ȿ
	if (intBirth < 19000101 || intBirth > 20141231)
	{
		cout << "Invalid" << endl;
		return;
	}
	else
	{
		for (int i = 6; i <= 13; ++i)
		{
			int tempNum = Birth[i - 6] - '0';
			sum += tempNum * (int)pow(2, 17 - i);
		}
	}
	//	6. 000�� ��ȿ���� ����. Ȧ���̸� ����, ¦���̸� ����
	if (intGender == 000)
	{
		cout << "Invalid" << endl;
		return;
	}
	else
	{
		if (intGender % 2 == 0)
			Gen = "Female";
		else
			Gen = "Male";

		for (int i = 14; i <= 16; ++i)
		{
			int tempNum = Gender[i - 14] - '0';
			sum += tempNum * (int)pow(2, 17 - i);
		}
	}

	//	7. �տ������� 17���� ���ڸ� a1, a2, ... , a17�̶�� �ϸ� CheckSum = (a1*pow(2, 17) + a2*pow(2, 16) + ... + a17*(2, 1)) % 11

	if (sum % 11 == 10)
	{
		if (CheckSum[0] == 'X')
			cout << Gen << endl;
		else
			cout << "Invalid" << endl;
		return;
	}
	else if (sum % 11 > 10)
	{
		cout << "Invalid" << endl;
		return;
	}
	else
	{
		if (sum % 11 == CheckSum[0] - '0')
		{
			cout << Gen << endl;
			return;
		}
		else
		{
			cout << "Invalid" << endl;
			return;
		}
	}
}

