/****************************************************************************
                        jee9894's Problem Solve Study
=============================================================================
        Problem Name       : 트리의 부모 찾기
        Problem Number     : 11725
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

vector<int> adjList[MAX_SIZE];
int parent[MAX_SIZE];
bool visited[MAX_SIZE];

void DFS(int num)
{
	visited[num] = true;

	for (int i = 0; i < adjList[num].size(); ++i)
	{
		int next = adjList[num][i];

		if (visited[next] == false)
		{
			parent[next] = num;
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

	for (int i = 0; i < N - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	DFS(1);
	
	for (int i = 2; i <= N; ++i)
	{
		cout << parent[i] << "\n";
	}
}