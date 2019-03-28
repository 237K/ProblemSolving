//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <GNS> (D3)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

static int countup[10];

void GNS(string str)
{
	if (str == "ZRO") countup[0]++;
	else if (str == "ONE") countup[1]++;
	else if (str == "TWO") countup[2]++;
	else if (str == "THR") countup[3]++;
	else if (str == "FOR") countup[4]++;
	else if (str == "FIV") countup[5]++;
	else if (str == "SIX") countup[6]++;
	else if (str == "SVN") countup[7]++;
	else if (str == "EGT") countup[8]++;
	else if (str == "NIN") countup[9]++;
}

void Print()
{
	for (int i = 0; i < 10; ++i)
	{
		int cnt = countup[i];
		string tok;
		switch (i)
		{
		case 0:
			tok = "ZRO";
			break;
		case 1:
			tok = "ONE";
			break;
		case 2:
			tok = "TWO";
			break;
		case 3:
			tok = "THR";
			break;
		case 4:
			tok = "FOR";
			break;
		case 5:
			tok = "FIV";
			break;
		case 6:
			tok = "SIX";
			break;
		case 7:
			tok = "SVN";
			break;
		case 8:
			tok = "EGT";
			break;
		case 9:
			tok = "NIN";
			break;
		}
		while (cnt)
		{
			cout << tok << ' ';
			cnt--;
		}
	}
	cout << '\n';
}

int main(int argc, char** argv)
{
	freopen("s_input#GNS.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	string TC;
	int N;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		(void)memset(countup, 0, sizeof(countup));
		cin >> TC >> N;
		for (int n = 0; n < N; ++n)
		{
			string input;
			cin >> input;
			GNS(input);
		}
		cout << TC << '\n';
		Print();
		cout << '\n';
	}
	return 0;
}