//
//	OS Windows
//	2019.07.18
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#1223] (D4) °è»ê±â2
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
using namespace std;
static string inorder, postorder;
static int N;
static stack<char> S1;
static stack<int> S2;

inline void init()
{
	inorder.clear();
	postorder.clear();
	while (!S1.empty()) { S1.pop(); }
	while (!S2.empty()) { S2.pop(); }
}
inline void change_to_postorder()
{
	register int i;
	for (i = 0; i < N; ++i)
	{
		char cur = inorder[i];
		if (cur >= '0' && cur <= '9') postorder.push_back(cur);
		else
		{
			if (S1.empty()) S1.push(cur);
			else
			{
				if (cur == '*')
				{
					while (1)
					{
						if (S1.empty() || S1.top() == '+') break;
						postorder.push_back(S1.top());
						S1.pop();
					}
				}
				else
				{
					while (1)
					{
						if (S1.empty()) break;
						postorder.push_back(S1.top());
						S1.pop();
					}
				}
				S1.push(cur);
			}
		}
	}
	while (!S1.empty())
	{
		postorder.push_back(S1.top());
		S1.pop();
	}
}
inline int cal()
{
	change_to_postorder();
	register int ret, i, left, right;
	for (i = 0; i < N; ++i)
	{
		char cur = postorder[i];
		if (cur >= '0' && cur <= '9')
		{
			S2.push(cur - '0');
			continue;
		}
		else
		{
			right = S2.top();
			S2.pop();
			left = S2.top();
			S2.pop();
			if (cur == '+') ret = left + right;
			else ret = left * right;
			S2.push(ret);
		}
	}
	return S2.top();
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc;
	for (tc = 1; tc <= 10; ++tc)
	{
		init();
		cin >> N;
		cin >> inorder;
		cout << "#" << tc << ' ' << cal() << '\n';
	}
	return 0;
}