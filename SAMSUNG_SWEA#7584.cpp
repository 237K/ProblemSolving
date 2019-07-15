//
//	OS Windows
//	2019.05.09
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#7584> (D3) 자가 복제 문자열
//
//	P0 = 001
//	P1 = 0010011
//	P2 = 001001100011011
//	P3 = 0010011000110110001001110011011
//	
//	P0 = 001
//	P1 = 001 + 0 + 011
//	P2 = 001 + 0 + 011 + 0 + 001 + 1 + 011
//	P3 = 001 + 0 + 011 + 0 + 001 + 1 + 011 + 0 + 001 + 0 + 011 + 1 + 001 + 1 + 011
//	
//	001과 011이 반복되고, 그 사이에서도 001과 011이 반복되고 그 사이에서도 001과 011이 반복됨
//	P3가 딱 31자리로, int형 변수에 비트마스크를 사용하면 됨. 16번째 자리만 2^5-1번 주기로 0 0 1 0 0 1 1
//	K <= 10^18 이므로 2^64 보다 작음

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int mask = 320541594;
int T, test_case, ret;
long long K;
int main(int argc, char** argv)
{
	freopen("s_input7584.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld", &K);
		int remainder = (int)(K % 32);
		if (remainder == 15)
		{
			long long quotient = K / 32;
			remainder = (int)(quotient % 32);
		}
		if (mask & (1 << remainder)) ret = 1;
		else ret = 0;
		printf("#%d %d\n", test_case, ret);
	}
	return 0;
}