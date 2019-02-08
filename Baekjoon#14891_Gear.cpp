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

const static int GEAR_NUMBER = 4;
const static int GEAR_TEETH = 8;

class GearClass
{
private:
	vector<int> *Gear;
	bool *Check;
	int Rotate;
	int Rotate_Gear;
	int Rotate_Direct;
	int Score;
public:
	GearClass() : Rotate(0), Rotate_Gear(0), Rotate_Direct(0), Score(0)
	{
		Gear = new vector<int>[GEAR_NUMBER + 1];
		Check = new bool[GEAR_NUMBER + 1];
		for (int init = 1; init <= GEAR_NUMBER; init++)
		{
			Gear[init].resize(GEAR_TEETH, 0);
			Check[init] = false;
		}
	}
	~GearClass()
	{
		delete[] Gear;
		delete[] Check;
	}
	void Set(ifstream& _fin)
	{
		int RecentNum = 0;
		for (int g = 1; g <= 4; ++g)
		{
			for (int t = 0; t < GEAR_TEETH; ++t)
			{
				scanf_s("%1d", &RecentNum);
				Gear[g][t] = RecentNum;
			}
		}
		_fin >> Rotate;
		for (int r = 1; r <= Rotate; ++r)
		{
			int count = 0;
			_fin >> Rotate_Gear >> Rotate_Direct;
			rotate(Gear[Rotate_Gear].begin(), Gear[Rotate_Gear].begin()-(Rotate_Direct), Gear[Rotate_Gear].end());	//rotate가 기본적으로 왼쪽(반시계방향)으로 시프트하므로 입력받은 방향에 부호반전시킴
			Check[Rotate_Gear] = true;
			Execution(Rotate_Gear, Rotate_Direct);
			CheckScore();
		}
		cout << "Score : " << Score << endl << endl;
	}
	void Execution(int _Rotate_Gear, int _Rotate_Direct)
	{
		if (!IsTheEnd())
			return;

		if (_Rotate_Gear - 1 >= 1 && Check[_Rotate_Gear-1] == false)
		{
			Check[_Rotate_Gear - 1] = true;
			if (Gear[_Rotate_Gear - 1][2] != Gear[_Rotate_Gear][6])
			{
				switch (_Rotate_Direct)
				{
				case -1:
					rotate(Gear[_Rotate_Gear - 1].begin(), Gear[_Rotate_Gear - 1].begin()+_Rotate_Direct, Gear[_Rotate_Gear - 1].end());
					Execution(_Rotate_Gear - 1, 1);
					break;
				case 1:
					rotate(Gear[_Rotate_Gear - 1].begin(), Gear[_Rotate_Gear - 1].begin()-(_Rotate_Direct), Gear[_Rotate_Gear - 1].end());
					Execution(_Rotate_Gear - 1, -1);
					break;
				}
			}
		}
		if (_Rotate_Gear + 1 <= 4 && Check[_Rotate_Gear + 1] == false)
		{
			Check[_Rotate_Gear + 1] = true;
			if (Gear[_Rotate_Gear][2] != Gear[_Rotate_Gear + 1][6])
			{
				switch (_Rotate_Direct)
				{
				case -1:
					rotate(Gear[_Rotate_Gear + 1].begin(), Gear[_Rotate_Gear + 1].begin() + _Rotate_Direct, Gear[_Rotate_Gear + 1].end());
					Execution(_Rotate_Gear + 1, 1);
					break;
				case 1:
					rotate(Gear[_Rotate_Gear + 1].begin(), Gear[_Rotate_Gear + 1].begin() - (_Rotate_Direct), Gear[_Rotate_Gear + 1].end());
					Execution(_Rotate_Gear + 1, -1);
					break;
				}
			}
		}

	}
	bool IsTheEnd()
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
	void CheckScore()
	{
		for (int s = 1; s <= 4; s++)
		{
			Score += Gear[s][0];
		}
	}
};

int main(void)
{
	GearClass *gear[100];
	int testcase = 0;
	ifstream fin("testcase_Gear.txt");

	fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		cout << "#" << tc << endl;
		gear[tc]->Set(fin);
	}

	fin.close();

	for (int del = 1; del <= testcase; ++del)
	{
		delete gear[del];
	}
	return 0;
}