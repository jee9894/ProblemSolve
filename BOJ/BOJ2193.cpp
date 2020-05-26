/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 이친수
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
		// i-1번째 자릿수가 0일때 뒤에 올 수 있는수는 0,1
		// i-1번째 자릿수가 1일때 뒤에 올 수 있는수는 0
		// 맨뒤에 0이 오는 수 만큼 경우의 수 증가
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
