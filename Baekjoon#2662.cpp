//
//	OS Windows
//	2019.01.29
//
//	[Algorithm Category]
//		<DP (Dynamic Programming)>
//
//	BAEKJOON #2662 �������
//	

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class CompanyInvestment
{
private:
	vector<int> *Information;		//��ǲ�� ����
	vector<int> *CI;				//���� ������� ����
	const int TotalMoney;			
	const int TargetCompany;
	vector<pair<int, int>> Investment;				//���ڸ� ������ ����� �ش����� ���� ���ڱ� ��� pair�� ����
	int Revenue;									//�ֻ��� �ó��������� ��ԵǴ� �̵�
	int Index, Profit1, Profit2;					//��ǲ�� �о�� �� ����� ����
public:
	static const int MAX_MONEY = 301;
	static const int MAX_COMPANY = 21;
public:
	explicit CompanyInvestment(const int _TotalMoney, const int _TargetCompany) : TotalMoney(_TotalMoney), TargetCompany(_TargetCompany), Revenue(0), Index(0), Profit1(0), Profit2(0)
	{
		Information = new vector<int>[_TotalMoney+1];
		CI = new vector<int>[_TotalMoney+1];
		for (int init = 0; init < _TotalMoney+1; ++init)
		{
			Information[init].clear();
			CI[init].clear();
		}
		Investment.clear();
		for (int init = 0; init < _TotalMoney; ++init)		//CI 0���� �ʱ�ȭ�ϴµ�, CI[�ִ�ݾ�] �� ��¥�� �����������Ƿ� ���߿� Ư�� �� push_back �� ����
		{
			CI[init].resize(_TargetCompany, 0);
		}
	}
	~CompanyInvestment()
	{
		delete[] Information;
		delete[] CI;
	}
	void Research(ifstream& _in)			//��ǲ�� �о�ͼ� ����
	{
		for (int column = 1; column <= TotalMoney; ++column)
		{
			_in >> Index >> Profit1 >> Profit2;
			Information[Index].push_back(Profit1);
			Information[Index].push_back(Profit2);
		}
	}
	void Analysis()
	{
		for (int i = 0; i < TargetCompany; ++i)
		{
			CI[TotalMoney].push_back(Information[TotalMoney][i]);		//CI[�ִ�ݾ�] �� ��¥�� �����������Ƿ�
			Investment.push_back(pair<int, int>(i+1, Information[TotalMoney][i]));
		}
		for (int row = 1; row < TotalMoney; ++row)
		{
			for (int column = 0; column < TargetCompany; ++column)
			{
				for (int a = 1; a <= TotalMoney-row; ++a)
				{
					for (int b = 0; b < TargetCompany; ++b)
					{
						if (column != b)
						{
							if (CI[row][column] < Information[row][column] + Information[a][b])
							{
								CI[row].erase(CI[row].begin() + column);
								CI[row].insert(CI[row].begin() + column, Information[row][column] + Information[a][b]);

								if (Information[TotalMoney][0] < Information[row][column] + Information[a][b] && Information[TotalMoney][1] < Information[row][column] + Information[a][b])							//CI���� ���ŵǸ� Investment(map)�� ����� ������ �����
								{
									Investment.clear();
									Investment.insert(Investment.begin(), pair<int, int>(column + 1, row));		//���ŵ� ������ ����
									Investment.insert(Investment.begin() + 1, pair<int, int>(b + 1, a));

									Revenue = Information[row][column] + Information[a][b];
								}
								else Revenue = max(Investment[0].second, Investment[1].second);
							}
						}
					}
				}
			}
		}
		PrintReport();
		cout << "Your Revenue : " << Revenue << endl << endl;

	}
	void PrintReport() const
	{
		cout << "[Research Report]" << endl<<endl;
		cout << "(Investment Money \\ Target Company)" << endl;
		for (int r = 1; r <= TotalMoney; ++r)
		{
			for (int c = 0; c < TargetCompany; ++c)
			{
				cout << Information[r][c] << ' ';
			}
			cout << endl << endl;
		}
		cout << "=======================" << endl << endl;
		cout << "[Analysis Report]" << endl << endl;
		for (int r = 1; r <= TotalMoney; ++r)
		{
			for (int c = 0; c < TargetCompany; ++c)
			{
				cout << CI[r][c] << ' ';
			}
			cout << endl << endl;
		}
		cout << "[Proposal]" << endl;
		cout << "[Strong Buy]" << endl;
		for (vector<pair<int, int>>::size_type i = 0 ; i < Investment.size() ; ++i)
		{
			cout <<i+1<< ") Company : " << Investment[i].first << "/ Investment : " << Investment[i].second << endl;
		}
	}
};

int main(void)
{
	int Money = 0;
	int Company = 0;
	clock_t timer_start, timer_end;
	double timer;

	timer_start = clock();

	ifstream in("testcase_BAEKJOON#2662.txt");
	if (!in.is_open())
		cout << "������ ã�� �� �����ϴ�." << endl;

	in >> Money >> Company;
	CompanyInvestment ci(Money, Company);

	ci.Research(in);

	ci.Analysis();

	timer_end = clock();
	timer = (double)(timer_end - timer_start);
	cout << "Execution Time : " << timer << "ms" << endl;

	in.close();
	return 0;
}