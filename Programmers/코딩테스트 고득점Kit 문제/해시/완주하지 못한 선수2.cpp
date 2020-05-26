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
			// ���������϶� value�� +1
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
			// ���������� ����� ��Ͽ� ���°�� ����
			if (hash[participant[i]] == 0) {
				answer = participant[i];
				break;
			}
			// ���������� ����� ��� value�� -1
			hash[participant[i]]--;
		}
	}
	return answer;
}