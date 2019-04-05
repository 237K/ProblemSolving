//
//	OS Windows
//	2019.03.29
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <���� �����> (����)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const static int SIZE = 10;
const static int MAX_CUSTOMER = 1001;

struct CUSTOMER
{
	int num, arrival_time, num_reception, num_repair;
	bool operator< (const CUSTOMER& c) const
	{
		if (arrival_time == c.arrival_time)
			return c.num < num;
		else
			return c.arrival_time < arrival_time;
	}
};

struct RECEPTION
{
	int time, work_or_wait;
	CUSTOMER customer_info;
};

struct REPAIR
{
	int time, work_or_wait;
	CUSTOMER customer_info;
};

static int N, M, K, A, B;
static CUSTOMER customer[MAX_CUSTOMER];
static RECEPTION reception[SIZE];
static REPAIR repair[SIZE];
static priority_queue<CUSTOMER> reception_PQ;
static priority_queue<CUSTOMER> repair_PQ;
static vector<CUSTOMER> end_customer;

inline void Init()
{
	end_customer.clear();
	while (!reception_PQ.empty()) { reception_PQ.pop(); }
	while (!repair_PQ.empty()) { repair_PQ.pop(); }
	//(void)memset(customer, { 0, 0, 0, 0 }, sizeof(customer));
	//(void)memset(reception, { 0, 0 }, sizeof(reception));
	//(void)memset(repair, { 0, 0 }, sizeof(repair));
	for (register int k = 1; k <= K; ++k)
	{
		customer[k].num = k;
		customer[k].arrival_time = 0;
		customer[k].num_reception = 0;
		customer[k].num_repair = 0;
	}
	for (register int n = 1; n <= N; ++n)
	{
		reception[n].time = 0;
		reception[n].work_or_wait = 0;
		reception[n].customer_info.arrival_time = 0;
		reception[n].customer_info.num = 0;
		reception[n].customer_info.num_reception = 0;
		reception[n].customer_info.num_repair = 0;
	}
	for (register int m = 1; m <= M; ++m)
	{
		repair[m].time = 0;
		repair[m].work_or_wait = 0;
		repair[m].customer_info.arrival_time = 0;
		repair[m].customer_info.num = 0;
		repair[m].customer_info.num_reception = 0;
		repair[m].customer_info.num_repair = 0;
	}
}

inline int is_there_ready_customer()
{
	for (register int c = 1; c <= K; ++c)
	{
		if (!customer[c].arrival_time)
		{
			customer[c].arrival_time--;
			//cout << c << "�� �մ� �����ϼ̽��ϴ�." << endl;
			return c;
		}
	}
	return 0;
}

inline void customer_tiktok()
{
	for (register int c = 1; c <= K; ++c)
	{
		customer[c].arrival_time--;
	}
}

inline int is_there_available_reception()
{
	for (register int r = 1; r <= N; ++r)
	{
		if (!reception[r].work_or_wait)
		{
			return r;
		}
	}
	return 0;
}

inline void reception_tiktok()
{
	for (register int r = 1; r <= N; ++r)
	{
		if (reception[r].work_or_wait)
		{
			reception[r].work_or_wait++;
		}
		if (reception[r].time + 1 == reception[r].work_or_wait)
		{
			reception[r].work_or_wait = 0;
			customer[reception[r].customer_info.num].num_reception = r;
			repair_PQ.push(customer[reception[r].customer_info.num]);
			//cout << reception[r].customer_info.num << "�� �մ� ������ ������ �����⿭�� ���ϴ�." << endl;
		}
	}
}

inline int is_there_available_repair()
{
	for (register int r = 1; r <= M; ++r)
	{
		if (!repair[r].work_or_wait)
			return r;
	}
	return 0;
}

inline void repair_tiktok()
{
	for (register int r = 1; r <= M; ++r)
	{
		if (repair[r].work_or_wait)
		{
			repair[r].work_or_wait++;
		}
		if (repair[r].time + 1 == repair[r].work_or_wait)
		{
			repair[r].work_or_wait = 0;
			customer[repair[r].customer_info.num].num_repair = r;
			end_customer.push_back(customer[repair[r].customer_info.num]);
			//cout << repair[r].customer_info.num << "�� �մ� ���� ������ ������ �ۼ��Ϸ� ���ϴ�." << endl;
		}
	}
}

inline int find_wallet()
{
	//������, ���� ��� ��ģ ������Ʈ�� ���鼭 A, B ��
	int result = 0;

	//cout << A << "�� �����ǰ� " << B << "�� ����Ҹ� �̿��� ������ ";
	for (vector<CUSTOMER>::iterator iter = end_customer.begin(); iter != end_customer.end(); ++iter)
	{
		if (iter->num_reception == A && iter->num_repair == B)
		{
			//cout << iter->num << ' ';
			result += iter->num;
		}
	}
	//cout << "�Դϴ�. " << endl << endl;

	if (!result)
		return -1;
	else
		return result;
}

int tiktok = 0;
inline int car_repair()
{
	//cout << "time : " << tiktok << "h" << endl;
	while (1)
	{
		if (end_customer.size() == K)
			break;
		else
		{
			//������ �մ� ������ť�� �ִ� �κ�
			while (1)
			{
				int ready_customer = is_there_ready_customer();
				if (!ready_customer)
					break;
				else
				{
					reception_PQ.push(customer[ready_customer]);
					//cout << ready_customer << "�� �մ� ������ ��⿭�� ���ϴ�." << endl;
				}
			}
			customer_tiktok();

			//������ �κ�
			while (1)
			{
				int available_reception = is_there_available_reception();
				if (!available_reception || reception_PQ.empty())
					break;
				else
				{
					CUSTOMER cur_reception_customer = reception_PQ.top();
					reception_PQ.pop();
					reception[available_reception].customer_info.num = cur_reception_customer.num;
					reception[available_reception].work_or_wait++;
					//cout << cur_reception_customer.num << "�� �մ� " << available_reception << "�� ���������� ���ϴ�." << endl;
				}
			}
			reception_tiktok();

			//���� �κ�
			while (1)
			{
				int available_repair = is_there_available_repair();
				if (!available_repair || repair_PQ.empty())
					break;
				else
				{
					CUSTOMER cur_repair_customer = repair_PQ.top();
					repair_PQ.pop();
					repair[available_repair].customer_info.num = cur_repair_customer.num;
					repair[available_repair].work_or_wait++;
					//cout << cur_repair_customer.num << "�� �մ� " << available_repair << "�� ����ҷ� ���ϴ�." << endl;
				}
			}
			repair_tiktok();
		}
		tiktok++;
	}

	return find_wallet();
}

int main(int argc, char** argv)
{
	freopen("s_input#CarRepair.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K >> A >> B;
		Init();
		for (register int n = 1; n <= N; ++n)
			cin >> reception[n].time;
		for (register int m = 1; m <= M; ++m)
			cin >> repair[m].time;
		for (register int c = 1; c <= K; ++c)
		{
			cin >> customer[c].arrival_time;
		}
		cout << "#" << test_case << ' ' << car_repair() << '\n';
	}
	return 0;
}