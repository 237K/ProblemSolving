//
//	OS Windows
//	2020.04.14
//
//	[Algorithm Problem Solving]
//
//	[±¸Çö] <jungol#1570> Áß¾Ó°ª
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	freopen("jinput1570.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, in, in2;
	register int n, i, sz = 1;
	vector<int> v;
	cin >> N;
	cin >> in;
	cout << in << '\n';
	v.push_back(in);
	for (n = 0; n < N / 2; ++n)
	{
		cin >> in >> in2;
		v.push_back(in);
		v.push_back(in2);
		sz += 2;
		sort(v.begin(), v.end());
		cout << v[sz / 2] << '\n';
	}
	return 0;
}