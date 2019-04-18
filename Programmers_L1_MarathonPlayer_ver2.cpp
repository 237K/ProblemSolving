//
//	[ Algorithm problem solving ]
//	
//	OS Windows
//	2019.04.16
//
//	[Programmers] <완주하지 못한 선수>
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (vector<string>::size_type i = 0; i < completion.size(); ++i)
	{
		if (participant[i] != completion[i])
		{
			answer = participant[i];
			return answer;
		}
	}
	int size = participant.size();
	answer = participant[size - 1];
	return answer;
}