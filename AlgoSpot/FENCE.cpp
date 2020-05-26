#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &fence, int left, int right)
{
	if (left == right)
		return fence[left];

	int mid = (left + right) / 2;

	// 왼쪽과 오른쪽 중에 가장 긴 울타리를 찾는다
	int result = max(solve(fence, left, mid), solve(fence, mid + 1, right));

	// 정중앙에서 [-1,+1]의 울타리 너비 고려
	int low = mid, high = mid + 1;
	int height = min(fence[low], fence[high]);
	result = max(result, height * 2);

	while (left < low || high < right)
	{
		if (high < right && (low == left || fence[low - 1] < fence[high + 1]))
		{
			high++;
			height = min(height, fence[high]);
		}
		else
		{
			low--;
			height = min(height, fence[low]);
		}
		result = max(result, height*(high - low + 1));
	}
	return result;
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
		vector<int> fence;
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			int input;
			cin >> input;
			fence.push_back(input);
		}
		cout << solve(fence, 0, n - 1) << endl;
	}

	return 0;
}