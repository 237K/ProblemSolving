//
//	OS Windows
//	2019.01.30
//
//	[Algorithm Problem Solving]
//		<Algorithm Category : Simple Implementation>
//
//	'갤러그 점수'
//	

#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	int testcase = 0;
	long long Point_A = 0, Point_B = 0;
	int day = 0;

	ifstream in("testcase_SI1.txt");
	if (!in.is_open()) cout << "파일을 찾을 수 없습니다." << endl;

	in >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		day = 0;
		in >> Point_A >> Point_B;
		while (1)
		{
			if (Point_A < Point_B)
				break;
			Point_A = Point_A * 2;
			Point_B = Point_B * 3;
			day++;
		}
		cout << "#" << tc << ' ' << day << endl;
	}

	in.close();
	return 0;
}