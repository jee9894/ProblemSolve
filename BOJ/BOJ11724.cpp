/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 연결 요소의 개수
		Problem Number     : 11724
		algorithm          : graph traversal
=============================================================================
		History
		---------------------------------------------------------------------
		jee9894 : 2019.12.18 create
		----------------------------------------------------------------------
=============================================================================
		Note.
****************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 1001

int N, M;
int adjMat[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE];

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visit[v] = true;
	while (false == q.empty())
	{
		v = q.front();
		q.pop();
		for (int i = 1; i <= N; ++i)
		{
			if (0 == adjMat[v][i] || true == visit[i])
				continue;
			q.push(i);
			visit[i] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= M; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjMat[u][v] = adjMat[v][u] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (false == visit[i])
		{
			bfs(i);
			cnt++;
		}
	}
	cout << cnt << "\n";
}
