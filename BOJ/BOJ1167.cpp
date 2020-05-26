/****************************************************************************
                        jee9894's Problem Solve Study
=============================================================================
        Problem Name       : 트리의 지름
        Problem Number     : 1167
        algorithm          : Graph traversal
=============================================================================
        History
        ---------------------------------------------------------------------
        jee9894 : 2020.01.01 create
        ----------------------------------------------------------------------
=============================================================================
        Note.
****************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 100001

vector< pair<int, int> > adjList[MAX_SIZE];
int diameter[MAX_SIZE];
bool visited[MAX_SIZE];

void DFS(int num)
{
	visited[num] = true;

	for (int i = 0; i < adjList[num].size(); ++i)
	{
		int next = adjList[num][i].first;
		int weight = adjList[num][i].second;

		if (visited[next] == false)
		{
			// 누적 가중치 + 부모 노드와의 가중치
			diameter[next] = diameter[num] + weight;
			DFS(next);
		}
	}
		
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int node;
		cin >> node;

		while (1)
		{
			int v, w;
			cin >> v;
			if (v == -1) break;
			cin >> w;
			adjList[node].push_back(make_pair(v, w));
		}
		
	}

	// 임의의 정점 1에서 시작하여 제일 거리가 긴 정점 찾고 visited, diameter 초기화
	DFS(1);
	int res = 0, temp;
	for (int i = 1; i <= N; ++i)
	{
		if (res < diameter[i])
		{
			res = diameter[i];
			temp = i;
		}
		
		visited[i] = false;
		diameter[i] = 0;
	}

	// 임의의 정점에서 가장 거리가 긴 정점에서 다시 거리가 긴 정점을 찾으면 트리의 지름
	DFS(temp);
	for (int i = 1; i <= N; ++i)
	{
		if (res < diameter[i])
		{
			res = diameter[i];
		}
	}

	cout << res << "\n";
}