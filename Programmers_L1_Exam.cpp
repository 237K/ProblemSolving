//
//	[ Algorithm problem solving ]
//	
//	OS Windows
//	2019.04.16
//
//	[Programmers] <모의고사>
//

#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int one_ans[5] = { 1, 2, 3, 4, 5 };
	int two_ans[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int thr_ans[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int one = 0, two = 0, thr = 0;
	for (vector<int>::size_type i = 0; i < answers.size(); ++i)
	{
		if (answers[i] == one_ans[i % 5])   one++;
		if (answers[i] == two_ans[i % 8])   two++;
		if (answers[i] == thr_ans[i % 10])  thr++;
	}
	int num_ans[4] = { 0, one, two, thr };
	int top = max(max(two, thr), one);
	for (register int i = 1; i <= 3; ++i)
		if (top == num_ans[i])  answer.push_back(i);
	return answer;
}