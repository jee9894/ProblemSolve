/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 1,2,3 ���ϱ�
		Problem Number     : 9095
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

#define MAX_SIZE 11

unsigned int dp[MAX_SIZE];

void PlusOneTwoThree()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX_SIZE; ++i)
	{
		// i��° ����� �� =
		// i-1��° ���� +1�� ����� �� +
		// i-2��° ���� +2�� ����� �� +
		// i-3��° ���� +3�� ����� ��
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	PlusOneTwoThree();

	int TestCase;
	cin >> TestCase;
	for (int i = 0; i < TestCase; ++i)
	{
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
}
