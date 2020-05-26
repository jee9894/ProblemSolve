#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	unordered_map<string, int> hash_map;

	// �ؽ� ���̺� ����
	// �ǻ� �̸��� �׻� �ٸ��Ƿ� ������ �����ϸ� �ȴ�
	for (int i = 0; i < clothes.size(); ++i)
	{
		if (hash_map.find(clothes[i][1]) == hash_map.end())
		{
			hash_map[clothes[i][1]] = 1;
		}
		else
		{
			hash_map[clothes[i][1]]++;
		}
	}

	int temp = 1;
	unordered_map<string, int>::iterator iter;
	for (iter = hash_map.begin(); iter != hash_map.end(); ++iter)
	{
		// ��� ����� ���� ����
		temp *= (iter->second + 1);
	}

	answer = temp - 1;
	return answer;
}