/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 2x 타일링
		Problem Number     : 11726
		algorithm          : dynamic programming
=============================================================================
		History
		---------------------------------------------------------------------
		jee9894 : 2019.12.12 create
		----------------------------------------------------------------------
=============================================================================
		Note.
****************************************************************************/
#include <iostream>

using namespace std;

#define MAX_SIZE 1001
#define MODULER 10007

unsigned int dp[MAX_SIZE];

void MakeTile(int n)
{
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i)
	{
		// n-1 크기에 1x2 타일을 하나 붙이는 경우의 수 + n-2 크기에 1x2타일을 2개 붙이는 경우의 수
		dp[i] = (dp[i - 1] + dp[i - 2]) % MODULER;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	MakeTile(num);
	cout << dp[num] << "\n";
}
