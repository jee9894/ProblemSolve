/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : DFS와 BFS
		Problem Number     : 1260
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
#include <stack>
#include <queue>

using namespace std;

#define MAX_SIZE 1001

// 정점의 갯수 : N
// 간선의 갯수 : M
// 탐색을 시작할 정점의 번호 : V
int N, M, V;
int adjMat[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE];

void dfs()
{
	int v = V;
	stack<int> s;
	s.push(v);
	cout << s.top() << ' ';
	visit[v] = true;
	while (false == s.empty())
	{
		v = s.top();
		bool searchingFlag = false;
		for (int i = 1; i <= N; ++i)
		{
			if (1 == adjMat[v][i] && false == visit[i])
			{
				s.push(i);
				cout << s.top() << ' ';
				visit[i] = true;
				searchingFlag = true;
				break;
			}
		}
		if (false == searchingFlag)
			s.pop();
	}
	cout << '\n';
}

void bfs()
{
	int v = V;
	queue<int> q;
	q.push(v);
	visit[v] = true;
	while (false == q.empty())
	{
		v = q.front();
		cout << v << ' ';
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

	cin >> N >> M >> V;

	for (int i = 0; i < M; ++i)
	{
		int x, y;
		cin >> x >> y;
		adjMat[x][y] = adjMat[y][x] = 1;
	}

	dfs();

	for (int i = 1; i < MAX_SIZE; ++i)
		visit[i] = false;

	bfs();
}
