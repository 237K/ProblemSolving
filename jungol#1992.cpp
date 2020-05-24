//
//	OS Windows
//	2020.05.22
//
//	[Algorithm Problem Solving]
//
//	[구현] <jungol#1992> 백설공주와 난장이
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const static int SZ = 7;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v(SZ, 0);
	register int i;
	for (i = 0; i < SZ; ++i)
		cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	cout << v[0] << '\n' << v[1];
	return 0;
}
