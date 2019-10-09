//
//	OS Windows
//	2019.10.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #10773 Á¦·Î
//

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char** argv)
{
	freopen("input10773.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int K, k, in, sum = 0;
	stack<int> st;
	cin >> K;
	for (k = 0; k < K; ++k)
	{
		cin >> in;
		if (!in) st.pop();
		else st.push(in);
	}
	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	printf("%d", sum);
	return 0;
}