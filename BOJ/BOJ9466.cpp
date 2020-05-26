/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 텀 프로젝트
		Problem Number     : 9466
		algorithm          : Graph traversal
=============================================================================
		History
		---------------------------------------------------------------------
		jee9894 : 2019.12.29 create
		----------------------------------------------------------------------
=============================================================================
		Note.
****************************************************************************/
#include <iostream>

using namespace std;

#define MAX_SIZE 100001

int wanted[MAX_SIZE];
bool visited[MAX_SIZE];
// 더이상 노드를 방문하지 않을것을 확인하는 배열
bool confirm[MAX_SIZE];
int cnt;

void DFS(int num)
{
	visited[num] = true;

	int next = wanted[num];
	if (visited[next] != true)
	{
		DFS(next);
	}
	// 한번 방문했던 노드인데 다시 방문했다 -> confirm배열이 false이다 -> 사이클이 존재한다
	else if (confirm[next] != true)
	{
		// 이번 노드에 대한 카운트
		cnt++;
		// 나와 같은 노드를 또다시 탐색할때까지 카운트
		for (int i = next; i != num; i = wanted[i]) 
		{
			cnt++;
		}
	}
	// 이번 노드는 더이상 방문하지 않은것임
	confirm[num] = true;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		for (int i = 1; i < MAX_SIZE; ++i)
		{
			wanted[i] = cnt = 0;
			visited[i] = confirm[i] = false;
		}

		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i) 
		{
			cin >> wanted[i];
		}

		for (int i = 1; i <= N; ++i)
		{
			if (visited[i] != true)
			{
				DFS(i);
			}
		}

		cout << N - cnt << "\n";
	}
}