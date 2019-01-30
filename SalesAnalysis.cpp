//
//	OS Windows
//	2019.01.30
//
//	[Algorithm Problem Solving]
//		<Algorithm Category : Simple Imprementation>
//
//	'���� �м�'
//	N���� ���� ����Ʈ�� �־����� ��, ���� �� �̻��� ���� �ϼ��� ���� ����Ʈ�� ���� ���϶�
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
	if (!in.is_open()) cout << "������ ã�� �� �����ϴ�." << endl;
	try
	{
		in >> testcase;
		if (testcase < 1 || testcase > MAX_TESTCASE)
			throw testcase;
	}
	catch (int expn)
	{
		cout << "(error) �Է��Ͻ� Test Case ���� : " << expn << endl;
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
				cout << "(error) �Է��Ͻ� ����� : " << expn << endl;
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