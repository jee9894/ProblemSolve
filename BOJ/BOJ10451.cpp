/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 순열 사이클
		Problem Number     : 10451
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
#include <vector>

using namespace std;

#define MAX_SIZE 1001

vector<int> adjList[MAX_SIZE];
int visit[MAX_SIZE];
int cnt;
int N;

void dfs(int v)
{
	visit[v] = 1;
	for (int i = 0; i < adjList[v].size(); ++i)
	{
		if (visit[adjList[v][i]] == 0)
		{
			dfs(adjList[v][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TestCase;
	cin >> TestCase;

	for (int i = 0; i < TestCase; ++i)
	{
		for (int j = 1; j < MAX_SIZE; ++j)
		{
			visit[j] = 0;
			adjList[j].clear();
			cnt = 0;
		}
		cin >> N;
		for (int j = 1; j <= N; ++j)
		{
			int temp;
			cin >> temp;
			adjList[j].push_back(temp);
		}
		for (int j = 1; j <= N; ++j)
		{
			if (visit[j] == 0)
			{
				dfs(j);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
}
