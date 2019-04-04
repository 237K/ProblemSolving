//
//	OS Windows
//	2019.04.02
//
//	[Algorithm Problem Solving]
//
//	SAMSUNG SW Expert Academy [#7333] <한솔이의 택배 아르바이트> (D4)
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

const static int MAX = 101;
static int N;
static vector<int> box;

inline int plan()
{
	if (N == 1)
		return 1;
	sort(box.begin(), box.end(), greater<int>());
	int front = -1;
	int rear = N - 1;
	int answer = 0;
	while (front < rear)
	{
		front++;
		if (front == rear)
		{
			break;
		}
		if (box[front] >= 50)
		{
			answer++;
		}
		else if (box[front] >= 25 && box[front] < 50)
		{
			rear -= 1;
			answer++;
		}
		else if (box[front] >= 17 && box[front] < 25)
		{
			rear -= 2;
			answer++;
		}
		else if (box[front] >= 13 && box[front] < 17)
		{
			rear -= 3;
			answer++;
		}
		else if (box[front] >= 10 && box[front] < 13)
		{
			rear -= 4;
			answer++;
		}
		else if (box[front] == 9)
		{
			rear -= 5;
			answer++;
		}
		else if (box[front] == 8)
		{
			rear -= 6;
			answer++;
		}
		else if (box[front] == 7)
		{
			rear -= 7;
			answer++;
		}
		else if (box[front] == 6)
		{
			rear -= 8;
			answer++;
		}
		else if (box[front] == 5)
		{
			rear -= 9;
			answer++;
		}
		else if (box[front] == 4)
		{
			rear -= 12;
			answer++;
		}
		else if (box[front] == 3)
		{
			rear -= 16;
			answer++;
		}
		else if (box[front] == 2)
		{
			rear -= 24;
			answer++;
		}
		else if (box[front] == 1)
		{
			rear -= 49;
			answer++;
		}
	}
	return answer;
}

int main(int argc, char** argv)
{
	freopen("s_input7333.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		box.clear();
		cin >> N;
		for (register int n = 0; n < N; ++n)
		{
			int w = 0;
			cin >> w;
			box.push_back(w);
		}
		cout << "#" << test_case << ' ' << plan() << '\n';
	}
	return 0;
}