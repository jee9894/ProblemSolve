/****************************************************************************
                        jee9894's Problem Solve Study
=============================================================================
        Problem Name       : 토마토
        Problem Number     : 7576
        algorithm          : Graph traversal
=============================================================================
        History
        ---------------------------------------------------------------------
        jee9894 : 2019.12.30 create
        ----------------------------------------------------------------------
=============================================================================
        Note.
****************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int coord[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;
	vector< vector<int> > tomatos(N, vector<int>(M, 0));
	vector< vector<int> > visited(N, vector<int>(M, 0));
	queue< pair<int, int> > q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> tomatos[i][j];
			if (tomatos[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
		}
	}

	int days = 0;
	while (1)
	{
		queue< pair<int, int> > temp;
		// BFS 부분
		while (q.empty() == false)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			visited[x][y] = true;

			for (int i = 0; i < 4; ++i)
			{
				int temp_x = x + coord[i][0];
				int temp_y = y + coord[i][1];
				if ((temp_x > -1 && temp_y > -1) && (temp_x < N && temp_y < M))
				{
					if (visited[temp_x][temp_y] == false && tomatos[temp_x][temp_y] == 0)
					{
						temp.push(make_pair(temp_x, temp_y));
						tomatos[temp_x][temp_y] = 1;
					}
				}
			}
		}
		// 큐에 들어가있던 토마토들 상하좌우 탐색이 모두 끝나면 day + 1
		q = temp;
		if (q.empty() == true) break;
		days++;
	}
	
	// 모든 조사를 마쳤는데 0이 남아있으면 익을수 없는 조건
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (tomatos[i][j] == 0)
			{
				days = -1;
			}
		}
	}

	cout << days << "\n";
}