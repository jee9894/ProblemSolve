#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> hash;
	for (int i = 0; i < completion.size(); ++i) {
		if (hash.find(completion[i]) == hash.end()) {
			hash.insert(make_pair(completion[i], 1));
		}
		else {
			// 동명이인일때 value값 +1
			hash[completion[i]]++;
		}
	}

	string answer;
	for (int i = 0; i < participant.size(); ++i) {
		if (hash.find(participant[i]) == hash.end()) {
			answer = participant[i];
			break;
		}
		else {
			// 동명이인이 통과자 목록에 없는경우 정답
			if (hash[participant[i]] == 0) {
				answer = participant[i];
				break;
			}
			// 동명이인이 통과한 경우 value값 -1
			hash[participant[i]]--;
		}
	}
	return answer;
}