/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 쉬운 계단수
		Problem Number     : 10844
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

#define MAX_SIZE 101
#define MODULER 1000000000

unsigned int dp[MAX_SIZE][10];

unsigned int MakeStairNum(int num)
{
	dp[1][0] = 0;
	dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = dp[1][7] = dp[1][8] = dp[1][9] = 1;

	for (int i = 2; i <= num; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 0)
			{
				// 뒤에서 2번째 자릿수가 0일때 맨뒤에 올 수 있는 수는 1밖에 없음
				dp[i][0] = dp[i - 1][1] % MODULER;
			}
			else if (j == 9)
			{
				// 뒤에서 2번째 자릿수가 9일때 맨뒤에 올 수 있는 수는 8밖에 없음
				dp[i][9] = dp[i - 1][8] % MODULER;
			}
			else
			{
				// 뒤에서 2번째 자릿수가 1~8이면 맨뒤에 올 수 있는 수는 -1,+1한 값
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MODULER;
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

	unsigned int answer = MakeStairNum(TestCase);

	cout << answer << "\n";
}
