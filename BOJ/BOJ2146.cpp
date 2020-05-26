/****************************************************************************
                        jee9894's Problem Solve Study
=============================================================================
        Problem Name       : 다리 만들기
        Problem Number     : 2146
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
#include <queue>
#include <cmath>
using namespace std;

#define MAX_SIZE 101

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int coord[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

// 육지를 저장할 큐
queue< pair< pair<int, int>, int> > q;

// DFS로 육지의 번호매김
void MakeLandNum(int x, int y, int landNum)
{
	visited[x][y] = true;
	q.push(make_pair(make_pair(x, y), landNum));

	for (int i = 0; i < 4; ++i)
	{
		int temp_x = x + coord[i][0];
		int temp_y = y + coord[i][1];

		if (temp_x<1 || temp_x>MAX_SIZE || temp_y<1 || temp_y>MAX_SIZE)
			continue;

		if (visited[temp_x][temp_y] == true || map[temp_x][temp_y] == 0)
			continue;

		MakeLandNum(temp_x, temp_y, landNum);
	}
}

// BFS로 최단거리 찾음
int SearchMinLen()
{
	int bridgeLen = 200;

	while (q.empty() == false)
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int landNum = q.front().second;
		q.pop();

		queue< pair< pair<int, int>, int> > temp = q;
		while (temp.empty() == false)
		{
			int temp_x = temp.front().first.first;
			int temp_y = temp.front().first.second;
			int temp_landNum = temp.front().second;
			temp.pop();

			if (landNum == temp_landNum) 
				continue;

			int res = abs(temp_x - x) + abs(temp_y - y) - 1;
			bridgeLen = bridgeLen > res ? res : bridgeLen;
		}
	}
	return bridgeLen;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];
		}
	}

	int landNum = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (visited[i][j] == false && map[i][j] == 1)
			{
				MakeLandNum(i, j, landNum);
				landNum++;
			}
		}
	}

	cout << SearchMinLen() << "\n";
}