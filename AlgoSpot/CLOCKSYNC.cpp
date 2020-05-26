#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 9999
#define SWITCHES 10
#define CLOCKS 16

vector<vector<int> > switches({
	vector<int>({ 0, 1, 2 }),
	vector<int>({ 3, 7, 9, 11 }),
	vector<int>({ 4, 10, 14, 15 }),
	vector<int>({ 0, 4, 5, 6, 7 }),
	vector<int>({ 6, 7, 8, 10, 12 }),
	vector<int>({ 0, 2, 14, 15 }),
	vector<int>({ 3, 14, 15 }),
	vector<int>({ 4, 5, 7, 14, 15 }),
	vector<int>({ 1, 2, 3, 4, 5 }),
	vector<int>({ 3, 4, 5, 9, 13 })
	});

bool areAligned(vector<int> &clocks)
{
	for (int i = 0; i < clocks.size(); ++i)
		if (clocks[i] != 12) return false;
	return true;
}

void push(vector<int> &clocks, int swtch)
{
	for (int i = 0; i < switches[swtch].size(); ++i)
	{
		clocks[switches[swtch][i]] += 3;
		if (clocks[switches[swtch][i]] == 15) clocks[switches[swtch][i]] = 3;
	}
}

int makeSync(vector<int> &clocks, int swtch)
{
	if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt)
	{
		ret = min(ret, cnt + makeSync(clocks, swtch + 1));
		push(clocks, swtch);
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
		vector<int> clocks;
		for (int j = 0; j < 16; ++j)
		{
			int input;
			cin >> input;
			clocks.push_back(input);
		}
		int result = makeSync(clocks, 0);
		result < INF ? cout << result << endl : cout << -1 << endl;
	}
	return 0;
}