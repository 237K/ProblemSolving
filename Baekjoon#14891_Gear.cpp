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
			Gear[init].resize(GEAR_TEETH);
			Check[init] = false;
		}
	}
	~GearClass()
	{
		delete[] Gear;
		delete[] Check;
	}
	void Right_rotate(vector<int>& v)
	{
		int Recent;
		Recent = v[v.size()-1];
		for (auto i = 0; i < v.size()-1; i++)
		{
			v[i + 1] = v[i];
		}
		v[0] = Recent;
	}
	void Left_rotate(vector<int>& v)
	{
		int Recent;
		Recent = v[0];
		for (auto i = v.size()-1; i > 0; --i)
		{
			v[i - 1] = v[i];
		}
		v[v.size() - 1] = Recent;
	}
	void Set(FILE *_file)
	{
		int RecentNum = 0;
		for (int g = 1; g <= 4; ++g)
		{
			for (int t = 0; t < GEAR_TEETH; ++t)
			{
				//fscanf_s(_file, "%1d", &Gear[g][t]);
				fscanf_s(_file, "%1d", &RecentNum);
				Gear[g][t] = RecentNum;
			}
		}
		//_fin >> Rotate;
		fscanf_s(_file, "%d", &Rotate);
		for (int r = 1; r <= Rotate; ++r)
		{
			int count = 0;
			//_fin >> Rotate_Gear >> Rotate_Direct;
			fscanf_s(_file, "%d %d", &Rotate_Gear, &Rotate_Direct);
			switch (Rotate_Direct)
			{
			case -1:
				Left_rotate(Gear[Rotate_Gear]);
				break;
			case 1:
				Right_rotate(Gear[Rotate_Gear]);
				break;
			}
			//rotate(Gear[Rotate_Gear].begin(), Gear[Rotate_Gear].begin()-(Rotate_Direct), Gear[Rotate_Gear].end());	//rotate가 기본적으로 왼쪽(반시계방향)으로 시프트하므로 입력받은 방향에 부호반전시킴
			Check[Rotate_Gear] = true;
			Execution(Rotate_Gear, Rotate_Direct);
		}
		CheckScore();
		cout << "Score : " << Score << endl << endl;
	}
	void Execution(int _Rotate_Gear, int _Rotate_Direct)
	{
		if (IsTheEnd())
			return;
		else
		{
			if (_Rotate_Gear - 1 >= 1 && Check[_Rotate_Gear - 1] == false)
			{
				Check[_Rotate_Gear - 1] = true;
				if (Gear[_Rotate_Gear - 1][2] != Gear[_Rotate_Gear][6])
				{
					switch (_Rotate_Direct)
					{
					case -1:
						Right_rotate(Gear[_Rotate_Gear - 1]);
						Execution(_Rotate_Gear - 1, 1);
						break;
					case 1:
						Left_rotate(Gear[_Rotate_Gear - 1]);
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
		if (Gear[1][0] == 1)
			Score += 1;
		if (Gear[2][0] == 1)
			Score += 2;
		if (Gear[3][0] == 1)
			Score += 4;
		if (Gear[4][0] == 1)
			Score += 8;
	}
};

int main(void)
{
	GearClass *gear[100];
	int testcase = 0;
	FILE *file = NULL;
	fopen_s(&file, "testcase_Gear.txt", "r");
	//ifstream fin("testcase_Gear.txt");

	fscanf_s(file, "%d", &testcase);
	//fin >> testcase;
	for (int tc = 1; tc <= testcase; ++tc)
	{
		gear[tc] = new GearClass();
		cout << "#" << tc << endl;
		//gear[tc]->Set(fin);
		gear[tc]->Set(file);
	}

	//fin.close();
	fclose(file);
	for (int del = 1; del <= testcase; ++del)
	{
		delete gear[del];
	}
	return 0;
}