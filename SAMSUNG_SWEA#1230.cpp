//
//	OS Windows
//	2019.04.07
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy <#1230> ¾ÏÈ£¹®3 (D3)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
const static int T = 10;

inline void print(const vector<int>& v)
{
	for (register int i = 0; i < 10; ++i)
		cout << v[i] << ' ';
	cout << '\n';
}

int main(int argc, char** argv)
{
	freopen("s_input1230.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (register int test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> Cryptogram;
		int length = 0, n = 0, num_order = 0, i_loc = 0, i_num = 0, i_temp = 0, d_loc = 0, d_num = 0, a_num = 0, a_temp = 0;
		char order;

		cin >> length;
		for (register int i = 0; i < length; ++i)
		{
			cin >> n;
			Cryptogram.push_back(n);
		}
		cin >> num_order;
		for (register int o = 0; o < num_order; ++o)
		{
			cin >> order;
			switch (order)
			{
			case 'I':
				cin >> i_loc >> i_num;
				for (register int n = 0; n < i_num; ++n)
				{
					cin >> i_temp;
					Cryptogram.insert(Cryptogram.begin() + i_loc+n, i_temp);
				}
				break;
			case 'D':
				cin >> d_loc >> d_num;
				Cryptogram.erase(Cryptogram.begin() + d_loc + 1, Cryptogram.begin() + d_loc + 1 + d_num);
				break;
			case 'A':
				cin >> a_num;
				for (register int n = 0; n < a_num; ++n)
				{
					cin >> a_temp;
					Cryptogram.push_back(a_temp);
				}
				break;
			}
		}
		cout << "#" << test_case << ' '; print(Cryptogram);
	}
	return 0;
}