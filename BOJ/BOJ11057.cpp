/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : ������ ��
		Problem Number     : 11057
		algorithm          : dynamic programming
=============================================================================
		History
		---------------------------------------------------------------------
		jee9894 : 2019.12.13 create
		----------------------------------------------------------------------
=============================================================================
		Note.
****************************************************************************/
#include <iostream>

using namespace std;

#define MAX_SIZE 1001
#define MODULER 10007

unsigned int dp[MAX_SIZE][10];

unsigned int MakeAscentNum(int num)
{
	for (int i = 0; i < 10; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= num; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = j; k < 10; ++k)
			{
				// �Ǿ��� ���� �ڱ��ڽź��� ũ�ų� ���� ����� ���� ��� �����ָ� �ȴ�
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MODULER;
			}
		}
	}

	unsigned int sum = 0;

	for (int i = 0; i < 10; ++i)
	{
		sum += dp[num][i];
		sum %= MODULER;
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TestCase;
	cin >> TestCase;

	unsigned int answer = MakeAscentNum(TestCase);
	cout << answer << "\n";
}
