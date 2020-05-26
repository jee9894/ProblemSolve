#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	// 정렬되어 있으면 완주하지 못한 선수를 한번만 쭉 훑으면 찾아낼 수 있다
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	string answer;

	for (int i = 0; i < participant.size(); ++i) {
		// 정렬되어 있으므로 participant와 completion가 처음으로 다른부분이 완주하지 못한 선수이다
		if (participant[i] != completion[i]) {
			answer = participant[i];
			break;
		}
	}

	// 해시 문제인데 해시로 풀지 않음
	return answer;
}