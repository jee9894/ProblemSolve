/****************************************************************************
						jee9894's Problem Solve Study
=============================================================================
		Problem Name       : 단지번호붙이기
		Problem Number     : 2667
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
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_SIZE 27

bool visited[MAX_SIZE][MAX_SIZE];
int dangee[MAX_SIZE][MAX_SIZE];
int cnt;

void DFS(int row, int col)
{
	visited[row][col] = true;
	cnt++;
	// 상하좌우 탐색
	if (visited[row - 1][col] == false && dangee[row - 1][col] == 1)
	{
		DFS(row - 1, col);
	}
	if (visited[row][col - 1] == false && dangee[row][col - 1] == 1)
	{
		DFS(row, col - 1);
	}
	if (visited[row + 1][col] == false && dangee[row + 1][col] == 1)
	{
		DFS(row + 1, col);
	}
	if (visited[row][col + 1] == false && dangee[row][col + 1] == 1)
	{
		DFS(row, col + 1);
	}
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
		string temp;
		cin >> temp;
		for (int j = 1; j <= N; ++j) 
		{
			dangee[i][j] = temp[j - 1] - '0';
		}
	}

	vector<int> answer;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j)
		{
			if (visited[i][j] == false && dangee[i][j] == 1)
			{
				DFS(i, j);
				if (cnt > 0)
				{
					answer.push_back(cnt);
					cnt = 0;
				}
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << "\n";
	}
}