//
//	OS Windows
//	2019.10.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1427 소트인사이드
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	freopen("input1427.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	vector<int> v;
	cin >> N;
	while (N)
	{
		v.push_back(N % 10);
		N /= 10;
	}
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) cout << *iter;
	return 0;
}