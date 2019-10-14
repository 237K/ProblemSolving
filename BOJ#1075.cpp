//
//	OS Windows
//	2019.10.14
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #1075 ³ª´©±â
//

#include <iostream>
using namespace std;
static int arr[2];
static int N, F;
inline void simul()
{
	register int i, tmp;
	if (!(N % F))
	{
		arr[0] = 0;
		arr[1] = 0;
		return;
	}
	N /= 100;
	N *= 100;
	for (i = 1; i < 100; ++i)
	{
		tmp = N + i;
		if (!(tmp % F))
		{
			if (i < 10)
			{
				arr[0] = 0;
				arr[1] = i;
			}
			else
			{
				arr[0] = i / 10;
				arr[1] = i % 10;
			}
			return;
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input1075.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cin >> F;
	simul();
	cout << arr[0] << arr[1];
	return 0;
}