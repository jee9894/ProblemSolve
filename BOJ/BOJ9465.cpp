/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 스티커
		Problem Number     : 9465
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

#define MAX_SIZE 100001

unsigned int dp[MAX_SIZE][2];
unsigned int sticker[MAX_SIZE][2];

unsigned int MakeMaxScore(int num)
{
	// 초기화
	for (int i = 0; i <= num; ++i)
	{
		dp[i][0] = dp[i][1] = 0;
	}

	dp[1][0] = sticker[1][0];
	dp[1][1] = sticker[1][1];

	for (int i = 2; i <= num; ++i)
	{
		// 대각선 방향으로 i-1 번째 자릿수의 수를 더한경우, i-2번째 자릿수의 수를 더한경우 중 더 큰 수 저장
		unsigned int X = sticker[i][0] + dp[i - 1][1];
		unsigned int Y = sticker[i][0] + dp[i - 2][1];
		dp[i][0] = X >= Y ? X : Y;

		X = sticker[i][1] + dp[i - 1][0];
		Y = sticker[i][1] + dp[i - 2][0];
		dp[i][1] = X >= Y ? X : Y;
	}

	return dp[num][0] >= dp[num][1] ? dp[num][0] : dp[num][1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TestCase;
	cin >> TestCase;

	int num;
	for (int i = 0; i < TestCase; ++i)
	{
		cin >> num;
		for (int j = 1; j <= num; ++j)
		{
			cin >> sticker[j][0];
		}
		for (int j = 1; j <= num; ++j)
		{
			cin >> sticker[j][1];
		}

		unsigned int answer = MakeMaxScore(num);
		cout << answer << "\n";
	}
}
