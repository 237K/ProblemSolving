//
//	OS Windows
//	2019.11.02
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #12791	Starman
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
typedef pair<int, string> pis;
const static int MAX = 25;
static pis DB[MAX] =
{
{1967, "DavidBowie"},
{1969, "SpaceOddity"},
{1970, "TheManWhoSoldTheWorld"},
{1971, "HunkyDory"},
{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
{1973, "AladdinSane"},
{1973, "PinUps"},
{1974, "DiamondDogs"},
{1975, "YoungAmericans"},
{1976, "StationToStation"},
{1977, "Low"},
{1977, "Heroes"},
{1979, "Lodger"},
{1980, "ScaryMonstersAndSuperCreeps"},
{1983, "LetsDance"},
{1984, "Tonight"},
{1987, "NeverLetMeDown"},
{1993, "BlackTieWhiteNoise"},
{1995, "1.Outside"},
{1997, "Earthling"},
{1999, "Hours"},
{2002, "Heathen"},
{2003, "Reality"},
{2013, "TheNextDay"},
{2016, "BlackStar"}
};
static pis ret[MAX];
int main(int argc, char** argv)
{
	freopen("input12791.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int Q, S, E, q, i, cnt;
	cin >> Q;
	for (q = 0; q < Q; ++q)
	{
		cnt = 0;
		cin >> S >> E;
		for (i = 0; i < MAX; ++i)
		{
			if (DB[i].first >= S && DB[i].first <= E) ret[cnt++] = DB[i];
			if (DB[i].first > E) break;
		}
		cout << cnt << '\n';
		for (i = 0; i < cnt; ++i) cout << ret[i].first << ' ' << ret[i].second << '\n';
	}
	return 0;
}