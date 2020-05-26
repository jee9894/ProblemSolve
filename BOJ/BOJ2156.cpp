/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 포도주 시식
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
		// 지금의 포도주와 바로 이전의 포도주를 마신경우 
		unsigned int X = wine[i] + wine[i - 1] + dp[i - 3];
		// 지금의 포도주와 전전 포도주는 마신경우
		unsigned int Y = wine[i] + dp[i - 2];
		// 지금의 포도주를 마시지 않는경우
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
