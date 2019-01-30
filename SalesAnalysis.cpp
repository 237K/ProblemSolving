//
//	OS Windows
//	2019.01.30
//
//	[Algorithm Problem Solving]
//		<Algorithm Category : Simple Imprementation>
//
//	'매출 분석'
//	N일의 매출 리포트가 주어졌을 때, 이전 날 이상의 매출 일수를 뽑은 리스트의 합을 구하라
//	

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(void)
{
	const int MAX_TESTCASE = 100;
	const int MAX_SALES = 5000;
	int testcase = 0, day = 0;
	int sales = 0;
	int count;
	int result;
	vector<int> sales_vector;

	ifstream in("testcase_SI2.txt");
	if (!in.is_open()) cout << "파일을 찾을 수 없습니다." << endl;
	try
	{
		in >> testcase;
		if (testcase < 1 || testcase > MAX_TESTCASE)
			throw testcase;
	}
	catch (int expn)
	{
		cout << "(error) 입력하신 Test Case 개수 : " << expn << endl;
	}
	for (int tc = 1; tc <= testcase; ++tc)
	{
		count = 0;
		result = 0;
		in >> day;
		for (int d = 1; d <= day; ++d)
		{
			try
			{
				in >> sales;
				if (sales < 1 || sales > MAX_SALES)
					throw sales;
				sales_vector.push_back(sales);
			}
			catch (int expn)
			{
				cout << "(error) 입력하신 매출액 : " << expn << endl;
			}
		}
		for (vector<int>::iterator iter = sales_vector.begin()+1; iter != sales_vector.end(); ++iter)
		{
			for (vector<int>::iterator iter2 = sales_vector.begin(); iter2 < iter; ++iter2)
			{
				if (*iter >= *iter2)
				{
					count++;
				}
			}
			result += count;
			count = 0;
		}
		cout << "#" << tc << " " << result << endl << endl;
		sales_vector.clear();
	}
	in.close();
	return 0;
}