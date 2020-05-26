/****************************************************************************
                        jee9894's Problem Solve Study
=============================================================================
        Problem Name       : 나무 자르기
        Problem Number     : 2805
        algorithm          : Binary Search
=============================================================================
        History
        ---------------------------------------------------------------------
        jee9894 : 2020.01.03 create
        ---------------------------------------------------------------------
=============================================================================
        Note.
****************************************************************************/
#include <iostream>
using namespace std;

#define MAX_SIZE 1000001

int length[MAX_SIZE];
int N, M;

int BinarySearch(int high)
{
	int result = 0, low = 0;
	while (high >= low)
	{
		int mid = (high + low) / 2;
		long long sum = 0;
		for (int i = 1; i <= N; ++i)
		{
			int temp = length[i] - mid;
			if (temp > 0)
			{
				// 벌목 할 수 있는 나무의 총 길이
				sum += temp;
			}
		}
		if (sum >= M)
		{
			result = mid > result ? mid : result;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return result;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	int high = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> length[i];
		high = length[i] > high ? length[i] : high;
	}

	cout << BinarySearch(high) << "\n";
}
