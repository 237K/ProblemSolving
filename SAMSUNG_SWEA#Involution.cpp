//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <°Åµì Á¦°ö> (D3)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int recursion(int num1, int max_depth, int depth, int result)
{
	if (max_depth < depth)
		return result;
	else
		recursion(num1, max_depth, depth + 1, result * num1);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("s_input_Involution.txt", "r", stdin);
	int T;
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
		int n1, n2;
		cin >> n1 >> n2;
		cout<<"#"<<T<<" "<<recursion(n1, n2, 1, 1)<<'\n';
	}
	return 0;
}