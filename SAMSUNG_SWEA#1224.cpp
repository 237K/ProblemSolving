//
//	OS Windows
//	2019.07.16
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1224] (D4) °è»ê±â3
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;
static string inorder, postorder;
static int N;
static stack<char> S;
inline void change_to_postorder()
{
	while (!S.empty()) { S.pop(); }
	postorder.clear();
	for (register int i = 0; i < N; ++i)
	{
		char cur = inorder[i];
		if (cur >= '0' && cur <= '9')
		{
			postorder.push_back(cur);
			continue;
		}
		else if (cur == '(')
		{
			S.push(cur);
			continue;
		}
		else if (cur == ')')
		{
			while (1)
			{
				char tmp = S.top();
				if (tmp == '(')
				{
					S.pop();
					break;
				}
				postorder.push_back(tmp);
				S.pop();
			}
		}
		else if (cur == '+' || cur == '*')
		{
			if (S.empty() || S.top() == '(') S.push(cur);
			else
			{
				if (cur == '+')
				{
					while (1)
					{
						if (S.empty()) break;
						char tmp = S.top();
						if (tmp == '(')
						{
							break;
						}
						else if (tmp == '+' || tmp == '*')
						{
							postorder.push_back(tmp);
							S.pop();
							continue;
						}
					}
					S.push(cur);
				}
				else if (cur == '*')
				{
					while (1)
					{
						if (S.empty()) break;
						char tmp = S.top();
						if (tmp == '(' || tmp == '+')
						{
							break;
						}
						else if (tmp == '*')
						{
							postorder.push_back(tmp);
							S.pop();
							continue;
						}
					}
					S.push(cur);
				}
			}
		}
	}
	while (!S.empty())
	{
		postorder.push_back(S.top());
		S.pop();
	}
}
int main(int argc, char** argv)
{
	freopen("s_input1224.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc;
	for (tc = 1; tc <= 10; ++tc)
	{
		cin >> N;
		cin >> inorder;
		change_to_postorder();
		cout << "#" << tc << ' ' << postorder << '\n';
	}
	return 0;
}