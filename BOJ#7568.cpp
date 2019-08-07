//
//	OS Windows
//	2019.08.07
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #7568	µ¢Ä¡
//

#include <iostream>
using namespace std;
const static int MAX = 51;
static int height[MAX], weight[MAX], ranking[MAX];
static int N;
int main(int argc, char** argv)
{
	freopen("input7568.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	register int i, j, cnt;
	cin >> N;
	for (i = 0; i < N; ++i)	cin >> height[i] >> weight[i];
	for (i = 0; i < N; ++i)
	{
		cnt = 0;
		for (j = 0; j < N; ++j)
		{
			if (height[i] < height[j] && weight[i] < weight[j]) cnt++;
		}
		ranking[i] = cnt + 1;
	}
	for (i = 0; i < N; ++i) cout << ranking[i] << ' ';
	return 0;
}