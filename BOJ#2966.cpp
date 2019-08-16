//
//	OS Windows
//	2019.08.07
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #2966	Âï±â
//

#include <iostream>
#include <string>
using namespace std;

static char AD[3] = { 'A', 'B', 'C' };
static char BR[4] = { 'B', 'A', 'B', 'C' };
static char GO[6] = { 'C', 'C', 'A', 'A', 'B', 'B' };
static int N, ret;

int main(int argc, char** argv)
{
	freopen("input2966.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	register int i, ai, bi, ci, a, b, c, max_value;
	a = b = c = 0;
	cin >> N;
	cin >> input;
	for (i = 0; i < N; ++i)
	{
		ai = i % 3; bi = i % 4; ci = i % 6;
		if (input[i] == AD[ai]) a++;
		if (input[i] == BR[bi]) b++;
		if (input[i] == GO[ci]) c++;
	}
	if (a < b) max_value = b;
	else max_value = a;
	if (max_value < c) max_value = c;
	cout << max_value << '\n';
	if (max_value == c) cout << "Goran\n";
	else if (max_value == b)
	{
		if (b == c) cout << "Bruno\nGoran\n";
		else cout << "Bruno\n";
	}
	else
	{
		if (a > b && a > c) cout << "Adrian\n";
		else if (a == b && a == c) cout << "Adrian\nBruno\nGoran";
		else if (a == b) cout << "Adrian\nBruno\n";
		else if (a == c) cout << "Adrian\nGoran\n";
	}
	return 0;
}