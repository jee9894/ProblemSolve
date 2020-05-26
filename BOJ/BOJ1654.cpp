/****************************************************************************
                        jee9894's Problem Solve Study
=============================================================================
        Problem Name       : 랜선 자르기
        Problem Number     : 1654
        algorithm          : Binary Search
=============================================================================
        History
        ---------------------------------------------------------------------
        jee9894 : 2020.01.02 create
        ---------------------------------------------------------------------
=============================================================================
        Note.
****************************************************************************/
#include <iostream>
using namespace std;

#define MAX_SIZE 10001

unsigned int ranWire[MAX_SIZE];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, N;
	cin >> K >> N;

	//  low = 1, high = 입력받은 K개의 랜선중 가장 긴 랜선 길이
	unsigned int high = 0, low = 1;
	for (int i = 1; i <= K; ++i)
	{
		cin >> ranWire[i];
		high = ranWire[i] > high ? ranWire[i] : high;
	}

	// 이분 탐색 시작
	unsigned int result = 0;
	while (high >= low)
	{
		// 중간값 설정
		unsigned int mid = (high + low) / 2;

		unsigned int cnt = 0;
		for (int i = 1; i <= K; ++i)
		{
			cnt += ranWire[i] / mid;
		}

		// 자른 랜선의 갯수가 N개 보다 많으면 됨
		if (cnt >= N)
		{
			result = mid > result ? mid : result;
			// 자른 랜선 갯수가 많으니 자를 랜선의 길이를 더 늘려도 됨
			low = mid + 1;
		}
		else
		{
			// 자른 랜선 갯수가 적으니 자를 랜선의 길이를 줄여야 함
			high = mid - 1;
		}
	}

	cout << result << "\n";
}