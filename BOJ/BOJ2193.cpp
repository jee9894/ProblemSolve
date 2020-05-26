/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : ��ģ��
		Problem Number     : 2193
		algorithm          : dynamic programming
=============================================================================
		History
		---------------------------------------------------------------------
		jee9894 : 2019.12.16 create
		----------------------------------------------------------------------
=============================================================================
		Note.
****************************************************************************/
#include <iostream>

using namespace std;

#define MAX_SIZE 91

unsigned long long dp[MAX_SIZE];

unsigned long long MakePinaryNum(int num)
{
	dp[1] = dp[2] = 1;

	for (int i = 3; i <= num; ++i)
	{
		// i-1��° �ڸ����� 0�϶� �ڿ� �� �� �ִ¼��� 0,1
		// i-1��° �ڸ����� 1�϶� �ڿ� �� �� �ִ¼��� 0
		// �ǵڿ� 0�� ���� �� ��ŭ ����� �� ����
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[num];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TestCase;
	cin >> TestCase;

	unsigned long long answer = MakePinaryNum(TestCase);
	cout << answer << "\n";
}
