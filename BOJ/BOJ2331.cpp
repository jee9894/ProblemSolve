/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 반복수열
		Problem Number     : 2331
		algorithm          : graph traversal
=============================================================================
		History
		---------------------------------------------------------------------
		jee9894 : 2019.12.20 create
		----------------------------------------------------------------------
=============================================================================
		Note.
****************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

// 최대 = (9*9*9*9*9)*4 = 236196
#define MAX_SIZE 236197

int visit[MAX_SIZE];

void dfs(int v, int p)
{
	visit[v]++;
	if (visit[v] > 2)
		return;
	int num = v, sum = 0;
	while (num)
	{
		sum += (int)floor(pow(num % 10, p) + 0.5);
		num /= 10;
	}
	dfs(sum, p);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, P, sum = 0, ret = -1;
	cin >> A >> P;

	dfs(A, P);

	int result = 0;
	for (int i = 1; i < MAX_SIZE; ++i)
	{
		if (visit[i] == 1) result++;
	}
	cout << result << '\n';
}
