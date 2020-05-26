/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : ������ �ý�
		Problem Number     : 2156
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

#define MAX_SIZE 10001

unsigned int dp[MAX_SIZE];
unsigned int wine[MAX_SIZE];

unsigned int MakeMaxWine(int num)
{
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= num; ++i)
	{
		// ������ �����ֿ� �ٷ� ������ �����ָ� ���Ű�� 
		unsigned int X = wine[i] + wine[i - 1] + dp[i - 3];
		// ������ �����ֿ� ���� �����ִ� ���Ű��
		unsigned int Y = wine[i] + dp[i - 2];
		// ������ �����ָ� ������ �ʴ°��
		unsigned int Z = dp[i - 1];
		dp[i] = X > Y ? (Z > X ? Z : X) : (Z > Y ? Z : Y);
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

	for (int i = 1; i <= TestCase; ++i)
	{
		cin >> wine[i];
	}

	unsigned int answer = MakeMaxWine(TestCase);
	cout << answer << "\n";
}
