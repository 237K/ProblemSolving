//
//	OS Windows
//	2019.01.31
//
//	[Algorithm Problem Solving]
//		<Algorithm Category : DP>
//
//	'로봇 쥐'
//	

#include <iostream>
#include <fstream>
using namespace std;

enum Direction { North = 0, East = 1, South = 2, West = 3 };
typedef pair<int, bool> PIB;
typedef pair<int, int> PII;
static int BlockCounter;

class Bot
{
private:
	PIB** Map;			//좌표가 막혀있는지 열려있는지에 대한 int 정보와 봇이 방문한 적 있는지에 대한 bool 정보 저장
	int Row;
	int Column;
	int Wall;			//구역이 막혀있는지 비어있는지에 대한 값을 입력받기 위한 변수
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
	void MakeMap(ifstream& _in)							//인풋값 읽어와서 맵 만드는 함수
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
	bool CanGo(PII _locate, Direction _direct)			//더 갈 수 있는지 확인하는 함수
	{
		switch (_direct)
		{
		case North:
			if (Map[_locate.first - 1][_locate.second].first == 0 && Map[_locate.first - 1][_locate.second].second == false)
				return true;
			else
				return false;
			break;
		case East:
			if (Map[_locate.first][_locate.second + 1].first == 0 && Map[_locate.first][_locate.second + 1].second == false)
				return true;
			else
				return false;
			break;
		case South:
			if (Map[_locate.first+1][_locate.second].first == 0 && Map[_locate.first+1][_locate.second].second == false)
				return true;
			else
				return false;
			break;
		case West:
			if (Map[_locate.first][_locate.second - 1].first == 0 && Map[_locate.first][_locate.second - 1].second == false)
				return true;
			else
				return false;
			break;
		}
	}
	bool IsTheEnd(PII _locate, Direction _direct)			//후진 했을 때 뒤가 벽인지 확인하는 함수
	{
		switch (_direct)
		{
		case North:
			if (Map[_locate.first + 1][_locate.second].first == 1)
				return true;
			else
				return false;
			break;
		case East:
			if (Map[_locate.first][_locate.second - 1].first == 1)
				return true;
			else
				return false;
			break;
		case South:
			if (Map[_locate.first - 1][_locate.second].first == 1)
				return true;
			else
				return false;
			break;
		case West:
			if (Map[_locate.first][_locate.second + 1].first == 1)
				return true;
			else
				return false;
			break;
		}
	}
	void RouteCheck(PII _locate)						//로봇쥐가 해당 좌표를 방문했는지 체크하는 함수
	{
		Map[_locate.first][_locate.second].second = true;
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
			delete Map[d];
		}
		delete[] Map;
	}
};

class MouseBot : public Bot					//MouseBot 'is a' Bot
{
private:
	PII Locate;								//로봇쥐의 좌표
	Direction Direct;						//로봇쥐의 방향
	int MoveCounter;
public:
	MouseBot(const int N, const int M, const int R, const int C, const int D) : Bot(N, M), Locate(PII(R, C)), MoveCounter(0)
	{
		Direct = (Direction)D;
	}
	MouseBot() : Bot(), Locate(PII(0, 0))
	{
		Direct = South;						//크게 의미없는 디폴트값
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
		return *this;
	}
	bool Move()								//주요 작동 함수. while(TheEnd != false) 일 때 Move를 반복함
	{
			Bot::RouteCheck(Locate);		//로봇쥐의 현재 좌표 체크하고

			switch (Direct)					//현재 로봇쥐의 방향이
			{
			case North:								//북쪽이면
				if (Bot::CanGo(Locate, Direct))		//이 방향으로 갈 수 있는지 검사하고
				{
					Locate.first -= 1;				//갈 수 있으면 북쪽으로 한 칸 이동
					Cheep_Go();						//(실행창에서 이동하는지 확인하기 위함)
					MoveCounter++;					//Move Counter 하나 증가
					BlockCounter = 0;				//이동했으니까 Block Counter는 초기화
					return true;					//다시 Move 실행
				}
				else
				{
					Cheep_Wall();					//이 방향으로 갈 수 없는데
					if (BlockCounter == 4)			//Block Counter가 4이면 (4방향이 모두 막혀 있으면)
					{
						Locate.first += 1;			//한 칸 후진
						Cheep_Back();				//(실행창에서 후진하는지 확인하기 위함)
						MoveCounter++;				//후진도 Move Counter에 포함되므로 하나 증가
						if (Bot::IsTheEnd(Locate, Direct))		//후진했는데 뒷쪽이 벽이면 끝이므로
						{
							cout << "더 이상 이동할 수 없습니다." << endl;
							return false;			//while문 끝
							
						}
						else
						{							//후진했는데 뒷쪽이 벽이 아니면 
							BlockCounter = 0;		//Block Counter 초기화
							Move();					//다시 Move
						}
					}
					else
					{
						Direct = (Direction)(Direct + 1);	//CanGo 함수에 의해 지금 방향이 막혀있는데 Block Counter가 4가 아니면 방향을 90도 회전 
						BlockCounter++;						//Block Counter 하나 증가
						return true;
					}
				}
				break;
			case East:	
				if (Bot::CanGo(Locate, Direct))
				{
					Locate.second += 1;
					Cheep_Go();
					MoveCounter++;
					BlockCounter = 0;
					return true;
				}
				else
				{
					Cheep_Wall();
					if (BlockCounter == 4)
					{
						Locate.second -= 1;
						Cheep_Back();
						MoveCounter++;
						if (Bot::IsTheEnd(Locate, Direct))
						{
							cout << "더 이상 이동할 수 없습니다." << endl;
							return false;
							
						}
						else
						{
							BlockCounter = 0;
							Move();
						}
					}
					else
					{
						Direct = (Direction)(Direct + 1);
						BlockCounter++;
						return true;
					}
				}
				break;
			case South:
				if (Bot::CanGo(Locate, Direct))
				{
					Locate.first += 1;
					Cheep_Go();
					MoveCounter++;
					BlockCounter = 0;
					return true;
				}
				else
				{
					Cheep_Wall();
					if (BlockCounter == 4)
					{
						Locate.first -= 1;
						Cheep_Back();
						MoveCounter++;
						if (Bot::IsTheEnd(Locate, Direct))
						{
							cout << "더 이상 이동할 수 없습니다." << endl;
							return false;
							
						}
						else
						{
							BlockCounter = 0;
							Move();
						}
					}
					else
					{
						Direct = (Direction)(Direct + 1);
						BlockCounter++;
						return true;
					}
				}
				break;
			case West:
				if (Bot::CanGo(Locate, Direct))
				{
					Locate.second -= 1;
					Cheep_Go();
					MoveCounter++;
					BlockCounter = 0;
					return true;
				}
				else
				{
					Cheep_Wall();
					if (BlockCounter == 4)
					{
						Locate.second += 1;
						Cheep_Back();
						MoveCounter++;
						if (Bot::IsTheEnd(Locate, Direct))
						{
							cout << "더 이상 이동할 수 없습니다." << endl;
							return false;
							
						}
						else
						{
							BlockCounter = 0;
							Move();
						}
					}
					else
					{
						Direct = (Direction)0;
						BlockCounter++;
						return true;
					}
				}
				break;
			}
	}
	int GetMoveCounter() const
	{
		return MoveCounter;
	}
	void Cheep_Wall()				//실행창에서 어떻게 움직이는지 확인하기 위함
	{
		cout << "(OㅅO)? Blocked! " << "("<<Locate.first<<", "<<Locate.second<<")"<<"/"<<Direct<<endl;
	}
	void Cheep_Go()					//실행창에서 어떻게 움직이는지 확인하기 위함
	{
		cout << "(^ㅅ^) Go!" << "(" << Locate.first << ", " << Locate.second << ")" << "/" << Direct << endl;
	}
	void Cheep_Back()				//실행창에서 어떻게 움직이는지 확인하기 위함
	{
		cout << "(=ㅅ=;) 후진" << "(" << Locate.first << ", " << Locate.second << ")" << "/" << Direct << endl;
	}
	~MouseBot() { cout << "Call MouseBot Destructor" << endl; }
};

class BotControl
{
private:
	MouseBot *Mickey[5];
	const int TestCase;
	int _row, _column;
	int _location_row, _location_column, _direct;
	bool TheEnd;
public:
	BotControl(const int _TestCase) : TestCase(_TestCase), _row(0), _column(0), _location_row(0), _location_column(0), _direct(0)
	{
		TheEnd = true;
	}
	void Test(ifstream& _in)
	{
		for (int tc = 1; tc <= TestCase; ++tc)
		{
			TheEnd = true;
			BlockCounter = 0;
			_in >> _row >> _column;
			_in >> _location_row >> _location_column >> _direct;
			Mickey[tc] = new MouseBot(_row, _column, _location_row, _location_column, _direct);
			Mickey[tc]->MakeMap(_in);
			cout << "#" << tc << endl;
			Mickey[tc]->PrintMap();
			while (TheEnd != false)					//로봇쥐가 더 이상 움직일 수 없을 때 까지 Move 반복
			{
				TheEnd = Mickey[tc]->Move();
			}
			cout << "Move Counter : " << Mickey[tc]->GetMoveCounter() << endl << endl;
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

//main
int main(void)
{
	int _testcase = 0;

	ifstream in("testcase_Robot1.txt");

	if (!in.is_open())
		cout << "파일을 찾을 수 없습니다." << endl;

	in >> _testcase;
	BotControl BC(_testcase);
	BC.Test(in);

	in.close();
	return 0;
}