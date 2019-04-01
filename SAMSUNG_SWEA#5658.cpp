//
//	OS Windows
//	2019.04.01
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#5658] <�������� ��й�ȣ> (���� SW �����׽�Ʈ)
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
		//�Է¹��� ���ڿ����� �� ���� ũ�⸸ŭ�� �߶�
		char ch_partial[MAX_NUM_LEN];
		string str_partial;
		str_partial = str.substr(start_idx, num_len);
		//cout << i + 1 << " " << str << "  " << str_partial << endl;
		start_idx = num_len * i;

		//�߶� ���ڿ��� 10������ �ٲٰ� ���Ϳ� ���� (strtol ����Ϸ��� string�� char�� �ٲ�� ��)
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
	//�ʱ����
	Transform10(str);

	//K-2�� ��ŭ ȸ����Ű�鼭 10������ �ٲ㼭 ���Ϳ� ����
	for (int i = 0; i < K-2; ++i)
	{
		Rotate(str);
		Transform10(str);
	}

	//�������� �����ϰ� �ߺ��� ���Ҹ� ����
	sort(Numbers.begin(), Numbers.end(), greater<int>());
	unique(Numbers.begin(), Numbers.end());
	
	//for (vector<int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
		//cout << *iter << ' ';
	//cout << endl;

	//K��° ���Ҹ� ��ȯ
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