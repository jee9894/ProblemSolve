/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 이분 그래프
		Problem Number     : 1707
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
#include <vector>
#include <string>
using namespace std;

#define MAX_SIZE 20001

enum Color {
	RED = -1,
	BULE = 1
};

int K, V, E;
vector<int> adjList[MAX_SIZE];
int visit[MAX_SIZE];
string ret = "YES";

void dfs(int v, int color) {
	visit[v] = color;
	for (int i = 0; i < adjList[v].size(); ++i) {
		if (visit[adjList[v][i]] == 0) {
			dfs(adjList[v][i], color * -1);
		}
	}
}

int main()
{
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> V >> E;

		for (int j = 1; j <= V; ++j) {
			adjList[j].clear();
			visit[j] = 0;
			ret = "YES";
		}

		for (int j = 0; j < E; ++j) {
			int u, v;
			cin >> u >> v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}

		for (int j = 1; j <= V; ++j) {
			if (visit[j] == 0) {
				dfs(j, RED);
			}
		}

		for (int j = 1; j <= V; ++j) {
			for (int k = 0; k < adjList[j].size(); ++k) {
				if (visit[adjList[j][k]] == visit[j])
					ret = "NO";
			}
		}
		cout << ret << '\n';
	}
}