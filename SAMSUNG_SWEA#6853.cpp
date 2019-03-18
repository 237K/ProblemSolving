//
//	OS Windows
//	2019.03.05
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6853] <직사각형과 점> (D3)
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

typedef pair<int, int> coor;

class Square
{
private:
	coor LeftTop;
	coor RightTop;
	coor LeftBottom;
	coor RightBottom;
	int inner;
	int bound;
	int out;
public:
	Square(int x1, int y1, int x2, int y2) : inner(0), bound(0), out(0)
	{
		LeftBottom = coor(x1, y1);
		LeftTop = coor(x1, y2);
		RightBottom = coor(x2, y1);
		RightTop = coor(x2, y2);
	}
	void Count(int x, int y)
	{
		if (x < LeftBottom.first || x > RightBottom.first || y < LeftBottom.second || y > LeftTop.second)
			out++;
		else if (x > LeftBottom.first && x < RightBottom.first && y > LeftBottom.second && y < LeftTop.second)
			inner++;
		else
			bound++;
	}
	void Print() const
	{
		printf("%d %d %d\n", inner, bound, out);
	}
};

int main(int argc, char** argv)
{
	int T;
	int test_case;
	int X1, Y1, X2, Y2;
	int N;
	freopen("sample_input6853.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0;
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		Square sq(X1, Y1, X2, Y2);
		scanf("%d", &N);
		for (int n = 0; n < N; ++n)
		{
			int pntx, pnty;
			scanf("%d %d", &pntx, &pnty);
			sq.Count(pntx, pnty);
		}
		printf("#%d ", test_case);
		sq.Print();
	}

	return 0;
}