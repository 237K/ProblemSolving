//
//	OS Windows
//	2019.04.06
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#2383> ���� �Ļ�ð�(����)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

const static int SIZE = 11;
const static int MAX_HUMAN = 10;
const static int MAX_STAIR = 2;
const static int INF = 2147000000;

struct human
{
	int x, y, distance_to_stair, wait_stair, time_to_ground, end_check;
};

struct stair
{
	int x, y, height, people_in_stair, end_flag;
};

static int map[SIZE][SIZE];
static human h[MAX_HUMAN];
static stair s[MAX_STAIR];
static int shortest_time;
static int N;
static int num_human;

inline void init()
{
	(void)memset(map, 0, sizeof(map));
	for (register int i = 0; i < MAX_HUMAN; ++i)
		h[i] = { 0, 0, 0, 0, 0, 0 };
	for (register int i = 0; i < MAX_STAIR; ++i)
		s[i] = { 0, 0, 0, 0, 0 };
	shortest_time = INF;
	num_human = 0;
}

/*
inline void print_vector(vector<int> stair1, vector<int> stair2)
{
	cout << "1�� ������� �������� ��� : ";
	for (vector<int>::iterator iter = stair1.begin(); iter != stair1.end(); ++iter)
		cout << *iter+1 << ' ';
	cout << '\n'<<"2�� ������� �������� ��� : ";
	for (vector<int>::iterator iter = stair2.begin(); iter != stair2.end(); ++iter)
		cout << *iter+1 << ' ';
	cout << '\n';
}
*/

inline int get_distance(int human_number, int stair_number)
{
	return abs(h[human_number].x - s[stair_number].x) + abs(h[human_number].y - s[stair_number].y);
}

inline int timer(vector<int> stair1, vector<int> stair2)
{
	//ù ��° ������� ������ ����� �Ÿ� ���
	if (!stair1.size())
	{
		s[0].end_flag = 1;
	}
	else
	{
		for (vector<int>::iterator iter = stair1.begin(); iter != stair1.end(); ++iter)
		{
			h[*iter].distance_to_stair = get_distance(*iter, 0);
		}
	}
	//�� ��° ������� ������ ����� �Ÿ� ���
	if (!stair2.size())
	{
		s[1].end_flag = 1;
	}
	else
	{
		for (vector<int>::iterator iter = stair2.begin(); iter != stair2.end(); ++iter)
		{
			h[*iter].distance_to_stair = get_distance(*iter, 1);
		}
	}

	//��� ����� �������µ� �ɸ��� �ð� ���
	int time = -1;
	int end_count_stair1 = 0;
	int end_count_stair2 = 0;
	while (1)
	{
		//��������. �ð� ��ȯ
		if (s[0].end_flag && s[1].end_flag)
			return time;
		else
		{
			time++;
			//cout <<'\n'<< "time : " << time << '\n';
			//ù ��° ���
			if (!s[0].end_flag)
			{
				for (vector<int>::iterator iter = stair1.begin(); iter != stair1.end(); ++iter)
				{
					//������� ������ ����� �ƴ� ���
					if (!h[*iter].end_check)
					{
						//����� �������� ���� ���
						if (h[*iter].time_to_ground)
						{
							//�� ĭ�� ������
							//���� ���������� üũ
							if (h[*iter].time_to_ground++ == s[0].height)
							{
								//cout << *iter + 1 << "�� ��� ���� ������" << '\n';
								s[0].people_in_stair--;
								h[*iter].end_check = 1;
								end_count_stair1++;
							}
						}
						//��� �տ��� ��ٸ��� ���� ���
						if (!h[*iter].time_to_ground && h[*iter].wait_stair)
						{
							//����� �������� �ִ� ����� 3�� �̸��� ��� �������� ������
							//��ܿ� 3�� ������ ��ٸ�
							if (s[0].people_in_stair < 3)
							{
								//cout << *iter + 1 << "�� ��� ��� �������� ������" << '\n';
								h[*iter].time_to_ground++;
								s[0].people_in_stair++;
								continue;
							}
							else
							{
								h[*iter].distance_to_stair--;
								h[*iter].wait_stair++;
								continue;
							}
						}
						//������� ���� ���� ���
						if (!h[*iter].time_to_ground && !h[*iter].wait_stair)
						{
							//��ܿ� ������ ������ �� ĭ�� �ɾ
							//�����ϸ� ��ٸ�
							if (!h[*iter].distance_to_stair--)
							{
								//cout << *iter + 1 << "�� ��� ��� �տ� ������" << '\n';
								h[*iter].wait_stair++;
								continue;
							}
							else
								continue;
						}
					}
				}
				//*****************************************************************************************//
				//********�� ���� ����� ���������� ���ÿ� ��ٸ��� �ִ� ����� �������� �����ؾ� ��.....********//
				//*****************************************************************************************//
				if (s[0].people_in_stair < 3)
				{
					for (vector<int>::iterator wait_push = stair1.begin(); wait_push != stair1.end(); ++wait_push)
					{
						if (!h[*wait_push].end_check &&
							!h[*wait_push].time_to_ground &&
							h[*wait_push].distance_to_stair < -1 &&
							h[*wait_push].wait_stair &&
							s[0].people_in_stair < 3)
						{
							//cout << *wait_push + 1 << "�� ��� ��� �������� ������" << '\n';
							h[*wait_push].time_to_ground++;
							s[0].people_in_stair++;
							break;
						}
					}
				}
				//*****************************************************************************************//
				//*****************************************************************************************//
				//*****************************************************************************************//
				if (end_count_stair1 == stair1.size())
					s[0].end_flag = 1;
			}

			//�� ��° ���
			if (!s[1].end_flag)
			{
				for (vector<int>::iterator iter = stair2.begin(); iter != stair2.end(); ++iter)
				{
					//������� ������ ����� �ƴ� ���
					if (!h[*iter].end_check)
					{
						//����� �������� ���� ���
						if (h[*iter].time_to_ground)
						{
							//�� ĭ�� ������
							//���� ���������� üũ
							if (h[*iter].time_to_ground++ == s[1].height)
							{
								//cout << *iter + 1 << "�� ��� ���� ������" << '\n';
								s[1].people_in_stair--;
								h[*iter].end_check = 1;
								end_count_stair2++;
							}
						}
						//��� �տ��� ��ٸ��� ���� ���
						if (!h[*iter].time_to_ground && h[*iter].wait_stair)
						{
							//����� �������� �ִ� ����� 3�� �̸��� ��� �������� ������
							//��ܿ� 3�� ������ ��ٸ�
							if (s[1].people_in_stair < 3)
							{
								//cout << *iter + 1 << "�� ��� ��� �������� ������" << '\n';
								h[*iter].time_to_ground++;
								s[1].people_in_stair++;
								continue;
							}
							else
							{
								h[*iter].distance_to_stair--;
								h[*iter].wait_stair++;
								continue;
							}
						}
						//������� ���� ���� ���
						if (!h[*iter].time_to_ground && !h[*iter].wait_stair)
						{
							//��ܿ� ������ ������ �� ĭ�� �ɾ
							//�����ϸ� ��ٸ�
							if (!h[*iter].distance_to_stair--)
							{
								//cout << *iter + 1 << "�� ��� ��� �տ� ������" << '\n';
								h[*iter].wait_stair++;
								continue;
							}
							else
								continue;
						}
					}
				}
				//*****************************************************************************************//
				//*******�� ���� ����� ���������� ���ÿ� ��ٸ��� �ִ� ����� �������� �����ؾ� ��.....*********//
				//*****************************************************************************************//
				if (s[1].people_in_stair < 3)
				{
					for (vector<int>::iterator wait_push = stair2.begin(); wait_push != stair2.end(); ++wait_push)
					{
						if (!h[*wait_push].end_check &&
							!h[*wait_push].time_to_ground &&
							h[*wait_push].distance_to_stair < -1 &&
							h[*wait_push].wait_stair &&
							s[1].people_in_stair < 3)
						{
							//cout << *wait_push + 1 << "�� ��� ��� �������� ������" << '\n';
							h[*wait_push].time_to_ground++;
							s[1].people_in_stair++;
							break;
						}
					}
				}
				//*****************************************************************************************//
				//*****************************************************************************************//
				//*****************************************************************************************//
				if (end_count_stair2 == stair2.size())
					s[1].end_flag = 1;
			}
		}
	}
}
inline void dfs(int count, vector<int> stair1, vector<int> stair2)
{
	//��� ���� ����
	if (count == num_human)
	{
		int temp_timer = timer(stair1, stair2);
		shortest_time = min(shortest_time, temp_timer);
		//print_vector(stair1, stair2);
		//cout << "�ҿ� �ð� : " << temp_timer << "\n\n";
		//////////�ʱ�ȭ�� �ʿ��� �κ�//////////
		for (register int i = 0; i < MAX_HUMAN; ++i)
		{
			h[i].end_check = 0;
			h[i].wait_stair = 0;
			h[i].time_to_ground = 0;
		}
		for (register int i = 0; i < MAX_STAIR; ++i)
		{
			s[i].end_flag = 0;
			s[i].people_in_stair = 0;
		}
		//////////�ʱ�ȭ�� �ʿ��� �κ�//////////
		return;
	}
	//��� ���� �κ�
	else
	{
		stair1.push_back(count);
		dfs(count + 1, stair1, stair2);
		stair1.pop_back();

		stair2.push_back(count);
		dfs(count + 1, stair1, stair2);
		stair2.pop_back();
	}
}
int main(int argc, char** argv)
{
	freopen("s_input#lunch.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		init();
		int h_idx = 0;
		int s_idx = 0;
		for (register int r = 1; r <= N; ++r)
		{
			for (register int c = 1; c <= N; ++c)
			{
				cin >> map[r][c];
				if (map[r][c] == 1)
				{
					h[h_idx++] = { r, c, 0, 0, 0, 0 };
					num_human++;
				}
				else if (map[r][c] > 1)
				{
					s[s_idx++] = { r, c, map[r][c], 0, 0 };
				}
			}
		}
		vector<int> first_stair, second_stair;
		dfs(0, first_stair, second_stair);
		cout << "#" << test_case <<' '<<shortest_time<< '\n';
	}
	return 0;
}