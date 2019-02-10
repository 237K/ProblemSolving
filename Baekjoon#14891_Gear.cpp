//
//	OS Windows
//	2019.02.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14891	톱니바퀴
//

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const static int GEAR_NUMBER = 4;			//톱니 개수
const static int GEAR_TEETH = 8;			//각 톱니 당 이빨 개수

class GearClass
{
private:
	vector<int> *Gear;				//문제에선 톱니 개수가 정해져있어서 동적할당을 안해도되긴 하지만 속도 비교해보기 위함
	bool *Check;					//톱니를 체크했는지 확인하기 위함
	int Rotate;						//회전 수
	int Rotate_Gear;				//회전시킬 톱니
	int Rotate_Direct;				//회전시킬 방향
	int Score;						//점수
public:
	GearClass() : Rotate(0), Rotate_Gear(0), Rotate_Direct(0), Score(0)
	{
		Gear = new vector<int>[GEAR_NUMBER + 1];
		Check = new bool[GEAR_NUMBER + 1];
		for (int init = 1; init <= GEAR_NUMBER; init++)
		{
			Gear[init].resize(GEAR_TEETH);
			Check[init] = false;
		}
	}
	~GearClass()
	{
		delete[] Gear;
		delete[] Check;
	}
	void Right_rotate(vector<int>& v)							//algorithm 헤더에 rotate를 사용해도 되지만 코드 간소화를 위해 그냥 정의함
	{
		int Last = v[v.size() - 1];
		for (vector<int>::size_type i = v.size()-1; i > 0; i--)
		{
			v[i] = v[i-1];
		}
		v[0] = Last;
	}
	void Left_rotate(vector<int>& v)							//algorithm 헤더에 rotate를 사용해도 되지만 코드 간소화를 위해 그냥 정의함
	{
		int First;
		First = v[0];
		for (vector<int>::size_type i = 0; i < v.size()-1; i++)
		{
			v[i] = v[i+1];
		}
		v[v.size() - 1] = First;
	}
	void Set(FILE *_file)						//인풋값 읽어와서 실행하는 함수
	{
		int RecentNum = 0;						
		for (int g = 1; g <= 4; ++g)
		{
			for (int t = 0; t < GEAR_TEETH; ++t)
			{
				fscanf_s(_file, "%1d", &RecentNum);		//톱니 상태 숫자가 붙어있는채로 주어져서 ifstream 말고 fscanf_s(FILE *file)로 읽어옴
				Gear[g][t] = RecentNum;					//벡터에 바로 집어넣어도 되지만, 안정성을 위해 임시변수를 명시적으로 사용함
			}
		}

		fscanf_s(_file, "%d", &Rotate);				//회전 수를 읽어와서
		for (int r = 1; r <= Rotate; ++r)			//회전 수 만큼 반복
		{
			fscanf_s(_file, "%d %d", &Rotate_Gear, &Rotate_Direct);		//회전시킬 톱니(Rotate_Gear)랑 방향(Rotate_Direct) 읽어와서
			CheckInit(Rotate_Gear);					//각 톱니 체크를 false로 초기화 한 다음, 회전할지 말지 검사하고 회전안할 톱니는 true로 변경
			Check[Rotate_Gear] = true;				//현재 회전시킬 톱니 체크하고
			switch (Rotate_Direct)
			{
			case -1:
				Left_rotate(Gear[Rotate_Gear]);		//방향이 -1이면 반시계방향(왼쪽) 로테이션
				break;
			case 1:
				Right_rotate(Gear[Rotate_Gear]);	//방향이 1이면 시계방향(오른쪽) 로테이션
				break;
			}

			Execution(Rotate_Gear, Rotate_Direct);	//실행 함수로 넘김

			//rotate(Gear[Rotate_Gear].begin(), Gear[Rotate_Gear].begin()-(Rotate_Direct), Gear[Rotate_Gear].end());	//STL algorithm 헤더에 rotate 함수 사용해도 됨
			
			PrintGear();		//확인을 위해 현재 기어들 상태 출력해봄
		}
		CheckScore();			//톱니 4개 다 체크하고나면 스코어 계산
		cout << "Score : " << Score << endl << endl;		//스코어 출력
	}
	void Execution(int _Rotate_Gear, int _Rotate_Direct)	//*핵심 함수.
	{														//현재 톱니랑 회전한 방향 인자로 받아와서
		if (IsTheEnd())			//톱니 4개 다 체크되있는지 확인한 후
			return;				//다 했으면 끝
		else
		{																		//끝이 아니면
			if (_Rotate_Gear - 1 >= 1 && Check[_Rotate_Gear - 1] == false)		//왼쪽에 톱니가 있고, 왼쪽 톱니가 체크 안되어있으면(회전해야 하는데 안했으면)
			{
				Check[_Rotate_Gear - 1] = true;									//왼쪽 톱니 체크하고,
					switch (_Rotate_Direct)										//인자로 받아온 이전 톱니가 회전한 방향에 따라
					{
					case -1:													//이전에 회전한 톱니가 반시계방향으로 돌았으면
						Right_rotate(Gear[_Rotate_Gear - 1]);					//시계방향(오른쪽)으로 회전
						Execution(_Rotate_Gear - 1, 1);							//다시 실행
						break;
					case 1:														//이전에 회전한 톱니가 시계방향으로 돌았으면
						Left_rotate(Gear[_Rotate_Gear - 1]);					//반시계방향(왼쪽)으로 회전
						Execution(_Rotate_Gear - 1, -1);						//다시 실행
						break;
					}
			}
			if (_Rotate_Gear + 1 <= 4 && Check[_Rotate_Gear + 1] == false)		//오른쪽 톱니 확인 및 실행
			{
				Check[_Rotate_Gear + 1] = true;
					switch (_Rotate_Direct)
					{
					case -1:
						Right_rotate(Gear[_Rotate_Gear + 1]);
						Execution(_Rotate_Gear + 1, 1);
						break;
					case 1:
						Left_rotate(Gear[_Rotate_Gear + 1]);
						Execution(_Rotate_Gear + 1, -1);
						break;
					}
			}
		}
	}
	bool IsTheEnd()											//하나라도 확인하지 않은 톱니가 있으면 끝이 아님
	{
		int count = 0;
		for (int check = 1; check <= 4; ++check)
		{
			if (Check[check] == false)
				count++;
		}
		if (count != 0)
			return false;
		else
			return true;
	}
	void CheckScore()										//점수 계산
	{
		Score = Gear[1][0] + (Gear[2][0] * 2) + (Gear[3][0] * 4) + (Gear[4][0] * 8);
	}
	void CheckInit(int _Rotate_Gear)						//각 회전 실행 전 각 톱니를 회전할지 말지 결정하기 위한 함수
	{
		for (int i = 1; i <= GEAR_NUMBER; ++i)				//일단 전부다 false로 초기화
		{
			Check[i] = false;
		}
															//일반화 하진 않았고.. 일단 톱니가 4개 밖에 없으니 상황 별로 명시함..
		if (_Rotate_Gear == 1)
		{
			if (Gear[1][2] == Gear[2][6])
			{
				for (int g = 1; g < GEAR_NUMBER; ++g)
				{
					if (Gear[g][2] == Gear[g + 1][6])
						Check[g + 1] = true;
				}
			}
		}
		else if (_Rotate_Gear == 2)
		{
			if (Gear[1][2] == Gear[2][6])
				Check[1] = true;

			if (Gear[2][2] == Gear[3][6])
			{
				Check[3] = true;
				Check[4] = true;
			}
		}
		else if (_Rotate_Gear == 3)
		{
			if (Gear[3][2] == Gear[4][6])
				Check[4] = true;
			if (Gear[2][2] == Gear[3][6])
			{
				Check[2] = true;
				Check[1] = true;
			}
		}
		else if (_Rotate_Gear == 4)
		{
			if (Gear[3][2] == Gear[4][6])
			{
				for (int g = 4; g > 1; --g)
				{
					if (Gear[g - 1][2] == Gear[g][6])
						Check[g - 1] = true;
				}
			}
		}
	}
	void PrintGear()const
	{
		for (int g = 1; g <= 4; ++g)
		{
			cout << "[Gear " << g << "] ";
			for (vector<int>::size_type i = 0; i < Gear[g].size(); ++i)
			{
				cout << Gear[g][i] << ' ';
			}
			cout << endl;
		}
		cout << "============================" << endl;
	}
};

int main(void)		//메인함수
{
	GearClass *gear[100];
	int testcase = 0;
	FILE *file = NULL;
	fopen_s(&file, "testcase_Gear.txt", "r");

	fscanf_s(file, "%d", &testcase);
	for (int tc = 1; tc <= testcase; ++tc)
	{
		gear[tc] = new GearClass();
		cout << "#" << tc << endl;
		gear[tc]->Set(file);
	}
	fclose(file);
	for (int del = 1; del <= testcase; ++del)
	{
		delete gear[del];
	}
	return 0;
}