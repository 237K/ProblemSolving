//
//	OS Windows
//	2019.04.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5658] <보물상자 비밀번호> (모의 SW 역량테스트)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const static int MAX = 28;
const static int MAX_NUM_LEN = 8;
static int N, K;
static vector<int> Numbers;

inline void Transform10(const string& str)
{
	const int num_len = N / 4;
	int start_idx = 0;
	for (int i = 1; i <= 4; ++i)
	{
		//입력받은 문자열에서 한 변의 크기만큼씩 잘라냄
		char ch_partial[MAX_NUM_LEN];
		string str_partial;
		str_partial = str.substr(start_idx, num_len);
		//cout << i + 1 << " " << str << "  " << str_partial << endl;
		start_idx = num_len * i;

		//잘라낸 문자열을 10진수로 바꾸고 벡터에 넣음 (strtol 사용하려면 string을 char로 바꿔야 함)
		strcpy(ch_partial, str_partial.c_str());
		int num10 = (int)strtol(ch_partial, NULL, 16);
		Numbers.push_back(num10);
		//cout << num10 << endl;
	}
}

inline void Rotate(string& str)
{
	char last = str[N - 1];
	for (int i = N - 1; i > 0; --i)
	{
		str[i] = str[i - 1];
	}
	str[0] = last;
}

inline int Hacking(string& str)
{
	//초기상태
	Transform10(str);

	//K-2번 만큼 회전시키면서 10진수로 바꿔서 벡터에 넣음
	for (int i = 0; i < K-2; ++i)
	{
		Rotate(str);
		Transform10(str);
	}

	//내림차순 정렬하고 중복된 원소를 제거
	sort(Numbers.begin(), Numbers.end(), greater<int>());
	unique(Numbers.begin(), Numbers.end());
	
	//for (vector<int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
		//cout << *iter << ' ';
	//cout << endl;

	//K번째 원소를 반환
	return Numbers[K - 1];
}

int main(int argc, char** argv)
{
	freopen("s_input5658.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Numbers.clear();

		cin >> N >> K;
		string input;
		cin >> input;
		cout << "#" << test_case << ' ' << Hacking(input) << '\n';
	}
	return 0;
}