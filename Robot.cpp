//
//	OS Windows
//	2019.01.31
//
//	[Algorithm Problem Solving]
//		<Algorithm Category : Simple Imprementation>
//
//	'�κ� ��'
//	

#include <iostream>
#include <fstream>
using namespace std;

enum Direction { North = 0, East = 1, South = 2, West = 3 };
typedef pair<int, bool> PIB;
typedef pair<int, int> PII;

class Bot
{
private:
	PIB** Map;
	const int Row;
	const int Column;
	int Wall;			//������ �����ִ��� ����ִ����� ���� ���� �Է¹ޱ� ���� ����
public:
	explicit Bot(const int N, const int M) : Row(N), Column(M)
	{
		Map = new PIB*[N+1];
		for (int row = 1; row <= N; ++row)
		{
			Map[row] = new PIB[M+1];
			for (int column = 1; column <= M; ++column)
			{
				Map[row][column] = PIB(0, false);
			}
		}
	}
	Bot() : Row(0), Column(0) {}
	void MakeMap(ifstream& _in)
	{
		for (int row = 1; row <= Row; ++row)
		{
			for (int column = 1; column <= Column; ++column)
			{
				_in >> Wall;
				Map[row][column] = PIB(Wall, false);
			}
		}
	}
	void PrintMap() const
	{
		for (int row = 1; row <= Row; ++row)
		{
			for (int column = 1; column <= Column; ++column)
			{
				cout<<Map[row][column].first<< ' ';
			}
			cout << endl << endl;
		}
	}
	~Bot()
	{
		cout << "Call Bot Destructor" << endl;
		for (int d = 1; d <= Row; ++d)
		{
			delete[] Map[d];
		}
		delete[] Map;
	}
};

class MouseBot : public Bot
{
private:
	PII Locate;
	Direction Direct;
public:
	MouseBot(const int N, const int M, const int R, const int C, int D) : Bot(N, M), Locate(PII(R, C))
	{
		Direct = (Direction)D;
	}
	MouseBot() : Bot(), Locate(PII(0, 0))
	{
		Direct = South;
	}
	void Cheep()
	{
		cout << "(O��O)?";
	}
};

int main(void)
{
	MouseBot *Mickey[5];
	int testcase = 0;
	int _row = 0, _column = 0;
	int _location_row = 0, _location_column = 0, _direct = 0;

	ifstream in("testcase_Robot1.txt");
	if (!in.is_open())
		cout << "������ ã�� �� �����ϴ�." << endl;

	in >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		in >> _row >> _column;
		in >> _location_row >> _location_column >> _direct;
		Mickey[tc] = new MouseBot(_row, _column, _location_row, _location_column, _direct);
		Mickey[tc]->MakeMap(in);

		cout << "#" << tc << endl;
		Mickey[tc]->PrintMap();
	}

	for (int del = 1; del <= testcase; ++del)
	{
		delete[] Mickey[del];
	}
	in.close();
	return 0;
}