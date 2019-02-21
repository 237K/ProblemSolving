//
//	OS Windows
//	2019.02.21
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6959] <이상한 나라의 덧셈게임> (D4)
//	
//	*그냥 맘편하게 string에 cin으로 받아온 다음에 
//	 1) 앞에서부터 두 개씩 숫자로 바꿔서 더하고, 
//	 2) string에서 앞에 두 개 잘라내고 
//	 3) 1번에서 더한거 붙여넣고,
//	 4) 뒤에꺼 붙여넣는걸
//	 5) 길이가 1될 때 까지 반복함
//	 *Flag에 따라 승자를 출력하는데 사이클이 한 번 돌 때마다(상대방에게 숫자를 넘길 때 마다) 승자가 바뀜
//	  -1로 시작해서 -1이면 B가 승리, 1이면 A가 승리
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <sstream>						//stringstream
#include <iostream>
using namespace std;

static string ItoS(int n);				//숫자를 문자로 변환해서 문자열에 접합하기 위한 함수

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