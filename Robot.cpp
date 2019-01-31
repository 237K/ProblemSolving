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
	int Row;
	int Column;
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
	Bot(const Bot& cpy)
	{
		Row = cpy.Row;
		Column = cpy.Column;
		for (int r = 1; r <= Row; ++r)
		{
			for (int c = 1; c <= Column; ++c)
			{
				Map[r][c] = cpy.Map[r][c];
			}
		}
	}
	Bot& operator= (const Bot& assign)
	{
		for (int i = 1; i <= Row; ++i)
		{
			delete Map[i];
		}
		Row = assign.Row;
		Column = assign.Column;
		for (int r = 1; r <= Row; ++r)
		{
			for (int c = 1; c <= Column; ++c)
			{
				Map[r][c] = assign.Map[r][c];
			}
		}
		return *this;
	}
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
	bool CanGo(PII _locate, Direction _direct)
	{
		switch (_direct)
		{
		case North:
			if (Map[_locate.first][_locate.second + 1].first == 0 && Map[_locate.first][_locate.second + 1].second == false)
				return true;
			else
				return false;
			break;
		case East:
			if (Map[_locate.first + 1][_locate.second].first == 0 && Map[_locate.first + 1][_locate.second].second == false)
				return true;
			else
				return false;
			break;
		case South:
			if (Map[_locate.first][_locate.second - 1].first == 0 && Map[_locate.first][_locate.second - 1].second == false)
				return true;
			else
				return false;
			break;
		case West:
			if (Map[_locate.first - 1][_locate.second].first == 0 Map[_locate.first - 1][_locate.second].second == false)
				return true;
			else
				return false;
			break;
		}
	}
	void RouteCheck(PII _locate)
	{
		Map[_locate.first][_locate.second] = true;
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
	virtual ~Bot()
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
	MouseBot(const int N, const int M, const int R, const int C, const int D) : Bot(N, M), Locate(PII(R, C))
	{
		Direct = (Direction)D;
		Bot::RouteCheck(Locate);
	}
	MouseBot() : Bot(), Locate(PII(0, 0))
	{
		Direct = South;
	}
	MouseBot(const MouseBot& cpy)
	{
		Locate = cpy.Locate;
		Direct = cpy.Direct;
	}
	MouseBot& operator= (const MouseBot& assign)
	{
		Locate = assign.Locate;
		Direct = assign.Direct;
	}
	void Move()
	{
			switch (Direct)
			{
			case North:
				if (Bot::CanGo(Locate, Direct))
				{
					Locate.second += 1;
					Bot::RouteCheck(Locate);
				}
				else

				break;
			case East:
				if (Bot::CanGo(Locate, Direct))
				{
					Locate.first += 1;
					Bot::RouteCheck(Locate);
				}
				break;
			case South:
				if (Bot::CanGo(Locate, Direct))
				{
					Locate.second -= 1;
					Bot::RouteCheck(Locate);
				}
				break;
			case West:
				if (Bot::CanGo(Locate, Direct))
				{
					Locate.first -= 1;
					Bot::RouteCheck(Locate);
				}
				break;
			}
	}
	void Cheep_Wall()
	{
		cout << "(O��O)?";
	}
	void Cheep_Go()
	{
		cout << "(^��^)" << endl;
	}
	~MouseBot() { cout << "Call MouseBot Destructor" << endl; }
};

class BotControl
{
private:
	MouseBot *Mickey[5];
	const int TestCase;
	int MoveCounter;
	int _row, _column;
	int _location_row, _location_column, _direct;
public:
	BotControl(const int _TestCase) : TestCase(_TestCase), MoveCounter(0), _row(0), _column(0), _location_row(0), _location_column(0), _direct(0)
	{
	}
	void Setting(ifstream& _in)
	{
		for (int tc = 1; tc <= TestCase; ++tc)
		{
			_in >> _row >> _column;
			_in >> _location_row >> _location_column >> _direct;
			Mickey[tc] = new MouseBot(_row, _column, _location_row, _location_column, _direct);
			Mickey[tc]->MakeMap(_in);
			cout << "#" << tc << endl;
			Mickey[tc]->PrintMap();
		}
	}
	~BotControl()
	{
		for (int del = 1; del <= TestCase; ++del)
		{
			delete Mickey[del];
		}
	}
};

int main(void)
{
	int _testcase = 0;

	ifstream in("testcase_Robot1.txt");
	if (!in.is_open())
		cout << "������ ã�� �� �����ϴ�." << endl;

	in >> _testcase;
	BotControl BC(_testcase);
	BC.Setting(in);

	in.close();
	return 0;
}