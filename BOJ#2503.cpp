//
//	OS Windows
//	2019.08.07
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2503	숫자 야구
//

#include <iostream>
#include <memory.h>
using namespace std;

static int attack[3], comp[3], question[100], strike[100], ball[100];
static int N, ret;
static int check[10];
inline bool QA()
{
	register int i, j, k, s, b;
	for (i = 0; i < N; ++i)
	{
		s = b = 0;
		comp[0] = question[i] / 100;
		comp[1] = (question[i] / 10) % 10;
		comp[2] = question[i] % 10;
		for (j = 0; j < 3; ++j)
		{
			for (k = 0; k < 3; ++k)
			{
				if (attack[j] == comp[k])
				{
					if (j == k) s++;
					else b++;
				}
			}
		}
		//cout << "strike : " << s << " ball : " << b << "\n\n";
		if (strike[i] != s || ball[i] != b) return false;
	}
	return true;
}
inline void simul(int cnt)
{
	if (cnt == 3)
	{
		//for (register int p = 0; p < 3; ++p) cout << attack[p] << ' ';
		if (QA()) ret++;
		return;
	}
	for (register int i = 1; i < 10; ++i)
	{
		if (!check[i])
		{
			check[i] = 1;
			attack[cnt] = i;
			simul(cnt + 1);
			check[i] = 0;
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input2503.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int i;
	ret = 0; (void)memset(check, 0, sizeof(check));
	cin >> N;
	for (i = 0; i < N; ++i) cin >> question[i] >> strike[i] >> ball[i];
	simul(0);
	cout << ret;
	return 0;
}