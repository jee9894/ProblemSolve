#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int triangle[100][100];
int cache[100][100];
int triNum;

int path(int y, int x)
{
	if (y == triNum - 1) return triangle[y][x];

	int &result = cache[y][x];

	if (result != -1) return result;

	return result = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
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
		memset(cache, -1, sizeof(cache));
		cin >> triNum;

		for (int j = 0; j < triNum; ++j)
			for (int k = 0; k < j + 1; ++k)
				cin >> triangle[j][k];
		cout << path(0, 0) << endl;
	}

	return 0;
}