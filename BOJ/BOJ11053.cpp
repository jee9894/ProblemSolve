/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : ���� �� �����ϴ� �κ� ����
		Problem Number     : 11053
		algorithm          : dynamic programming
=============================================================================
		History
		---------------------------------------------------------------------
		jee9894 : 2019.12.17 create
		----------------------------------------------------------------------
=============================================================================
		Note.
****************************************************************************/
#include <iostream>

using namespace std;

#define MAX_SIZE 1001

unsigned int dp[MAX_SIZE];
unsigned int seq[MAX_SIZE];

unsigned int MakeLongestSeq(int num)
{
	dp[1] = 1;

	// �迭�� ó������ ���� ������ �������� ã�� dp�迭���� ���� ū ���� ã�� 1 ������
	for (int i = 2; i <= num; ++i)
	{
		unsigned int max = 0;
		for (int j = 1; j < i; ++j)
		{
			if (seq[j] < seq[i])
			{
				if (max < dp[j])
				{
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1;
	}

	// dp�迭�� ����ū �� ����
	unsigned int ret = 0;
	for (int i = 1; i < MAX_SIZE; ++i)
	{
		if (dp[i] > ret)
		{
			ret = dp[i];
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TestCase;
	cin >> TestCase;

	for (int i = 1; i <= TestCase; ++i)
	{
		cin >> seq[i];
	}

	unsigned int answer = MakeLongestSeq(TestCase);
	cout << answer << "\n";
}
