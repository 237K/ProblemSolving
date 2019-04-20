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
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	multimap<string, bool> mm;
	int p_size = participant.size();
	for (register int i = 0; i < p_size; ++i)
		mm.insert(pair<string, bool>(participant[i], false));

	multimap<string, bool>::iterator find_iter;

	for (auto iter = completion.begin(); iter != completion.end(); ++iter)
	{
		find_iter = mm.find(*iter);
		find_iter->second = true;
	}

	for (auto iter = mm.begin(); iter != mm.end(); ++iter)
	{
		if (!iter->second)
		{
			answer = iter->first;
			//cout << answer << '\n';
			break;
		}
	}
	return answer;
}