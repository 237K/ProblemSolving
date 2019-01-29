//
//	OS Windows
//	2019.01.29
//
//	[Algorithm Category]
//		<DP (Dynamic Programming)>
//
//	BAEKJOON #2662 기업투자
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
	vector<int> *Information;		//인풋값 저장
	vector<int> *CI;				//투자 검토과정 저장
	const int TotalMoney;			
	const int TargetCompany;
	vector<pair<int, int>> Investment;			//투자를 결정한 기업과 해당기업에 대한 투자금 목록 pair로 저장
	int Revenue;									//최상의 시나리오에서 얻게되는 이득
	int Index, Profit1, Profit2;				//인풋값 읽어올 때 사용할 변수
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
	}
	~CompanyInvestment()
	{
		delete[] Information;
		delete[] CI;
	}
	void Research(ifstream& _in)			//인풋값 읽어와서 저장
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
		for (int row = 1; row <= TotalMoney; ++row)
		{
			for (int column = 1; column <= TargetCompany; ++column)
			{
				for (int a = 1; (a + row) <= TotalMoney; ++a)
				{
					for (int b = 2; (b + column) <= TargetCompany; ++b)
					{
						if (CI[row][column] < Information[row][column] + Information[a][b])
						{
							CI[row].erase(CI[row].begin() + column);
							CI[row].insert(CI[row].begin() + column, Information[row][column] + Information[a][b]);

							if (!Investment.empty())							//CI값이 갱신되면 Investment(map)에 저장된 내용을 지우고
								Investment.clear();

							Investment.push_back(pair<int, int>(column, row));		//갱신된 내용을 저장
							Investment.push_back(pair<int, int>(b, a));
						}
					}
				}
			}
		}
		PrintReport();

		for (int row = 1; row <= TotalMoney; ++row)
		{
			sort(CI[row].begin(), CI[row].end());
		}
		for (int row = 1; row < TotalMoney; ++row)
		{
			Revenue = max(CI[row][TargetCompany], CI[row][TargetCompany + 1]);
		}

		cout << "Your Revenue : " << Revenue << endl << endl;

	}
	void PrintReport() const
	{
		cout << "[Research Report]" << endl<<endl;
		cout << "(Investment Money \ Target Company)" << endl;
		for (int r = 1; r <= TotalMoney; ++r)
		{
			for (int c = 1; c <= TargetCompany; ++c)
			{
				cout << r << ' ' << Information[r][c] << ' ';
			}
			cout << endl << endl;
		}
		cout << "=======================" << endl << endl;
		cout << "[Analysis Report]" << endl << endl;
		for (int r = 1; r <= TotalMoney; ++r)
		{
			for (int c = 1; c <= TargetCompany; ++c)
			{
				cout << r << ' ' << CI[r][c] << ' ';
			}
			cout << endl << endl;
		}
		cout << "[Proposal]" << endl;
		cout << "[Buy]" << endl;
		for (vector<pair<int, int>>::size_type i = 0 ; i < Investment.size() ; ++i)
		{
			cout <<i+1<< ") Company : " << Investment[i].first << "/ Investment : " << Investment[i].second << endl;
		}
	}
};