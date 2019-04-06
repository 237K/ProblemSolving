//
//	OS Windows
//	2019.04.03
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #16235 나무 재테크
//	

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

const static int SIZE = 11;
const static int DIRECT = 8;

struct tree
{
	int age, live;
	bool operator< (const tree& t) const
	{
		return t.age < age;
	}
};
typedef pair<int, int> coor;
typedef pair<coor, int> coor_and_age;

static int dir[DIRECT][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
static int N, M, K;
static vector<tree> tree_map[SIZE][SIZE];
static int soil_map[SIZE][SIZE];
static int R2D2[SIZE][SIZE];
static queue<coor_and_age> Q_dead_tree;
static queue<coor> Q_seed;

inline void init()
{
	(void)memset(R2D2, 0, sizeof(R2D2));
	for (register int r = 0; r < SIZE; ++r)
	{
		for (register int c = 0; c < SIZE; ++c)
		{
			soil_map[r][c] = 5;
			tree_map[r][c].clear();
		}
	}
}

inline int sort_tree_map()
{
	int count = 0;
	for (register int r = 1; r <= N; ++r)
	{
		for (register int c = 1; c <= N; ++c)
		{
			if (!tree_map[r][c].size())
				continue;
			else
			{
				sort(tree_map[r][c].begin(), tree_map[r][c].end());
				count++;
			}
		}
	}
	return count;
}

inline int count_tree()
{
	int count = 0;
	for (register int r = 1; r <= N; ++r)
	{
		for (register int c = 1; c <= N; ++c)
		{
			count += tree_map[r][c].size();
		}
	}
	return count;
}

/*
inline void printmap()
{
	cout << "Tree map" << '\n';
	for (register int r = 1; r <= N; ++r)
	{
		for (register int c = 1; c <= N; ++c)
		{
			cout << tree_map[r][c].size() << ' ';
		}
		cout << "\n\n";
	}
	cout << "\n";

	cout << "Soil map" << '\n';
	for (register int r = 1; r <= N; ++r)
	{
		for (register int c = 1; c <= N; ++c)
		{
			cout << soil_map[r][c] << ' ';
		}
		cout << "\n\n";
	}
	cout << "\n";

	cout << "Tree list" << '\n';
	for (register int r = 1; r <= N; ++r)
	{
		for (register int c = 1; c <= N; ++c)
		{
			if (tree_map[r][c].size())
			{
				for (auto iter = tree_map[r][c].begin(); iter != tree_map[r][c].end(); ++iter)
				{
					cout << "(" << r << ", " << c << ")  "<< iter->age<< ' ';
				}
				cout << '\n';
			}
		}
		cout << "\n\n";
	}
	cout << "\n";
}
*/

inline int simulation()
{
	while (K--)
	{
		//봄
		//어린나무부터 자기 나이만큼 양분 먹고 나이 +1
		//나이만큼 양분 못먹으면 죽음
		if (!sort_tree_map())
			return 0;
		
		for (register int r = 1; r <= N; ++r)
		{
			for (register int c = 1; c <= N; ++c)
			{
				if (!tree_map[r][c].size())
					continue;
				else
				{
					for (vector<tree>::iterator iter = tree_map[r][c].begin(); iter != tree_map[r][c].end(); ++iter)
					{
						if (iter->age <= soil_map[r][c])
						{
							soil_map[r][c] -= iter->age;
							iter->age++;
							if (iter->age && iter->live && iter->age % 5 == 0)
								Q_seed.push({ r, c });
						}
						else
						{
							Q_dead_tree.push({ {r, c}, iter->age });
							iter = tree_map[r][c].erase(iter);
							if (iter == tree_map[r][c].end())
								break;
							continue;
						}
					}
				}
			}
		}
		//여름
		//죽은 나무가 양분이 됨
		while (!Q_dead_tree.empty())
		{
			coor_and_age cur = Q_dead_tree.front();
			Q_dead_tree.pop();
			int curx = cur.first.first;
			int cury = cur.first.second;
			int cur_age = cur.second;
			soil_map[curx][cury] += cur_age / 2;
		}
		//가을
		//나무 나이가 5의 배수이면 번식함
		//주변 8칸에 나이가 1인 나무가 생김
		while (!Q_seed.empty())
		{
			coor cur = Q_seed.front();
			Q_seed.pop();
			int curx = cur.first;
			int cury = cur.second;
			for (register int d = 0; d < DIRECT; ++d)
			{
				int nx = curx + dir[d][0];
				int ny = cury + dir[d][1];
				if (nx < 1 || ny < 1 || nx > N || ny > N)
					continue;
				tree_map[nx][ny].push_back({ 1, 1 });
			}
		}
		//겨울
		//R2D2가 양분을 공급함
		for (register int r = 1; r <= N; ++r)
		{
			for (register int c = 1; c <= N; ++c)
			{
				soil_map[r][c] += R2D2[r][c];
			}
		}
		//printmap();
	}
	return count_tree();
}

int main(int argc, char** argv)
{
	freopen("s_input#16235.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	init();
	for (register int r = 1; r <= N; ++r)
	{
		for (register int c = 1; c <= N; ++c)
		{
			cin >> R2D2[r][c];
		}
	}
	for (register int m = 1; m <= M; ++m)
	{
		int x = 0;
		int y = 0;
		int age = 0;
		cin >> x >> y >> age;
		tree_map[y][x].push_back({ age, 1 });
	}
	cout << simulation();
	return 0;
}