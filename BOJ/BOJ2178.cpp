/****************************************************************************
                        jee9894's Problem Solve Study
=============================================================================
        Problem Name       : ¹Ì·Î Å½»ö
        Problem Number     : 2178
        algorithm          : Graph traversal
=============================================================================
        History
        ---------------------------------------------------------------------
        jee9894 : 2019.12.30 create
        ----------------------------------------------------------------------
=============================================================================
        Note.
****************************************************************************/
#include <cstdio>
#include <queue>
using namespace std;

#define MAX_SIZE 101

int maze[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int coord[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int BFS(int n, int m)
{
	queue< pair< pair<int, int>, int > > q;
	q.push(make_pair(make_pair(1, 1), 1));
	visited[1][1] = true;

	while (q.empty() == false)
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int temp_x = x + coord[i][0];
			int temp_y = y + coord[i][1];

			if (temp_x <= 0 || temp_y <= 0 || temp_x > n || temp_y > m)
			{
				continue;
			}
			if (temp_x == n && temp_y == m)
			{
				return z + 1;
			}
			if (visited[temp_x][temp_y] == false && maze[temp_x][temp_y] == 1)
			{
				q.push(make_pair(make_pair(temp_x, temp_y), z + 1));
				visited[temp_x][temp_y] = true;
			}
		}
	}
}

int main() 
{
	int M, N;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	printf("%d\n", BFS(N, M));
}