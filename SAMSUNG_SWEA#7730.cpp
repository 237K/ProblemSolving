//
//	OS Windows
//	2019.05.22
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#7730> (D5) ³ª¹« ±ð´Â È«ÁØ
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int T, N, M, H, in;
vector<int> v;
int main(int argc, char** argv)
{
	freopen("s_input7730.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int tc, n, tmp;
	bool flag;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		H = 0; tmp = 0; flag = false;
		cin >> N >> M;
		v.resize(N, 0);
		for (n = 0; n < N; ++n)
		{
			cin >> in;
			v[n] = in;
			tmp += in;
			if (v[n] > H) H = v[n];
		}
		if (tmp == M) H = 0;
		else
		{
			H--;
			sort(v.begin(), v.end(), greater<int>());
			while (1)
			{
				tmp = 0;
				for (n = 0; n < N; ++n)
				{
					if (v[n] <= H)
						break;
					tmp += v[n] - H;
				}
				if (tmp >= M) break;
				H--;
			}
		}
		cout << "#" << tc << ' ' << H << '\n';
	}
	return 0;
}