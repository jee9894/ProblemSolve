#include <iostream>
#include <vector>

using namespace std;

const int coverType[4][3][2] = 
{
	{{0,0},{1,0},{0,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{0,1},{-1,1}}
};

bool set(vector< vector<int> > &board, int x, int y, int type, int delta)
{
	bool result = true;
	
	for (int i = 0; i < 3; ++i)
	{
		int nx = x + coverType[type][i][0];
		int ny = y + coverType[type][i][1];
		if (nx < 0 || ny < 0 || nx >= board[0].size() || ny >= board.size())
			result = false;
		else if ((board[ny][nx] += delta) > 1)
			result = false;
	}

	return result;
}

int cover(vector< vector<int> > &board)
{
	int startX = -1, startY = -1;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == 0)
			{
				startX = j;
				startY = i;
				break;
			}
		}
		if (startX != -1) break;
	}

	if (startX == -1) return 1;

	int ret = 0;
	for (int type = 0; type < 4; ++type)
	{
		if (set(board, startX, startY, type, 1))
			ret += cover(board);
		set(board, startX, startY, type, -1);
	}
	return ret;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(false);
	cout.tie(false);

	int testCase;
	cin >> testCase;

	
	for (int i = 0; i < testCase; ++i)
	{
		int h, w, cnt = 0;
		cin >> h >> w;
		vector< vector<int> > board(h);
		for (int j = 0; j < h; ++j)
		{
			for (int k = 0; k < w; ++k)
			{
				char input;
				cin >> input;
				if (input == '#') board[j].push_back(1);
				else 
				{
					board[j].push_back(0);
					cnt++;
				}
			}
		}
		if (cnt % 3 == 0)
			cout << cover(board) << endl;
		else
			cout << 0 << endl;
	}
}