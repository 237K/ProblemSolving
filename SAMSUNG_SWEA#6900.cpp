//
//	OS Windows
//	2019.02.15
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#6900] <�������� ���� ��÷> (D3)
//	

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int StoI(char ch)			//stdlib ����� atoi, string ����� stoi ���� ä���������� ���� �߻��ϴ� �� ���Ƽ� ���� ����
{
	switch (ch)
	{
	case 48:
		return 0;
		break;
	case 49:
		return 1;
		break;
	case 50:
		return 2;
		break;
	case 51:
		return 3;
		break;
	case 52:
		return 4;
		break;
	case 53:
		return 5;
		break;
	case 54:
		return 6;
		break;
	case 55:
		return 7;
		break;
	case 56:
		return 8;
		break;
	case 57:
		return 9;
		break;
	default:
		return -1;
		break;
	}
}

int main(int argc, char**argv)
{
	int test_case;
	int T;
	int N, M;
	int MyLottery[8];		//�� �ڵ忡�� �迭�� �ȹ޾ƿ͵� ���������� Ȯ���� �����ص�
	char **Lottery;			//��÷���� �о�ͼ� ������
	int *Reward;			//��÷�� �о�ͼ� ������
	bool *Flag;				//��÷������ ��ġ�ϴ��� ���� ����
	int Answer;				//�� ���ɾ� ����

	freopen("s_input6900.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		N = 0; M = 0; Answer = 0;
		scanf("%d %d", &N, &M);
		Lottery = new char*[N];
		Reward = new int[N];
		Flag = new bool[N];
		for (int in = 0; in < N; ++in)
		{
			Lottery[in] = new char[9];
			Flag[in] = true;
			scanf("%8s %d", Lottery[in], &Reward[in]);				//��÷������ ��÷�� �о�ͼ� Lottery[N][9], Reward[N]�� �����ص�
		}
		for (int i = 0; i < M; ++i)									//���� ���� �� ���������� �о�ðǵ�
		{
			for (int my = 0; my < 8; ++my)						
			{				
				scanf("%1d", &MyLottery[my]);						//�� ���ھ� �о���鼭
				for (int search = 0; search < N; ++search)			//��÷���� 0~N ������ ���غ���
				{
					if (Lottery[search][my] == '*')					//*�̸� �������ڷ� �Ѿ��
						continue;

					else if (StoI(Lottery[search][my]) != MyLottery[my])	//*�� �ƴѵ� ���ڰ� �ٸ��� 
					{
						Flag[search] = false;								//�̰� ��÷ �ȵȰŶ�� ǥ���ϰ� �Ѿ
						continue;
					}
				}
			}
			for (int ans = 0; ans < N; ++ans)
			{
				if (Flag[ans])
					Answer += Reward[ans];
				Flag[ans] = true;
			}
		}
		
		printf("#%d %d\n", test_case, Answer);

		for (int i = 0; i < N; ++i)
		{
			delete Lottery[i];
		}
		delete[] Lottery;
		delete[] Reward;
		delete[] Flag;
	}
	return 0;
}