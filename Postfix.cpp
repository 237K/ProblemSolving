//
//	OS Windows
//	2019.02.22
//
//	[Algorithm Problem Solving]
//
//	<후위순회 수식표현>
//	
//	중위순회 수식표현 : 21 + (3 - 4) * (8 - 3) * (3 + 1) / 2
//	후위순회 수식표현 : 21 3 4 - 8 3 - * 3 1 + * 2 / +
//
//	중위순회 수식을 입력받아서 후위순회 수식으로 출력
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
static string Postfix;

bool isOperator(const char& ch);
int Priority(const char& ch);
void ConvertToPostfix(const string& in);

int main(int argc, char** argv)
{
	int T;
	int test_case;
	string TC;
	string Input;
	freopen("testcase_Postfix.txt", "r", stdin);
	getline(cin, TC);
	T = stoi(TC);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Input.clear();
		Postfix.clear();
		getline(cin, Input);
		ConvertToPostfix(Input);
		cout << "#" << test_case << ' ' << Postfix << endl;
	}
	return 0;
}

bool isOperator(const char& ch)
{
	if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
		return true;
	else
		return false;
}

int Priority(const char& ch)
{
	switch (ch)
	{
	case '*':
	case '/':
		return 3;
		break;
	case '+':
	case '-':
		return 2;
		break;
	case '(':
		return 1;
		break;
	default:
		return -1;
		break;
	}
}

void ConvertToPostfix(const string& in)
{
	stack<char> st;
	while (!st.empty()) { st.pop(); }
	int Length = in.length();
	int cnt = 0;								//2자리 이상의 수(10이상의 수)가 주어질 경우에 대응하기 위함
	for (int i = 0; i < Length; ++i)
	{
		if (in[i] >= '0' && in[i] <= '9')
		{
			cnt++;
			if (cnt == 2)
			{
				Postfix.pop_back();
				Postfix.push_back(in[i]);
				Postfix.push_back(' ');
				cnt = 0;
			}
			else
			{
				Postfix.push_back(in[i]);
				Postfix.push_back(' ');
			}
		}

		else if (isOperator(in[i]))
		{
			cnt = 0;
			if (st.empty())
			{
				st.push(in[i]);
			}
			else
			{
				while (!st.empty() && Priority(st.top()) >= Priority(in[i]))
				{
					char tempOP = st.top();
					Postfix.push_back(tempOP);
					Postfix.push_back(' ');
					st.pop();
				}
				st.push(in[i]);
			}
		}
		else if (in[i] == '(')
		{
			cnt = 0;
			st.push(in[i]);
		}
		else if (in[i] == ')')
		{
			cnt = 0;
			while (st.top() != '(')
			{
				char tempOP = st.top();
				Postfix.push_back(tempOP);
				Postfix.push_back(' ');
				st.pop();
			}
			st.pop();
		}
	}
	while (!st.empty())
	{
		char tempOP = st.top();
		st.pop();
		Postfix.push_back(tempOP);
		Postfix.push_back(' ');
	}
}