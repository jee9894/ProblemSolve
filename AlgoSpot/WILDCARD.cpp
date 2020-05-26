#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[101][101];
string W, S;

bool check(int w, int s)
{
	int &result = cache[w][s];
	if (result != -1) return result;

	while (s < S.size() && w < W.size() && (W[w] == S[s] || W[w] == '?'))
		return result =	check(w + 1, s + 1);
	
	if (w == W.size()) return result = (s == S.size());

	if (W[w] == '*')
		if (check(w + 1, s) || (s < S.size() && check(w, s + 1)))
			return result = 1;
	return result = 0;
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
		vector<string> v;
		int input; 
		cin >> W >> input;
		for (int j = 0; j < input; ++j)
		{
			cin >> S;
			memset(cache, -1, sizeof(cache));
			if (check(0, 0))
				v.push_back(S);
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); ++j)
			cout << v[j] << endl;
	}

	return 0;
}