#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	// ���ĵǾ� ������ �������� ���� ������ �ѹ��� �� ������ ã�Ƴ� �� �ִ�
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	string answer;

	for (int i = 0; i < participant.size(); ++i) {
		// ���ĵǾ� �����Ƿ� participant�� completion�� ó������ �ٸ��κ��� �������� ���� �����̴�
		if (participant[i] != completion[i]) {
			answer = participant[i];
			break;
		}
	}

	// �ؽ� �����ε� �ؽ÷� Ǯ�� ����
	return answer;
}