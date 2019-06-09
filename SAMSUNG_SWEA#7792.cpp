//
//	OS Windows
//	2019.06.05
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7792] (D4) 반장 선출
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

const static int MAX = 101;
const static int VAR = 26;

static int variable[MAX][VAR];
static int counter[MAX];
static string name[MAX];
static string ret;

int main(int argc, char** argv)
{
	freopen("s_input7792.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, len;
	register int tc, n, i, max_kind = 0;
	string trash;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		(void)memset(variable, 0, sizeof(variable));
		(void)memset(counter, 0, sizeof(counter));
		max_kind = 0;
		ret.clear();
		cin >> N;	getline(cin, trash);
		for (n = 0; n < N; ++n)
		{
			getline(cin, name[n]);
			len = name[n].length();
			for (i = 0; i < len; ++i)
			{
				if (name[n][i] >= 'A' && name[n][i] <= 'Z')
				{
					if (!variable[n][name[n][i] - 'A'])
					{
						variable[n][name[n][i] - 'A'] = 1;
						if ((++counter[n]) > max_kind)
						{
							max_kind = counter[n];
							ret = name[n];
						}
						else if (counter[n] == max_kind)
						{
							if (!ret.empty() && ret > name[n])
								ret = name[n];
						}
					}
				}
			}
		}
		cout << "#" << tc << ' ' << ret << '\n';
	}
	return 0;
}