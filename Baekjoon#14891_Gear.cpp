//
//	OS Windows
//	2019.02.08
//
//	[Algorithm Problem Solving]
//
//	BAEKJOON #14891	��Ϲ���
//

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const static int GEAR_NUMBER = 4;			//��� ����
const static int GEAR_TEETH = 8;			//�� ��� �� �̻� ����

class GearClass
{
private:
	vector<int> *Gear;				//�������� ��� ������ �������־ �����Ҵ��� ���ص� �Ǳ� ������ �׽�Ʈ�� ����
	bool *Check;					//��ϸ� üũ�ߴ��� Ȯ���ϱ� ����
	int Rotate;						//ȸ�� ��
	int Rotate_Gear;				//ȸ����ų ���
	int Rotate_Direct;				//ȸ����ų ����
	int Score;						//����
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
	void Right_rotate(vector<int>& v)							//algorithm ����� rotate�� ����ص� ������ �ڵ� ����ȭ�� ���� �׳� ������
	{
		int Last = v[v.size() - 1];
		for (vector<int>::size_type i = v.size()-1; i > 0; i--)
		{
			v[i] = v[i-1];
		}
		v[0] = Last;
	}
	void Left_rotate(vector<int>& v)							//algorithm ����� rotate�� ����ص� ������ �ڵ� ����ȭ�� ���� �׳� ������
	{
		int First;
		First = v[0];
		for (vector<int>::size_type i = 0; i < v.size()-1; i++)
		{
			v[i] = v[i+1];
		}
		v[v.size() - 1] = First;
	}
	void Set(FILE *_file)						//��ǲ�� �о�ͼ� �����ϴ� �Լ�
	{
		int RecentNum = 0;
		for (int g = 1; g <= 4; ++g)
		{
			for (int t = 0; t < GEAR_TEETH; ++t)
			{
				//fscanf_s(_file, "%1d", &Gear[g][t]);
				fscanf_s(_file, "%1d", &RecentNum);		//��� ���� ���ڰ� �پ��ִ�ä�� �־����� ifstream ���� fscanf_s(FILE *file)�� �о��
				Gear[g][t] = RecentNum;
			}
		}
		//_fin >> Rotate;
		fscanf_s(_file, "%d", &Rotate);
		for (int r = 1; r <= Rotate; ++r)			//ȸ�� �� ��ŭ
		{
			CheckInit();
			//_fin >> Rotate_Gear >> Rotate_Direct;
			fscanf_s(_file, "%d %d", &Rotate_Gear, &Rotate_Direct);		//ȸ����ų ��϶� ���� �о�ͼ�
			Execution(Rotate_Gear, Rotate_Direct);		//���� �Լ��� �ѱ�
			switch (Rotate_Direct)					 
			{
			case -1:
				Left_rotate(Gear[Rotate_Gear]);			//������ -1�̸� �ݽð����(����) �����̼�
				break;
			case 1:
				Right_rotate(Gear[Rotate_Gear]);		//������ 1�̸� �ð����(������) �����̼�
				break;
			}
			//rotate(Gear[Rotate_Gear].begin(), Gear[Rotate_Gear].begin()-(Rotate_Direct), Gear[Rotate_Gear].end());	//rotate�� �⺻������ ����(�ݽð����)���� ����Ʈ�ϹǷ� �Է¹��� ���⿡ ��ȣ������Ŵ
			Check[Rotate_Gear] = true;				//�� ��� üũ�ϰ�
			
			PrintGear();
		}
		CheckScore();
		cout << "Score : " << Score << endl << endl;
	}
	void Execution(int _Rotate_Gear, int _Rotate_Direct)	//���� ��϶� ȸ���� ���� ���ڷ� �޾ƿͼ�
	{
		if (IsTheEnd())		//���̸� ����
			return;
		else
		{																		//���� �ƴϸ�
			if (_Rotate_Gear - 1 >= 1 && Check[_Rotate_Gear - 1] == false)		//���ʿ� ��ϰ� �ְ�, ���� ��ϰ� üũ �ȵǾ�������
			{
				Check[_Rotate_Gear - 1] = true;									//���� ��Ϸ� �̵��ؼ� üũ�ϰ�
				if (Gear[_Rotate_Gear - 1][2] != Gear[_Rotate_Gear][6])			//�¹����� ����� ����(N�� / S��)�� �ٸ��� ȸ�� ��ų�ǵ�,
				{
					switch (_Rotate_Direct)										//���ڷ� �޾ƿ�(���� ��ϰ� ȸ���� ���⿡ ����)
					{
					case -1:													//������ ȸ���� ��ϰ� �ݽð�������� ��������
						Right_rotate(Gear[_Rotate_Gear - 1]);					//�ð����(������)���� ȸ��
						Execution(_Rotate_Gear - 1, 1);							//�ٽ� ����
						break;
					case 1:														//������ ȸ���� ��ϰ� �ð�������� ��������
						Left_rotate(Gear[_Rotate_Gear - 1]);					//�ݽð�������� ȸ��
						Execution(_Rotate_Gear - 1, -1);
						break;
					}
				}
			}
			if (_Rotate_Gear + 1 <= 4 && Check[_Rotate_Gear + 1] == false)		//������ ��� Ȯ��
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
	bool IsTheEnd()											//�ϳ��� Ȯ������ ���� ��ϰ� ������ ���� �ƴ�
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
	void CheckScore()										//���� ���
	{
		Score = Gear[1][0] + (Gear[2][0] * 2) + (Gear[3][0] * 4) + (Gear[4][0] * 8);
	}
	void PrintGear()const
	{
		for (int g = 1; g <= 4; ++g)
		{
			cout << "[Gear "<<g<< "] ";
			for (vector<int>::size_type i = 0; i < Gear[g].size() ; ++i)
			{
				cout << Gear[g][i] << ' ';
			}
			cout << endl;
		}
		cout << "============================"<<endl;
	}
	void CheckInit()
	{
		for (int i = 1; i <= GEAR_NUMBER; ++i)
		{
			Check[i] = false;
		}
	}
};

int main(void)									//�����Լ�
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