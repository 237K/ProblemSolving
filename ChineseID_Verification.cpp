//
//	OS Windows
//	2019.02.27
//
//	[Algorithm Problem Solving]
//
//	<중국인 ID 검증>
//
//	1. 중국인 ID는 총 18글자로 구성되어 있음
//	2. 처음 17글자는 모두 숫자이며, 마지막 글자는 숫자 혹은 X
//	3. 앞 부터 순서대로 지역코드가 6글자, 생일코드 8글자, 순서코드 3글자, CheckSum Code 1글자로 구성됨
//	4. 지역코드는 000001, 000010, 000100, 001000, 010000, 100000 중 하나
//	5. 생일코드는 8개 숫자이며 YYYYMMDD 형식, 19000101 ~ 20141231 범위만 유효
//	6. 000은 유효하지 않음. 홀수이면 남자, 짝수이면 여자
//	7. 앞에서부터 17개의 숫자를 a1, a2, ... , a17이라고 하면 CheckSum = (a1*pow(2, 17) + a2*pow(2, 16) + ... + a17*(2, 1)) % 11
//	   CheckSum의 값은 0~10이며, 10의 경우 X로 표기
//	8. 유효한 ID이면 "Male" or "Female", 유요하지 않으면 "Invalid" 출력
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
	//	4. 지역코드는 000001, 000010, 000100, 001000, 010000, 100000 중 하나
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
	{			//지역코드가 유효하면,
		sum += (int)pow(2, 17 - idx);
	}
	
	//	5. 생일코드는 8개 숫자이며 YYYYMMDD 형식, 19000101 ~ 20141231 범위만 유효
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
	//	6. 000은 유효하지 않음. 홀수이면 남자, 짝수이면 여자
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

	//	7. 앞에서부터 17개의 숫자를 a1, a2, ... , a17이라고 하면 CheckSum = (a1*pow(2, 17) + a2*pow(2, 16) + ... + a17*(2, 1)) % 11

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

