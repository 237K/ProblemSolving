//
//	OS Windows
//	2019.08.24
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #4153	Á÷°¢»ï°¢Çü
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
	freopen("input4153.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> T;
	int flag, i, ret;
	T.resize(3);
	while (1)
	{
		flag = 0;
		for (i = 0; i < 3; ++i)
		{
			cin >> T[i];
			if (!T[i]) flag++;
		}
		if (flag == 3) break;
		sort(T.begin(), T.end());
		if (((T[0] * T[0]) + (T[1] * T[1])) == (T[2] * T[2])) ret = 1;
		else ret = 0;
		if (ret) cout << "right\n";
		else cout << "wrong\n";
	}
	return 0;
}