#include <iostream>

using namespace std;

int n, m;
bool areFriends[10][10];

int countFriends(bool taken[10])
{
	int firstFriend = -1;
	for (int i = 0; i < n; ++i) 
		if (!taken[i])
		{
			firstFriend = i;
			break;
		}

	if (firstFriend == -1) return 1;

	int ret = 0;

	for (int secondFriend = firstFriend + 1; secondFriend < n; ++secondFriend)
	{
		if (!taken[secondFriend] && areFriends[firstFriend][secondFriend])
		{
			taken[firstFriend] = taken[secondFriend] = true;
			ret += countFriends(taken);
			taken[firstFriend] = taken[secondFriend] = false;
		}
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
		cin >> n >> m;
		for (int j = 0; j < m; ++j)
		{
			int p, q;
			cin >> p >> q;
			areFriends[p][q] = areFriends[q][p] = true;
		}

		bool taken[10] = { false, };
		cout << countFriends(taken) << endl;

		for (int p = 0; p < 10; ++p)
			for (int q = 0; q < 10; ++q)
				areFriends[p][q] = false;
	}
}