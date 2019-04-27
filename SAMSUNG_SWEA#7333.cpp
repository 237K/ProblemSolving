//
//	OS Windows
//	2019.04.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7333] <한솔이의 택배 아르바이트> (D4)
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	freopen("s_input7333.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int T;
	vector<int> box;
	int N, result, b;
	cin >> T;
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		box.clear();
		result = 0;
		cin >> N;
		for (register int n = 0; n < N; ++n)
		{
			cin >> b;
			if (b >= 50) result++;
			else box.push_back(b);
		}
		sort(box.begin(), box.end(), greater<int>());
		int size = box.size();
		int front = 0;
		while (front < size)
		{
			int cur = box[front];
			int moving = (int)(ceil((double)50 / (double)cur) - 1);
			if (size - moving > front) size -= moving;
			else break;
			result++;
			front++;
		}
		cout << "#" << test_case << ' ' << result << '\n';
	}
	return 0;
}