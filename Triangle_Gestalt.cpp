//
//	OS Windows
//	2019.03.13
//
//	[Algorithm Problem Solving]
//
//	<삼각형 형태 알아내기>
//		1. 꼭짓점 3개의 좌표를 입력받아서
//		2. 직각삼각형인지(1 출력), 둔각삼각형인지(2 출력), 예각삼각형인지(3 출력), 삼각형이 되지 않는지(0) 출력
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

class Test
{
private:
	PII Triangle1;
	PII Triangle2;
	PII Triangle3;
	vector<double> Distance;
public:
	Test() : Triangle1(PII(0, 0)), Triangle2(PII(0, 0)), Triangle3(PII(0, 0)) { Distance.clear(); };
	~Test() {};
	void MakeTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		Triangle1.first = x1;
		Triangle1.second = y1;
		Triangle2.first = x2;
		Triangle2.second = y2;
		Triangle3.first = x3;
		Triangle3.second = y3;
	}
	double GetDistance(PII T1, PII T2)
	{
		double Distance12 = pow((T1.first - T2.first), 2) + pow((T1.second - T2.second), 2);
		return Distance12;
	}
	int Check()
	{
		if (Triangle1.first == Triangle1.first && Triangle1.second == Triangle2.second ||
			Triangle1.first == Triangle3.first && Triangle1.second == Triangle3.second ||
			Triangle2.first == Triangle3.first && Triangle2.second == Triangle3.second ||
			Triangle1.first == Triangle2.first == Triangle3.first ||
			Triangle1.second == Triangle2.second == Triangle3.second ||
			Triangle1.first == Triangle1.second && Triangle2.first == Triangle2.second && Triangle3.first == Triangle3.second)
			return 0;

		else
		{
			double D1 = GetDistance(Triangle1, Triangle2);
			double D2 = GetDistance(Triangle1, Triangle3);
			double D3 = GetDistance(Triangle2, Triangle3);

			Distance.push_back(D1);
			Distance.push_back(D2);
			Distance.push_back(D3);

			sort(Distance.begin(), Distance.end());
			double Max = Distance[2];
			double A = Distance[0];
			double B = Distance[1];

			cout << Max << ' ' << A << ' ' << B << endl << endl;

			if ((A + B) == Max)
				return 1;
			else if ((A + B) < Max)
				return 2;
			else
				return 3;
		}
	}
};

int main(int argc, char** argv)
{
	int T;
	int test_case;
	freopen("testcase_Triangle.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Test Tri;
		int locX1, locY1, locX2, locY2, locX3, locY3;
		scanf("%d %d %d %d %d %d", &locX1, &locY1, &locX2, &locY2, &locX3, &locY3);

		Tri.MakeTriangle(locX1, locY1, locX2, locY2, locX3, locY3);

		int result = Tri.Check();
		printf("#%d %d\n", test_case, result);
	}
	return 0;
}